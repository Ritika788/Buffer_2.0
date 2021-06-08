#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<cstdlib>
#include <bits/stdc++.h>
#include <ctime>
using namespace std;
double amount = 0;
double sum = 0;
int mode;
struct node{

	string item_name;
	int num;
	int qty;
	struct node *next;
	int rand();
}*start;
int serialNo[58]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58};
	string Menu[58]={ "Tomato soup","Veg corn soup","Veg Manchow soup","Sweet corn","Veg Thai soup","Chicken Manchow soup","Chicken Hot n Sour soup","Chicken Okaiya soup","Chicken Chinese soup","Chicken corn soup","Spring roll","Grilled Mushroom","Chilli Paneer","Veg Manchurian","Veg lollipop","Chicken Tandoori","Chicken Tikka","Chicken Wings","Chicken Platter Jumbo","Chicken Crispy","Paneer Butter Masala"," Veg Kolhapuri","Mix veg","Paneer Tikka Masala","Kadai Paneer","Malai Kofta","Veg Hyderabadi","Aloo Gobi","Bhindi Masala","Punjabi Chole","Butter Chicken","Murg Mussalam","Garlic Chicken","Chicken Cafreal","Roti","Butter Roti","Naan","Butter Naan","Tandoori Roti","Kulcha","Laccha Paratha","Roti Basket","Dal tadka","Dal Fry","Yellow Dal","Dal Makhni","Steam Rice","Jeera Rice","Veg Pulao","Veg Biryani","Chicken Biryani","Mutton Biryani","Chocolate Ice Cream","Vanilla Ice Cream","Gulab Jamun","Brownie","Rasgulla","Gulkand Paan"};

	int Price[58]={80,85,90,95,100,95,150,130,80,95,105,120,130,95,100,125,130,140,150,250,240,265,290,270,280,300,320,150 ,180,200,280,300,350,15,20,30,40,45,50,55,200,180,170,190,200,150,220,240,300,350,200,210,300,320,310,120,140,30};


class customer{
public:
	node* create_node(int,string,int);
	void insert_begin();
	void StoreMenu();
	 void display();
	 void total_bill(int,int,string,int);
	 void billing_details();
	 void customer_details(int);
	 void bill_delivery(double);
	 void delete_item(node**, int );

};
node *customer::create_node(int no,string itemname,int quant)
{
    struct node *temp;
    temp = new(struct node);
    if (temp == NULL)
    {
        cout<<"Please give your order...! "<<endl;
        return 0;
    }
    else
    {
        temp->num = no;
        temp->item_name = itemname;
        temp->qty=quant;
        temp->next = NULL;
        return temp;
    }
    
}
void customer::insert_begin()
{
    int num;
    cout<<"Enter the order number and quantity: "<<endl;
    cin>>num;
    int quant;
    cin>>quant;
    struct node *temp, *p;
    temp = create_node(num,Menu[num-1],quant);
    if (start == NULL)
    {
        start = temp;
        start->next = NULL;
    }
    else
    {
        p = start;
        start = temp;
        start->next = p;
    }

}
void customer::display(){
	struct node *temp;
    if (start == NULL)
    {
        cout<<"The List is Empty"<<endl;
        return;
    }
    temp = start;
    cout<<"Items of the order: "<<endl;
    while (temp != NULL)
    {
    	total_bill(temp->num , temp->qty , temp->item_name , Price[temp->num - 1] );
    	
        cout<<temp->num<<"\t\t"<<temp->item_name<<"    quantity--->"<<temp->qty;
        cout<<"    Price of 1 item--->"<<Price[temp->num-1]<<"    Total Price--->"<<temp->qty*Price[temp->num-1]<<endl<<endl;
        temp = temp->next;
    }
    time_t now = time(0);

   // convert now to string form
   char* date_time = ctime(&now);

   cout << "The current date and time is: " << date_time << endl;
   
    
}


