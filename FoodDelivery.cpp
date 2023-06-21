/*
FOOD DELIVERY PROGRAM
BY GROUP 2
MEMBERS:
1) IESKANDAR ZULQARNAIN A20EC0046
2) KHAIRUL IZZAT        A20EC0058
3) DZAKIRIN ASYRAFF     A20EC0030
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <cctype>
#include <windows.h>
#include <ctime>
#include "Vendor.h"
#include "Customer.h"
#include "Deliverer.h"
#include "Ewallet.h"
#include "Order.h"
#include "Person.h"
#include "Shop.h"

using namespace std;
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

//Global Declaration
string iduser,pass;
static unsigned int ord = 0; //order
static unsigned int w = 0; // customer
static unsigned int x = 0; // vendor
static unsigned int y = 0; // Deliverer
static unsigned int z = 0; // shop

int idord = 1000;
int a = 0; // customer
int b = 0; // vendor
int c = 0; // Deliverer

//data type for function time
int day, month, year;

//Function Prototype
//Function for main menu, log in, and registration
void login();
void loadface();
void faceB();
void Daftar(char);
void Register();
void mainMenu(char cate);
//Function for page heading (UI)
void headOverride();
void headcustomer();
void headvendor();
void headdeliverer();
void headewallet();
void headshop();
void headcustorder();
void headbye();
//Function for specific menu page
void displayVendorMenu();
void displayDelivererMenu();
void displayEwalletMenu();
void displayCustomerMenu();
//Function for Shop menu in Vendor and Customer
void ShopmenuVendor(int);
void ShopmenuCustomer();
void receiptcust(Order *);
//Order function
void Send_order(int,int,double);
void ViewOrderShop(int);
//Shop function
void displayshop();
void addshop();
void deleteshop();
void removeMenu(int);
//EWallet Functions
void displaybalance();
void topupbalance();
//Deliverer functions
//Display
void displayerrorMain();
void displayRegister(char);
void OverrideMode();
void invalidinput();
void time(int &a, int &b, int &c);

//Object 
Customer *custo[100];
Vendor *vendo[100];
Deliverer *delivo[100];
Shop *shopo[100];
Order *ordo[50];
Shop *cart;

//main function
int main(){
    //To make sure all output in 2 decimal places
    cout << fixed << setprecision(2);
    //Declaration of the object
    custo[w] = new Customer("C100","Iym","Naim Jalil", "0119161852","011230030505", "jamil@hot.com", 50.00);w++;
    vendo[x] = new Vendor("V100", "Iesz", "Ieskandar Zulqarnain", "0146352896", "980525102055", "samad@hot.com");x++;
    delivo[y] = new Deliverer("D100", "Ali", "Ali Seng", "0145588421", "850625102033", "ali@hot.com");y++;
    custo[w] = new Customer("C200","Aniq","Aniq Aqil", "0199821654","950212108553", "Aniq@hot.com", 100.00);w++;
    vendo[x] = new Vendor("V200", "izzat", "Khairul Izzat", "0149032857", "980429036691", "AA@hot.com");x++;
    delivo[y] = new Deliverer("D200","Bob", "Bobbius Mars", "01121590766", "000705010991", "bob@hot.com");y++;
    delivo[y] = new Deliverer("D300","Haziq", "Haziq Zikry", "0160983211", "950705036345", "QiQi@hot.com");y++;
    delivo[y] = new Deliverer("D400", "Aiman", "Aiman Naim", "0123150132", "9830204033393", "mat@hot.com"); y++;
    
    //Declare Shop and menu for Food/Drink
    //and increament the index for the next information
    shopo[z] = new Shop("Kelantan Fried Chicken",9.00,23.00,100);
    shopo[z]->setdefmenu("food","EXO Meal", 16.90);
    shopo[z]->setdefmenu("food","Boxed Meal", 20.90);
    shopo[z]->setdefmenu("Drink","Coco cola", 3.50);
    shopo[z]->setdefmenu("Drink","Mineral", 2.00);
    z++;  
    shopo[z] = new Shop("MC Corner",10.00,22.00,100);
    shopo[z]->setdefmenu("food","Child Meal", 13.90);
    shopo[z]->setdefmenu("food","BlackPunk Meal", 17.90);
    shopo[z]->setdefmenu("Drink","Pepsa", 2.50);
    shopo[z]->setdefmenu("Drink","Fanto", 3.20);
    z++;
    shopo[z] = new Shop("AYAM PENYET",8.00,23.00,100);
    shopo[z]->setdefmenu("food","Set Ayam Penyet", 8.00);
    shopo[z]->setdefmenu("food","Set Daging Empal", 10.00);
    shopo[z]->setdefmenu("food","Set Ayam Bakar", 10.00);
    shopo[z]->setdefmenu("food","Set Keli Bakar", 10.00);
    shopo[z]->setdefmenu("Drink","Soda Gembira", 5.00);
    shopo[z]->setdefmenu("Drink","Teh O Beng", 2.00);
    shopo[z]->setdefmenu("Drink","Milo Dinosaur", 5.00);
    z++;
    shopo[z] = new Shop("Abe Ajih Cendol",13.00,22.00,100);
    shopo[z]->setdefmenu("food","Cendol Pulut Tapai", 8.00);
    shopo[z]->setdefmenu("food","Cendol Pulut Aiskrim", 7.90);
    shopo[z]->setdefmenu("food","Cendol Pulut Durian", 10.90);
    shopo[z]->setdefmenu("Drink","Air Kelapa", 2.50);
    shopo[z]->setdefmenu("Drink","Caramel Machiato", 3.50);
    z++;
    

    char loop = 'N';
    char opt;
    string idcheck,passcheck;
    bool found;
    loadface();
    
    do{
        found = false;
        faceB();

        /*
            Prompt the user to enter the the choice base on option given.
        */
        cout << endl << endl;
        cout << "\t\tY - SIGN IN\n";
        cout << "\t\tN - REGISTER\n";
        cout << "\t\tZ - OVERRIDE MODE (DEVELOPER ONLY)\n";
        cout << "\t\tX - EXIT PROGRAM\n";
        SetConsoleTextAttribute(color, 12);
        cout << "\n\n\t\tIf you doesn't have any account, please choose REGISTER (enter 'N')\n\n";
        SetConsoleTextAttribute(color, 7);
        cout << "\t\tPlease enter the option => ";

        cin >> opt;
        opt = toupper(opt);
        

        /*
            This segment is to check whether the account for user is exist or not.
            The first letter of id user:
                -V : Vendor
                -C : Customer
                -D : Deliverer

            For example : if user enter V100 the first letter of the id user 
            indicate as vendor. 
        */
        if(opt == 'Y'){
            login();                                                
            iduser[0] = toupper(iduser[0]);                         
            if(iduser[0] == 'V'){                                   
                for(int i = 0; i < x; i++){
                    idcheck = vendo[i]->getIdven();
                    idcheck[0] = toupper(idcheck[0]);
                    passcheck = vendo[i]->getPassven();
                    if(idcheck == iduser){
                        found = true;
                        if(passcheck == pass){
                            b = i; 
                            mainMenu(iduser[0]);
                            cout << "\t\t\t";system("pause");
                        }
                        else{
                            displayerrorMain();
                            cout << "\t\t\t";system("pause");
                            break;
                        }
                        
                    }
                }
                
                if(found = false){
                    displayerrorMain();
                    cout << "\t\t\t";system("pause");
                    break;
                }
            }
            else if(iduser[0] == 'D'){
                for(int i = 0; i < y; i++){
                    idcheck = delivo[i]->getIdDel();
                    idcheck[0] = toupper(idcheck[0]);
                    passcheck = delivo[i]->getPassDel();
                    if(idcheck == iduser){
                        found = true;
                        if(passcheck == pass){
                            c = i; 
                            mainMenu(iduser[0]);
                            cout << "\t\t\t";system("pause");
                        }
                        else{
                            displayerrorMain();
                            cout << "\t\t\t";system("pause");
                            break;
                        }
                    }
                }
                if(found = false){
                    displayerrorMain();
                    cout << "\t\t\t";system("pause");
                    break;
                }
            }
            else if(iduser[0] == 'C'){
                for(int i = 0; i < w; i++){
                    idcheck = custo[i]->getIdcust();
                    idcheck[0] = toupper(idcheck[0]);
                    passcheck = custo[i]->getPasscust();
                    if(idcheck == iduser){
                        found = true;
                        if(passcheck == pass){
                            a = i; 
                            mainMenu(iduser[0]);
                            cout << "\t\t\t";system("pause");
                        }
                        else{
                            displayerrorMain();
                            cout << "\t\t\t";system("pause");
                            break;
                        }
                    }
                }
                if(found = false){
                    displayerrorMain();
                    cout << "\t\t\t";system("pause");
                    break;
                }
            }
            else{
                displayerrorMain();
                cout << "\t\t\t";system("pause");
                
            }
        }
        /*
            This segment is to call the Override function which 
            to display all of the data in this program
        */
        else if(opt == 'Z'){
            login();
            if(iduser == "OVER" && pass == "RIDE")
                OverrideMode();
            cout << "\t\t\t";system("pause");
        }
        /*
            This segment is to call the register function which to 
            sign up the new user to this programme
        */
        else if(opt == 'N'){
            Register();
        }

        /*
            This segment to assign the loop with character 'X' which to terminate the program.
        */
        else if(opt == 'X')
            loop = 'X';
        else
            invalidinput();
    }while(toupper(loop) != 'X');
    headbye();
    return 0;
}

