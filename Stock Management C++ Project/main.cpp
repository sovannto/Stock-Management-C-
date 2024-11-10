#include <iostream>
#include <string>
#include"Login.h"
#include <string>
#include <conio.h>

using namespace std;

string mainName;
int main(){
   
	int choice;

	
	LoginUser();
	mainName = showUsername();

	system("CLS");
	
	do
		{	
		
		DisplayMenu(mainName);
		cout << "                                 	 Enter your choice (1 - 3) : ";
			cin >> choice;
		//choosing Choice From The Menu Display
			
		switch(choice)
		{
			case 1 :		
				system("CLS");						
				AddStock(mainName);	
				break;
				
			case 2 :	
				system("CLS");
				ViewStock(mainName);
				break;
                
            case 3 :
                cout << "Thank you for using the app! See you next time!" << endl;
                	break;
            default:		
                    cin.clear();
            		system("CLS");
            	cout << "                                 =================================================" << endl;
    			cout << "                                 |       Invalid choice, Please try again.       |" << endl;
    			cout << "                                 =================================================" << endl;        
    			    cin.clear();
    			    cin.ignore();  	
			}
			
  	if (choice != 3)
 		  {		  	
            _getch();     // Wait for user input
        	system("CLS"); // Clear the console again
		  }
		
	}	while(choice != 3);
		return 0;
}
		
	








