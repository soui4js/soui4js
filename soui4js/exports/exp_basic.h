#pragma once

void Exp_Basic(qjsbind::Module* module) {
	{
		JsClass<POINT> jsCls = module->ExportClass<POINT>("POINT");
		jsCls.Init();
		jsCls.AddGetSet("x", &POINT::x);
		jsCls.AddGetSet("y", &POINT::y);
	}
	{
		JsClass<CPoint> jsCls = module->ExportClass<CPoint>("CPoint");
		jsCls.Init(JsClass<POINT>::class_id());
		jsCls.AddCtor<qjsbind::constructor<CPoint, int, int>>();
	}
	{
		JsClass<RECT> jsCls = module->ExportClass<RECT>("RECT");
		jsCls.Init();
		jsCls.AddGetSet( "left", &RECT::left);
		jsCls.AddGetSet( "top", &RECT::top);
		jsCls.AddGetSet( "right", &RECT::right);
		jsCls.AddGetSet( "bottom", &RECT::bottom);
	}
	{
		JsClass<CRect> jsCls = module->ExportClass<CRect>("CRect");
		jsCls.Init(JsClass<RECT>::class_id());
		jsCls.AddCtor<qjsbind::constructor<CRect, int, int,int,int>>();
		jsCls.AddCtor<qjsbind::constructor<CRect, RECT>>();
		jsCls.AddFunc("CenterPoint", &CRect::CenterPoint);
		jsCls.AddFunc("Width", &CRect::Width);
		jsCls.AddFunc("Height", &CRect::Height);
		jsCls.AddFunc("PtInRect", &CRect::PtInRect);
		jsCls.AddFunc("IsRectEmpty", &CRect::IsRectEmpty);
		jsCls.AddFunc("InflateRect", (void (CRect::*)(int,int,int,int))&CRect::InflateRect);
		jsCls.AddFunc("DeflateRect", (void (CRect::*)(int, int, int, int)) & CRect::DeflateRect);
		jsCls.AddFunc("OffsetRect", (void (CRect::*)(int, int)) &CRect::OffsetRect);
		jsCls.AddFunc("MoveToXY", (void (CRect::*)(int, int)) & CRect::MoveToXY);
		jsCls.AddFunc("MoveToX",  & CRect::MoveToX);
		jsCls.AddFunc("MoveToY",  & CRect::MoveToY);
		jsCls.AddFunc("IntersectRect", &CRect::IntersectRect);
		jsCls.AddFunc("UnionRect", &CRect::UnionRect);
		jsCls.AddFunc("SubtractRect", &CRect::SubtractRect);
	}
	//SIZE
	{
		JsClass<SIZE> jsCls = module->ExportClass<SIZE>("SIZE");
		jsCls.Init();
		jsCls.AddGetSet("cx", &SIZE::cx);
		jsCls.AddGetSet("cy", &SIZE::cy);
	}
	{
		JsClass<CSize> jsCls = module->ExportClass<CSize>("CSize");
		jsCls.Init(JsClass<SIZE>::class_id());
		jsCls.AddCtor<qjsbind::constructor<CSize, int, int>>();
		jsCls.AddCtor<qjsbind::constructor<CSize, int, int>>();
	}
	{
		JsClass<SYSTEMTIME> jsCls = module->ExportClass<SYSTEMTIME>("SYSTEMTIME");
		jsCls.Init();
		jsCls.AddGetSet("wYear", &SYSTEMTIME::wYear);
		jsCls.AddGetSet("wMonth", &SYSTEMTIME::wMonth);
		jsCls.AddGetSet("wDayOfWeek", &SYSTEMTIME::wDayOfWeek);
		jsCls.AddGetSet("wDay", &SYSTEMTIME::wDay);
		jsCls.AddGetSet("wHour", &SYSTEMTIME::wHour);
		jsCls.AddGetSet("wMinute", &SYSTEMTIME::wMinute);
		jsCls.AddGetSet("wSecond", &SYSTEMTIME::wSecond);
		jsCls.AddGetSet("wMilliseconds", &SYSTEMTIME::wMilliseconds);
	}
}