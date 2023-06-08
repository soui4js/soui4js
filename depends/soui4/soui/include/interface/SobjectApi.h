//define IObject APIs, included by its derieved interfaces.

    //!�������
    /*!
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    //!�ͷ�����
    /*!
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    //!�ͷŶ���
    /*!
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    /**
     * IsClass
     * @brief    �ж�this�ǲ�������ָ��������
     * @param    LPCWSTR lpszName --  ����������
     * @return   BOOL -- true�ǲ�������
     * Describe
     */
    STDMETHOD_(BOOL, IsClass)(CTHIS_ LPCWSTR lpszName) SCONST PURE;

    /**
     * GetObjectClass
     * @brief    ���������
     * @return   LPCWSTR -- ������
     * Describe  ����һ���麯����ע����GetClassName������
     */
    STDMETHOD_(LPCWSTR, GetObjectClass)(CTHIS) SCONST PURE;

    /**
     * GetObjectType
     * @brief    ��ö�������
     * @return   int -- ��������
     * Describe  ����һ���麯����ע����GetClassType������
     */
    STDMETHOD_(int, GetObjectType)(CTHIS) SCONST PURE;

    /**
     * GetID
     * @brief    ��ȡ����ID
     * @return   int -- ����ID
     * Describe
     */
    STDMETHOD_(int, GetID)(CTHIS) SCONST PURE;

    /**
     * @brief ���ö���ID
     * @param nID int--����ID
     * @return
     */
    STDMETHOD_(void, SetID)(THIS_ int nID) PURE;

    /**
     * GetName
     * @brief    ��ȡ����Name
     * @return   LPCWSTR -- ����Name
     * Describe
     */
    STDMETHOD_(LPCWSTR, GetName)(CTHIS) SCONST PURE;

	STDMETHOD_(LPCSTR, GetNameA)(CTHIS) SCONST PURE;

    /**
     * @brief ���ö���Name
     * @param pszName LPCWSTR -- ����Name
     * @return
     */
    STDMETHOD_(void, SetName)(THIS_ LPCWSTR pszName) PURE;

    /**
     * InitFromXml
     * @brief    ��XML��ڳ�ʼ��SObject����
     * @param    SXmlNode --  XML���
     * @return   BOOL -- �ɹ�����TRUE
     * Describe
     */
    STDMETHOD_(BOOL, InitFromXml)(THIS_ IXmlNode * xmlNode) PURE;

    /**
     * OnInitFinished
     * @brief    ���Գ�ʼ����ɴ���ӿ�
     * @param    SXmlNode xmlNode --  ���Խڵ�
     * @return   void
     * Describe
     */
    STDMETHOD_(void, OnInitFinished)(THIS_ IXmlNode * xmlNode) PURE;


    /**
     * ISetAttribute
     * @brief    ����һ����������
     * @param    const IStringW *strAttribName --  ������
     * @param    const IStringW *strValue --  ����ֵ
     * @param    BOOL bLoading --  ���󴴽�ʱ��ϵͳ���ñ�־
     * @return   HRESULT -- ��������
     * Describe
     */
    STDMETHOD_(HRESULT, ISetAttribute)
    (THIS_ const IStringW *strAttribName, const IStringW *strValue, BOOL bLoading) PURE;

    /**
     * SetAttribute
     * @brief    ����һ����������
     * @param    LPCSTR pszAttr --  ������
     * @param    LPCSTR pszValue --  ����ֵ
     * @param    BOOL bLoading --  ���󴴽�ʱ��ϵͳ���ñ�־
     * @return   HRESULT -- ��������
     * Describe
     */
    STDMETHOD_(HRESULT, SetAttributeA)(THIS_ LPCSTR pszAttr, LPCSTR pszValue, BOOL bLoading DEF_VAL(FALSE)) PURE;

    /**
     * SetAttribute
     * @brief    ����һ����������
     * @param    LPCWSTR pszAttr --  ������
     * @param    LPCWSTR pszValue --  ����ֵ
     * @param    BOOL bLoading --  ���󴴽�ʱ��ϵͳ���ñ�־
     * @return   HRESULT -- ��������
     * Describe
     */
    STDMETHOD_(HRESULT, SetAttribute)(THIS_ LPCWSTR pszAttr, LPCWSTR pszValue, BOOL bLoading DEF_VAL(FALSE)) PURE;

    /**
     * GetAttribute
     * @brief    ͨ����������ѯ����ֵ
     * @param    LPCWSTR strAttr --  ������
     * @param    IStringW * pValue -- ����ֵ
     * @return   BOOL, TRUE:��ȡ�ɹ���FALSE:��ȡʧ�ܣ����Բ�����
     * Describe  Ĭ�Ϸ��ؿ�
     */
    STDMETHOD_(BOOL, GetAttribute)(CTHIS_ LPCWSTR strAttr, IStringW *pValue) SCONST PURE;

    /**
     * OnAttribute
     * @brief    ���Դ������õķ���
     * @param    LPCWSTR pszAttr--  ������
     * @param    LPCWSTR pszValue --  ����ֵ
     * @param    BOOL bLoading --  ���󴴽�ʱ��ϵͳ���ñ�־
     * @param    HRESULT hr --  ���Դ�����
     * Describe  ��������ֱ�ӷ���
     */
    STDMETHOD_(HRESULT, AfterAttribute)
    (THIS_ LPCWSTR pszAttr, LPCWSTR pszValue, BOOL bLoading, HRESULT hr) PURE;

	 /**
     * SetAttrHandler
     * @brief    �������Դ���ص�����
     * @param    FunAttrHandler attrHandler--  ���Դ���ص�����
	 * @return   void
     * Describe  
     */
	STDMETHOD_(void, SetAttrHandler)(THIS_ FunAttrHandler attrHandler) PURE;

