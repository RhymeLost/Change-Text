#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void znumbers(char*, char*, int*);
void zsymbols(char*, char*, int*);
void zkiril(char*, char*, int*);
void zlatin(char*, char*, int*);
void fsymbols(const char*, char*, char*, int*);
void fnumbers(const char*, char*, char*, int*);
void fkiril(const char*, char*, char*, int*);
void flatin(const char*, char*, char*,int*);
void vivod(char*);
void vvod(char*);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const char latin[27] = { "abcdefghijklmnopqrstuvwxyz" };
	const char kiril[34] = { "אבגדהו¸זחטיךכלםמןנסעףפץצקרשüûת‎‏ÿ" };
	const char numbers[11] = { "0123456789" };
	const char symbols[8] = { '.', ',', '!', '?', ';', ':', '-' };
	char text[55], delsymbols[55], delnumbers[55], delkiril[55], dellatin[55];
	int ZL=0, ZK=0, ZN=0, ZS=0;
	int ch;
	cout << "Hello!";
	while (1) {
		cout << "\nPut an action:";
		cout << "\n1 - Add new text";
		cout << "\n2 - Delete/return latins";
		cout << "\n3 - Delete/return kiril";
		cout << "\n4 - Delete/return symbols";
		cout << "\n5 - Delete/return numbers\n";
		cin >> ch;
		cin.ignore();
		switch (ch) {
		case 1:
			vvod(text);
		break;
		case 2:
			if (!ZL) {
				flatin(latin, text, dellatin, &ZL);
				vivod(text);
		}
			else{
				zlatin(text, dellatin, &ZL);
				vivod(text);
			}
			break;
		case 3:
			if (!ZK) {
				fkiril(kiril, text, delkiril, &ZK);
				vivod(text);
			}
			else {
				zkiril(text, delkiril, &ZK);
				vivod(text);
			}
			break;
		case 4:
			if (!ZS) {
				fsymbols(symbols, text, delsymbols, &ZS);
				vivod(text);
			}
			else {
				zsymbols(text, delsymbols, &ZS);
				vivod(text);
			}
			break;
		case 5:
			if (!ZN) {
				fnumbers(numbers, text, delnumbers, &ZN);
				vivod(text);
			}
			else {
				znumbers(text, delnumbers, &ZN);
				vivod(text);
			}
			break;
		default:
			cout << "\nWrong number!";
			break;
		}
	}
	return 0;
}

void vivod(char* mas) {
	cout << "\nYour text: " << mas<<endl<<endl;
}
void vvod(char* mas) {
	for (int i = 0; i < 55; i++) {
		*(mas + i) = ' ';
	}
	cout << "\nPlease, put the text (max 54):\n";
	cin.getline(mas, 55);
}
void flatin(const char* latin, char* mas,char* del,int *ZL) {
	for (int i = 0; i < strlen(mas); i++) {
		*(del + i) = ' ';
		for (int j = 0; j < 27; j++) {
			if (*(latin + j) == *(mas + i)) {
				*(del + i) = *(mas + i);
				*(mas + i) = ' ';
				
			}
		}
	}
	for (int i = strlen(mas); i<55; i++) {
		*(del + i) = ' ';
	}
	*ZL = 1;
}
void fkiril(const char* kiril, char* mas, char* del, int* ZK) {
	for (int i = 0; i < strlen(mas); i++) {
		*(del + i) = ' ';
		for (int j = 0; j < 34; j++) {
			if (*(kiril + j) == *(mas + i)) {
				*(del + i) = *(mas + i);
				*(mas + i) = ' ';
			}
		}
	}
	for (int i = strlen(mas); i < 55; i++) {
		*(del + i) = ' ';
	}
	*ZK = 1;
}
void fnumbers(const char* numbers, char* mas, char* del, int* ZN) {
	for (int i = 0; i < strlen(mas); i++) {
		*(del + i) = ' ';
		for (int j = 0; j < 11; j++) {
			if (*(numbers + j) == *(mas + i)) {
				*(del + i) = *(mas + i);
				*(mas + i) = ' ';
			}
		}
	}
	for (int i = strlen(mas); i < 55; i++) {
		*(del + i) = ' ';
	}
	*ZN = 1;
}
void fsymbols(const char* symbols, char* mas, char* del, int* ZS) {
	for (int i = 0; i < strlen(mas); i++) {
		*(del + i) = ' ';
		for (int j = 0; j < 8; j++) {
			if (*(symbols + j) == *(mas + i)) {
				*(del + i) = *(mas + i);
				*(mas + i) = ' ';
			}
		}
	}
	for (int i = strlen(mas); i < 55; i++) {
		*(del + i) = ' ';
	}
	*ZS = 1;
}
void zlatin(char* mas, char* del, int* ZL) {
	for (int i = 0; i < strlen(mas); i++) {
		if (*(del + i) != ' ') {
			*(mas + i) = *(del + i);
		}
	}
	for (int i = 0; i < 55; i++) {
		*(del + i) = ' ';
	}

	*ZL = 0;
}
void zkiril(char* mas, char* del, int* ZK) {
	for (int i = 0; i < strlen(mas); i++) {
		if (*(del + i) != ' ') {
			*(mas + i) = *(del + i);
		}
	}
	for (int i = 0; i < 55; i++) {
		*(del + i) = ' ';
	}

	*ZK = 0;
}
void zsymbols(char* mas, char* del, int* ZS) {
	for (int i = 0; i < strlen(mas); i++) {
		if (*(del + i) != ' ') {
			*(mas + i) = *(del + i);
		}
	}
	for (int i = 0; i < 55; i++) {
		*(del + i) = ' ';
	}

	*ZS = 0;
}
void znumbers(char* mas, char* del, int* ZN) {
	for (int i = 0; i < strlen(mas); i++) {
		if (*(del + i) != ' ') {
			*(mas + i) = *(del + i);
		}
	}
	for (int i = 0; i < 55; i++) {
		*(del + i) = ' ';
	}

	*ZN = 0;
}