#include <iostream>
#include <windows.h>
#include <conio.h>
int main()
{
    std::cout << "Anti Steal Test\n";
    HWND window;
    window = FindWindowA("ConsoleWindowClass", nullptr);
    ShowWindow(window, 0);
    while (true) {
        if (GetAsyncKeyState(VK_F8) & 0x8000) {
            exit(1);
        }
        SetCursorPos(500, 500);
        POINT cspos;
        if (GetCursorPos(&cspos)) {
            if (cspos.x == 500 and cspos.y == 500) {
                
            }
            else {
                MessageBox(NULL, TEXT("PLEASE GET AWAY FROM THE PC"), TEXT("ATTENTION"), MB_DEFBUTTON1);
                std::cout << "Detected Mouse Movement\n";
                Beep(5000, 2000);
            }
        }
        if (_kbhit()) {
            MessageBox(NULL, TEXT("PLEASE GET AWAY FROM THE PC"), TEXT("ATTENTION"), MB_DEFBUTTON1);
            printf("Detected Key Press, [%c]\n", _getch());
            Beep(5000, 2000);
        }
    }
}
