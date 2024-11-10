#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <fstream>
#include <ctime>
#include <conio.h>

using namespace std;

	string CurrentDate() {
    	time_t now = time(0);
  	  	char* dt = ctime(&now); // Convert to string format
   		string dateStr = string(dt);
    	dateStr.pop_back(); // Remove trailing newline from ctime()
    		return dateStr;
}	

	
	void AddStock(string nameFromMain) //Function Name
	{ 
	 	 list <string> category {"Drink", "Snack", "Fruit", "Meat", "Exit"};  //This cant be change by user //Note: Only Developer only
																			// Category List
		string name=nameFromMain;
		string item;	 //for name of the product
		string amount;   //for amount of the product
		int cat;		 //for category choice
		int i = 1;
		
		//Select the category for the product
			cout << "                                      +------------------------------------------+" << endl;
			cout << "                                      |              Select Category             |" << endl;			
			cout << "                                      +------------------------------------------+" << endl;			
        
		for(string category : category)		//Display Category and can be modify in list<string> 
			{
		     cout << "                                      | " << setw(1) << i << ". " << left << setw(36) << category << "  |\n";
				i++;																										  
			}
			cout << "                                      +------------------------------------------+" << endl;
			cout << "                                      Select Category : " << "(1 - "<< i - 1 << "): ";
				cin >> cat;
				cin.ignore();
		    
		    
		    
		    
			if(cat < 1 || cat > i - 1 )
			{   
			    	system("CLS");
				cout << "                                 =================================================" << endl;
    			cout << "                                 |       Invalid choice, Please try again.       |" << endl;
    			cout << "                                 =================================================" << endl;      
           		_getch();
           			system("CLS");
                	return AddStock(nameFromMain);
                
			}
			
			else if(cat == 5){
				return;
			}
			
			
			cout << "                                      +------------------------------------------+" << endl;
			cout << "                                      |                 Item Name                |" << endl;			
			cout << "                                      +------------------------------------------+" << endl;
		
		    
			cout  << "                                       Enter Product Name: ";
				
   				getline(cin, item);
   				
   			while (item.empty()|| item.find_first_not_of(' ') == string::npos) { 
   				cout << "                                          You did not enter a product name." << endl;
   				cout << "                                      > Enter Product Name: "; 
   					getline(cin, item);
			  }	
   			
			
		//Input the quantity of the item		
		 	cout << "                                      +------------------------------------------+" << endl;
			cout << "                                      |                 Quantity                 |" << endl;			
			cout << "                                      +------------------------------------------+" << endl;
			
			cout << "                                        Enter Amount : ";
					getline(cin, amount);
			
			while (amount.empty()|| amount.find_first_not_of(' ') == string::npos){
   				cout  << "                                          You did not enter a quantity." << endl;
   				cout  << "                                     > Enter Amount : ";
					getline(cin, amount);
				
		        }
			  system("CLS");
		
		    cout << "                                 =================================================" << endl;
    		cout << "                                 |     Thank you your Stock Have Been Updated !  |" << endl;
    		cout << "                                 =================================================" << endl;   
		
		ofstream file(nameFromMain + "stock.csv", ios::out | ios::app);
		
		// Select the correct category using an iterator
   		auto it = category.begin();	 // it stand for iterator it use for  //This use for call the category start from "Drink" mean from the beginning
    	advance(it, cat - 1);  			// Move iterator to the selected category (it , cat - 1 ) is cat = 2 it will display snack bcuz computer call from 0,1,2,3 
		
		if(!file.is_open())
		{
			cout << "Error: File cannot be open ";
				return;
		}
						
		file << *it << ", "<< item << "," << amount << "," << CurrentDate() << "\n";
		file.close();
}


