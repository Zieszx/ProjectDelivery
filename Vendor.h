/*
FOOD DELIVERY PROGRAM
BY GROUP 2
MEMBERS:
1) IESKANDAR ZULQARNAIN A20EC0046
2) KHAIRUL IZZAT        A20EC0058
3) DZAKIRIN ASYRAFF     A20EC0030
*/

#ifndef VENDOR_H
#define VENDOR_H
#include <iostream>
#include <string>
#include "Shop.h"
#include "Person.h"
using namespace std;

//vendor class inheritance with Person class
class Vendor : public Person{
    private:
        string idven;
        string passven;
        Shop shop;
        
    public:
    	//constructor with arguements
        Vendor(string id, string pass, string n, string p, string ic, string e):Person(n,p,ic,e){
            id[0] = toupper(id[0]);
            passven = pass;
            idven = id;
        }
        Vendor(string n, string p, string ic, string e):Person(n,p,ic,e){
        }
		
		//mutator to set ID and pass vendor
        void setIdven(string id){idven = id;}
        void setPassven(string pass){passven = pass;}
		
		//accessor to get ID and password vendor
        string getIdven(){return idven;}
        string getPassven(){return passven;}
		
		//function to display data of vendor
        void displayAlldataVen(){
            cout << setw(6) << idven << setw(10) << passven << setw(30) << name << setw(15) << IC << setw(14) << phonenum << email << endl;
        }
		
		//function to diplay ID of vendor
        void displayDataVen(){
            headadded();
            cout << "ID           :: " << idven << endl;
            displaydata();
        }
};
#endif
