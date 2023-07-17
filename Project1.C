<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>    //header_files
#include <time.h>
#include <conio.h>

void menu();
void createAccount();
void withdraw();
void balCheck();       //declarationOfFunctionsUsed
void moneyTrans();
void lastDetails();
void deposit();
void yellow();
void red();
void green();
void white();
void divid();

int bal=0, accNo, with;     //global_variables
char name[35], fname[20], lname[20];
int dep;


int main() {            //main_function

    while(1) {

    char select;
    system("color Aa");
    red();

    printf("Do You have an account? (Y/N)\n" );
    scanf("%c",&select);
    system("cls");

    if(select=='N' || select=='n') {

        createAccount();

    }


    else if (select=='Y' || select=='y'){

        int input;
        int actNo;
        printf("Account Number : ");
        scanf("%d", &input);

        if(input == accNo) {

        label :
            system("cls");
            menu();
            printf("\nEnter The Activity No : ");
            scanf("%d", &actNo);

            switch (actNo)
            {

            case 1:
                system("cls");
                withdraw();
                printf("\n* * * * Press any key to continue * * * * ");
                getch();
                goto label;
                break;

            case 2:
                system("cls");
                deposit();
                printf("\n* * * * Press any key to continue * * * * ");
                getch();
                goto label;
                break;

            case 3:
                system("cls");
                balCheck();
                printf("\n* * * * Press any key to continue * * * * ");
                getch();
                goto label;
                break;

            case 4:
                system("cls");
                moneyTrans();
                printf("\n* * * * Press any key to continue * * * * ");
                getch();
                goto label;
                break;

            case 5:
                system("cls");

                FILE *pntr;

                pntr = fopen("Records.txt", "r");

                char myString[1000];

                while(fgets(myString, 1000, pntr)) {

                    printf("%s", myString);

                };

                fclose(pntr);
                printf("\n* * * * Press any key to continue * * * * ");
                getch();
                goto label;
                break;

            case 6:
                lastDetails();
                exit(0);

                break;

            default:
                printf("INVALID INPUT");
                printf("\n* * * * Press any key to continue * * * * ");
                getch();
                break;

              }
  }

        else if (input != accNo) {

                printf("You have to create a account first!");
                printf("\n* * * * Press any key to continue... * * * * ");
                getch();

  }
 }
 }

return 0;

}

void yellow () {
    printf("\033[1;33m");
}
void red () {
    printf("\033[1;31m");   //consoleTextFormatting_functions
}
void green () {
    printf("\033[1;32m");
}
void white () {
    printf("\033[1;37m");
}



void menu() {           //menu_function

    printf("\t\t* * * * WELCOME TO \"C\" BANK * * * * \n");
    divid();
    printf("\nActivities Menu\n");
    divid();
    printf("\n\t1. Withdraw\n");
    printf("\t2. Deposit\n");
    printf("\t3. Balance Check\n");
    printf("\t4. Transfer Money\n");
    printf("\t5. Transaction History\n");
    printf("\t6. Exit\n");

}

void withdraw() {       //withdraw_function

    time_t tm;
    time(&tm);

    FILE *pntr = fopen("Records.txt", "a");

    printf("* * * WITHDRAW MONEY * * *\n\n");

    printf("Enter The Amount You Want To Withdraw : ");
    scanf("%d", &with);

    if(bal<with) {

       printf("YOUR BALANCE IS INSUFFICIENT");
        fprintf(pntr, "Your balance is insufficient to withdraw %d LKR\n", with);
        fprintf(pntr, "DATE AND TIME OF THE TRANSACTION : %s\n", ctime(&tm));

    }

    else {

        bal -= with;

        printf("\nYOU WITHDRAWED %d LKR", with);
        printf("\nBALANCE OF THE ACCOUNT IS %d LKR\n", bal);

        fprintf(pntr, "\n%d has Withdrawn from this account %d\n", with, accNo);
        fprintf(pntr, "DATE AND TIME OF THE TRANSACTION : %s\n", ctime(&tm));

    }

    fclose(pntr);

}

