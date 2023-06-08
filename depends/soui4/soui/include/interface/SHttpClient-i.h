/*****************************************************************
*HTTP�����࣬��Ҫ����HTTP GET/POST�����أ�֧���ض��򣩹���
*Author��	JelinYao
*Date��		2015/2/14 12:11
*Email��	mailto://jelinyao@163.com
*/
/*****************************************************************
*/
#pragma once
#include <interface/obj-ref-i.h>
#include <interface/sstring-i.h>
#include <stdint.h>

SNSBEGIN

typedef enum RequestType
{
	Hr_Post,
	Hr_Get,
}RequestType;
//ö������״̬
typedef enum DownloadState
{
	DS_Start = 0,
	DS_Loading,
	DS_Finished,
	DS_Failed,
}DownloadState;

/******************************************************
*���������Ϣ
*
******************************************************/
typedef enum HttpError
{
	Hir_Success = 0,		//�ɹ�
	Hir_InitErr,			//��ʼ��ʧ��
	Hir_ConnectErr,			//����HTTP������ʧ��
	Hir_SendErr,			//��������ʧ��
	Hir_QueryErr,			//��ѯHTTP����ͷʧ��
	Hir_404,				//ҳ�治����
	Hir_IllegalUrl,			//��Ч��URL
	Hir_CreateFileErr,		//�����ļ�ʧ��
	Hir_DownloadErr,		//����ʧ��
	Hir_QueryIPErr,			//��ȡ������Ӧ�ĵ�ַʧ��
	Hir_SocketErr,			//�׽��ִ���
	Hir_UserCancel,			//�û�ȡ������
	Hir_BufferErr,			//�ļ�̫�󣬻���������
	Hir_HeaderErr,			//HTTP����ͷ����
	Hir_ParamErr,			//�������󣬿�ָ�룬���ַ�����
	Hir_UnknowErr,

}HttpError;


#undef INTERFACE
#define INTERFACE IHttpCallback
DECLARE_INTERFACE_(IHttpCallback, IObjRef){
   /**
     * @brief �������ü���
     * @return �����ü���
    */
    STDMETHOD_(long,AddRef) (THIS) PURE;

    /**
     * @brief �������ü���
     * @return �����ü���
    */
    STDMETHOD_(long,Release) (THIS) PURE;

	/**
	 * @brief �ͷŶ���
	 * @return void
	*/
	STDMETHOD_(void,OnFinalRelease) (THIS) PURE;
	//////////////////////////////////////////////////////////////////////////
	STDMETHOD_(BOOL,OnDownloadCallback)(THIS_ DownloadState state, uint64_t nTotalSize, uint64_t nLoadSize) PURE;
};

#undef INTERFACE
#define INTERFACE IHttpClient
DECLARE_INTERFACE_(IHttpClient, IObjRef){
   /**
     * @brief �������ü���
     * @return �����ü���
    */
    STDMETHOD_(long,AddRef) (THIS) PURE;

    /**
     * @brief �������ü���
     * @return �����ü���
    */
    STDMETHOD_(long,Release) (THIS) PURE;

	/**
	 * @brief �ͷŶ���
	 * @return void
	*/
	STDMETHOD_(void,OnFinalRelease) (THIS) PURE;
	//////////////////////////////////////////////////////////////////////////
	STDMETHOD_(void,SetHeader)(THIS_ LPCSTR pszKey,LPCSTR pszValue) PURE;
	STDMETHOD_(void,SetDownloadCallback)(THIS_ IHttpCallback* pCallback) PURE;
	STDMETHOD_(BOOL,DownloadFile)(THIS_ LPCSTR lpUrl, LPCSTR lpFilePath) PURE;
	STDMETHOD_(BOOL,DownloadToMem)(THIS_ LPCSTR lpUrl, OUT void** ppBuffer, OUT int* nSize) PURE;
	STDMETHOD_(HttpError,GetErrorCode)(CTHIS) SCONST PURE;
	STDMETHOD_(BOOL,Request)(THIS_ IStringA *result,LPCSTR lpUrl, RequestType type, LPCSTR lpPostData DEF_VAL(NULL), LPCSTR lpHeader DEF_VAL(NULL)) PURE;
	STDMETHOD_(void,SetTimeOut)(THIS_ int dwConnectTime,  int dwSendTime, int dwRecvTime) PURE;		
	STDMETHOD_(int,GetHttpCode)(CTHIS) SCONST PURE;
};

SNSEND



