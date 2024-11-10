#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>


using namespace std;
	string stockrows[10];
	string row[4]; //each row have 4 colunm
	string category[10];
	string names[10];
	string quantity[10];
	string dates[10];
	int poslist[10];

    
  
void listpos(string input, char character){
  int lastpos;
  int l;
  int j=0;


    //list the position
     l=input.rfind(character);
   for(int i=0;i<=l;){      
    poslist[j]=input.find(character,i)+1;
    i=input.find(character,i)+1;
    j++;}
  
}

void searchToDel(string nameFromMain, int numberOfitem) {	
    // Open the file in read/write mode
    //fstream file(nameFromMain + "stock.csv", ios::in | ios::out);
    ifstream file(nameFromMain + "stock.csv");
    if (!file.is_open()) {
        cout << "Error: File cannot be opened." << endl;
        return;
    }
	            cout << "                                 +++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    string itemToDel;
    string spAndname;
    	cin.ignore();
    cout << "                                               Item to delete: ";
    getline(cin, itemToDel);
    
    bool itemFound = false;
    spAndname = " " + itemToDel;
    // Loop through the arrays to find the item to delete
    for (int i = 0; i < 10; i++){
        if (names[i] == spAndname){
            category[i] = "";
            names[i] = "";
            quantity[i] = "";
            dates[i] = "";
            cout << "                                               Found item to delete: " << itemToDel << endl;
            cout << "                                 +++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
            itemFound = true;
            numberOfitem -=1;
        }
    }

    if (!itemFound) {
        cout << "                                               Item not found." << endl;
        cout << "                                 +++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
        file.close();
        return;
    }

    // Clear the file and write updated contents
    file.clear(); // Clear any error flags
    file.seekg(0); // Move to the beginning of the file
    file.close(); // Close the file before rewriting

    // Reopen the file in write mode to overwrite it
    ofstream outFile(nameFromMain + "stock.csv");
    
    for (int i = 0; i < numberOfitem; i++) {
        if (!category[i].empty()) { // Only write non-empty categories
            outFile << category[i] << "," << names[i] << "," << quantity[i] << "," << dates[i] << endl;
        }
    }

    outFile.close();
}

 //Using to Read the Data from the CSV file	
void ViewStock(string nameFromMain){
  string stockrows[10];
  string line;
  int numberOfitem=0; 
  fstream readfile;
  readfile.open(nameFromMain + "stock.csv", ios::in);
  
  const int lowStockThreshold = 15; // Set the low stock threshold
  bool lowStockFound = false;
  
  if(readfile.is_open()){ 
    int i=0;
    while(getline(readfile,line)){  
    //stockrows[i]=line;
      listpos(line, ',');//rewnew poslist for every line
      category[i] = line.substr (0, poslist[0]-1);
      names[i]    = line.substr (poslist[0], poslist[1]-poslist[0]-1);
      quantity[i] = line.substr (poslist[1], poslist[2]-poslist[1]-1);
      dates[i]    = line.substr (poslist[2],poslist[3]-poslist[2]-1);
      i++;
      
    }
    readfile.close();
  }else{
    cout << "Unable to open file and extract"<<endl;
  }

	cout  << "           +==============================================================================================+" << endl;
	cout  << "           |                                        Stock Overview                                        |" << endl;
	cout  << "           +==============================================================================================+" << endl;
	cout  << "           |     Category                 Item             Quantity                      Date             |" << endl;
	cout  << "           +==============================================================================================+" << endl;
 
   for(int i = 0; i < 10 ;i++){
    if(!category[i].empty()){
    	cout << setw(17) << " " << left << setw(23) << category[i] << setw(23) << names[i] << setw(18) << quantity[i] << setw(38) << dates[i] <<endl;
      	numberOfitem+=1;
     }  
   }
   
	cout  << "           +==============================================================================================+" << endl;
	cout << "\n";
     // Display Low Stock Alerts
    cout << "                                       Low Stock Alerts (Quantity below " << lowStockThreshold << "):" << endl;
    cout << "                                 ---------------------------------------------------" << endl;
    for (int i = 0; i < 10; i++) {
    	int quantityI;
    	try {
               quantityI= stoi(quantity[i]); 
             } catch (invalid_argument& e) {  //if error type: invalid argument, in this case is non-numeric item quantity
                      quantityI=0;
		     }
		     
        if (!quantity[i].empty() && quantityI< lowStockThreshold) {	
            cout << "                                      " << right << names[i] << " (" << category[i] << ") - Quantity: " << quantity[i] << " units" << endl;
            	lowStockFound = true;
        }
    }

    if (!lowStockFound) {
        cout << "                                     No items with low stock!" << endl;
    }
    cout << "                                 ---------------------------------------------------" << endl;
  
   int del;
  do{
  	 
     cout << "                                               0: Return to Menu" << endl;
     cout << "                                               1: Delete stock" << endl;
     cout << "                                              Please select an option: "; 
	 	cin >> del;
     
     
	 if(del == 1){
     	searchToDel(nameFromMain,numberOfitem);
	 }
	 
  }while(del);
  

} 