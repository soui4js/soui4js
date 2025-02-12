#ifndef WsClient_H
#define WsClient_H

#include <ws-i.h>
#include <libwebsockets.h>
#include <helper/obj-ref-impl.hpp>
#include <string>
#include <thread>
#include <condition_variable>
#include <sstream>
#include <atomic>
#include <mutex>
#include <list>
#include <windows.h>
SNSBEGIN

class WsClient : public TObjRefImpl<IWsClient> {
  public:
    WsClient(IConnListener *pListener);

    ~WsClient();

  public:
    int connectTo(const char *server_, const char *path_, uint16_t port, const char *protocolName_, ClientOption option) override;

    bool wait(int timeoutMs) override;

    int isValid() const override
    {
        return m_connected || !m_finished;
    }

    int sendText(const char *text, int nLen) override
    {
        if (nLen < 0)
            nLen = strlen(text);
        return send(std::string(text, nLen), false);
    }
    int sendBinary(const void *data, int nLen) override
    {
        return send(std::string((const char *)data, nLen), true);
    }
 
    void disconnect() override;

  private:
    void quit();

    int send(const std::string &text, bool bBinary);

    int genMsgId()
    {
        m_msgId++;
        if (m_msgId < 0)
            m_msgId = 0;
        return m_msgId;
    }

    void run();
    int handler(lws_callback_reasons reasons, void *user, const void *data, std::size_t len);

    IConnListener *m_pListener;
    std::thread m_worker;
    std::atomic_bool m_connected;

    std::string m_server, m_path;
    uint16_t m_port;

    std::string m_protocolName;
    lws_context *m_context;
    lws *m_wsi;

    std::mutex m_mutex;
    std::condition_variable m_cvQuit;
    std::atomic_bool m_finished;

    std::stringstream m_receiveStream;

    struct MsgData
    {
        std::string buf;
        bool bBinary;
        int msgId;
    };
    std::list<MsgData> m_sendingBuf;
    int m_msgId;

    static int cb_lws(lws *websocket, lws_callback_reasons reasons, void *, void *data, std::size_t len);
};

SNSEND

#endif // WsClient_H
