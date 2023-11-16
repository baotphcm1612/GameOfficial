#ifndef DoHoa_H
#define DoHoa_H
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

// Hàm thay đổi kích cỡ của khung cmd với tham số truyền vào là chiều cao, chiều rộng.
inline void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Hàm tô màu.
inline void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

// Hàm dịch chuyển con trỏ đến tọa độ x, y.
inline void gotoxy(int x, int y) {
	
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = { static_cast<SHORT>(x - 1), static_cast<SHORT>(y - 1) };
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

//Hàm xóa màn hình
inline void clearScreen() {
    COORD topLeft = {0, 0};
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    SetConsoleCursorPosition(console, topLeft);
}

inline void ToMau(int x, int y, char *a, int color) // x, y là tọa độ con trỏ cần nhảy đến để viết, a là chuỗi cần truyền vào, color là màu truyền vào.
{
	gotoxy(x, y);
	textcolor(color);
	cout << a;
}

// Ở trên là copy ở dưới team tự viết
// Hàm vẽ khung
inline void createBorder() {
    for(int x = 10; x <= 110;x++) {
        gotoxy(x,1);
        std::cout << "�";
        gotoxy(x,27);
        std::cout << "�";
    }
    for(int y = 2;y <= 26 ;y++) {
        gotoxy(10,y);
        std::cout << "�";
        gotoxy(110,y);
        std::cout << "�";
    }
}
//Hàm xóa
inline void clearCharacter(int x,int y) {
    gotoxy(x,y);
    std::cout << " ";
}
//Hàm xóa nhiều
inline void clearCharacter(int x,int x_end, int y) {
    for(int i = x; i <= x_end;i++) {
        gotoxy(i,y);
        std::cout << " ";
    }
}
#endif