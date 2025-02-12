#ifndef _MULTIMON_H_
#define _MULTIMON_H_
#include <windows.h>

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

    HMONITOR MonitorFromWindow(HWND hwnd, DWORD dwFlags);
    HMONITOR MonitorFromPoint(POINT pt,     // point
                              DWORD dwFlags // determine return value
    );

    HMONITOR MonitorFromRect(LPCRECT lprc, // rectangle
                             DWORD dwFlags // determine return value
    );

    BOOL GetMonitorInfoA(HMONITOR hMonitor, LPMONITORINFO lpmi);
    BOOL GetMonitorInfoW(HMONITOR hMonitor, LPMONITORINFO lpmi);
#ifdef UNICODE
#define GetMonitorInfo GetMonitorInfoW
#else
#define GetMonitorInfo GetMonitorInfoA
#endif // UNICODE

    typedef BOOL(CALLBACK *MONITORENUMPROC)(HMONITOR, HDC, LPRECT, LPARAM);

    BOOL WINAPI EnumDisplayMonitors(HDC, LPCRECT, MONITORENUMPROC, LPARAM);

    typedef struct _DISPLAY_DEVICEA
    {
        DWORD cb;
        CHAR DeviceName[32];
        CHAR DeviceString[128];
        DWORD StateFlags;
        CHAR DeviceID[128];
        CHAR DeviceKey[128];
    } DISPLAY_DEVICEA, *PDISPLAY_DEVICEA, *LPDISPLAY_DEVICEA;
    typedef struct _DISPLAY_DEVICEW
    {
        DWORD cb;
        WCHAR DeviceName[32];
        WCHAR DeviceString[128];
        DWORD StateFlags;
        WCHAR DeviceID[128];
        WCHAR DeviceKey[128];
    } DISPLAY_DEVICEW, *PDISPLAY_DEVICEW, *LPDISPLAY_DEVICEW;

    BOOL WINAPI EnumDisplayDevicesW(PVOID, DWORD, PDISPLAY_DEVICEW, DWORD);
    BOOL WINAPI EnumDisplayDevicesA(PVOID, DWORD, PDISPLAY_DEVICEA, DWORD);

#ifdef UNICODE
    typedef DISPLAY_DEVICEW DISPLAY_DEVICE;
    typedef PDISPLAY_DEVICEW PDISPLAY_DEVICE;
    typedef LPDISPLAY_DEVICEW LPDISPLAY_DEVICE;
#define EnumDisplayDevices EnumDisplayDevicesW
#else
typedef DISPLAY_DEVICEA DISPLAY_DEVICE;
typedef PDISPLAY_DEVICEA PDISPLAY_DEVICE;
typedef LPDISPLAY_DEVICEA LPDISPLAY_DEVICE;
#define EnumDisplayDevices EnumDisplayDevicesA
#endif // UNICODE

#define CCHFORMNAME   32
#define CCHDEVICENAME 32

    typedef struct _devicemodea
    {
        char dmDeviceName[CCHDEVICENAME];
        WORD dmSpecVersion;
        WORD dmDriverVersion;
        WORD dmSize;
        WORD dmDriverExtra;
        DWORD dmFields;
        union {
            struct
            {
                short dmOrientation;
                short dmPaperSize;
                short dmPaperLength;
                short dmPaperWidth;
                short dmScale;
                short dmCopies;
                short dmDefaultSource;
                short dmPrintQuality;
            };
            struct
            {
                POINTL dmPosition;
                DWORD dmDisplayOrientation;
                DWORD dmDisplayFixedOutput;
            };
        };
        short dmColor;
        short dmDuplex;
        short dmYResolution;
        short dmTTOption;
        short dmCollate;
        char dmFormName[CCHFORMNAME];
        WORD dmLogPixels;
        DWORD dmBitsPerPel;
        DWORD dmPelsWidth;
        DWORD dmPelsHeight;
        union {
            DWORD dmDisplayFlags;
            DWORD dmNup;
        };
        DWORD dmDisplayFrequency;
        DWORD dmICMMethod;
        DWORD dmICMIntent;
        DWORD dmMediaType;
        DWORD dmDitherType;
        DWORD dmReserved1;
        DWORD dmReserved2;
        DWORD dmPanningWidth;
        DWORD dmPanningHeight;
    } DEVMODEA, *PDEVMODEA, *NPDEVMODEA, *LPDEVMODEA;

    typedef struct _devicemodew
    {
        WCHAR dmDeviceName[CCHDEVICENAME];
        WORD dmSpecVersion;
        WORD dmDriverVersion;
        WORD dmSize;
        WORD dmDriverExtra;
        DWORD dmFields;
        union {
            struct
            {
                short dmOrientation;
                short dmPaperSize;
                short dmPaperLength;
                short dmPaperWidth;
                short dmScale;
                short dmCopies;
                short dmDefaultSource;
                short dmPrintQuality;
            };
            struct
            {
                POINTL dmPosition;
                DWORD dmDisplayOrientation;
                DWORD dmDisplayFixedOutput;
            };
        };
        short dmColor;
        short dmDuplex;
        short dmYResolution;
        short dmTTOption;
        short dmCollate;
        WCHAR dmFormName[CCHFORMNAME];
        WORD dmLogPixels;
        DWORD dmBitsPerPel;
        DWORD dmPelsWidth;
        DWORD dmPelsHeight;
        union {
            DWORD dmDisplayFlags;
            DWORD dmNup;
        };
        DWORD dmDisplayFrequency;
        DWORD dmICMMethod;
        DWORD dmICMIntent;
        DWORD dmMediaType;
        DWORD dmDitherType;
        DWORD dmReserved1;
        DWORD dmReserved2;
        DWORD dmPanningWidth;
        DWORD dmPanningHeight;
    } DEVMODEW, *PDEVMODEW, *NPDEVMODEW, *LPDEVMODEW;

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //_MULTIMON_H_