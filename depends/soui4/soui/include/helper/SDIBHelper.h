﻿#pragma once

#include "interface/SRender-i.h"

SNSBEGIN
/// <summary>
///		简洁版本，简版去掉了对8、16、24位的支持,
/// </summary>
class SOUI_EXP SDIBHelper {
  public:
    static bool Colorize(IBitmapS *pBmp, COLORREF crRef);

    static bool Colorize(COLORREF &crTarget, COLORREF crRef);

    static bool GrayImage(IBitmapS *pBmp);

    //计算图片的平均色
    // IBitmap *pBmp:图片源
    // int nPercent:有效值百分比，90代表最高和最低5%的值会丢掉，不参与平均。
    // int int nBlockSize:分块大小, 每次计算一个块的颜色平均值。
    static COLORREF CalcAvarageColor(IBitmapS *pBmp, int nPercent = 90, int nBlockSize = 5);
};

SNSEND