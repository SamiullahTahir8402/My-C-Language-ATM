#include<stdio.h>

#include<conio.h>

#include<stdlib.h>

#include<string.h>

#define Pin 8402

int Balance=50000;

int PIN();

int balance();

int cash();

int deposit();

int funds();

int ext();

int menu();

int main()

{

	printf("\n\t\t\t\t\t****Welcome to ST_09 ATM program****\n");

	PIN();

	menu();

	return 0;

}

int menu()

{

	int a;

	while(1)

	{

		system("cls");

		printf("\nPress 1 - Balance Inquiry");

		printf("\nPress 2 - Cash Withdrawal");

		printf("\nPress 3 - Cash Deposit");

		printf("\nPress 4 - Transfer Funds");

		printf("\nPress 5 - Exit");

		printf("\n-->-\b");

		scanf("%d",&a);

		system("cls");

		switch (a)

		{

			case 1:

				{

					balance();

					break;

				}

			case 2:

				{

					cash();

					break;

				}

			case 3:

				{

					deposit();

					break;

				}

			case 4:

				{

					funds();

					break;

				}

			case 5:

				{

					ext();

					break;

				}

			default:

				{

					printf("Invalid Input");

				}

		}

	return 0;

}

}

int PIN()

{

	int pin;

	for(int attempt=3;attempt>=0;attempt--)

	{

	if(attempt>0)

	{

		printf("\nEnter Your Pin : ");

		scanf("%d",&pin);

			if(pin==Pin)

			{

				printf("Attempt Successful");

				system("cls");

				break;

			}

			else

			{

				printf("\nIncorrect PIN...!!\nYou are Left with %d Attempts",attempt-1);

			}

	}

		if(attempt==0)

		{

			printf("\nYou have Entered Incorrect PIN 3 times.\nYour Card has been Captured.");

			printf("\nContact your bank for further assistance");

			exit(0);

		}

	}

	return 0;

}

int balance()

{

		printf("Your Balance= %d",Balance);

		printf("\nPress Any key to Continue:");

		getch();

		return menu();

}

int cash()

{

	int x,y;

	printf("\nEnter The Anount You Want to withdraw : ");

	scanf("%d",&x);

	if(x%500==0)

	{

		if(x>=0 && x<=20000)

		{

			y=Balance-x;	

			printf("\nYou are Left with %d Balance.",y);

			printf("\n\n\t\t\tTake your Cash.!!!");

			printf("\n\nPress Any Key to Continue.");

			getch();

			return menu();

		}	

	}

	if(x>50000)

		{

			printf("Insufficient Balance...!!!");

			printf("\nPress Any Key to Continue.");

			getch();

			return cash();

		}

	else

	{

		printf("Please Enter Valid Amount.\nAmount Entered must be in Denomination of \"500\"");

	}	

	

	return cash();

}

int deposit()

{

	int x,y;

	printf("\nEnter The Anount You Want to Deposit : ");

	scanf("%d",&x);

	if(x%500==0)

	{

		if(x>=0 && x<=10000)

		{

			y=Balance+x;

			printf("\nBalance Successfully Deposited.!!!");

			printf("\nYou\'r Balance is now %d.",y);

			printf("\n\nPress Any Key to Continue.");

			getch();

			return menu();

		}

	}

	if(x>10000)

		{

			printf("Max of 10,000 can be deposited in single Transaction...!!!");

			printf("\nPress Any Key to Continue.");

			getch();

			return deposit();

		}

}

int funds()

{

	int x,y;

	char Acc[11];

	printf("\nEnter The Account Number : ");

	scanf("%s",&Acc);

if(strlen(Acc)>0 && strlen(Acc)<11)

	{

	if(Acc[2]!='-' || Acc[6]!='-')

 	{

		printf("\nInvalid Account Number");

		return funds();

	}

	else

	{

		printf("Enter Amount to Transfer : ");

		scanf("%d",&x);

		if(x%100==0)

		{

			printf("\nCash Successfully transferred");

			y=Balance-x;

			printf("\nYour Remaining Balance is %d",y);

			printf("\nPress any Key to Continue.");

			getch();

			return menu();

		}

		else

		{

			

		}

			if(x>10000)

		{

			printf("Per Transaction Should not exceed 10,000...!!!");

			printf("\nPress Any Key to Continue.");

			getch();

			return funds();

		}	

	}

}

else

{

	printf("\nInvalid Account Number");

	return funds();

}

	return 0;

}

int ext()

{

	printf("Your Balance= %d",Balance);

	printf("\nGood Bye Sir..!!!\nThanks For Choosing ST_09 Bank");

	exit(0);

}