//Function for display error if invalid input in login() function
void displayerrorMain(){
    SetConsoleTextAttribute(color, 4);
    cout << "\t\t\tInvalid ID and Password Please RE-ENTER;\n";
    SetConsoleTextAttribute(color, 7);
}

//Function for displaying time and date
void time(int &a, int &b, int &c){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    a = ltm->tm_mday;
    b = 1+ltm->tm_mon;
    c = 1900+ltm->tm_year;
}

/* 
    function for the admin to view the list of user and shop information
*/
void OverrideMode(){
    bool temp = true;
    time(day,month,year);
    do{
        headOverride();
        char opt;
        SetConsoleTextAttribute(color, 10);
        cout << "\t\t\tA - DISPLAY DATA\n";
        cout << "\t\t\tX - EXIT\n";
        cout << "\t\t\tPlease enter the option => ";
        cin >> opt;
        opt = toupper(opt);
        headOverride();
        if(opt == 'A'){
            cout << "\n\n                                             ::All DATA::\n\n";
            SetConsoleTextAttribute(color, 7);
            cout << "                                             : Customer Data : \n";
            cout << "\t" << left << setw(6) << "ID" << setw(10) << "Password" << setw(30) << "Name" << setw(15) << "IC" << setw(14) << "Phone Number" << "Email Address" << endl;
            for(int i = 0; i < w; i++){ //Customer
                custo[i]->displayAlldataCust();
            }
            cout << "\n===========================================================================================================\n\n";
            cout << "\n                                            : Vendor Data : \n";
            cout << "\t" << left << setw(6) << "ID" << setw(10) << "Password" << setw(30) << "Name" << setw(15) << "IC" << setw(14) << "Phone Number" << "Email Address" << endl;
            for(int i = 0; i < x; i++){ //Vendor
                vendo[i]->displayAlldataVen();
            }
            cout << "\n===========================================================================================================\n\n";
            cout << "\n                                          : Deliverer Data : \n";
            cout << "\t" << left << setw(6) << "ID" << setw(10) << "Password" << setw(30) << "Name" << setw(15) << "IC" << setw(14) << "Phone Number" << "Email Address" << endl;
            for(int i = 0; i < y; i++){ //Deliverer
                delivo[i]->displayAlldataDeli();
            }
            cout << "\n===========================================================================================================\n\n";
            cout << "\n                                            : Shop Data : \n";
            cout << "\t" << left << setw(5) << "Num."  << setw(35) <<"Shop Name" << setw(15) << "Start Hour" << setw(15) << "End Hour" << endl;
            for(int i = 0; i < z ; i++){
                cout << "\t" << left << setw(5) <<  i+1 << setw(35)<< shopo[i]->getShopname() 
                    << setw(15) << shopo[i]->getOperate() << shopo[i]->getClose() << endl;
            }
            cout << "\n===========================================================================================================\n\n";
            cout << "\n                                            : Order Data : \n";
            cout << left << setw(10) << "ID Order" << setw(25) << "Menu" << setw(15) << "Price" << setw(15) << "Quantity" << setw(15) << "Total Price"
                << setw(15) << "Category" << setw(15)<< "Time" << "status" << endl;
            for(int i = 0; i < ord; i++){ //Order
                ordo[i]->displayAlldataOrder();
            }
            cout << "\n==========================================================================================================================\n\n";
            cout << "\t\t\t";system("pause");
        }
        else if(opt == 'X'){
            temp = false;
        }
        else{
            invalidinput();
            temp = true;
        }
    }while(temp);
}

