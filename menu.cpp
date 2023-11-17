#include "menu.h"
#include "DoHoa.h"

big_small a;
devided b;
guess_number c;

void gotoMenu() {
	gotoxy(35,23);
	if(language == 1)
		std::cout << " Ấn phím bất kỳ để thoát ra menu game ! ";
	else std::cout << "Press any key to back main menu ! ";
}

void warning() {
	textcolor(7);
	if(language == 1) {
		gotoxy(30,25);
		std::cout << "Chơi game quá 180 phút mỗi ngày sẽ ảnh hưởng đến sức khỏe. ";
	}
	else {
		gotoxy(25,25);
		std::cout << "Playing games for more than 180 minutes per day can adversely affect health.";
	} 
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
	if(language == 1)
		std::cout << "Phím 1:   Game Lớn Nhỏ (Không phải \"Tài Xỉu\")";
	else std::cout << "Key 1:    Sic Bo ";

	textcolor(11);
	gotoxy(15,11);
	if(language == 1)
		std::cout << "Phím 2:   Game số chia may mắn ! (Bản quyền của nhóm)";
	else std::cout << "Key 2:    Lucky divisor "; 
	
	textcolor(5);
	gotoxy(15,14);
	if(language == 1)
		std::cout << "Phím 3:   Game đoán số (Liều ăn nhiều điểm)";
	else std::cout << "Key 3:    Guess the number ";
	
	textcolor(4);
	gotoxy(15,17);
	if(language == 1)
		std::cout << "Phím 4:   Thoát Game (Good Bye !)";
	else std::cout << "Key 4:    Exit game ";
	
	
	textcolor(3);
	gotoxy(15,20);
	if(language == 1)
		std::cout << "Phím 5:   Hướng dẫn ";
	else std::cout << "Key 5:    Guide ";
	warning();
}

void guide() {
	gotoxy(20,6);
	if(language == 1)
		std::cout << "Game Lớn Nhỏ: Luật chơi giống Tài Xỉu !" << std::endl;
	else std::cout << "You chose Big and result >= 11, you win. Opposite...";
	gotoxy(20,8);
	if(language == 1)
		std::cout << "Game số chia may mắn: Chọn con số bên dưới, nếu con số ngẫu nhiên của máy ";
	else std::cout << "Lucky division game: Choose the number below, if the random number generated ";
	gotoxy(20,9);
	if(language == 1)
		std::cout << "tạo ra chia hết cho số bạn vừa chọn thì bạn thắng. Tuy nhiên, số chỉ được ";
	else std::cout << "by the machine is divisible by the number you just selected, you win. However,";
	gotoxy(20,10);
	if(language == 1)
		std::cout << "phép chia hết cho 1 số, nếu số đó chia hết cho 1 trong các số còn lại thì ";
	else std::cout << "a number can only be divisible by 1 number, if that number is divisible by one";
	gotoxy(20,11);
	if(language == 1)
		std::cout << "bạn vẫn thua nhé !" << std::endl;
	else std::cout << "of the remaining numbers, you still lose!" << std::endl;
	gotoxy(20,13);
	if(language == 1)
		std::cout << "Game đoán số: dễ khỏi giải thích, chơi là hiểu à " << std::endl;
	else std::cout << "Guess the number: Too easy to know how to play !" << std::endl;
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
							createBorder();
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

