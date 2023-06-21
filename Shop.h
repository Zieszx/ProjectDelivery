/*
FOOD DELIVERY PROGRAM
BY GROUP 2
MEMBERS:
1) IESKANDAR ZULQARNAIN A20EC0046
2) KHAIRUL IZZAT        A20EC0058
3) DZAKIRIN ASYRAFF     A20EC0030
*/
//header file library
#ifndef SHOP_H
#define SHOP_H
#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
using namespace std;

//shop class
class Shop{
    private:
        string shopname;
        double operatetime,closetime;
        string *food;
        string *category;
        double *price;
        int *quantity;
        int list;
        
    public:
        Shop(){
            shopname = "";
            setOperate(0.00,0.00);
        }
        //constructor with arguements
        Shop(string n, double operate, double closet, int product){
            setOperate(operate,closet);
            shopname = n;
            food = new string[product];
            price = new double[product];
            quantity = new int[product];
            category = new string[product];
            list = 0;

        }
        int getlist() const{return list;}
        
        //mutator to set category, food name, price
        void setdefmenu(string cat, string fn, double p){
            category[list] = cat;
            for(int j = 0;j < category[list].length();j++)
                category[list][j] = toupper(category[list][j]);
            food[list] = fn;
            price[list] = p;
            list++;
        }
        
        void setMenu(int);
        void addfood(int);
        
        //function to display list of food
        void listfood(){
            cout <<  left << setw(5) << "Type" << setw(35) << "Food/Drink name" << setw(15) << "Category" << "Price" << endl;
            for(int i = 0; i < list; i++){
                cout << setw(3) << (i+1) << "  " << setw(35) << food[i] << setw(15) << category[i] << "RM " << price[i] << endl;
            }
        }
		
		//accessor to get data of the shop
		string getShopname(){return shopname;}
        double getOperate(){return operatetime;}
        double getClose(){return closetime;}
		
		//calculate the total price of order
        double totalprice(double p, int q){
            return p*static_cast<double>(q);
        }
        
        ////accessor to get value of category, food, price and quantity
        string getCategory(int i){return category[i];}
        string getFood(int i){return food[i];}
        double getPrice(int i){return price[i];}
        int getQuantity(int i){return quantity[i];}
		
		//function to display selected food
        void selectedFood(int i){
            cout << "\nThe food that has been selected is ::\n";
            cout << endl << left << setw(19) << "Food/Drink name" << setw(15) << "Category" << "Price" << endl;
            cout << setw(19) << food[i] << setw(15) << category[i] << price[i] << endl;
        }

		//mutator to set operate time and close time
        void setOperate(double op, double ct){
                operatetime = op;
                closetime = ct;
        }
        
        //function to delete menu
        void deleteMenu(int i){
            i = i - 1;
            for(int j = i + 1; j < list; j++){
                category[i] = category[j];
                price[i] = price[j];
                food[i] = food[j];
                i++;
            }
            list--;
        }
        
		    
        friend void addCart(Shop *);
        friend class Order;
};
#endif
