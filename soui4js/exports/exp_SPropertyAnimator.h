#pragma once
#include "interface/SPropertyAnimator-i.h"
#include "interface/SValueAnimator-i.h"
#include "interface/SApp-i.h"
#include <valueAnimator/SPropertyAnimator.h>
#include "exp_SValueAnimator.h"
#include <vector>

class JsPropertyValuesHolder : public JsThisOwner {
public:
    JsPropertyValuesHolder() {}
    
    void Init(IPropertyValuesHolder* pHolder) {
        m_propertyValuesHolder = pHolder;
    }
    
    IPropertyValuesHolder* GetIPropertyValuesHolder() {
        return m_propertyValuesHolder;
    }
    
    void SetPropertyName(const LPCSTR name) {
        if (!m_propertyValuesHolder)
            return;
        SStringW wstrName = S_CA2T(name, CP_UTF8);
        m_propertyValuesHolder->SetPropertyName(wstrName);
    }
    
    const char* GetPropertyName() {
        if (!m_propertyValuesHolder)
            return "";
        LPCWSTR wstrName = m_propertyValuesHolder->GetPropertyName();
        if (!wstrName) return "";
        m_strName = S_CW2A(wstrName, CP_UTF8);
        return m_strName;
    }
    
    void SetFloatValues(const qjsbind::Value& values){
        if (!m_propertyValuesHolder) return;
        if(!values.IsArray()) return;
        float *data = new float[values.length()];
        for (int i = 0; i < values.length(); i++) {
            data[i] = (float)values.GetProperty(i).ToFloat64();
        }
        m_propertyValuesHolder->SetFloatValues(data, values.length());
        delete []data;
    }

    void SetByteValues(const qjsbind::Value& values){
        if (!m_propertyValuesHolder) return;
        if(!values.IsArray()) return;
        uint8_t *data = new uint8_t[values.length()];
        for (int i = 0; i < values.length(); i++) {
            data[i] = (uint8_t)values.GetProperty(i).ToInt32();
        }
        m_propertyValuesHolder->SetByteValues(data, values.length());
        delete []data;
    }

    void SetIntValues(const qjsbind::Value& values){
        if (!m_propertyValuesHolder) return;
        if(!values.IsArray()) return;
        int *data = new int[values.length()];
        for (int i = 0; i < values.length(); i++) {
            data[i] = (int)values.GetProperty(i).ToInt32();
        }
        m_propertyValuesHolder->SetIntValues(data, values.length());
        delete []data;
    }

    void SetColorRefValues(const qjsbind::Value& values){
        if (!m_propertyValuesHolder) return;
        if(!values.IsArray()) return;
        COLORREF *data = new COLORREF[values.length()];
        for (int i = 0; i < values.length(); i++) {
            data[i] = values.GetProperty(i).ToUint32();
        }
        m_propertyValuesHolder->SetColorRefValues(data, values.length());
        delete []data;
    }

    float GetAnimatedValue(float fraction) {
        if (!m_propertyValuesHolder) return 0.0f;
        
        float value = 0.0f;
        if (m_propertyValuesHolder->GetAnimatedValue(fraction, &value)) {
            return value;
        }
        return 0.0f;
    }
    
    int GetValueType() {
        if (!m_propertyValuesHolder) return PROP_TYPE_UNKNOWN;
        return m_propertyValuesHolder->GetValueType();
    }
    
    int GetValueSize() {
        if (!m_propertyValuesHolder) return 0;
        return m_propertyValuesHolder->GetValueSize();
    }

    int GetKeyframeCount() {
        if (!m_propertyValuesHolder) return 0;
        return m_propertyValuesHolder->GetKeyframeCount();
    }
    
    bool SetKeyFrameWeights(const qjsbind::Value& weights) {
        if (!m_propertyValuesHolder) return false;
        
        std::vector<float> weightValues;
        if (weights.IsArray()) {
            int len = weights.length();
            for (int i = 0; i < len; i++) {
                weightValues.push_back((float)weights.GetProperty(i).ToFloat64());
            }
        }
        return m_propertyValuesHolder->SetKeyFrameWeights(weightValues.empty() ? nullptr : &weightValues[0], (int)weightValues.size());
    }
    
    bool GetKeyFrameWeights(qjsbind::Value& weights) {
        if (!m_propertyValuesHolder) return false;
        
        int count = weights.length();
        std::vector<float> weightValues(count);
        bool result = m_propertyValuesHolder->GetKeyFrameWeights(weightValues.empty() ? nullptr : &weightValues[0], count);
        if (result) {
            qjsbind::Context* ctx = weights.context();
            for (uint32_t i = 0; i < count; i++) {
                qjsbind::Value weightValue = qjsbind::NewValue(*ctx, weightValues[i]);
                weights.SetProperty(i, weightValue);
            }
        }
        return result;
    }

protected:
    SAutoRefPtr<IPropertyValuesHolder> m_propertyValuesHolder;
    SStringA m_strName;
};

class JsPropertyAnimator : public JsValueAnimator {
public:
    JsPropertyAnimator() {
        m_propertyAnimator.Attach(new SPropertyAnimator(nullptr));
        InitAnimator(m_propertyAnimator);
    }
    
    ~JsPropertyAnimator() {

    }
    
public:
    IPropertyAnimator* GetIPropertyAnimator() {
        return m_propertyAnimator;
    }

public:
    /**
     * @brief 获取动画目标
     * @return 动画目标
     */
    IWindow * GetTarget() const{
        return m_propertyAnimator->GetTarget();
    }

    /**
     * @brief 设置动画目标
     * @param target 动画目标
     */
    void SetTarget(IWindow *target){
        m_propertyAnimator->SetTarget(target);
    }