//segment for exit of the program
void headbye(){
    SetConsoleTextAttribute(color, 9);
    system("cls");
    // Initialize char for printing
    // loading bar
    char a = 177, b = 219;
  
    cout << "\n\n\n\n\t\t\t\t\t    " << "Loading...\n\n";
    cout << "\t\t\t\t       ";
  
    // Print initial loading bar
    for (int i = 0; i < 20; i++)
        cout << a;
  
    // Set the cursor again starting
    // point of loading bar
    cout << "\r";
    cout <<"\t\t\t\t      ";
  
    // Print loading bar progress
    for (int i = 0; i < 20; i++) {
        cout << b;
  
        Sleep(50);
    }
    cout << "\n\n\n";
    system("cls");
    Sleep(550);
    cout << " " << endl;
    cout << "     \t\t|||||||||     ||      ||   ||||||||||    ||" << endl;
    cout << "     \t\t||      ||     ||    ||    ||            ||" << endl;
    cout << "     \t\t||      ||      ||  ||     ||            ||" << endl;
    cout << "     \t\t|||||||||        ||||      ||||||||||    ||" << endl;
    cout << "     \t\t||      ||        ||       ||            ||" << endl;
    cout << "     \t\t||      ||        ||       ||            " << endl;
    cout << "     \t\t|||||||||         ||       ||||||||||    ||" << endl;
    cout << " " << endl;
    cout << "\t\t\t";system("pause");
    SetConsoleTextAttribute(color, 7);
}
//display header override
void headOverride(){
    system("CLS");
    SetConsoleTextAttribute(color, 10);
    cout << "*****************************************************ADMIN*************************************************\n\n";
    cout << "===========================================================================================================\n";
    cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
    cout << "                                                OVERRIDE MODE\n";
    cout << "                                                  DEVELOPER\n";
    cout << "************************************************" << right << setfill('0') << setw(2) << day << "/" << setw(2) << month << "/" << setw(4) << year << setfill(' ') 
            <<"*************************************************" << endl;
    cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
    cout << "===========================================================================================================\n\n";
    SetConsoleTextAttribute(color, 7);
}
//display header menu
void headcustomer(){
    system("CLS");
    time(day,month,year);
    SetConsoleTextAttribute(color, 11);
	cout << "============================================================================================================\n";
    cout << "------------------------------------------------------------------------------------------------------------\n";
    cout << "============================================================================================================\n";
    SetConsoleTextAttribute(color, 2);
	cout << "                                         C U S T O M E R  P A G E S\n";
    SetConsoleTextAttribute(color, 11);
    cout << "************************************************" << right << setfill('0') << setw(2) << day << "/" << setw(2) << month << "/" << setw(4) << year << setfill(' ') 
            <<"*************************************************" << endl;
    cout << "============================================================================================================\n";
    cout << "------------------------------------------------------------------------------------------------------------\n";
    cout << "============================================================================================================\n";
    cout << left << custo[a]->getIC() << right << setw(96) << custo[a]->getName() << endl << endl << left;
	SetConsoleTextAttribute(color, 7);
}

//display header menu
void headvendor(){
    system("CLS");
    time(day,month,year);
	SetConsoleTextAttribute(color, 12);
	cout << "*****************************************************ADMIN**************************************************\n\n";
    SetConsoleTextAttribute(color, 11);
	cout << "============================================================================================================\n";
    cout << "------------------------------------------------------------------------------------------------------------\n";
    cout << "============================================================================================================\n";
    SetConsoleTextAttribute(color, 6);
	cout << "                                           V E N D O R  P A G E S\n";
    SetConsoleTextAttribute(color, 11);
    cout << "*************************************************" << right << setfill('0') << setw(2) << day << "/" << setw(2) << month << "/" << setw(4) << year << setfill(' ') 
            <<"*************************************************" << endl;
    cout << "============================================================================================================\n";
    cout << "------------------------------------------------------------------------------------------------------------\n";
    cout << "============================================================================================================\n";
    cout << left << custo[a]->getIC() << right << setw(96) << vendo[b]->getName() << endl << endl << left;
	SetConsoleTextAttribute(color, 7);
}
//display header menu
void headdeliverer(){
    system("CLS");
    time(day,month,year);
	SetConsoleTextAttribute(color, 12);
	cout << "*****************************************************ADMIN**************************************************\n\n";
    SetConsoleTextAttribute(color, 11);
    cout << "============================================================================================================\n";
    cout << "------------------------------------------------------------------------------------------------------------\n";
    cout << "============================================================================================================\n";
    SetConsoleTextAttribute(color, 15);
	cout << "                                       D E L I V E R E R  P A G E S\n";
    SetConsoleTextAttribute(color, 11);
    cout << "*************************************************" << right << setfill('0') << setw(2) << day << "/" << setw(2) << month << "/" << setw(4) << year << setfill(' ') 
            <<"*************************************************" << endl;
    cout << "============================================================================================================\n";
    cout << "------------------------------------------------------------------------------------------------------------\n";
    cout << "============================================================================================================\n";
    cout << left << delivo[c]->getIC() << right << setw(96) << delivo[c]->getName() << endl << endl << left;
	SetConsoleTextAttribute(color, 7);
}
//display header menu
void headewallet(){
    system("CLS");
    time(day,month,year);
    SetConsoleTextAttribute(color, 11);
    cout << "============================================================================================================\n";
    cout << "------------------------------------------------------------------------------------------------------------\n";
    cout << "============================================================================================================\n";
    SetConsoleTextAttribute(color, 2);
	cout << "                                        E - W A L L E T  P A G E S\n";
    SetConsoleTextAttribute(color, 11);
    cout << "*************************************************" << right << setfill('0') << setw(2) << day << "/" << setw(2) << month << "/" << setw(4) << year << setfill(' ') 
            <<"*************************************************" << endl;
    cout << "============================================================================================================\n";
    cout << "------------------------------------------------------------------------------------------------------------\n";
    cout << "============================================================================================================\n";
    cout << left << custo[a]->getIC() << right << setw(96) << custo[a]->getName() << endl << endl << left;
    SetConsoleTextAttribute(color, 7);
}
//display header menu
void headshop(){
    system("CLS");
    time(day,month,year);
    SetConsoleTextAttribute(color, 12);
	cout << "*****************************************************ADMIN**************************************************\n\n";
    SetConsoleTextAttribute(color, 11);
	cout << "============================================================================================================\n";
    cout << "------------------------------------------------------------------------------------------------------------\n";
    cout << "============================================================================================================\n";
    SetConsoleTextAttribute(color, 6);
	cout << "                                            S H O P  P A G E S\n";
    SetConsoleTextAttribute(color, 11);
    cout << "*************************************************" << right << setfill('0') << setw(2) << day << "/" << setw(2) << month << "/" << setw(4) << year << setfill(' ') 
            <<"*************************************************" << endl;
    cout << "============================================================================================================\n";
    cout << "------------------------------------------------------------------------------------------------------------\n";
    cout << "============================================================================================================\n";
    cout << left << vendo[b]->getIC() << right << setw(96) << vendo[b]->getName() << endl << endl << left;
	SetConsoleTextAttribute(color, 7);
}

