#ifndef _CLASS_H_
#define _CLASS_H_

#define MAX_ATOM_LEN 255

typedef struct tagCLASS
{
    UINT style;           /* Class style */
    WNDPROC winproc;      /* Window procedure */
    INT cbClsExtra;       /* Class extra bytes */
    INT cbWndExtra;       /* Window extra bytes */
    UINT_PTR instance;    /* Module that created the task */
    HICON hIcon;          /* Default icon */
    HICON hIconSm;        /* Default small icon */
    HCURSOR hCursor;      /* Default cursor */
    HBRUSH hbrBackground; /* Default background */
    ATOM atomName;        /* Name of the class */
    char name[MAX_ATOM_LEN + 1];
    char *basename; /* Base name for redirected classes, pointer within 'name'. */
} CLASS;

typedef struct tagWNDCLASSEXA
{
    UINT cbSize;
    UINT style;
    WNDPROC lpfnWndProc;
    INT cbClsExtra;
    INT cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCSTR lpszMenuName;
    LPCSTR lpszClassName;
    HICON hIconSm;
} WNDCLASSEXA, *PWNDCLASSEXA, *LPWNDCLASSEXA;

typedef struct tagWNDCLASSEXW
{
    UINT cbSize;
    UINT style;
    WNDPROC lpfnWndProc;
    INT cbClsExtra;
    INT cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCWSTR lpszMenuName;
    LPCWSTR lpszClassName;
    HICON hIconSm;
} WNDCLASSEXW, *PWNDCLASSEXW, *LPWNDCLASSEXW;

typedef struct tagWNDCLASSA
{
    UINT style;
    WNDPROC lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCSTR lpszMenuName;
    LPCSTR lpszClassName;
} WNDCLASSA, *PWNDCLASSA, NEAR *NPWNDCLASSA, FAR *LPWNDCLASSA;
typedef struct tagWNDCLASSW
{
    UINT style;
    WNDPROC lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCWSTR lpszMenuName;
    LPCWSTR lpszClassName;
} WNDCLASSW, *PWNDCLASSW, NEAR *NPWNDCLASSW, FAR *LPWNDCLASSW;
#ifdef UNICODE
typedef WNDCLASSW WNDCLASS;
typedef PWNDCLASSW PWNDCLASS;
typedef NPWNDCLASSW NPWNDCLASS;
typedef LPWNDCLASSW LPWNDCLASS;
#else
typedef WNDCLASSA WNDCLASS;
typedef PWNDCLASSA PWNDCLASS;
typedef NPWNDCLASSA NPWNDCLASS;
typedef LPWNDCLASSA LPWNDCLASS;
#endif // UNICODE

ATOM WINAPI RegisterClassA(const WNDCLASSA *lpWndClass);
ATOM WINAPI RegisterClassW(const WNDCLASSW *lpWndClass);
ATOM WINAPI RegisterClassExA(const WNDCLASSEXA *wc);
ATOM WINAPI RegisterClassExW(const WNDCLASSEXW *wc);
BOOL WINAPI UnregisterClassA(LPCSTR className, HINSTANCE instance);
BOOL WINAPI UnregisterClassW(LPCWSTR className, HINSTANCE instance);

BOOL WINAPI GetClassInfoExA(HINSTANCE hInstance, LPCSTR name, WNDCLASSEXA *wc);
BOOL WINAPI GetClassInfoExW(HINSTANCE hInstance, LPCWSTR name, WNDCLASSEXW *wc);

UINT WINAPI GetAtomNameA(ATOM atomName, LPSTR name, int cchLen);
UINT WINAPI GetAtomNameW(ATOM atomName, LPWSTR name, int cchLen);

ATOM WINAPI FindAtomA(_In_opt_ LPCSTR lpString);
ATOM WINAPI FindAtomW(_In_opt_ LPCWSTR lpString);

#ifdef UNICODE
#define WNDCLASSEX      WNDCLASSEXW
#define RegisterClass   RegisterClassW
#define RegisterClassEx RegisterClassExW
#define UnregisterClass UnregisterClassW
#define GetClassInfoEx  GetClassInfoExW
#define GetAtomName     GetAtomNameW
#define FindAtom        FindAtomW
#else
#define WNDCLASSEX      WNDCLASSEXA
#define RegisterClass   RegisterClassA
#define RegisterClassEx RegisterClassExA
#define UnregisterClass UnregisterClassA
#define GetClassInfoEx  GetClassInfoExA
#define GetAtomName     GetAtomNameA
#define FindAtom        FindAtomA
#endif // UNICODE

#endif //_CLASS_H_