void deposit() {            //deposit_function

    time_t tm;
    time(&tm);

    FILE *pntr = fopen("Records.txt", "a");

    printf("\n* * * DEPOSIT MONEY * * *\n\n");

    printf("Enter The Amount You Want To Deposit : ");
    scanf("%d", &dep);

    bal += dep;

    printf("\nYOUR MONEY HAS DEPOSITED SUCCESSFULLY!!!");

    printf("\nBALANCE OF THE ACCOUNT IS %d LKR\n", bal);

    fprintf(pntr, "\n%d LKR has deposited to this account %d\n", dep, accNo);
    fprintf(pntr, "DATE AND TIME OF THE TRANSACTION : %s\n", ctime(&tm));

    fclose(pntr);

}

void balCheck() {          //balance_function

printf("Your Balance : %d",bal);

}

void moneyTrans() {

        time_t tm;
        time(&tm);

        FILE *pntr=fopen("Records.txt", "a");

        int tAmount,tAcc;

        printf("Enter a Account Number You want to Transfer : ");
        scanf("%d",&tAcc);
label2:
        printf("Enter the Amount You want to Transfer : ");
        scanf("%d",&tAmount);

 if(bal<tAmount)
    {

        printf("YOUR BALANCE IS INSUFFICIENT\n\n");
        fprintf(pntr, "\nYour balance is insufficient to transfer  LKR\n" );
        fprintf(pntr, "DATE AND TIME OF THE TRANSACTION : %s\n", ctime(&tm));
        goto label2;
    }

    else {

        bal-=tAmount;

        printf("\n\nYOU TRANSFERED %d LKR", tAmount);
        printf("\nBALANCE OF THE ACCOUNT IS %d LKR", bal);
        fprintf(pntr, "\n%d LKR has transfered from this account %d \n", tAmount, accNo);
        fprintf(pntr, "DATE AND TIME OF THE TRANSACTION : %s\n", ctime(&tm));

    }

    fclose(pntr);

}

void lastDetails() {            //exit_function

    printf("\nNAME : %s %s", fname, lname );
    printf("\nACCOUNT : %d", accNo);
    printf("\nBALANCE : %d\n\n", bal);

}

void createAccount() {          //createAccount_function

    time_t tm;
    time(&tm);

    char dateOfBirth[20];
    char nic[20];
    char tel[20];
    char email[20];
    FILE *pntr=fopen("userDetails.txt","a");

    FILE *ptr=fopen("Accounts.txt","a");
    FILE *pr=fopen("Records.txt", "a");



    printf("\t\t* * * * WELCOME TO \"C\" BANK * * * * \n");
    divid();
    printf("\nFirst Name : ");
    scanf("%s",&fname);
    fprintf(pntr,"Firstname : %s\n",fname);

    printf("\nLast Name : ");
    scanf("%s",&lname);
    fprintf(pntr,"Lastname : %s\n",lname);

    printf("\nDate of Birth (dd/mm/yy) : ");
    scanf("%s",&dateOfBirth);
    fprintf(pntr,"Date Of Birth : %s\n",dateOfBirth);

    printf("\nNIC No : ");
    scanf("%s",&nic);
    fprintf(pntr,"NIC : %s\n",nic);

    printf("\nTelephone No : ");
    scanf("%s",&tel);
    fprintf(pntr,"Telephone : %s\n",tel);

    printf("\nE-mail : ");
    scanf("%s",&email);
    fprintf(pntr,"E-mail : %s\n",email);

    printf("\nENTER YOUR FIRST DEPOSIT AMOUNT : ");
    scanf("%d",&dep);


    bal=dep;
    fprintf(pr,"\nYou have deposited %d LKR\n",dep);
    fprintf(pr, "DATE AND TIME OF THE TRANSACTION : %s\n", ctime(&tm));

    printf("\n\nYOUR ACCOUNT HAS CREATED SUCCESSFULLY!!!! \n");


    srand(time(NULL));
    accNo=rand();

    fprintf(ptr,"%d",accNo);
    fprintf(ptr,"\n");

    printf("Your Account Number Is " );
    yellow ();
    printf("%d\n", accNo);
    red();

    printf("\n* * * * Press any key to continue... * * * * ");

    getch();

    fclose(pntr);
    fclose(ptr);
    fclose(pr);



}


void divid()
{
    for(int i=0;i<60;i++)
    {
        printf("-");
    }
}