//display header customer menu
void headcustorder(){
    SetConsoleTextAttribute(color, 11);
    time(day,month,year);
    cout << "===========================================================================================================\n";
    cout << "-----------------------------------------------------------------------------------------------------------\n";
    cout << "===========================================================================================================\n";
    SetConsoleTextAttribute(color, 2);
    cout << "                                        C U S T O M E R P A G E S\n";
    SetConsoleTextAttribute(color, 11);
    cout << "===============================================ORDER DETAILS===============================================\n";
    cout << "************************************************" << right << setfill('0') << setw(2) << day << "/" << setw(2) << month << "/" << setw(4) << year << setfill(' ') 
            <<"*************************************************" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------\n";
    cout << "===========================================================================================================\n\n";
    SetConsoleTextAttribute(color, 7);
}

/*
    This segment is to display error when user enter invalid inputs
*/
void invalidinput(){
    SetConsoleTextAttribute(color, 4);
    cout << "\n\n\t\t\tInvalid option!! Please input again.\n\n\n";
    SetConsoleTextAttribute(color, 7);
    cout << "\t\t\t";system("pause");
}

//Function for user to login
void login(){
    system("cls");
    faceB();
    SetConsoleTextAttribute(color, 11);
    cout << "\n\t\t\t\t\t\t:: LOG IN ::\n\n";
    cout << "\t\t\t\t\t" << "      ID : ";
    cin >> iduser;
    cout << "\t\t\t\t\t" << "PASSWORD : ";
    cin >> pass;
    SetConsoleTextAttribute(color, 7);
}
//function to decide the menu for the user
void mainMenu(char cate){
    if(cate == 'V'){
        displayVendorMenu();
    }
    else if(cate == 'D'){
 
        displayDelivererMenu();
    }
    else{
        displayCustomerMenu();
    }
}

void loadface(){
    system("CLS");
	SetConsoleTextAttribute(color, 14);
    time(day,month,year);
    cout << "##################################################################################################\n";
    cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
    cout << "                                            COPYRIGHT BY :\n";
    cout << "                                        BLACK PANDA SDN BHD\n";
    cout << "********************************************" << right << setfill('0') << setw(2) << day << "/" << setw(2) << month << "/" << setw(4) << year << setfill(' ') 
            <<"********************************************" << endl;
    cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
    cout << "##################################################################################################\n\n";
  
    // Initialize char for printing
    // loading bar
    char a = 177, b = 219;
  
    cout << "\n\n\t\t\t\t\t    " << "Loading...\n\n";
    cout << "\t\t\t\t       ";
  
    // Print initial loading bar
    for (int i = 0; i < 20; i++)
        cout << a;
  
    // Set the cursor again starting
    // point of loading bar
    cout << "\r";
    cout <<"\t\t\t\t      ";
  
    // Print loading bar progress
    for (int i = 0; i < 20; i++) {
        cout << b;
  
        Sleep(80);
    }
    cout << "\n\n\n";
    SetConsoleTextAttribute(color, 7);
}

//Header for main page of the program
void faceB(){
    system("CLS");
    SetConsoleTextAttribute(color, 14);
    time(day,month,year);
    cout << "___________________________________________________________________________________________________________\n";
    cout << "-----------------------------------------------------------------------------------------------------------\n";
    cout << "-----------------------------------------------------------------------------------------------------------\n";
    cout << "                                                  WELCOME!!\n";
    cout << "                                            BLACK PANDA DELIVERY\n";
    cout << "================================================" << right << setfill('0') << setw(2) << day << "/" << setw(2) << month << "/" << setw(4) << year << setfill(' ') 
         <<"=================================================" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------\n";
    cout << "-----------------------------------------------------------------------------------------------------------\n";
    cout << "___________________________________________________________________________________________________________\n";
    SetConsoleTextAttribute(color, 7);
    
}
// function for user to key-in their information
void Daftar(char o){
    SetConsoleTextAttribute(color, 11);
    string n,pn,icuser,e,regid,regpass;
    faceB();
    cout << "\t\t\t\t\tCreate your Account\n\n";
    cin.ignore();
    cout << "\t\t\tName => ";
    getline(cin ,n);
    cout << "\t\t\tIC => ";
    cin >> icuser;
    cout << "\t\t\tPhone Number => ";
    cin >> pn;
    cout << "\t\t\tEmail => ";
    cin >> e;
    
    displayRegister(o);

    cout << "\t\t\tID => ";
    cin >> regid;
    regid[0] = toupper(regid[0]);

    cout << "\t\t\tPASSWORD => ";
    cin >> regpass;

    if(o == 'A'){
        while(regid[0] != 'V'){
            SetConsoleTextAttribute(color, 4);
            cout << "\t\t\t\tYour id is invalid!! Please Reenter again.\n";
            SetConsoleTextAttribute(color, 7);
            displayRegister(o);
            cout << "\t\t\tID => ";
            cin >> regid;
            regid[0] = toupper(regid[0]);
        }
        vendo[x] = new Vendor(n,pn,icuser,e);
        vendo[x]->setIdven(regid);
        vendo[x]->setPassven(regpass);
        SetConsoleTextAttribute(color, 9);
        vendo[x]->displayDataVen();
        SetConsoleTextAttribute(color, 7);
        x++;
    }
    else if(o == 'B'){
        while(regid[0] != 'D'){
            SetConsoleTextAttribute(color, 4);
            cout << "\t\t\t\tYour id is invalid!! Please Reenter again.\n";
            SetConsoleTextAttribute(color, 7);
            displayRegister(o);
            cout << "\t\t\tID => ";
            cin >> regid;
            regid[0] = toupper(regid[0]);
        }
        delivo[y] = new Deliverer(n,pn,icuser,e);
        delivo[y]->setIDdel(regid);
        delivo[y]->setPassDel(regpass);
        SetConsoleTextAttribute(color, 9);
        delivo[y]->displayDataDel();
        SetConsoleTextAttribute(color, 7);
        y++;
    }
    else{
        while(regid[0] != 'C'){
            SetConsoleTextAttribute(color, 4);
            cout << "\t\t\t\tYour id is invalid!! Please Reenter again.\n";
            SetConsoleTextAttribute(color, 7);
            displayRegister(o);
            cout << "\t\t\tID => ";
            cin >> regid;
            regid[0] = toupper(regid[0]);
        }
        custo[w] = new Customer(n,pn,icuser,e);
        custo[w]->setIdcust(regid);
        custo[w]->setPasscust(regpass);
        SetConsoleTextAttribute(color, 9);
        custo[w]->displayDataCust();
        SetConsoleTextAttribute(color, 7);
        w++;
    }
    cout << "\t\t\t";system("pause");
    
}

