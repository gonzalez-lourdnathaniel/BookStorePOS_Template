#include <iostream>
#include <windows.h>

#include "SecuritySys.h"
#include "AppUI.h"
#include "EditBook.h"
#include "OrderSys.h"

AppUI UI;
SecuritySys SecSysFunc;
EditBook BookFunc;
OrderSys OrderFunc;

using namespace std;

HWND WINAPI GetConsoleWindowNT(void)
{
    //declare function pointer type
    typedef HWND WINAPI(*GetConsoleWindowT)(void);
    //declare one such function pointer
    GetConsoleWindowT GetConsoleWindow;

    //get a handle on kernel32.dll
    HMODULE hk32Lib = GetModuleHandle(TEXT("KERNEL32.DLL"));
    //assign proceedure address to function pointer
    GetConsoleWindow = (GetConsoleWindowT)GetProcAddress(hk32Lib,TEXT("GetConsoleWindow"));

    //check if the function pointer is valid
    //since the function pointer is undocumented
    if(GetConsoleWindow == NULL)
    {
        return NULL;
    }
    //call the undocumented function
    return GetConsoleWindow();
}

int main()
{
    //this is the main file/class
    //all methods and features will be call here
    //Assigned to: Bryan Calulo

    // Set console window height & width
    const int width = 1280;
    const int height = 720;

    HWND hWnd=GetConsoleWindowNT();
    //resize window and center to screen
    MoveWindow(hWnd, GetSystemMetrics(SM_CXSCREEN)/2 - width/2, GetSystemMetrics(SM_CYSCREEN)/2 - height/2, width, height, SWP_SHOWWINDOW);

    SetConsoleTitle("CICT Book Store");

    SecSysFunc.Login();
}
