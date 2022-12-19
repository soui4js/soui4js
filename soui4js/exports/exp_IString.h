#pragma once
#include <interface/sstring-i.h>

void Exp_IStringA(qjsbind::Module* module)
{
	JsClass<IStringA> jsCls = module->ExportClass<IStringA>("IStringA");
	jsCls.Init();
	jsCls.AddFunc("GetLength", &IStringA::GetLength);
	jsCls.AddFunc("IsEmpty", &IStringA::IsEmpty);
	jsCls.AddFunc("Empty", &IStringA::Empty);
	jsCls.AddFunc("GetAt", &IStringA::GetAt);
	jsCls.AddFunc("SetAt", &IStringA::SetAt);

	jsCls.AddFunc("c_str", &IStringA::c_str);
	jsCls.AddFunc("Compare", &IStringA::Compare);
	jsCls.AddFunc("CompareNoCase", &IStringA::CompareNoCase);

	jsCls.AddFunc("TrimBlank", &IStringA::TrimBlank);
	jsCls.AddFunc("InsertChar", &IStringA::InsertChar);
	jsCls.AddFunc("Insert", &IStringA::Insert);
	jsCls.AddFunc("Delete", &IStringA::Delete);
	jsCls.AddFunc("ReplaceChar", &IStringA::ReplaceChar);
	jsCls.AddFunc("Replace", &IStringA::Replace);
	jsCls.AddFunc("Remove", &IStringA::Remove);

	jsCls.AddFunc("FindChar", &IStringA::FindChar);
	jsCls.AddFunc("ReverseFind", &IStringA::ReverseFind);

	jsCls.AddFunc("Find", &IStringA::Find);

	jsCls.AddFunc("GetBuffer", &IStringA::GetBuffer);
	jsCls.AddFunc("ReleaseBuffer", &IStringA::ReleaseBuffer);
	jsCls.AddFunc("GetBufferSetLength", &IStringA::GetBufferSetLength);
	jsCls.AddFunc("SetLength", &IStringA::SetLength);
	jsCls.AddFunc("Copy", &IStringA::Copy);
	jsCls.AddFunc("Assign", &IStringA::Assign);
	jsCls.AddFunc("Assign2", &IStringA::Assign2);
	jsCls.AddFunc("GetPrivData", &IStringA::GetPrivData);

	jsCls.AddFunc("ToUpper", &IStringA::ToUpper);
	jsCls.AddFunc("ToLower", &IStringA::ToLower);

	jsCls.AddFunc("TrimRight", &IStringA::TrimRight);
	jsCls.AddFunc("TrimLeft", &IStringA::TrimLeft);
	jsCls.AddFunc("Trim", &IStringA::Trim);
	jsCls.AddFunc("AppendChar", &IStringA::AppendChar);
	jsCls.AddFunc("AppendStr", &IStringA::AppendStr);
}

void Exp_IStringW(qjsbind::Module* module)
{
	JsClass<IStringW> jsCls = module->ExportClass<IStringW>("IStringW");
	jsCls.Init();
	jsCls.AddFunc("GetLength", &IStringW::GetLength);
	jsCls.AddFunc("IsEmpty", &IStringW::IsEmpty);
	jsCls.AddFunc("Empty", &IStringW::Empty);
	jsCls.AddFunc("GetAt", &IStringW::GetAt);
	jsCls.AddFunc("SetAt", &IStringW::SetAt);

	jsCls.AddFunc("c_str", &IStringW::c_str);
	jsCls.AddFunc("Compare", &IStringW::Compare);
	jsCls.AddFunc("CompareNoCase", &IStringW::CompareNoCase);

	jsCls.AddFunc("TrimBlank", &IStringW::TrimBlank);
	jsCls.AddFunc("InsertChar", &IStringW::InsertChar);
	jsCls.AddFunc("Insert", &IStringW::Insert);
	jsCls.AddFunc("Delete", &IStringW::Delete);
	jsCls.AddFunc("ReplaceChar", &IStringW::ReplaceChar);
	jsCls.AddFunc("Replace", &IStringW::Replace);
	jsCls.AddFunc("Remove", &IStringW::Remove);

	jsCls.AddFunc("FindChar", &IStringW::FindChar);
	jsCls.AddFunc("ReverseFind", &IStringW::ReverseFind);

	jsCls.AddFunc("Find", &IStringW::Find);

	jsCls.AddFunc("GetBuffer", &IStringW::GetBuffer);
	jsCls.AddFunc("ReleaseBuffer", &IStringW::ReleaseBuffer);
	jsCls.AddFunc("GetBufferSetLength", &IStringW::GetBufferSetLength);
	jsCls.AddFunc("SetLength", &IStringW::SetLength);
	jsCls.AddFunc("Copy", &IStringW::Copy);
	jsCls.AddFunc("Assign", &IStringW::Assign);
	jsCls.AddFunc("Assign2", &IStringW::Assign2);
	jsCls.AddFunc("GetPrivData", &IStringW::GetPrivData);

	jsCls.AddFunc("ToUpper", &IStringW::ToUpper);
	jsCls.AddFunc("ToLower", &IStringW::ToLower);

	jsCls.AddFunc("TrimRight", &IStringW::TrimRight);
	jsCls.AddFunc("TrimLeft", &IStringW::TrimLeft);
	jsCls.AddFunc("Trim", &IStringW::Trim);
	jsCls.AddFunc("AppendChar", &IStringW::AppendChar);
	jsCls.AddFunc("AppendStr", &IStringW::AppendStr);
}