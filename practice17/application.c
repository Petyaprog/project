#include <Windows.h>

#define bt2_id 2
#define bt3_id 3
#define bt4_id 4
#define bt5_id 5

HWND bt_quit;

LRESULT CALLBACK MainWinProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int ss){

    WNDCLASS wc = {};
    wc.lpfnWndProc = MainWinProc;
    wc.lpszClassName = "MyWindowClass";
    RegisterClass(&wc);

    HWND hwnd = CreateWindow("MyWindowClass", "My Window", WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, NULL, NULL);

    ShowWindow(hwnd, SW_SHOWNORMAL);

    bt_quit = CreateWindow("button", "Quit", WS_CHILD | WS_VISIBLE,
                           10, 10, 100, 70, hwnd, NULL, NULL, NULL);

    HWND bt2 = CreateWindow("button", "My button", WS_CHILD | WS_VISIBLE,
                           120, 10, 100, 70, hwnd, bt2_id, NULL, NULL);

    HWND bt3 = CreateWindow("button", "Modal", WS_CHILD | WS_VISIBLE,
                            230, 10, 100, 70, hwnd, bt3_id, NULL, NULL);

    HWND bt4 = CreateWindow("button", "Не Modal", WS_CHILD | WS_VISIBLE,
                            340, 10, 100, 70, hwnd, bt4_id, NULL, NULL);

    HWND bt5 = CreateWindow("button", "Несколько окон", WS_CHILD | WS_VISIBLE,
                            450, 10, 120, 70, hwnd, bt5_id, NULL, NULL);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

LRESULT CALLBACK MainWinProc(HWND hw, UINT message, WPARAM wp, LPARAM lp){

    if (message == WM_DESTROY)
        PostQuitMessage(0);

    else if (message == WM_COMMAND)
    {
        if (bt_quit == lp)
            PostQuitMessage(0);

        if (LOWORD(wp) == bt2_id)
            ShowWindow(hw, SW_MINIMIZE);

        if (LOWORD(wp) == bt3_id)
            MessageBox(NULL, "HOHIO", "NLNKO", MB_OK);

        if (LOWORD(wp) == bt4_id)
            MessageBox(hw, "КД ЧД", "Прив", MB_OK);

        if (LOWORD(wp) == bt5_id)
        {
            MessageBox(NULL, "Первое окно", "Поставьте 5", MB_OK);
            MessageBox(NULL, "Второе окно", "У вас выбора нет", MB_OK);
        }
    }
    else return DefWindowProc(hw, message, wp, lp);
}