void customer::StoreMenu(){
		
	int j,order,x;
	int cat;
	do{
		
		cout<<"PICK A CATEGORY :"<<endl<<"1. Soups"<<endl<<"2. Starters"<<endl<<"3. Veg Main Course"<<endl<<"4. Non Veg Main Course"<<endl<<"5. Indian Bread"<<endl<<"6. Dals"<<endl<<"7. Rice & Biryani"<<endl<<"8. Desserts"<<endl<<"9. EXIT"<<endl;
	    cin>>cat;
	switch (cat){
		case 1:
			for( j=0;j<10;j++)
			cout<<serialNo[j]  << "---------"<< Menu[j]<<"---------"<<Price[j]<<endl;
			break;
		case 2:
				for( j=10;j<20;j++)
					cout<<serialNo[j]  << "---------"<< Menu[j]<<"--------"<<Price[j]<<endl;
					break;
		case 3:
				for( j=20;j<30;j++)
					cout<<serialNo[j]  << "---------"<< Menu[j]<<"--------"<<Price[j]<<endl;
					break;
		case 4:
				for( j=30;j<34;j++)
					cout<<serialNo[j]  << "---------"<< Menu[j]<<"--------"<<Price[j]<<endl;
					break;
		case 5:
				for( j=34;j<42;j++)
					cout<<serialNo[j]  << "--------"<< Menu[j]<<"---------"<<Price[j]<<endl;
					break;
		case 6:
				for( j=42;j<46;j++)
					cout<<serialNo[j]  << "--------"<< Menu[j]<<"---------"<<Price[j]<<endl;
					break;
		case 7:
				for( j=46;j<52;j++)
					cout<<serialNo[j]  << "--------"<< Menu[j]<<"---------"<<Price[j]<<endl;
					break;
						
		case 8:	for( j=52;j<58;j++)
					cout<<serialNo[j]  << "--------"<< Menu[j]<<"---------"<<Price[j]<<endl;
					break;
		case 9:
			return;
			}
				 
	int c;		
   do{
     cout<<"1. PLACE ORDER WITH QUANTITY"<<endl<<"2. EXIT FROM CATEGORY"<<endl;	
     cin>>c;
     switch(c)
     {
	case 1:
		  insert_begin();
		   break;
	case 2:
		 break;
    }
     
   }while(c!=2);
     
			
	}while(cat!=9);
}

void customer::total_bill(int no , int quant , string item ,int price)
{
	
	amount = amount + quant*price;
	
	
	
}

void customer::billing_details( )
{
	
	  double cgst = 0.09 , sgst = 0.09 ,servicetax = 0.03;
    cout<<"************************* BILL ***************************"<<endl;
    
    cout<<endl;
	cout<<" Total amount : "<<amount<<endl;
	cout<<" CGST :   "<<cgst<<endl;
	cout<<" SGST :   "<<sgst<<endl;
	cout<<" Service Charge : "<<servicetax<<endl;
	 double tax = (cgst*amount) + (sgst*amount)+ (servicetax*amount);
	 cout<<" Total tax : "<<tax<<endl<<endl;
	  sum = amount + tax;
	 cout<<" TOTAL BILL  :      "<<sum<<endl<<endl;
	 cout<<"***********************************************************"<<endl;

}
void customer::customer_details(int m)
{
    srand(time(0));
    cin.ignore();  
	string name;
	cout<<"Enter your name:"<<endl;
	getline(cin,name);
	cout<<"Your name is:- "<<name<<endl;
	int customer_id;
	customer_id = rand() % 100 + 1000;
	cout<<"Your customer id is:"<<customer_id<<endl<<endl;
	
	if(m==2){

	int table_no;
	table_no = rand() % 100 + 1; 
	if(table_no<=80)
	{
		cout<<"Your table number is:"<<table_no<<endl<<endl;
	}
	else 
	{
		cout<<"Kindly wait for 20 min "<<endl<<endl;
	}
  }
}
 void customer::bill_delivery(double sum1){
	 int day;
	double money;
	int delivery_charge;
	if(sum1<=500){
		
		delivery_charge = 100;
	}
	else if(sum1>500 && sum1<=1000){
		delivery_charge = 50;
	}
	else{
		delivery_charge = 0;
	}
	
	money = sum1 + delivery_charge;
	cout<<"Your total bill including delivery charge is: "<<money<<endl;
	cout<<"Look for everyday value offers ....."<<endl;
	cout<<"Enter the day of the week (in caps) as your coupon code to get your offer"<<endl;
	cout<<"1.MONDAY 2.TUESDAY 3.WEDNESDAY 4.THRUSDAY 5.FRIDAY 6.SATURDAY 7.SUNDAY"<<endl;
	cin>>day;
	double bill_discount;
	switch(day){
		case 1:
			cout<<"Hurray.........!!!!!"<<endl<<endl;
			cout<<"You have unlocked 10% discount on your overall order..!"<<endl;
			cout<<"BON APPETIT :) "<<endl;
			bill_discount = 0.01*money;
			cout<<"Your total discount is...:"<<bill_discount<<endl;
			
			
			break;
		case 2:
			cout<<"OOPS..!! We are sorry. We have no offers for you today"<<endl;
			bill_discount=0;
			cout<<"Your total discount is...:"<<bill_discount<<endl;
			break;
		case 3:
			cout<<"Hurray.........!!!!!"<<endl<<endl;
			cout<<"You have unlocked 5% discount on your overall order..!"<<endl;
			cout<<"BON APPETIT :) "<<endl;
			bill_discount = 0.05*money;
			cout<<"Your total discount is...:"<<bill_discount<<endl;
			
			break;
		case 4:
			cout<<"Hurray.........!!!!!"<<endl<<endl;
			cout<<"You have unlocked 5% discount on your overall order..!"<<endl;
			cout<<"BON APPETIT :) "<<endl;
			bill_discount = 0.05*money;
			cout<<"Your total discount is...:"<<bill_discount<<endl;
			break;
		case 5:
			cout<<"OOPS..!! We are sorry. We have no offers for you today"<<endl;
			bill_discount=0;
			cout<<"Your total discount is...:"<<bill_discount<<endl;
			break;
		case 6:
			cout<<"Hurray.........!!!!!"<<endl<<endl;
			cout<<"You have unlocked 20% discount on your overall order..!"<<endl;
			cout<<"BON APPETIT :) "<<endl;
			bill_discount = 0.2*money;
			cout<<"Your total discount is...:"<<bill_discount<<endl;
			break;
		case 7:
			cout<<"Hurray.........!!!!!"<<endl<<endl;
			cout<<"You have unlocked 25% discount on your overall order..!"<<endl;
			cout<<"BON APPETIT :) "<<endl;
			bill_discount = 0.25*money;
	        cout<<"Your total discount is...:"<<bill_discount<<endl;
			break;
			
	}
	double finalbill;
	finalbill=money-bill_discount;
	cout<<"Your Total bill: "<<finalbill<<endl;
}
void customer::delete_item(node** head_ref, int key){

     node* temp = *head_ref;
    node* prev = NULL;
     
    if (temp != NULL && temp->num == key)
    {
        *head_ref = temp->next; // Changed head
        cin.ignore();
        cout<<"Item cancelled is:"<<"  "<<temp->num <<"  "<< temp->item_name<<endl;
        delete temp; 
        return;
    }
    
      else
    {
    while (temp != NULL && temp->num != key)
    {
        prev = temp;
        temp = temp->next;
    }
 
    // If key was not present in linked list
    if (temp == NULL)
        return;

    prev->next = temp->next;
    delete temp;
    }
	
	
}