#include<stdio.h>
int main() {
   int option;
   printf("Please select Your Option \n");
   scanf("%d",&option);#include <stdio.h>
#include <stdlib.h>    //header_files
#include <time.h>
#include <conio.h>

void menu();
void createAccount();
void withdraw();
void balCheck();       //declarationOfFunctionsUsed
void moneyTrans();
void lastDetails();
void deposit();
void yellow();
void red();
void green();
void white();
void divid();

int bal=0, accNo, with;     //global_variables
char name[35], fname[20], lname[20];
int dep;


int main() {            //main_function

    while(1) {

    char select;
    system("color Aa");
    red();

    printf("Do You have an account? (Y/N)\n" );
    scanf("%c",&select);
    system("cls");

    if(select=='N' || select=='n') {

        createAccount();

    }


    else if (select=='Y' || select=='y'){

        int input;
        int actNo;
        printf("Account Number : ");
        scanf("%d", &input);

        if(input == accNo) {

        label :
            system("cls");
            menu();
            printf("\nEnter The Activity No : ");
            scanf("%d", &actNo);

            switch (actNo)
            {

            case 1:
                system("cls");
                withdraw();
                printf("\n* * * * Press any key to continue * * * * ");
                getch();
                goto label;
                break;

            case 2:
                system("cls");
                deposit();
                printf("\n* * * * Press any key to continue * * * * ");
                getch();
                goto label;
                break;

            case 3:
                system("cls");
                balCheck();
                printf("\n* * * * Press any key to continue * * * * ");
                getch();
                goto label;
                break;

            case 4:
                system("cls");
                moneyTrans();
                printf("\n* * * * Press any key to continue * * * * ");
                getch();
                goto label;
                break;

            case 5:
                system("cls");

                FILE *pntr;

                pntr = fopen("Records.txt", "r");

                char myString[1000];

                while(fgets(myString, 1000, pntr)) {

                    printf("%s", myString);

                };

                fclose(pntr);
                printf("\n* * * * Press any key to continue * * * * ");
                getch();
                goto label;
                break;

            case 6:
                lastDetails();
                exit(0);

                break;

            default:
                printf("INVALID INPUT");
                printf("\n* * * * Press any key to continue * * * * ");
                getch();
                break;

              }
  }

        else if (input != accNo) {

                printf("You have to create a account first!");
                printf("\n* * * * Press any key to continue... * * * * ");
                getch();

  }
 }
 }

return 0;

}

void yellow () {
    printf("\033[1;33m");
}
void red () {
    printf("\033[1;31m");   //consoleTextFormatting_functions
}
void green () {
    printf("\033[1;32m");
}
void white () {
    printf("\033[1;37m");
}



void menu() {           //menu_function

    printf("\t\t* * * * WELCOME TO \"C\" BANK * * * * \n");
    divid();
    printf("\nActivities Menu\n");
    divid();
    printf("\n\t1. Withdraw\n");
    printf("\t2. Deposit\n");
    printf("\t3. Balance Check\n");
    printf("\t4. Transfer Money\n");
    printf("\t5. Transaction History\n");
    printf("\t6. Exit\n");

}

void withdraw() {       //withdraw_function

    time_t tm;
    time(&tm);

    FILE *pntr = fopen("Records.txt", "a");

    printf("* * * WITHDRAW MONEY * * *\n\n");

    printf("Enter The Amount You Want To Withdraw : ");
    scanf("%d", &with);

    if(bal<with) {

       printf("YOUR BALANCE IS INSUFFICIENT");
        fprintf(pntr, "Your balance is insufficient to withdraw %d LKR\n", with);
        fprintf(pntr, "DATE AND TIME OF THE TRANSACTION : %s\n", ctime(&tm));

    }

    else {

        bal -= with;

        printf("\nYOU WITHDRAWED %d LKR", with);
        printf("\nBALANCE OF THE ACCOUNT IS %d LKR\n", bal);

        fprintf(pntr, "\n%d has Withdrawn from this account %d\n", with, accNo);
        fprintf(pntr, "DATE AND TIME OF THE TRANSACTION : %s\n", ctime(&tm));

    }

    fclose(pntr);

}

void deposit() {            //deposit_function

    time_t tm;
    time(&tm);

    FILE *pntr = fopen("Records.txt", "a");

    printf("\n* * * DEPOSIT MONEY * * *\n\n");

    printf("Enter The Amount You Want To Deposit : ");
    scanf("%d", &dep);

    bal += dep;

    printf("\nYOUR MONEY HAS DEPOSITED SUCCESSFULLY!!!");

    printf("\nBALANCE OF THE ACCOUNT IS %d LKR\n", bal);

    fprintf(pntr, "\n%d LKR has deposited to this account %d\n", dep, accNo);
    fprintf(pntr, "DATE AND TIME OF THE TRANSACTION : %s\n", ctime(&tm));

    fclose(pntr);

}

void balCheck() {          //balance_function

printf("Your Balance : %d",bal);

}

void moneyTrans() {

        time_t tm;
        time(&tm);

        FILE *pntr=fopen("Records.txt", "a");

        int tAmount,tAcc;

        printf("Enter a Account Number You want to Transfer : ");
        scanf("%d",&tAcc);
label2:
        printf("Enter the Amount You want to Transfer : ");
        scanf("%d",&tAmount);

 if(bal<tAmount)
    {

        printf("YOUR BALANCE IS INSUFFICIENT\n\n");
        fprintf(pntr, "\nYour balance is insufficient to transfer  LKR\n" );
        fprintf(pntr, "DATE AND TIME OF THE TRANSACTION : %s\n", ctime(&tm));
        goto label2;
    }

    else {

        bal-=tAmount;

        printf("\n\nYOU TRANSFERED %d LKR", tAmount);
        printf("\nBALANCE OF THE ACCOUNT IS %d LKR", bal);
        fprintf(pntr, "\n%d LKR has transfered from this account %d \n", tAmount, accNo);
        fprintf(pntr, "DATE AND TIME OF THE TRANSACTION : %s\n", ctime(&tm));

    }

    fclose(pntr);

}

void lastDetails() {            //exit_function

    printf("\nNAME : %s %s", fname, lname );
    printf("\nACCOUNT : %d", accNo);
    printf("\nBALANCE : %d\n\n", bal);

}

void createAccount() {          //createAccount_function

    time_t tm;
    time(&tm);

    char dateOfBirth[20];
    char nic[20];
    char tel[20];
    char email[20];
    FILE *pntr=fopen("userDetails.txt","a");

    FILE *ptr=fopen("Accounts.txt","a");
    FILE *pr=fopen("Records.txt", "a");



    printf("\t\t* * * * WELCOME TO \"C\" BANK * * * * \n");
    divid();
    printf("\nFirst Name : ");
    scanf("%s",&fname);
    fprintf(pntr,"Firstname : %s\n",fname);

    printf("\nLast Name : ");
    scanf("%s",&lname);
    fprintf(pntr,"Lastname : %s\n",lname);

    printf("\nDate of Birth (dd/mm/yy) : ");
    scanf("%s",&dateOfBirth);
    fprintf(pntr,"Date Of Birth : %s\n",dateOfBirth);

    printf("\nNIC No : ");
    scanf("%s",&nic);
    fprintf(pntr,"NIC : %s\n",nic);

    printf("\nTelephone No : ");
    scanf("%s",&tel);
    fprintf(pntr,"Telephone : %s\n",tel);

    printf("\nE-mail : ");
    scanf("%s",&email);
    fprintf(pntr,"E-mail : %s\n",email);

    printf("\nENTER YOUR FIRST DEPOSIT AMOUNT : ");
    scanf("%d",&dep);


    bal=dep;
    fprintf(pr,"\nYou have deposited %d LKR\n",dep);
    fprintf(pr, "DATE AND TIME OF THE TRANSACTION : %s\n", ctime(&tm));

    printf("\n\nYOUR ACCOUNT HAS CREATED SUCCESSFULLY!!!! \n");


    srand(time(NULL));
    accNo=rand();

    fprintf(ptr,"%d",accNo);
    fprintf(ptr,"\n");

    printf("Your Account Number Is " );
    yellow ();
    printf("%d\n", accNo);
    red();

    printf("\n* * * * Press any key to continue... * * * * ");

    getch();

    fclose(pntr);
    fclose(ptr);
    fclose(pr);



}


void divid()
{
    for(int i=0;i<60;i++)
    {
        printf("-");
    }
}




  switch(option)
    {
        case 1:new_accounts();
        break;
        case 2:update();
        break;
        case 3:transact();
        break;
        case 4:see();
        break;
        case 5:deleted();
        break;
        case 6:view_list();
        break;
        case 7:close();
        break;

    }
  
   
   return 0;
}
>>>>>>> 53e11a5739792cba41c3745b4d5697f9a5699c3c
