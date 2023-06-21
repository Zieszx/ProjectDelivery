/*
FOOD DELIVERY PROGRAM
BY GROUP 2
MEMBERS:
1) IESKANDAR ZULQARNAIN A20EC0046
2) KHAIRUL IZZAT        A20EC0058
3) DZAKIRIN ASYRAFF     A20EC0030
*/
//header file library
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
#include "Ewallet.h"
#include "Person.h"
#include "Order.h"

using namespace std;

//customer class inheritance with person
class Customer : public Person{
    private:
        string id_cust;
        string passcust;
        Ewallet wallet;
        Order *ord;

    public:
    	//constructor with arguements
        Customer(string id, string pass, string n, string p, string ic, string e, double t):Person(n,p,ic,e){
            id[0] = toupper(id[0]);
            id_cust = id;
            passcust = pass;
            wallet.setBalance(t);
        }
        Customer(string n, string p, string ic, string e):Person(n,p,ic,e){
            wallet.setBalance(0);
        }
        //function to call the topup balance function
        void topupwallet(double t){
            wallet.topup_balance(t);
        }
        
        //function to get balance
        double checkbalance(){
            return wallet.getBalance();
        }

		//accessor to get ID and password of customer
        string getIdcust(){return id_cust;}
        string getPasscust(){return passcust;}
        
        //mutator to set balance, ID customer and password customer
		void setBalance(double bal){wallet.setBalance(bal);}
        void setIdcust(string id){id_cust = id;}
        void setPasscust(string pass){passcust = pass;}
        
        //function to display data customer
		void displayAlldataCust(){
            cout << setw(6) << id_cust << setw(10) << passcust << setw(30) << name << setw(15) << IC << setw(14) << phonenum << email<< endl;
        }

		//function to display customer ID
        void displayDataCust(){     
            headadded();
            cout << "ID           :: " << id_cust << endl;
            displaydata();
        }
};
#endif