int main(){
    cout<<"---------------INDULGE-------------"<<endl<<endl;
    cout<<"--------Welcome to INDULGE---------"<<endl<<endl;
    int t;
	customer obj;
	int c;
	
	
	
	do{
		
	cout<<"1. DELIVERY"<<endl<<"2. DINE -IN "<<endl<<"3. EXIT"<<endl;
    cin>>mode;

	cout<<"You have chosen "<<mode<<endl;
     switch(mode){
         
         case 1:
         obj.customer_details(mode);
         start = NULL;
         obj.StoreMenu();
         cout<<"Your Order is: "<<endl;
	  obj.display();
	   int nos;
	   cout<<"Are you sure you want to confirm your order ? 0. Edit  1. Yes confirm"<<endl;
	   cin>>nos;
	   if(nos==0){
	   	   amount = 0;
	       cout<<"How many items do you want to delete ? :"<<endl;
	       int del;
	       cin>>del;
	       for(int i=0; i<del; i++){
	       	int Sno;
	       	cout<<"Enter serial number of the item you want to delete!"<<endl;
	        cin>>Sno;
	       	obj.delete_item(&start, Sno);
		   }
	       
	   }
	   cout<<"Your final order is:-"<<endl;
	  
	   obj.display();
	   obj.billing_details();
	   obj.bill_delivery(sum);
	    break;
         
        
         
        case 2: 
        obj.customer_details(mode);
        start = NULL;
         obj.StoreMenu();
         cout<<"Your Order is: "<<endl;
	  obj.display();
	   int nd;
	   cout<<"Are you sure you want to confirm your order ? 0. Edit  1. Yes confirm"<<endl;
	   cin>>nd;
	   if(nd==0){
	   	   amount = 0;
	       cout<<"Enter Serial no of item to be deleted:"<<endl;
	       int Sno;
	       cin>>Sno;
	   	obj.delete_item(&start, Sno);
	   }
	   cout<<"Your final order is:-"<<endl;
	  
	   obj.display();
	   obj.billing_details();
	   break;

	  case 3:
		 cout<<"Please Visit again"<<endl;
	   	 break;
	   }
}while(mode!=3);
	
	cout<<"THANKYOU FOR ORDERING...!!..We hope you enjoyed our food and services..!!!"<<endl;
	
	return 0;
}





