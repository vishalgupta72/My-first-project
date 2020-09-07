//#endif // CAR_H_INCLUDED#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED
#include <time.h>
typedef struct User
{
    char userid[20];
    char pwd[20];
    char name[20];
};
typedef struct Car
{
int capacity;
int car_count;
int price;
int car_id;
char car_name[50];
};
typedef struct Customer_Car_Details
{
    int car_id;
    char cust_name[30];
    char pick[30];
    char drop[30];
    struct tm sd,ed;
};
typedef struct User User;
typedef struct Car Car;
typedef struct Customer_Car_Details Customer_Car_Details;
void addAdmin();
User* getInput();
int checkUserExist(User,char*);
int adminMenu();
void addEmployee();
void viewEmployee();
void addCarDetails();
void showCarDetails();
int deleteEmp();
int deleteCarModel();
void welcomeDisplay();
void Option();
void sub_str(char*,char*,char);
int empMenu();
int checkAvailability();
int rentCar();
void availCarDetail();
int selectCarModel();
void updateCarCount(int);
void bookedCarDetails();
char* getCarName();
int isValidDate(struct tm);
int dateValid();
int rentCar();
//#endif // CAR_H_INCLUDED
