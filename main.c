#include <stdio.h>
#include <stdlib.h>
#include"car.h"
#include"conio2.h"

int main()
{

        gotoxy(1,8);int i;
        textcolor(YELLOW);
        for(i=0;i<80;i++)
            printf("*");
     int x=10;
     while(x<15)
    {
    gotoxy(18,x);
    printf("=");
    gotoxy(60,x);
    printf("=");
    x++;
    }
    gotoxy(25,10);
    textcolor(BLUE);
    printf("WELCOME TO CAR RENTAL SYSYTEM");

    gotoxy(20,13);
    textcolor(LIGHTGREEN);
    printf("* RENT A CAR AND GO WHEREVER YOU NEED *");

    gotoxy(1,17);
    textcolor(YELLOW);

        for(i=0;i<80;i++)
            printf("*");

        addAdmin();


        User *usr;
        int result;
    _getch();
    textcolor(YELLOW);

    int choice,type;
    while(1)
    {

        clrscr();
        textcolor(LIGHTRED);
        gotoxy(32,2);
        printf("CAR RENTAL SYSTEM");
        //UPPER LINE
        gotoxy(1,8);
        textcolor(YELLOW);
        for(i=0;i<80;i++)
            printf("*");
        //lower line
        gotoxy(1,17);
        for(i=0;i<80;i++)
            printf("*");
            gotoxy(32,10);
            textcolor(YELLOW);
            printf("1.ADMIN");
            gotoxy(32,12);
            printf("2.EMPLOYEE");
            gotoxy(32,14);
            textcolor(WHITE);
            int k;
            printf("Select your role:");
            do
            {
              scanf("%d",&type);
              k=0;
             if(type==1)
             {
                 do
                 {
                     usr=getInput();
                     if(usr!=NULL)
                     {
                         k=checkUserExist(*usr,"admin");
                         //code for validation userid and password
                     }
                    else
                    {
                     break;

                    }
                 }
                 while(k==0);

                 if(k==1)
                 {
                        gotoxy(30,14);
                        textcolor(LIGHTGREEN);

                        printf("Login Accepted!");

                        gotoxy(21,20);
                        textcolor(WHITE);
                        printf("Enter any key to continue..");
                        _getch();
                        while(1)
                        {
                            clrscr();
                            choice=adminMenu();


                            if(choice==7)
                            {
                                clrscr();
                                break;
                            }
                            switch(choice)
                            {
                            case 1:
                                clrscr();
                               addEmployee();
                                break;

                            case 2:
                                clrscr();
                               addCarDetails();
                                break;

                            case 3:
                                viewEmployee();
                                clrscr();

                                break;

                            case 4:
                                showCarDetails();
                                break;

                            case 5:
                                clrscr();
                                result=deleteEmp();
                                if(result==0)
                                {
                                    gotoxy(15,14);
                                    textcolor(LIGHTRED);
                                    printf("Sorry! No Employee found with the given Employee ID");
                                    textcolor(WHITE);
                                    printf("\n\nPress any key to go back to the main menu");
                                    _getch();
                                }
                                else if(result==1)
                                {
                                    gotoxy(25,14);
                                    textcolor(LIGHTGREEN);
                                    printf("Record Deleted successfully");
                                    textcolor(WHITE);
                                    printf("\n\nPress any key to go back to the main menu");
                                    _getch();

                                }
                                break;

                            case 6:
                                result=deleteCarModel();
                                if(result==0)
                                {
                                    gotoxy(15,14);
                                    textcolor(LIGHTRED);
                                    printf("Sorry! No car found with the given CAR-ID");
                                    textcolor(WHITE);
                                    printf("\n\nPress any key to go back to the main menu");
                                    _getch();
                                }
                                else if(result==1)
                                {
                                    gotoxy(25,14);
                                    textcolor(LIGHTGREEN);
                                    printf("Record Deleted successfully");
                                    textcolor(WHITE);
                                    printf("\n\nPress any key to go back to the main menu");
                                    _getch();

                                }
                                break;


                            default:
                                printf("Incorrect choice:");
                                _getch();
                                break;
                            }
                        }
                 }
                 //Code for handling employee login
             }
             else if(type==2)
             {
                 //Code for handling
                do
                 {
                     usr=getInput();
                     if(usr!=NULL)
                     {
                         k=checkUserExist(*usr,"emp");
                         //code for validation userid and password
                     }
                    else
                    {
                     break;

                    }
                 }
                 while(k==0);

                 if(k==1)
                 {
                        gotoxy(30,14);
                        textcolor(LIGHTGREEN);

                        printf("Login Accepted!");

                        gotoxy(21,20);
                        textcolor(WHITE);
                        printf("Enter any key to continue..");
                        _getch();
                        while(1)
                        {
                            clrscr();
                            choice=empMenu();


                            if(choice==5)
                            {
                                clrscr();
                                break;
                            }
                            switch(choice)
                            {
                            case 1:
                                clrscr();
                                int j;
                                do
                                {
                                    clrscr();
                                    j=rentCar();
                                    if (j==0)
                                        printf("Booking Cancelled\nTry again");
                                    _getch();
                                }while(j==0);
                                _getch();
                                break;

                            case 2:
                                clrscr();
                                bookedCarDetails();
                                _getch();
                                break;

                            case 3:
                                clrscr();
                               availCarDetails();
                                break;
                            case 4:
                                clrscr();
                                showCarDetails();
                                break;
                            default:
                                printf("Incorrect choice:");
                                break;
                            }
                        }
                 }
             }
             else
             {
                 textcolor(LIGHTRED);
                 gotoxy(30,20);
                 printf("\t\t\t");
                 gotoxy(50,14);
                 printf("\t");
                 gotoxy(50,14);
                 textcolor(WHITE);

             }
        }
        while(type!=1&& type!=2);

    }

    return 0;
}
