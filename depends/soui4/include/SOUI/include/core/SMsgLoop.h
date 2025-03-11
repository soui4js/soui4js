﻿#ifndef __SMSGLOOP__H__
#define __SMSGLOOP__H__
#include <soui_exp.h>
#include <helper/obj-ref-impl.hpp>
#include <interface/SMsgLoop-i.h>

SNSBEGIN

class SMessageLoopPriv;
class SOUI_EXP SMessageLoop : public TObjRefImpl<IMessageLoop> {
  public:
    SMessageLoop(IMessageLoop *pParentLoop);
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
    STDMETHOD_(BOOL, OnIdle)(THIS_ int nIdleCount) OVERRIDE;

    STDMETHOD_(int, Run)(THIS) OVERRIDE;

    STDMETHOD_(BOOL, IsRunning)(THIS) const OVERRIDE;

    STDMETHOD_(void, OnMsg)(THIS_ LPMSG pMsg) OVERRIDE;

    STDMETHOD_(void, Quit)(THIS_ int exitCode) OVERRIDE;

    STDMETHOD_(BOOL, PostTask)(THIS_ IRunnable *runable) OVERRIDE;

    STDMETHOD_(int, RemoveTasksForObject)(THIS_ void *pObj) OVERRIDE;

    STDMETHOD_(void, ExecutePendingTask)() OVERRIDE;

    STDMETHOD_(BOOL, PeekMsg)(THIS_ LPMSG pMsg, UINT wMsgFilterMin, UINT wMsgFilterMax, BOOL bRemove) OVERRIDE;

    STDMETHOD_(BOOL, WaitMsg)(THIS) OVERRIDE;

    STDMETHOD_(int, HandleMsg)(THIS) OVERRIDE;

  public:
    static BOOL IsIdleMessage(MSG *pMsg);

  protected:
    void RunIdle();
  protected:

    BOOL m_bRunning;
    BOOL m_bQuit;
    BOOL m_bDoIdle;
    int m_nIdleCount;

    SCriticalSection m_cs;
    SCriticalSection m_csRunningQueue;
    tid_t m_tid;
    SMessageLoopPriv *m_priv;
};

SNSEND
#endif // __SMSGLOOP__H__