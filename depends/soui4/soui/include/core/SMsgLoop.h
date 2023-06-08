﻿#pragma once
#include <interface/smsgloop-i.h>
#include <souicoll.h>

SNSBEGIN

class SOUI_EXP SMessageLoop : public TObjRefImpl<IMessageLoop> {
  public:
    SMessageLoop(IMessageLoop * pParentLoop);
    virtual ~SMessageLoop();

  public:
    // Message filter operations
    STDMETHOD_(BOOL, AddMessageFilter)(THIS_ IMsgFilter *pMessageFilter) OVERRIDE;

    STDMETHOD_(BOOL, RemoveMessageFilter)(THIS_ IMsgFilter *pMessageFilter) OVERRIDE;

    // Idle handler operations
    STDMETHOD_(BOOL, AddIdleHandler)(THIS_ IIdleHandler *pIdleHandler) OVERRIDE;

    STDMETHOD_(BOOL, RemoveIdleHandler)(THIS_ IIdleHandler *pIdleHandler) OVERRIDE;

    // Override to change message filtering
    STDMETHOD_(BOOL, PreTranslateMessage)(THIS_ MSG *pMsg) OVERRIDE;

    // override to change idle processing
    STDMETHOD_(BOOL, OnIdle)(THIS_ int /*nIdleCount*/) OVERRIDE;

    STDMETHOD_(int, Run)(THIS) OVERRIDE;

    STDMETHOD_(BOOL, IsRunning)(THIS) const OVERRIDE;

    STDMETHOD_(void, OnMsg)(THIS_ LPMSG pMsg) OVERRIDE;

    STDMETHOD_(void, Quit)(THIS) OVERRIDE;

    STDMETHOD_(BOOL, PostTask)(THIS_ IRunnable *runable) OVERRIDE;

    STDMETHOD_(int, RemoveTasksForObject)(THIS_ void *pObj) OVERRIDE;

	STDMETHOD_(void, ExecutePendingTask)() OVERRIDE;

  protected:
	virtual BOOL OnWaitMessage();
  public:
    static BOOL IsIdleMessage(MSG *pMsg);

  protected:
    SArray<IMsgFilter *> m_aMsgFilter;
    SArray<IIdleHandler *> m_aIdleHandler;
    MSG m_msg;

    BOOL m_bRunning;
    BOOL m_bQuit;
    SCriticalSection m_cs;
    SList<IRunnable *> m_runnables;
    SCriticalSection m_csRunningQueue;
    SList<IRunnable *> m_runningQueue;
	SAutoRefPtr<IMessageLoop> m_parentLoop;
    DWORD m_tid;
};

SNSEND