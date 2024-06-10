/*
Задано непустий текст довжиною до 255 символів. Виконати над
кожним словом тексту наступні дії. З кожної пари поруч розташованих
однакових символів слова вилучити один з них таким чином, щоб в
результаті слово не містило жодної пари підряд розміщених однакових
символів.
*/
#include <stdio.h>
#include<stdlib.h>
#include <windows.h> // HANDLE, Gotoxy, SetColor
#include <conio.h>   //_getch
#include <string.h>
#define BUFF 255
#define count 3
#define k1 0
HANDLE hConsole;    //HANDLE hStdout
HANDLE hStdOut;

void SetColor(int text);
void GotoXY(int X, int Y);
void Frame(int x1, int y1, int x2, int y2);
void Screensaver();
void TextEditor(char text[BUFF]);
int horiz_menu(int k2, int kp);
void TaskSolving();
void FrameExtension(char* text);
void Menu_main();

int main() {
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Screensaver();
	Menu_main();
	return 0;
}

void TaskSolving() {
	
	Frame(5, 5, 80, 20);
	Frame(27, 7, 57, 9);
	GotoXY(32, 8);
	
	printf("Type your text please:\n");
	GotoXY(6, 6); printf("[And press Enter to save the text]");//45,19
	GotoXY(20, 12);
	int capacity = 10; // Initial array capacity
	int size = 0; // Current number of characters
	char* text = (char*)malloc(capacity * sizeof(char));
	while (1) {//This cycle is take opportunity to fill the array and define a size dinamicly
		if (size + 1 >= capacity) {
			capacity *= 2; // Capacity x2
			char* temp = (char*)realloc(text, capacity * sizeof(char));
			text = temp;
		}

		fgets(text + size, capacity - size, stdin); // Text reading

		// Ищем символ '@' для завершения ввода
		if (strchr(text + size, '\n') != NULL) {
			break;
		}
		size = strlen(text); // Update a symbol's count
	}
	text[BUFF] = '\0'; // End of the text after 254 symbol

	TextEditor(&text[0]);

	system("cls");
	Frame(5, 5, 80, 20);
	Frame(27, 7, 57, 9);
	GotoXY(37, 8);
	printf("Edited text:");
	GotoXY(6, 6); printf("[Press any key to exit]");	GotoXY(20, 12);

	FrameExtension(&text[0]);
	_getch();
}

void FrameExtension(char* text) {
	int counter = 0;
	float temp, ycord;
	for (int i = 0; text[i] != '\0'; i++) {
		printf("%c", text[i]);
		if ((temp = wherex()) == 65) {
			ycord = wherey();
			GotoXY(5, 20 + counter); printf("\272");//'║'
			for (int k = 6; k < 80; k++) {
				printf(" ");
			}
			printf("\272");//'║'

			GotoXY(5, 21 + counter); printf("\310"); // '╚'

			for (temp = 6; temp <= 79; temp++)
				printf("\315");// '═'
			printf("\274");// '╝'

			counter++;
			GotoXY(20, ycord + 1);
		}

	}
}

void SetColor(int text) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, text);
}

int wherex() {
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	return info.dwCursorPosition.X;
}

int wherey() {
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	return info.dwCursorPosition.Y;
}

int horiz_menu(int k2, int kp) {
	typedef char punkt[30];
	punkt m[count] = { "Info about author", "Task solving", "Exit" };

	int i, t, r, result;  
	char ch; int Flag=1; 
	int pp[count]; 
	t = strlen(m[0]);  r = 0;
	for (i = 0; i < kp; i++)  r += strlen(m[i]);
	r = ((80 - r) / kp) - 1;
	Frame(6, k2 - 1, 79, k2 + 1);
	GotoXY(28, 15);
	printf("Choose with q and press ENTER");
	GotoXY((r / 2 + 1), k2);
	for (i = 0; i < kp; i++) {
		if (i == 0) { SetColor(7); }
		else { SetColor(1); }
		GotoXY(wherex() + 8,wherey());
		pp[i] = wherex();
		printf("%s",m[i]);
		if (i == kp) r = 3;
	}
	i = 0;  
	while (Flag == 1) {
		ch = _getch();
			switch (ch) {
			case 'q': {
				GotoXY(k1 + pp[i], k2);
				SetColor(1);
				printf("%s", m[i]);
				i++;
				if (i == kp) {
					i = 0;
					SetColor(1);
					GotoXY(k1 + pp[0], k2);
					SetColor(7);
					printf("%s", m[i]);
					SetColor(1);
				}
				GotoXY(k1 + pp[i], k2);
				SetColor(7);
				printf("%s", m[i]);
				SetColor(1); break;  
			};//case 'q'
			case 13: {
				Flag = 0;
				result = i;
			}//case '13-enter'
			 
			};// switch
	}// while
	return result;
} //goriz_menu()

void Frame(int x1, int y1, int x2, int y2) { 
	int i;
	GotoXY(x1, y1); printf("\311");//'╔'
	for (i = (x1 + 1); i <= (x2 - 1); i++) printf("\315");// '═'
	printf("\273");//'╗'
	for (i = (y1 + 1); i <= (y2 - 1); i++) {
		GotoXY(x1, i); printf("\272");//'║'
		GotoXY(x2, i); printf("\272");//'║'
	}
	GotoXY(x1, y2); printf("\310");// '╚'

	for (i = (x1 + 1); i <= (x2 - 1); i++)
		printf("\315");// '═'
	printf("\274");// '╝'
	return;
} //Frame()

void Screensaver() {
	system("cls"); Frame(5, 5, 80, 22);
	GotoXY(27, 8);  printf("Work #6 created by Denis Fesenko");
	GotoXY(32, 10); printf("Student of group: KV-34");
	GotoXY(39, 12); printf("Variant 23");
	GotoXY(7, 14); printf("A non-empty text with a length of up to 255 characters is specified."); 
	GotoXY(7, 15);printf("   Execute over with each word of the text the following actions.");
	GotoXY(7, 16); printf("From each pair of adjacent ones of the same word symbols, remove one of");
	GotoXY(7, 17); printf(" them in such a way that in as a result, the word did not contain any");
	GotoXY(7, 18); printf("           pairs of the same ones placed in a row symbols.");
	GotoXY(40, 20); printf("Kyiv 2023");
	GotoXY(65, 21); printf("[Press any key]");	
	_getch(); system("cls");//<-clear screen
	return;
} // Screensaver()

void Menu_main() {
	short regime;
	while (1) {
		system("cls");
		Frame(5, 5, 80, 20);
		GotoXY(37, 6); printf("MAIN MENU");
		regime = horiz_menu(18, count);
		switch (regime) {
		case 0: {
			Screensaver();
			break; }
		case 1: {system("cls");
			TaskSolving();
			break; }
		case 2: {
			system("cls");
			return 0; }
		} //switch
	} //while
}

void GotoXY(int X, int Y) {
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);  //функція переміщення курсора по Х і У
}

void TextEditor(char text[BUFF]) {
	int p = -1, i = 1;
	for (; text[i] != '\0';) {
		if (p == -1) {
			if (text[i] == text[i - 1])	p++;
			else {
				i++;
				continue;
			}
			text[i - p - 1] = text[i];
			i++;
		}
		else {
			if (text[i] == text[i - 1])p++;
			text[i - p - 1] = text[i];
			i++;
		}
	}
	text[i - p - 1] = '\0';//end of our text
}