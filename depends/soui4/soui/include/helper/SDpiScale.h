﻿#ifndef __SDPISCALE__H__
#define __SDPISCALE__H__
SNSBEGIN
class SOUI_EXP SDpiScale {
  public:
    static int GetBuiltinScaleCount();

    static const int *GetBuiltinScales();

    /**
     * NormalizeScale
     * @brief    标准化放大比例, 选择比自己指定比例小一号的比例
     * @param [in] nScale -- input scale
     * @return   int -- normalized scale
     *
     * Describe
     */
    static int NormalizeScale(int nScale);
};

SNSEND

#endif // __SDPISCALE__H__