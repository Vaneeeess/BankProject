#include <stdio.h>
#include <stdlib.h>
#include "bank.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	Bank banks[100];
	int count = 0;
	float withdraws, deposits;
	printf("\t\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM\n");
	
	
	printf("\n\t\t\t\t//////////WELCOME TO THE MAIN MENU\\\\\\\\\\\\\\\n");
	
	int choice;
	do{
		
		printf("1. Create new account\n");
		printf("2. View customer's list\n");
		printf("3. Edit Account\n");
		printf("4. For transaction\n");
		printf("5. Removing existing account\n");
		printf("6. See details Account\n");
		printf("7. Exit the program\n");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		fflush(stdin);
		
		switch(choice) {
			case 1: {
				Bank newAcc;
				printf("Enter your name please: ");
				scanf(" %[^\n]", newAcc.name);
				printf("Enter your age please: ");
				scanf("%d", &newAcc.age);
				printf("Enter your address please: ");
				scanf(" %[^\n]", newAcc.address);
				printf("Enter your date of birth please just the year: ");
				scanf("%d", &newAcc.dateofbirth);
				printf("Enter your Phone Number please: ");
				scanf("%d", &newAcc.phonenum);
				printf("Enter your citizenship please: ");
				scanf(" %[^\n]", newAcc.citizenship);
				printf("Enter your balance: ");
				scanf("%f", &newAcc.balance);
				printf("Enter Account Number: ");
				scanf("%d", &newAcc.banknumber);
				new_acc(banks, &count, newAcc);
				break;
			}
			case 2: {
				char name[50];
				printf("Enter name you want to view on the list: ");
				scanf(" %[^\n]", name);
				view_list(banks, count, name);
				break;
			}
			case 3: {
				Bank editAccount;
				printf("Enter new name: ");
				scanf(" %[^\n]", editAccount.name);
				printf("Enter new age: ");
				scanf("%d", editAccount.age);
				printf("Enter new Address: ");
				scanf(" %[^\n]", editAccount.address);
				printf("Enter new birth of date: ");
				scanf("%d", &editAccount.dateofbirth);
				printf("Enter new phone number: ");
				scanf("%d", &editAccount.phonenum);
				printf("Enter new Citizenship: ");
				scanf(" %[^\n]", editAccount.citizenship);
				printf("Enter new balance: ");
				scanf("%f", &editAccount.balance);
				edit(banks, &count, editAccount);
				break;
			}
			case 4: {
				int banknums;
				printf("Enter banknumber: ");
				scanf("%d", &banknums);
				transact(banks, count, banknums, withdraws, deposits);
				break;
			}
			case 5: {
				int banknums;
				printf("Enter banknumber to delete: ");
				scanf("%d", &banknums);
				eraseacc(banks, &count, banknums);
				break;
			}
			case 6: {
				char name[50];
				printf("Enter name to see information: ");
				scanf(" %[^\n]", name);
				see(banks, &count, name);
				break;
			}
			case 7: {
				printf("Exiting Program...\n");
				break;
			}
			default:
				printf("Inavlid input!\n");
		}
		
	}while(choice != 7);
	return 0;
}
