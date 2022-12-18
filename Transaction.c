#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned long amount = 1000, deposit, withdraw;
int choice,
    pin, k;
char transaction = 'y';

bool Authenticate(int pin)
{
    if (pin == 1520)
    {
        printf("PIN NUMBER ACCEPTED \n");
        return true;
    }
    else
    {
        printf("INVALID PIN NUMBER \n");
        return false;
    }
}

bool Deposit()
{
    printf("\nENTER THE AMOUNT TO DEPOSIT: ");
    scanf("%lu", &deposit);
    if (!deposit)
    {
        printf("\nINVALID AMOUNT");
        return false;
    }
    else
    {
        amount = amount + deposit;
        printf("\nYOUR BALANCE IS %lu", amount);
        return true;
    }
}

bool Withdraw()
{
    printf("\nENTER THE AMOUNT TO WITHDRAW: ");
    scanf("%lu", &withdraw);
    if (!withdraw)
    {
        printf("\nINVALID AMOUNT");
        return false;
    }
    else if (withdraw % 100 != 0)
    {
        printf("\nPLEASE ENTER THE AMOUNT IN MULTIPLES OF 100");
        return false;
    }
    else if (withdraw > (amount - 500))
    {
        printf("\nINSUFFICENT BALANCE");
        return false;
    }
    else
    {
        amount = amount - withdraw;
        printf("\nPLEASE COLLECT CASH");
        printf("\nYOUR CURRENT BALANCE IS %lu", amount);
        return true;
    }
}

int Welcome()
{
    printf("\n********Welcome to ATM Service**************\n");
    printf("1. Check Balance\n");
    printf("2. Withdraw Cash\n");
    printf("3. Deposit Cash\n");
    printf("4. Quit\n");
    printf("********************************************\n\n");
    scanf("%d", &choice);
    return choice;
}

void ThankYou()
{
    printf("\n\nTHANKS FOR USING OUR ATM SERVICE");
    printf("\n\nREGARDS DBI");
    fflush(stdin);
    exit(0);
}

void main()
{
    if (system("CLS"))
        system("clear");

    do
    {
        printf("ENTER YOUR SECRET PIN NUMBER: ");
        scanf("%d", &pin);
    } while (Authenticate(pin) == false);

    do
    {
        switch (Welcome())
        {
        case 1:
            printf("\nYOUR BALANCE IN Rs: %lu ", amount);
            break;
        case 2:
            while (!Withdraw())
                printf("\nPLEASE TRY AGAIN");
            break;
        case 3:
            while (!Deposit())
                printf("\nPLEASE TRY AGAIN");
            break;
        case 4:
            printf("\nTHANK U USING ATM");
            ThankYou();
            break;
        default:
            printf("\nINVALID CHOICE");
            printf("\nPLEASE TRY AGAIN");
        }
    } while (true);
}