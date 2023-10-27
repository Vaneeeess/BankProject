#ifndef Bank_H
#define Bank_H


typedef struct {
	
	char name[50];
	int dateofbirth;
	char citizenship[50];
	char address[50];
	int phonenum;
	int banknumber;
	float balance;
	int age;
} Bank;

int new_acc(Bank bank[], int *count, Bank newNumber);
int view_list(Bank bank[], int count, char name[]);
int edit(Bank bank[], int *count, Bank editacc);
int transact(Bank bank[], int count, int banknum, float withdraw, float deposit);
void eraseacc(Bank bank[], int *count, int banknum);
void see(Bank bank[], int *count, char name[]);
#endif