void displayRegister(char o){
    if(o == 'A')
        cout << "\t\t\tMake sure your id have 'V' or 'v' at the first letter\n";
    else if(o == 'B')
        cout << "\t\t\tMake sure your id have 'D' or 'd' at the first letter\n";
    else
        cout << "\t\t\tMake sure your id have 'C' or 'c' at the first letter\n";
}

//function to register as vendor/deliverer/customer
void Register(){
    char option;
    bool cond = false;
	do{
		faceB();
		cout << "\t\tA - As Vendor\n";
		cout << "\t\tB - As Deliverer\n";
		cout << "\t\tC - As Customer\n";
        cout << "\t\tX - To leave\n";
        cout << "\t\tEnter Option => ";
        cin >> option;
        option = toupper(option);
        if(option == 'X')
            cond = false;
        if(option != 'A' && option != 'B' && option != 'C' && option != 'X'){
            invalidinput();
            Register();
        }
        else if (option == 'A' || option == 'B' ||  option == 'C'){
            Daftar(option);
            cout << "\t\t\t";system("pause");
        }
        else{
            cout << "\t\t\t";system("pause");
            break;
        }
    }while(cond);
}

/*Function for vendor menu that will show option:
1. addshop - this function will call the addshop() function
2. dislay shop- this selection will call the displayshop() function
3. deleteshop - this selection will delete any shop that will be choose*/
void displayVendorMenu(){ 
    
    headvendor();
    char opt;
    int numlist;
    cout << "\t\tA - Add Shop\n";
	cout << "\t\tB - Display Shop\n";
    cout << "\t\tC - Delete Shop\n";
	cout << "\t\tX - Back to Main Menu\n\n";
    cout << "\t\tInput the option=> ";
    cin >> opt;
    opt = toupper(opt);
    if(opt == 'A'){
        system("cls");
        headvendor();
        addshop();
        cout << "\t\t\t";system("pause");
        displayVendorMenu();
    }
    else if(opt == 'B'){
        system("cls");
        headvendor();
        displayshop();
        cout << "\n\n\tEnter your shop did you want(by number) => ";
        cin >> numlist;
        ShopmenuVendor(numlist);
        cout << "\t\t\t";system("pause");
    }
    else if(opt == 'C'){
        system("cls");
        headvendor();
        deleteshop();
        cout << "\t\t\t";system("pause");
        displayVendorMenu();
    }
    else if(opt == 'X'){
        faceB();
    }
    else{
        invalidinput();
        system("cls");
        displayVendorMenu();
    }
        
}

//Function for deliverer menu
void displayDelivererMenu(){
    
    headdeliverer();
    char opt;
    int idor;
    double sal;
    bool test = false;
    cout << "\t\tA - View assigned order\n";
    cout << "\t\tB - Display Completed Delivery\n";
    cout << "\t\tX - Back to Main Menu\n\n";
    cout << "\t\tInput the option => ";
    cin >> opt;
    opt = toupper(opt);
    //Selection if deliverer want to view their assigned order
    if(opt == 'A'){
        headdeliverer();
        cout << left << setw(10) << "ID Order" << setw(25) << "Menu" << setw(15) << "Price" << setw(15) << "Quantity" << setw(15) << "Total Price"
         << setw(15) << "Category" << setw(15)<< "Time" << "status" << endl;
        for(int i = 0; i < ord; i++){
            if(delivo[c]->getIdDel() == ordo[i]->getDeliver()){
                cout << *ordo[i];
                if(ordo[i]->getStatus()=="Completed"){
                    test = false;
                }
                else
                    test = true;
            }
        }
        if(test){
            cout << "\t\tInput the ID order for the order that you would like to complete :: ";
            cin >> idor;
            cout << "\t\t\t";system("pause");
            headdeliverer();
            for(int i = 0; i < ord; i++){
                if(idor == ordo[i]->getIDorder()){
                    ordo[i]->setStatus("Completed");
                    sal = delivo[c]->getSalary() + 5;
                    delivo[c]->setSalary(sal);
                }
            }
            cout << endl << endl;
            cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
            cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
            cout << "                                        Your task has been completed\n";
            cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
            cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
        }
        else
            cout << "\t\t\tDoenst have any order yet Or your order has been Completed!\n";
        cout << "\t\t\t";system("pause");
        displayDelivererMenu();
    }
    //Selection if deliverer want to view their completed delivery and salary
    else if(opt == 'B'){
        headdeliverer();
        cout << "\t\t\t" << left << setw(10) << "ID Order" << setw(20) << "Menu" << setw(15) << "status" << "Commisson" << endl;
        for(int i = 0; i < ord; i++){
            if(delivo[c]->getIdDel() == ordo[i]->getDeliver()){
                if(ordo[i]->getStatus() == "Completed"){
                    cout << "\t\t\t" << left << setw(10) << ordo[i]->getIDorder() 
                        << setw(20) << ordo[i]->getFoodname(0)
                        << setw(15) << ordo[i]->getStatus()
                        << setw(10) << "RM 5"
                        << endl;
                    for(int j = 1; j < ordo[i]->getTotalList(); j++){
                        cout << "\t\t\t" << left << setw(10) << " " 
                        << setw(20) << ordo[i]->getFoodname(j)
                        << setw(15) << ordo[i]->getStatus()
                        << endl;
                    }
                    test = true;
                }
            }
        }
        if(!test)
            cout << "\t\t\tDoesnt have any order complete!\n";
        cout << endl << endl;
        cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
        cout << "                                                  SALARY\n";
        cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
        cout << "\t\t\tNAME :: " << delivo[c]->getName() << endl << endl;

        cout << "\t\t\tYour salary for today : " << "RM " << delivo[c]->getSalary() << endl;
        cout << "\t\t\t";system("pause");
        displayDelivererMenu();
    }

    else if(opt == 'X'){
        faceB();
        //back to main menu
    }
    else{
        invalidinput();
        displayDelivererMenu();
    }
}

//Function for E-wallet main menu
void displayEwalletMenu(){
    
    headewallet();
    
    char opt;   
    cout << "\t\tA - Display Balance\n";
	cout << "\t\tB - Topup Balance\n";
	cout << "\t\tX - Back to Menu\n\n";
    cout << "\t\tInput the option => ";
    cin >> opt;
    opt = toupper(opt);
    if(opt == 'A'){
        displaybalance();
        cout << "\t\t\t";system("pause");
        displayEwalletMenu();
    }
    else if(opt == 'B'){
        topupbalance();
        cout << "\t\t\t";system("pause");
        displayEwalletMenu();
    }
    else if(opt == 'X'){
        faceB();
    }
    else{
        invalidinput();
        displayEwalletMenu();
    }
}

//function to display the e-wallet balance of customer
void displaybalance(){
    headewallet();
    cout << "\n\t\t\tYour balance in your Ewallet is : RM " << custo[a]->checkbalance() << endl;

}

