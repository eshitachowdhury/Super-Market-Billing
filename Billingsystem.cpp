#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>
using namespace std;

class Bill{
	private:
		string Item;
		int Rate, Quantity;
	public:
	Bill():Item(""), Rate(0), Quantity(0) {}
	
	void setItem(string item){
		Item = item;
	}
	void setRate(int rate){
		Rate = rate;
	}
	void setQuant (int quant){
		Quantity = quant;
	}
	string getItem(){
		return Item;
	}
	int getRate(){
		return Rate;
	}
	
	int getQuant(){
		return Quantity;
	}
};

void addItem(Bill b){
bool close=false;
while(!close){
	int choice;
	cout<<"\t1. Add."<<endl;
	cout<<"\t2. Close."<<endl;
	cout<<"\tEnter Choice: "<<endl;
	cin>>choice;
	
	if(choice==1){
		system("cls");
		string item;
		int rate, quant;
		
		cout<<"\tEnter item name: ";
		cin>>item;
		b.setItem(item);
		
		cout<<"\tEnter rate of item: ";
		cin>>rate;
		b.setRate(rate);
		
		cout<<"\tEnter quantity of item: ";
		cin>>quant;
		b.setQuant(quant);
		
		ofstream out("D:/Bill.txt",ios::app);
		if(!out){
			cout<<"\tError: File can't open"<<endl;
		}
		else{
			out<<"\t"<<b.getItem()<<" : "<<b.getRate()<<" : "<<b.getQuant()<<endl<<endl;
		}
		out.close();
		cout<<"\tItem Added Successfully!"<<endl;
		Sleep(3000);
		}
		
		else if(choice == 2){
			system("cls");
			close = true;
			cout<<"\tBack To Main Menu!"<<endl;
			Sleep(3000);
		}
}
}

printBill(){
	system("cls");
	int count=0;
	bool close=false;
	while(!close){
		system("cls");
	int choice;
	cout<<"\t1. Add bill"<<endl;
	cout<<"\t2. Close session"<<endl;
	cout<<"\t Enter choice: "<<endl;
	cin>>choice;
	
	if(choice==1){
		string item;
		int quant;
		cout<<"\t Enter item: ";
		cin>>item;
		cout<<"\tEnter quantity: ";
		cin>>quant;
		
		ifstream in("D:/Bill.txt");
		ofstream out("D:/Bill Temp.txt");
		
		string line;
		bool found=false;
		
		while(getline(in, line)){
			stringstream ss;
			ss<<line;
			string itemName;
			int itemRate, itemQuant;
			char delimiter;
			ss>>itemName>>delimiter>>itemRate>>delimiter>>itemQuant;
			
			if(item==itemName){
				found= true;
				if(quant<=itemQuant){
					int amount = itemRate * quant;
					cout<<"\t Item | Rate | Quantity | Amount"<<endl;
					cout<<"\t"<<itemName<<"\t"<<itemRate<<"\t"<<quant<<"\t"<<amount<<endl;
					int newQuant = itemQuant - quant;
					itemQuant = newQuant;
					count += amount;
					
					out<<"\t"<<itemName<<" : "<<itemRate<<" : "<<itemQuant<<endl;
				}
				else{
					cout<<"\tSorry, "<<item<<"Ended!"<<endl;
				}
			}
			else{
				out<<line<<endl;
			}
		}
		if(!found){
			cout<<"\tItem not available"<<endl;
		}
		out.close();
		in.close();
		remove("D:/Bill.txt");
		rename("D:/Bill Temp.txt", "D:/Bill.txt");
	}	
	else if(choice==2){
		close=true;
		cout<<"\tCounting total bill"<<endl;
	}
	Sleep(3000);
 }
 system("cls");
 cout<<endl<<endl;
 cout<<"\t Total bill ------: "<<count<<endl;
 cout<<"\t Thanks for shopping!"<<endl;
 Sleep(5000);
}
int main(){
	Bill b;
	
	bool exit = false;
	while(!exit){
		system("cls");
		int val;
		
		cout<<"\tWelcome to the Super Market"<<endl;
		cout<<"\t*****"<<endl;
		cout<<"\t\t1.Add Item"<<endl;
		cout<<"\t\t2.Print Bill"<<endl;
		cout<<"\t\t3. Exit"<<endl;
		cout<<"\t Enter Choice: ";
		cin>>val;
		
		if(val==1){
			system("cls");
			addItem(b);
			Sleep(3000);
		}
		else if(val==2){
		printBill();
		}
		
		else if(val==3){
			system("cls");
			exit=true;
			cout<<"\tGood luck!"<<endl;
			Sleep(3000);
		}
	}
}

