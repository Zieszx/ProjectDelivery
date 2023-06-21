/*
FOOD DELIVERY PROGRAM
BY GROUP 2
MEMBERS:
1) IESKANDAR ZULQARNAIN A20EC0046
2) KHAIRUL IZZAT        A20EC0058
3) DZAKIRIN ASYRAFF     A20EC0030
*/
//header file library
#ifndef EWALLET_H
#define EWALLET_H
#include <iostream>
#include <string>
using namespace std;

//Ewallet class
class Ewallet{
    private:
    double balance;
    double topup;

    public:
    	//constructor with no arguements
        Ewallet(){
            balance=0;
            topup=0;}
        
        //mutator to set balance
        Ewallet(double bal){
            balance = bal;
            topup = 0;
        }
        
        //function to top up balance
        void topup_balance(double topup){
            balance+= topup;
        }
        
        //accessor to get balance
        double getBalance(){
            return balance;
        }
        
        //mutator to set balance
        void setBalance(double b){
            balance = b;
        }

};
#endif