//function for customer to topup balance
void topupbalance(){
    double wanttopup;
    headewallet();
    cout << "\t\t\tYour E-Wallet Balance :: " << custo[a]->checkbalance() << endl;
    cout << "\t\t\tHow much you want to topup => RM ";
    cin >> wanttopup;
    custo[a]->topupwallet(wanttopup);

    SetConsoleTextAttribute(color, 3);
    cout << endl;
    cout << "============================================================================================================\n";
    cout << "------------------------------------------------------------------------------------------------------------\n";
    cout << "                                   SUCCESSFULY ADDED TO YOUR EWALLET!!\n";
    cout << "------------------------------------------------------------------------------------------------------------\n";
    cout << "============================================================================================================\n";

    cout << "\t\t\tNow your balance is : RM " << custo[a]->checkbalance() << endl;
    SetConsoleTextAttribute(color, 7);
    cout << "\t\t\t";system("pause");
}

//Function for customer main menu
void displayCustomerMenu(){
    
    headcustomer();
    
    char opt,opt2;
    int numlist, num, testid;
    double t , ot, ct;
    bool cond = false;
	cout << "\t\tA - Display Shop(to buy a food)\n";
    cout << "\t\tB - E-Wallet\n";
    cout << "\t\tC - Receipt\n";
	cout << "\t\tX - Back to Menu\n\n";
    cout << "\t\tInput the option => ";

    cin >> opt;
    opt = toupper(opt);
    //selection if customer choose to view shop and order food
    if (opt == 'A'){
        headcustomer();
        

        time(day, month, year);
        
        
        do {
            system("CLS");
            headcustorder();
            displayshop();
            cout << "\n\n\t\t\tWant to Order Food ? (Y/N) => ";
            cin >> opt2;
            
            opt2 = toupper(opt2);
            
            if (opt2 =='Y'){
                cout << "\n\t\tEnter your shop did you want(by number) => ";
                cin >> numlist;
                
                do{
                    system("CLS");
                    headcustorder();
                    cout << "\t\t\tShop Name :: " << shopo[numlist-1]->getShopname() << endl << endl;
                    cout << "\t\t\tOperating time :: " << shopo[numlist-1]->getOperate() << " until " << shopo[numlist-1]->getClose() << "\n\n";
                    cout << "\t\tPlease pick time between the operating hour => ";
                    cin >> t ;
                    cout << endl << endl;
                    ot = shopo[numlist-1]->getOperate();
                    ct = shopo[numlist-1]->getClose();
                    if(ot > t || ct < t ){
                        cond = true;
                        SetConsoleTextAttribute(color, 4);
                        cout << "\t\tYour chosen time is not within operating hour!!\n";
                        SetConsoleTextAttribute(color, 7);
                        system("pause");
                    }
                    else
                        cond = false;
                    
                }while(cond);
                cout << "===========================================================================================================\n\n";
                addCart(shopo[numlist-1]);
                idord++;
                system("cls");
                headcustorder();
                SetConsoleTextAttribute(color, 14);
                cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n";
                cout << "                                                  DELIVERER\n";
                cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n";
                SetConsoleTextAttribute(color, 7);
                cout << left << setw(6) << "Num" << setw(30) << "Name" << setw(14) << "No Phone" << "Email\n";
                for(int i = 0; i < y;i++){
                    cout <<left << setw(6) << (i+1) << setw(30) << delivo[i]->getName() << setw(14) << delivo[i]->getPhonenum() << delivo[i]->getEmail() << endl;
                }
                cout << "\t\t\tPlease select your Rider (By Number):: ";
                cin >> num;
                ordo[ord] = new Order(cart,delivo[num - 1],idord, t,"Not Completed",day, month, year,custo[a]->getName());
                ord++;

                double money, wallet = custo[a]->checkbalance(), pay = ordo[ord-1]->getTotalPrice() + 5, tempWallet;
                
                //top up
                do{
                    if(wallet < pay){
                        tempWallet = custo[a]->checkbalance();
                        cout << "\t\t\tTotal Price : RM " << ordo[ord-1]->getTotalPrice() + 5 << " (Including delivery fee RM 5) " << endl;
                        SetConsoleTextAttribute(color, 4);
                        cout << "\n\t\t\tYou need to topup first your E-Wallet!\n";
                        cout << "\t\t\t";system("pause");
                        SetConsoleTextAttribute(color, 7);
                        topupbalance();
                        wallet = custo[a]->checkbalance();
                    }
                    else
                        break;
                }while(tempWallet != wallet);
                

                if(wallet >= pay)
                {
                    cout << "\t\t\tTotal Price : RM " << ordo[ord-1]->getTotalPrice() << " (Including delivery fee RM 5) " <<  endl;
                    custo[a]->setBalance(custo[a]->checkbalance() - ordo[ord-1]->getTotalPrice() - 5);
                    cout << "\t\t\tBalance E-Wallet : RM " << custo[a]->checkbalance() << endl;
                    cond = true;
                }
                else{
                    cout << "\t\t\tYour order is not successful!\n";
                    ord--;
                    delete ordo[ord];
                    cond = false;
                }

                if(cond){
                    system("cls");
                    headcustomer();
                    receiptcust(ordo[ord-1]);
                    cout << endl << endl;
                    SetConsoleTextAttribute(color, 11);
                    cout << "\n===========================================================================================================\n";
                    cout << "                                             YOUR ORDER IS SUCCEED!\n";
                    cout << "=============================================================================================================\n\n\n";
                    SetConsoleTextAttribute(color, 7);
                }

                cout << "\t\t\t";system("pause");
            }
            else if(opt2 == 'N'){
                cout << "\t\t\tYou will go back to Customer Main Menu\n";
                opt2 == toupper(opt2);
                cout << "\t\t\t";system("pause");
                displayCustomerMenu();
            
            }
            else{
                invalidinput();
                opt2 = 'Y';
            }    
        }while(opt2 == 'Y');
    }
    else if(opt == 'B'){
        displayEwalletMenu();
        cout << "\t\t\t";system("pause");
        displayCustomerMenu();
    }
    //Selection if customer wants to view existing receipt
    else if(opt == 'C'){
        
        cout << "\t\tPlease enter your Order ID :: ";
        cin >> testid;
        headcustomer();
        for(int i = 0; i < ord; i++){
            if(ordo[i]->custoName() == custo[a]->getName()){
                if(testid == ordo[i]->getIDorder()){
                    system("cls");
                    receiptcust(ordo[i]);
                }
                else {
                    cout << "\t\t\t\tYour receipt is doesnt exist\n";
                    cout << "\t\t\t";system("pause");
                }
            }
        }
        displayCustomerMenu();
        
    }
    else if(opt == 'X'){
        faceB();
    }
    else{
        invalidinput();
        displayCustomerMenu();
        
    }
}

