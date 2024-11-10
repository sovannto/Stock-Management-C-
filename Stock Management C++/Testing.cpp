#include<iostream>
#include<iomanip>
#include<string>
#include<list>
#include<fstream>


using namespace std;

	
	void AddStock()
	{
	 	const list<string> category {"Drink", "Snack", "Fruit", "Meat"};  //This cant be change by user //Note: Only Developer only
		
		int i = 1;		 //for amount of category
		int amount;  	 //for amount of the product
		int cat;		 //for category choice
		string item;	 //for name of the product
		
		//Select the category for the product
			cout <<setw(75) <<"+------------------------------------------+" <<endl;
			cout <<setw(32) <<"|" <<setw(28)<<"Select Category" <<right <<setw(15) <<"|" <<endl;			
			cout <<setw(75) <<"+------------------------------------------+" <<endl;			

		for(const string category : category)		//Display Category and can be modify in list<string> 
			{
				cout <<setw(40) <<i <<". " <<category <<"\n"; 	 
				i++;
			}

		cout<<endl;
		cout <<setw(50) <<"Select Category : " <<"(1 - "<< i-1 << "): ";
			cin>>cat;
		
		if(cat == i-2)
			{
				cout<<"Snack";
			}
			
		else if (cat == i-3)
			{
				cout<<"Fruit";	
			}
			
		else if(cat == i-4)
			{
				cout<<"Meat";
			}
		
//		else(cat<1|| cat > i -1 )
//			{
//			system("CLS");
//		cout<<"Invalid category selected." <<endl;
//				return; //this return to select category
//			}
		cout<<endl;
				
				
				
		//Input the Item name		
		 	cout <<setw(75) <<"+------------------------------------------+" <<endl;
			cout <<setw(32) <<"|" <<setw(24)<<"Item Name" <<right <<setw(19) <<"|" <<endl;			
			cout <<setw(75) <<"+------------------------------------------+" <<endl;
		
			cout << setw(50) << "Enter Product Name: ";
			cin.ignore();
   			getline(cin, item);
    		cout << endl;
		
		
				
		//Input the quantity of the item		
		 	cout <<setw(75) <<"+------------------------------------------+" <<endl;
			cout <<setw(32) <<"|" <<setw(24)<<"Quantity" <<right <<setw(19) <<"|" <<endl;			
			cout <<setw(75) <<"+------------------------------------------+" <<endl;
			
			cout <<setw(50) <<"Enter Amount : ";
				cin>>amount;
			cout<<endl;
		
		cin.ignore();
		cout <<setw(73) <<"Thank you your Stock Have Been Updated !" <<endl;
		cout<<"\n\n\n";		 
		system("PAUSE");
		system("CLS");
	
		ofstream file("Addstock.csv", ios::out | ios::app);
		
		if(!file.is_open())
		{
			cout<<"Error: File cannot be open ";
				return;
		}
		
		file <<category.front() <<"," <<item <<"," <<amount <<"\n";
		file.close();
}

	