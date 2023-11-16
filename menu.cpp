#include "menu.h"
#include "DoHoa.h"
#define Button1 GetAsyncKeyState(0x31) & 0x8001
#define Button2 GetAsyncKeyState(0x32) & 0x8001
#define Button3 GetAsyncKeyState(0x33) & 0x8001
#define Button4 GetAsyncKeyState(0x34) & 0x8001

big_small a;
devided b;
guess_number c;

void gotoMenu() {
	gotoxy(35,23);
	std::cout << " Ấn phím bất kỳ để thoát ra menu game ! ";
}

void warning() {
	textcolor(7);
	gotoxy(30,25);
	std::cout << "Chơi game quá 180 phút mỗi ngày sẽ ảnh hưởng đến sức khỏe. ";
}

void menu() {
	resizeConsole(1920,1080);
	createBorder(); // x: 10 - 110 ; y: 2 - 27

	gotoxy(45,3);
	textcolor(12);
	std::cout << "GAME VE NHUNG CON SO MAY MAN !";
	
	gotoxy(45,5);
	textcolor(12);
	std::cout << "-----NUMBER GAME MACHINE-----";

	textcolor(10);
	gotoxy(15,8);
	std::cout << "Phím 1:   Game Lớn Nhỏ (Không phải \"Tài Xỉu\")";

	textcolor(11);
	gotoxy(15,11);
	std::cout << "Phím 2:   Game số chia may mắn ! (Bản quyền của nhóm)";
	
	textcolor(5);
	gotoxy(15,14);
	std::cout << "Phím 3:   Game đoán số (Liều ăn nhiều điểm)";
	
	textcolor(4);
	gotoxy(15,17);
	std::cout << "Phím 4:   Thoát Game (Good Bye !)";
	
	textcolor(3);
	gotoxy(15,20);
	std::cout << "Phím 5:   Hướng dẫn ";
	warning();
}

void guide() {
	gotoxy(20,6);
	std::cout << "Game Lớn Nhỏ: Luật chơi giống Tài Xỉu !" << std::endl;
	gotoxy(20,8);
	std::cout << "Game số chia may mắn: Chọn con số bên dưới, nếu con số ngẫu nhiên của máy ";
	gotoxy(20,9);
	std::cout << "tạo ra chia hết cho số bạn vừa chọn thì bạn thắng. Tuy nhiên, số chỉ được ";
	gotoxy(20,10);
	std::cout << "phép chia hết cho 1 số, nếu số đó chia hết cho 1 trong các số còn lại thì ";
	gotoxy(20,11);
	std::cout << "bạn vẫn thua nhé !" << std::endl;
	gotoxy(20,13);
	std::cout << "Game đoán số: dễ khỏi giải thích, chơi là hiểu à " << std::endl;
}

void returnMenu() {
	_getch();
	clearScreen();
	play();
}

void play() {
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD cNumRead;
    INPUT_RECORD irInBuf[128];
	menu();
    while(true) {
        if (GetNumberOfConsoleInputEvents(hInput, &cNumRead) > 0) {
            ReadConsoleInputA(hInput, irInBuf, cNumRead, &cNumRead);

            for (DWORD i = 0; i < cNumRead; ++i) {
                if (irInBuf[i].EventType == KEY_EVENT && irInBuf[i].Event.KeyEvent.bKeyDown) {
                    switch (irInBuf[i].Event.KeyEvent.wVirtualKeyCode) {
                        case 0x31:  // Phím 1
							clearScreen();
							warning();
                            a.control();
							returnMenu();
                            break;
                        case 0x32:  // Phím 2
							clearScreen();
							warning();
                            b.control();
							returnMenu();
                            break;
                        case 0x33:  // Phím 3
							clearScreen();
							warning();
                            c.control();
							returnMenu();
                            break;
                        case 0x34:  // Phím 4 (Thoát)
                            exit(0);
						case 0x35: // phim5
							clearScreen();
							warning();
							guide();
							returnMenu();
							gotoMenu();
							break;
                        default:
                            break;
                    }
                }
            }
        }
    }
}