/*Function for Shop menu that will display all of the option like Display list menu, add menu, remove menu, view order, and receipt.
This Shop menu will display when The user choose to pick any specific shop from Vendor menu*/ 
void ShopmenuVendor(int numlist){
    
    headshop();
    SetConsoleTextAttribute(color, 1);
    cout << "\t\t\tSHOP NAME :: "<< shopo[numlist-1]->getShopname() << "\n\n";
    SetConsoleTextAttribute(color, 7);
    char opt;
    int ad, testid;
	cout << "\t\tA - Display List Menu\n";
    cout << "\t\tB - Add Menu\n";
    cout << "\t\tC - Remove Menu\n";
    cout << "\t\tD - View Order For today\n";
    cout << "\t\tE - Receipt for reference\n";
	cout << "\t\tX - Back to Menu\n\n";
    cout << "\t\tInput the option => ";
    cin>> opt;
    opt = toupper(opt);
    
    //If the user select A, it will show the list of the menu that will be take from shop class
    if (opt == 'A'){
        system("cls");
        headshop();
        shopo[numlist-1]->listfood();
        cout << "\t\t\t";system("pause");
        ShopmenuVendor(numlist);
    }

    //this B selection for add menu and save the data in shop class
    else if(opt == 'B'){
        system("cls");
        headshop();
        SetConsoleTextAttribute(color, 1);
        cout << "\t\t\tSHOP NAME :: "<< shopo[numlist-1]->getShopname() << "\n\n";
        SetConsoleTextAttribute(color, 7);
        cout << "\n\t\tHow many Food/Drink that you want to add => ";
        cin >> ad;
        shopo[numlist-1]->addfood(ad);
        cout << "\t\t\t";system("pause");
        ShopmenuVendor(numlist);
    }
    //selection if user wants to delete food menu of the shop
    else if(opt == 'C'){
        system("cls");
        headshop();
        SetConsoleTextAttribute(color, 1);
        cout << "\t\t\tSHOP NAME :: "<< shopo[numlist-1]->getShopname() << "\n\n";
        SetConsoleTextAttribute(color, 7);
        removeMenu(numlist);
        cout << "\t\t\t";system("pause");
        ShopmenuVendor(numlist);
    }
    //Selection if user wants to view order made for shop
    else if(opt == 'D'){
        ViewOrderShop(numlist);
        cout << "\t\t\t";system("pause");
        ShopmenuVendor(numlist);
    }
    //Selection if user wants to view existing receipts
    else if(opt == 'E'){
        system("cls");
        headshop();
        SetConsoleTextAttribute(color, 1);
        cout << "\t\t\tSHOP NAME :: "<< shopo[numlist-1]->getShopname() << "\n\n";
        SetConsoleTextAttribute(color, 7);

        cout << "\t\t\tPlease enter your Order ID :: ";
        cin >> testid;
        headshop();
        for(int i = 0; i < ord; i++){
            if(ordo[i]->getShop()->getShopname() == shopo[numlist-1]->getShopname()){
                if(testid == ordo[i]->getIDorder()){
                    system("cls");
                    receiptcust(ordo[i]);
                }
                else
                    cout << "\t\t\t\tYour receipt is doesnt exist\n";
                    cout << "\t\t\t";system("pause");
            }
        }
        ShopmenuVendor(numlist);
    }
    else if(opt == 'X'){
        displayVendorMenu();
    }
    else{
        invalidinput();
        ShopmenuVendor(numlist);
        
    }
}
//function to list out all of the shop that has been register
void displayshop(){
    cout <<"\t\t"<< left << setw(5) << "Num."  << setw(35) <<"Shop Name" 
             << setw(15) << "Start Hour" << setw(15) << "End Hour" << endl;
    for(int i = 0; i < z ; i++){
        cout <<"\t\t"<< left << setw(5) <<  i+1 << setw(35)<< shopo[i]->getShopname() 
             << setw(15) << shopo[i]->getOperate() << shopo[i]->getClose() << endl;
    }
}
//function to add menu of selected shop by taking the Shop's class function
void Shop::addfood(int product){
    int u = 1;
    cout << "\n===========================================================================================================\n\n";
    for(int i = list ; i < list + product; i++){
        cout << "\t\t" << "Food " << u++ << " :: \n\n";
        cout << "\t\t" << "What category is this product(Food/Drink) => ";
        cin >> category[i];
        for(int j = 0;j < category[i].length();j++)
            category[i][j] = toupper(category[i][j]);
        
        while(category[i] != "FOOD" && category[i] != "DRINK" ){
            SetConsoleTextAttribute(color, 4);
            cout << "\t\t" << "Your category for product is invalid!! Please Reenter again.\n\n";
            SetConsoleTextAttribute(color, 7);
            cout  << "\t\t" << "What category this product(Food/Drink) => ";
            cin >> category[i];
            for(int j = 0;j < category[i].length();j++)
                category[i][j] = toupper(category[i][j]);
        }
        cout  << "\t\t" << "Enter Food / Drink name => ";
        cin.ignore();
        getline(cin,food[i]);
        cout  << "\t\t" << "Enter price for the Food => ";
        cin >> price[i];
        cout << endl << endl;
        cout << "\t" << "=========================================================================================\n\n";
    }
    list = list + product;
}

//function to add a new shop as Vendor
void addshop(){
    //calling headvendor
    headvendor();
    string sn;
    double ot, ct; // ot : Operating time, ct : Closing time
    int pro; // pro : how many product did shop have

    cout << "\t\t\t                     REGISTER RESTAURANT\n\n";
    cout << "\t\t\tEnter the restaurant name => "; 
    cin.ignore();
    getline(cin,sn);
    cout << "\t\t\tStart operate             => "; 
    cin >> ot;
    cout << "\t\t\tEnd operate               => ";
    cin >> ct;
    
    //send the shop's information to Shop class
    shopo[z] = new Shop(sn, ot, ct, 100);
    

    SetConsoleTextAttribute(color, 9);
    cout << "\n===========================================================================================================\n";
    cout << "-------------------------------------------------------------------------------------------------------------\n";
    cout << "                                        Restaurant has been added!!\n";
    cout << "-------------------------------------------------------------------------------------------------------------\n";
    cout << "=============================================================================================================\n";
    SetConsoleTextAttribute(color, 7);
    cout << "\t\t\tRESTAURANT NAME:: " << sn << endl;
    cout << "\t\t\tSTART HOUR     :: " << ot << endl;
    cout << "\t\t\tEND HOUR       :: " << ct << endl;

    z++;
}

