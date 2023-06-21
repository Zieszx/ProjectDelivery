/*
FOOD DELIVERY PROGRAM
BY GROUP 2
MEMBERS:
1) IESKANDAR ZULQARNAIN A20EC0046
2) KHAIRUL IZZAT        A20EC0058
3) DZAKIRIN ASYRAFF     A20EC0030
*/
//header file library
#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <string>
#include <iomanip>
#include "Shop.h"
#include "Deliverer.h"
using namespace std;

//Order class
class Order{
    private:
    int id_order;
    double time;
    int day, month, year;
    double total;
    string status, custname;
    Shop *item;
    Deliverer *del;


    public:
    	//constructor with no arguement
        Order(){
            id_order = 0;
            time = 0;
            total = 0;
        }
		
		//mutator to set data of deliverer , order and date
        Order(Shop *s,Deliverer *d,int ido, double time, string stat, int _day, int _month, int _year, string cust){
            item = s;
            del = d;
            id_order = ido;
            status = stat;
            this->time = time;
            total = 0;
            for(int i = 0; i < s->list; i++){
                total = total + (s->price[i]) * (s->quantity[i]);
            }
            day = _day;
            month = _month;
            year = _year;
            custname = cust;
        }
		
		//accessor for get shop name
        string getShopname(){
            return item->getShopname();
        }
		
		//accessor for get id deliverer
        string getDeliver(){
            return del->getIdDel();
        }
		
		//accessor to get id order
        int getIDorder(){
            return id_order;
        }
        
        //accessor to get time
        double gettime(){
            return time;
        }
        
        //mutator to set status of order
        void setStatus(string stat){
            status = stat;
        }
        
        //accessor to get status of order
        string getStatus(){
            return status;
        }
		
		//accessor to get name of customer
        string custoName(){
            return custname;
        }
        
        //mutator to set ID order
        void setIDorder(int ido){
            id_order = ido;
        }

		//accessor to get food, category, price and quantity
        string getFoodname(int i){return item->getFood(i);}
        string getFoodCate(int i){return item->getCategory(i);}
        double getFoodprice(int i){return item->getPrice(i);}
        int getQuantity(int i){return item->getQuantity(i);}

		//function to display information of the order
        void displayAlldataOrder(){
            for (int i = 0; i < item->getlist(); i++)
            cout << left << setw(10) << id_order << setw(20) << item->getFood(i) << "RM " << setw(15) 
                 << item->getPrice(i) << setw(15) << item->getQuantity(i) << setw(15) << item->getQuantity(i) * item->getPrice(i) << setw(15) << item->getCategory(i) << setw(15) << time << setw(15) << status << endl;
        }
		
		//function to deduct money in e-wallet
        void payment(Ewallet &fee){
            double bal = fee.getBalance() - total;
            fee.setBalance(bal);
        }
		
		//accessor
        double getTotalPrice(){return total;}
        int getTotalList(){return item->list;}
        int getDay(){return day;}
        int getMonth(){return month;}
        int getYear(){return year;}
        Deliverer *getDeliverObj(){return del;}
        Shop *getShop(){return item;}
        
        friend ostream &operator<<(ostream &out, Order &obj);

};
#endif
