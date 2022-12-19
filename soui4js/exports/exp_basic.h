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