//function to remove selected food from selected shop
void removeMenu(int numlist){
    int del;
    string ndel;
    shopo[numlist-1]->listfood();
    cout << "\t\t\tSelect type did want to delete(by Number) => ";
    cin >> del;
    ndel = shopo[numlist-1]->getFood(del-1);
    shopo[numlist-1]->deleteMenu(del);
    cout << endl << endl;
    SetConsoleTextAttribute(color, 11);
    cout << "\n===========================================================================================================\n";
    cout << "                                 THE MENU  " << ndel <<" HAS BEEN DELETED!\n";
    cout << "=============================================================================================================\n\n\n";
    SetConsoleTextAttribute(color, 7);

}
//Function to delete a shop from the list of shop for vendor
void deleteshop(){
    //display headvendor by calling the function
    headvendor();
    //calling the display shop to list out all the shop
    displayshop();
    string ndel;

    int numlist; 
    cout << "\n\n \t\t\tCHOOSE SHOP TO DELETE FROM THE SYSTEM  => "; 
    //choose shop to delete
    cin >> numlist;
    ndel = shopo[numlist-1]->getShopname();
    delete shopo[numlist-1];
    int j = numlist;
    for(int i = numlist-1; i < z && j < z; i++){
        shopo[i] = shopo[j];
        j++;
    }       
    z--;
    cout << endl << endl;
    SetConsoleTextAttribute(color, 11);
    cout << "\n===========================================================================================================\n";
    cout << "                                   YOUR " << ndel << " HAS BEEN DELETED !\n";
    cout << "===========================================================================================================\n\n\n";
    SetConsoleTextAttribute(color, 7);

}
//Function for the customer to make order
void addCart(Shop *kedai){
    int num;
    cart = new Shop(kedai->getShopname(), kedai->getOperate(), kedai->getClose(), 50);
    kedai->listfood();
    
    //loop for repetition order
    do{
        cout << "\n\t\tPlease enter the food number (Enter 0 if done) => ";
        cin >> num;

        if(num > 0 && num <= kedai->list){
            cart->food[cart->list] = kedai->food[num-1];
            cart->category[cart->list] = kedai->category[num-1];
            cart->price[cart->list] = kedai->price[num-1];
            cout << "\t\t\tEnter Quantity : ";
            cin >> cart->quantity[cart->list];
            kedai->quantity[num-1] = kedai->quantity[num-1] - cart->quantity[cart->list];
            cart->list++;
        }
        else if(num != 0)
            cout << "\t\t\tUnknown choice\n";
    }while(num != 0);
}

//Function for vendor to check the list of order made from selected shop
void ViewOrderShop(int numlist){

    bool test = false;
    double totalall = 0;
    system("cls");
    headshop();
    SetConsoleTextAttribute(color, 1);
    cout << "\t\t\tSHOP NAME :: "<< shopo[numlist-1]->getShopname() << "\n\n";
    SetConsoleTextAttribute(color, 7);
    
    cout << left << setw(10) << "ID Order" << setw(25) << "Menu" << setw(15) << "Price" << setw(15) << "Quantity" << setw(15) << "Total Price"
        << setw(15) << "Category" << setw(15)<< "Time" << "status" << endl;   
    for(int i = 0; i < ord ; i++){
        if(shopo[numlist-1]->getShopname() == ordo[i]->getShopname()){
            cout << *ordo[i];
            totalall = totalall + ordo[i]->getTotalPrice();
            test = true;
        }
    }
    
    if(test = false) 
        cout << "\t\t\tDoesnt have any order Today!\n";
    else{
        cout << "\n====================================================================================================================";
        cout << "\n\n\t\t\tTotal profit for today : RM " << totalall << endl;
    }
    cout << "\t\t\t";system("pause");
    ShopmenuVendor(numlist);
    
}

//Overloaded operator for outputting food menu 
ostream &operator<<(ostream &out, Order &obj){
    out << left << setw(10) << obj.id_order
    << setw(25) << obj.getFoodname(0) << "RM " 
    << setw(12) << obj.getFoodprice(0) 
    << setw(15) << obj.getQuantity(0) 
    << setw(15) << obj.getFoodprice(0) * obj.getQuantity(0) 
    << setw(15) << obj.getFoodCate(0) 
    << setw(15) << obj.time
    << setw(15) << obj.status
    << endl;

    for(int j = 1; j < obj.getTotalList(); j++)
    {
        out << left << setw(10) << " " 
        << setw(25) << obj.getFoodname(j) << "RM " 
        << setw(12) << obj.getFoodprice(j) 
        << setw(15) << obj.getQuantity(j) 
        << setw(15) << obj.getFoodprice(j) * obj.getQuantity(j) 
        << setw(15) << obj.getFoodCate(j) 
        << setw(15) << obj.time
        << setw(15) << obj.status
        << endl;
    }

    return out;
}

//Function to display the receipt for order made by customer
void receiptcust(Order *resit){
    cout << "                                           Please Wait!\n" ;
    Sleep(550);
    system("cls");
    cout << "\n\n                                  :: Here is your Receipt :: \n";
    int d = resit->getDay();
    int m = resit->getMonth();
    int y = resit->getYear();
    cout << endl;
    cout << "                    ====================================================\n";
    cout << "                                   BLACK PANDA SDN BHD\n\n";
    cout << "                     Shop Name          :: " << resit->getShop()->getShopname() << endl;
    cout << "                     Customer Name      :: " << resit->custoName() << endl;
    cout << "                     Order Date         :: " << right << setfill('0') << setw(2) << d << "/" << setw(2) << m << "/" << setw(4) << y << setfill(' ') << left << endl;
    cout << "                     Order ID #         :: " << resit->getIDorder() << endl << endl;
    cout << "                     Delivery Boy       :: " << resit->getDeliverObj()->getName() << endl;
    cout << "                     No Phone Deliverer :: " << resit->getDeliverObj()->getPhonenum() << endl;
    cout << "                         Name      " << "Price       " << "Qty       " << " Total" << endl;
    cout << "                    ------------------------------------------------------  \n";
    for(int i = 0; i < resit->getTotalList(); i++){
        cout << setw(25) << " " << resit->getFoodname(i) << endl;
        cout << left;
        cout << setw(35) << " " << setw(12) << resit->getFoodprice(i) << setw(12) << resit->getQuantity(i) << (resit->getQuantity(i)*resit->getFoodprice(i)) << endl;
    }
    cout << "\n                    ------------------------------------------------------\n\n";
    cout << right << setw(57) << "Your SubTotal     :: " << setw(7) << resit->getTotalPrice() << endl;
    cout << right << setw(57) << "Your Delivery fee :: " << setw(7) << "5" << endl;
    cout << right << setw(57) << "Your Total Price  :: " << setw(7) << resit->getTotalPrice()+5 << endl << endl << left;
    cout << "                  =========================================================\n";
    cout << "\t\t\t";system("pause");
}
