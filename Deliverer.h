/*
FOOD DELIVERY PROGRAM
BY GROUP 2
MEMBERS:
1) IESKANDAR ZULQARNAIN A20EC0046
2) KHAIRUL IZZAT        A20EC0058
3) DZAKIRIN ASYRAFF     A20EC0030
*/
//header file library
#ifndef DELIVERER_H
#define DELIVERER_H
#include <iostream>
#include <string>

#include "Person.h"
#include "Shop.h"

using namespace std;

//Deliverer class inheritance with Person class
class Deliverer : public Person{
    private:
        string id_del;
        string passdel;
        double salary;

    public:
    	//constructor with arguements
        Deliverer(string id, string pass, string n, string p, string ic, string e):Person(n,p,ic,e){
            id[0] = toupper(id[0]);
            id_del = id;
            passdel = pass;
        }
        Deliverer(string n, string p, string ic, string e):Person(n,p,ic,e){  
        }
		
		//accessor
        string getIdDel(){return id_del;}
        string getPassDel(){return passdel;}
        double getSalary(){return salary;}
        
        //mutator
        void setIDdel(string id){id_del = id;}
        void setPassDel(string pass){passdel = pass;}
        void setSalary(double sal){salary=sal;}
        
        //function to display data of deliverer
        void displayAlldataDeli(){
            cout << setw(6) << id_del << setw(10) << passdel << setw(30) << name << setw(15) << IC << setw(14) << phonenum << email << endl;
        }
		
		//function display data ID
        void displayDataDel(){     
            
            cout << "ID           :: " << id_del << endl;
            
        }

};
#endif
