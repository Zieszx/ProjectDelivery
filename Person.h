/*
FOOD DELIVERY PROGRAM
BY GROUP 2
MEMBERS:
1) IESKANDAR ZULQARNAIN A20EC0046
2) KHAIRUL IZZAT        A20EC0058
3) DZAKIRIN ASYRAFF     A20EC0030
*/
//header file library
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

//Declaration of class parent named Person
class Person{
	//Protected attributes (name, phonenum, IC and email)
    protected:
        string name;
        string phonenum;
        string IC;
        string email;

    public:
    	//constructor with arguements
        Person(string n, string pn, string ic, string e){
            name = n;
            IC = ic;
            phonenum = pn;
            email = e;
        }
        
        //mutator to set name, phonenum, IC and email
        void setName(string n){name = n;}
        void setPhonenum(string pn){phonenum = pn;}
        void setIC(string ic){IC = ic;}
        void setEmail(string e){email = e;}
        
        //accessor to get value of name, phonenum, IC and email
        string getName(){return name;}
        string getPhonenum(){return phonenum;}
        string getIC(){return IC;}
        string getEmail(){return email;}
        
		//function to display successful register using polymorphims characteristis
        virtual void headadded(){
            cout << "\n===========================================================================================================\n";
            cout << "\n                                      Your data is successfully added!!\n";
            cout << "\n===========================================================================================================\n";
        }
        
        //function to display back the input by the user using polymorphims characteristis
        virtual void displaydata(){
            cout << "NAME         :: " << name << endl;
            cout << "PHONE NUMBER :: " << phonenum << endl;
            cout << "IC           :: " << IC << endl;
            cout << "EMAIL ADDRESS:: " << email << endl;
        }

};


#endif
