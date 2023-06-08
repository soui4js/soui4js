#pragma once
#include <interface/obj-ref-i.h>

SNSBEGIN

#undef INTERFACE
#define INTERFACE IRunnable
DECLARE_INTERFACE_(IRunnable, IObjRef)
{
    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, AddRef)(THIS) PURE;

    /**
     * @brief �������ü���
     * @return �����ü���
     */
    STDMETHOD_(long, Release)(THIS) PURE;

    /**
     * @brief �ͷŶ���
     * @return void
     */
    STDMETHOD_(void, OnFinalRelease)(THIS) PURE;

    /**
     * @brief clone��ǰ����
     * @return IRunnable *--clone�õ����¶���
     */
    STDMETHOD_(IRunnable *, clone)(CTHIS) SCONST PURE;

    /**
     * @brief ���иö���
     * @return
     */
    STDMETHOD_(void, run)(THIS) PURE;

    /**
     * @brief ��ȡ��Runnable������
     * @return void *--����ָ�룬����FreeFunction���󣬸�ֵΪNULL
     */
    STDMETHOD_(void *, getObject)(THIS) PURE;

    /**
     * @brief ��ȡrunnable������
     * @return const char *--����
     */
    STDMETHOD_(const char *, getClassInfo)(CTHIS) SCONST PURE;
};

typedef enum Priority
{
    High = 1,
    Normal = 0,
    Low = -1,
} Priority;

#undef INTERFACE
#define INTERFACE ITaskLoop
DECLARE_INTERFACE_(ITaskLoop, IObjRef)
{
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

    STDMETHOD_(BOOL, getName)(THIS_ char *pszBuf, int nBufLen) PURE;

    /**
     * Start a thread to run.
     * @param priority the thread priority
     */
    STDMETHOD_(void, start)(THIS_ const char *pszName, Priority priority) PURE;

    /**
     * Stop thread synchronized.
     */
    STDMETHOD_(void, stop)(THIS) PURE;

    /**
     * postTask post or send a tasks to this task manager.
     * @param runnable the to be run task object.
     * @param waitUntilDone, true for send and false for post.
     * @param priority, the task priority.
     * @return the task id, can be used by cancelTask.
     */
    STDMETHOD_(long, postTask)
    (THIS_ const IRunnable *runnable, BOOL waitUntilDone, int priority) PURE;

    /**
     * Remove tasks for a specific object from task loop pending task list
     * @param object the specific object wants pending functors to be removed
     */
    STDMETHOD_(void, cancelTasksForObject)(THIS_ void *object) PURE;

    /**
     * Cancel tasks for a specific task ID list
     * @param taskList the task ID list to be canceled
     * @return the removed task list.
     */
    STDMETHOD_(BOOL, cancelTask)(THIS_ long taskId) PURE;

    /**
     * get the total task number in the task loop queue.
     * @return total task number in task loop queue
     */
    STDMETHOD_(int, getTaskCount)(CTHIS) SCONST PURE;

    /**
     * get the run loop status.
     * @return the running status
     */
    STDMETHOD_(BOOL, isRunning)(THIS) PURE;

    /**
     * get the running task info.
     * @param buf, to receive task info buf.
     * @param bufLen, buffer length
     * @return false - no task is running; true - succeed.
     */
    STDMETHOD_(BOOL, getRunningTaskInfo)(THIS_ char *buf, int bufLen) PURE;


	/**
     * set a task to run repeat.
     * @param pTask the to be run task object.
     * @param intervel heart beat interval
     * @return void
	 * @remark task loop will hold a clone of the pTask. set pTask to null to stop heart beat.
     */
	STDMETHOD_(void,setHeartBeatTask)(THIS_ IRunnable *pTask, int intervel) PURE;
};

SNSEND