#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <conio.h> 

using namespace std;

const int max_user = 3;
string unames[3], passwords[3];
string loggedinName;


void registe(){
	string username, password;
	string un,pw;
	
	cout  << "                                      +=======================================" << endl;
    cout  << "                                      |         Account Registration         |" << endl;
    cout  << "                                      +=======================================" << endl;
    cout  << "                                      |                                      |" << endl;
    cout  << "                                      |  Enter Your Username :               |" << endl;
    cout  << "                                      |                                      |" << endl;
    cout  << "                                      |  Enter Password:                     |" << endl;
    cout  << "                                      |                                      |" << endl;
    cout  << "                                      +======================================+" << endl;
    cout  << "                                      |          Type('r' to return)         |" << endl;
    cout  << "                                      +======================================+" << endl;
    cout  << "                                    > Enter Username : ";  getline(cin, username);
    
	if(username.empty()){
		system("CLS");
		registe();
	} 
	
	if(username=="r"){
		system("CLS");
		return;
	}
	
	if(!username.empty()){
	password_input:			  
    cout  << "                                    > Enter Password : ";  getline(cin, password);
    
         if(password.empty()){
         	//system("CLS");
         	goto password_input;
		 }
         
         
	     if(password=="r"){
	     	system("CLS");
	     	return;
		 }
	
	}
    	
   if(!password.empty()){
   
	//check if name already exit through external file 
	ifstream read(username +".txt");
	getline(read, un);
	getline(read, pw);
	
	if(un == username){
		
		cout << "                               ----------------------------------------------------" << endl;
    	cout << "                               |                                                  |" << endl;
    	cout << "                               |        This name has already been registered     |" << endl;
    	cout << "                               |                                                  |" << endl;
    	cout << "                               ----------------------------------------------------" << endl;
			_getch();		
			system("CLS");
		return;
	}
	system("CLS");



	//store name and passwords in internal arrays
	for(int i=0; i < 3; i++){
		if(unames[i] == ""){
			unames[i] = username;
			passwords[i] = password;
			break;
		}
	}
	
	//store user registration input into a file  
	ofstream file;
	file.open(username + ".txt");
	file << username <<endl <<password;
	file.close();
		cout << "                                      =======================================" << endl;
    	cout << "                                      |        Registration Successful!     |" << endl;
    	cout << "                                      =======================================" << endl;
    	cout << "                                      |                                     |" << endl;
    	cout << "                                      |      Thank you for registering!     |" << endl;
    	cout << "                                      |      You can now log in to your     |" << endl;
    	cout << "                                      |    account and start using the app. |" << endl;
    	cout << "                                      |                                     |" << endl;
    	cout << "                                      =======================================" << endl;
			_getch();		
			system("CLS");
	
	
}

}



bool isLoggedin(){
	
    string username, password;
	string un, pw;
	
	cout << "                                     +======================================+" << endl;
    cout << "                                     |           Sign In Your Account       |" << endl;
    cout << "                                     +======================================+" << endl;
    cout << "                                     |          Type('r' to return)         |" << endl;
    cout << "                                     +======================================+" << endl;
    cout << "                                     Enter Your Username : "; getline(cin, username);
	
	if(username.empty()){
		system("CLS");
		isLoggedin();
	} 
	
	
	if(username=="r"){
		system("CLS");
		return false;
	}
	
	if(!username.empty()){
	Loginpassword_input:			  
    cout  << "                                     Enter Password : ";  getline(cin, password);
    
         if(password.empty()){
         	goto Loginpassword_input;
		 }
         
         
	     if(password=="r"){
	     	system("CLS");
	     	return false;
		 }
	
	}
	
	
   if(!password.empty()){
   
                
	for(int i = 0; i < 3; i++){
		if(unames[i] == username && passwords[i] == password){
			return true;
		}	 
	}
	system("CLS");
	
    ifstream read(username + ".txt");
    if (read.is_open()) {  // Ensure the file is successfully opened
        getline(read, un);
        getline(read, pw);

        if (un == username && pw == password) {
        	loggedinName=username;

           return true;
        }
    } else {
        // File doesn't exist or couldn't be opened
    //    cout << "Error: Could not open user file for " << username << "." << endl;
    }

    // If all checks fail, return false
    cout << "                                      +==========================================+" << endl;
    cout << "                                      |       Incorrect Username or Password     |" << endl;
    cout << "                                      +==========================================+" << endl;
		_getch();
    	system("CLS");
    return false;
  }
  return false;
}

void LoginUser(){
	
    bool loggedIn = false;

    do {
		cout << "                                      +---------------------------------------+" << endl;
    	cout << "                                      |           Welcome to the App          |" << endl;
    	cout << "                                      +---------------------------------------+" << endl;		
    	cout << "                                      |           1. Register                 |" << endl;
    	cout << "                                      |           2. Login                    |" << endl;
    	cout << "                                      +---------------------------------------+" << endl;
    	cout << "                                            Enter your choice (1-2): ";
      
	   
	    char choice;
        cin >> choice;
        cin.ignore(); 	// Clear the newline character from the buffer

        system("CLS");	// Clearing Menu Display After choosing 

        switch(choice){
            case '1':	 // Initialize registration	
                registe();
                break;
                
            case '2':	// Initialize login
                loggedIn = isLoggedin();
                break;
            
            default:
                cout << "                                      ===================================================" << endl;
    			cout << "                                      |        Invalid Choice, Please try again.        |" << endl;
    			cout << "                                      ===================================================" << endl;
                	_getch();
               		system("CLS");
              	  break;
           
        }
        
    } while(!loggedIn); 
    
}

string showUsername(){
	return loggedinName;
}