    /**
     * @brief 设置属性值持有者
     * @param pHolder 属性值持有者
     */
    void SetPropertyValuesHolder(JsPropertyValuesHolder *pHolder){
        if(pHolder)
            m_propertyAnimator->SetPropertyValuesHolder(pHolder->GetIPropertyValuesHolder());
    }
    /**
     * @brief 设置属性值持有者数组
     * @param pHolders 属性值持有者数组
     * @param count 属性值持有者数量
     */
    void SetPropertyValuesHolders(IPropertyValuesHolder **pHolders, int count){
        m_propertyAnimator->SetPropertyValuesHolders(pHolders, count);
    }
    /**
     * @brief 获取属性值持有者
     * @param propertyName 属性名称
     * @return 属性值持有者
     */
    IPropertyValuesHolder *GetPropertyValuesHolderByName(LPCSTR propertyName){
        SStringW strName = S_CA2W(propertyName, CP_UTF8);
        return m_propertyAnimator->GetPropertyValuesHolderByName(strName);
    }

    /**
     * @brief 获取属性值持有者
     * @param index 索引
     * @return 属性值持有者
     */
    IPropertyValuesHolder *GetPropertyValuesHolderByIndex(int index){
        return m_propertyAnimator->GetPropertyValuesHolderByIndex(index);
    }

    /**
     * @brief 获取属性值持有者数量
     * @return 属性值持有者数量
     */
    int GetPropertyValuesHolderCount(){
        return m_propertyAnimator->GetPropertyValuesHolderCount();
    }

protected:
    SAutoRefPtr<IPropertyAnimator> m_propertyAnimator;
};

void JsPropertyAnimator_SetPropertyValuesHolders(Context* ctx, JsPropertyAnimator* _this, ArgList& args){
    if(args.size() == 0)
        return;
    if(args.size() == 1){
        if(args[0].IsArray()){
            int len = args[0].length();
            IPropertyValuesHolder * * holders = new IPropertyValuesHolder*[len];
            for(int i=0;i<len;i++){
                holders[i] = args[0].GetProperty(i).ToObject<IPropertyValuesHolder>();
            }
            _this->SetPropertyValuesHolders(holders,len);
            delete [] holders;
        }
    }else{
        IPropertyValuesHolder * * holders = new IPropertyValuesHolder*[args.size()];
        for(int i=0;i<args.size();i++){
            holders[i] = args[i].ToObject<IPropertyValuesHolder>();
        }
        _this->SetPropertyValuesHolders(holders, args.size());
        delete []holders;
    }
}

void Exp_SPropertyAnimator(qjsbind::Module* module) {

    {
        // Export SPropertyValuesHolder as JsPropertyValuesHolder
        JsClass<JsPropertyValuesHolder> jsCls = module->ExportClass<JsPropertyValuesHolder>("SPropertyValuesHolder");
        jsCls.Init();
        jsCls.AddCtor<constructor<JsPropertyValuesHolder>>();
        jsCls.AddFunc("GetIPropertyValuesHolder", &JsPropertyValuesHolder::GetIPropertyValuesHolder);
        jsCls.AddFunc("SetPropertyName", &JsPropertyValuesHolder::SetPropertyName);
        jsCls.AddFunc("GetPropertyName", &JsPropertyValuesHolder::GetPropertyName);
        jsCls.AddFunc("SetFloatValues", &JsPropertyValuesHolder::SetFloatValues);
        jsCls.AddFunc("SetByteValues", &JsPropertyValuesHolder::SetByteValues);
        jsCls.AddFunc("SetIntValues", &JsPropertyValuesHolder::SetIntValues);
        jsCls.AddFunc("SetColorRefValues", &JsPropertyValuesHolder::SetColorRefValues);
        jsCls.AddFunc("GetAnimatedValue", &JsPropertyValuesHolder::GetAnimatedValue);
        jsCls.AddFunc("GetValueType", &JsPropertyValuesHolder::GetValueType);
        jsCls.AddFunc("GetValueSize", &JsPropertyValuesHolder::GetValueSize);
        jsCls.AddFunc("GetKeyframeCount", &JsPropertyValuesHolder::GetKeyframeCount);
        jsCls.AddFunc("SetKeyFrameWeights", &JsPropertyValuesHolder::SetKeyFrameWeights);
        jsCls.AddFunc("GetKeyFrameWeights", &JsPropertyValuesHolder::GetKeyFrameWeights);
    }
    
    {
        // Export SPropertyAnimator as JsPropertyAnimator
        JsClass<JsPropertyAnimator> jsCls = module->ExportClass<JsPropertyAnimator>("SPropertyAnimator");
        jsCls.Init(JsClass<JsValueAnimator>::class_id());
        jsCls.AddCtor<constructor<JsPropertyAnimator>>();
        jsCls.AddFunc("GetIPropertyAnimator", &JsPropertyAnimator::GetIPropertyAnimator);
        jsCls.AddFunc("GetTarget", &JsPropertyAnimator::GetTarget);
        jsCls.AddFunc("SetTarget", &JsPropertyAnimator::SetTarget);
        jsCls.AddFunc("SetPropertyValuesHolder", &JsPropertyAnimator::SetPropertyValuesHolder);
        jsCls.AddCFunc("SetPropertyValuesHolders", JsPropertyAnimator_SetPropertyValuesHolders);
        jsCls.AddFunc("GetPropertyValuesHolderByName", &JsPropertyAnimator::GetPropertyValuesHolderByName);
        jsCls.AddFunc("GetPropertyValuesHolderByIndex", &JsPropertyAnimator::GetPropertyValuesHolderByIndex);
        jsCls.AddFunc("GetPropertyValuesHolderCount", &JsPropertyAnimator::GetPropertyValuesHolderCount);
    }
}