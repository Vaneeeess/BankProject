#include <stdio.h>
#include "bank.h"
#include <string.h>
#include <stdlib.h>
#include <windows.h>
void SetColor(int ForgC) {
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

void ClearConsoleToColors(int ForgC, int BackC) {
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {0, 0};
    DWORD count;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    SetConsoleTextAttribute(hStdOut, wColor);
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
        FillConsoleOutputCharacter(hStdOut, (TCHAR) ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
        SetConsoleCursorPosition(hStdOut, coord);
    }
}


void SetColorAndBackground(int ForgC, int BackC) {
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int new_acc(Bank bank[], int *count, Bank newNumber) {
	
	for(int i = 0; i < *count; i++) {
		if(bank[i].banknumber == newNumber.banknumber) {
			printf("Bank number must be unique.\n");
			return -1;
		}
	}
	bank[*count] = newNumber;
	(*count)++;
	printf("New Acc has been successfully added.\n");
	return 1;
}

int view_list(Bank bank[], int count, char name[]) {
	
	char choice;
	for(int i = 0; i < count; i++) {
		if(strcmp(bank[i].name, name) == 0) {
			printf("The name is found in the list!\n");
			printf("Do you want to display her/his credentials? (Y/N): ");
			scanf(" %c", &choice);
			if(choice == 'y' || choice == 'Y') {
				for(int i = 0; i < count; i++) {
					printf("Name: %s\n", bank[i].name);
					printf("Account Number: %d\n", bank[i].banknumber);
					printf("Address: %s\n", bank[i].address);
					printf("Phone Number: %d", bank[i].phonenum);
				}
			} else {
				return -1;
			}
		}
	}
	return -1;
}

int edit(Bank bank[], int *count, Bank editacc) {
	
	char choice;
	for(int i = 0; i < *count; i++) {
		if(bank[i].banknumber == editacc.banknumber) {
			printf("Account is found!\n");
			printf("Do you want to edit this acc? (Y/N): ");
			scanf(" %c", &choice);
			if(choice == 'y' || choice == 'Y') {
				bank[i] = editacc;
				printf("The Account has been successfully edited.\n");
				return 1;
			}else {
				return -1;
			}
		} else {
			printf("This Account is not on the list!\n");
		}
	}
	return 1;
}

int transact(Bank bank[], int count, int banknum, float withdraw, float deposit) {
	
	char choice;
	for(int i = 0; i < count; i++) {
		if(bank[i].banknumber == banknum) {
			printf("This Account is on the list\n");
			printf("What do you wish to do this Account? Type 'W' for withdraw or 'D' for deposit: ");
			scanf(" %c", &choice);
			if(choice == 'w' || choice == 'W') {
				printf("Enter amount to withdraw: ");
				scanf("%f", &withdraw);
				bank[i].balance -=withdraw;
				printf("The transaction has successfully done!\n");
			} else {
				printf("Enter amount to deposit: ");
				scanf("%f", &deposit);
				bank[i].balance +=deposit;
				printf("The transaction has successfully done!\n");
			}
		 }
	}
	
	return -1;
}

void eraseacc(Bank bank[], int *count, int banknum) {
	
	char choice;
	int index = -1;
	for(int i = 0; i < *count; i++) {
		if(bank[i].banknumber == banknum) {
			index = i;
			break;
		}
	}
	if(index != -1) {
		printf("This Account is on the list!\n");
		printf("Do you want to delete this Account (Y/N): ");
		scanf(" %c", &choice);
		if(choice == 'y' || choice == 'Y') {
			for(int i = index; i < *count - 1; i++) {
				bank[i] = bank[i + 1];
			}
			(*count)--;
			printf("The account has been delete successfully!\n");
		} else {
			printf("You no then bye!\n");
		}
	}else {
		printf("This account is not on the list!\n");
	}
}

void see(Bank bank[], int *count, char name[]) {
	
	for(int i = 0; i < *count; i++) {
		if(strcmp(bank[i].name, name) == 0) {
			printf("Account Number: %d\n", bank[i].banknumber);
			printf("Name: %s\n", bank[i].name);
			printf("Date of Birth: %d\n", bank[i].dateofbirth);
			printf("Citizenship Number: %d\n", bank[i].citizenship);
			printf("Age: %d\n", bank[i].age);
			printf("Address: %s\n", bank[i].address);
			printf("Phone Number: %d\n", bank[i].phonenum);
			printf("Balance: %.2f\n", bank[i].balance);
		} else {
			printf("This account is not on the list!\n");
		}
	}
}




