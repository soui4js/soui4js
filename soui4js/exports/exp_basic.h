#ifndef __EXP_BASIC__H__
#define __EXP_BASIC__H__

namespace qjsbind {
	template<>
	CRect* constructor(ArgList& args)
	{
		if(args.size()==1)
		{
			RECT* pSrc = (RECT*)args[0];
			if (pSrc) return new CRect(pSrc);
		}
		else if (args.size() == 2) {
			POINT* pt = (POINT*)args[0];
			SIZE* sz = (SIZE*)args[1];
			if (pt && sz)
				return new CRect(*pt,*sz);
		}
		else if (args.size() == 4) {
			return new CRect(
				(int)args[0],
				(int)args[1],
				(int)args[2],
				(int)args[3]
			);
		}
		return new CRect();
	}

	template<>
	CSize* constructor(ArgList& args)
	{
		if (args.size() == 1)
		{
			SIZE* sz = (SIZE*)args[0];
			if (sz)
				return new CSize(*sz);
		}		
		else if (args.size() == 2) {
			return new CSize(
				(int)args[0],
				(int)args[1]
			);
		}
		return new CSize();
	}

	template<>
	CPoint* constructor(ArgList& args)
	{
		if (args.size() == 1)
		{
			POINT* pt = (POINT*)args[0];
			if (pt)
				return new CPoint(*pt);
		}
		else if (args.size() == 2) {
			return new CPoint(
				(int)args[0],
				(int)args[1]
			);
		}
		return new CPoint();
	}
}

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
		jsCls.AddCtor<qjsbind::constructor<CPoint>>();
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
		jsCls.AddCtor<qjsbind::constructor<CRect>>();
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
		jsCls.AddCtor<qjsbind::constructor<CSize>>();
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
#endif // __EXP_BASIC__H__