// Author: Brij Malhotra
// Filename: assignment4.cpp
// Version: 1
// Purpose: This program stimulates a covid data tracker using a hash table. The user has 5 choices they can
// do: create an initial hash table, add new data entry, get data entry, remove data entry, and display hash table

#include <iostream>
#include "CovidDB.h"
#include "DataEntry.h"
#include <fstream>

using namespace std;

//function prototype
int menu();

int main(){
   CovidDB hash;
   int choice = menu();


   while (choice != 0){


       // if else statements based on user's choice
       if(choice == 1){            // Creates initial hash table
           ifstream inputFile ("WHO-COVID-data.csv");
           string data;
           // opening file
           if(inputFile.is_open()){
               while(!inputFile.eof()){
                   getline(inputFile, data);
                   if(inputFile.eof()){
                       break;
                   }
                   // adding file into hash table
                   DataEntry newData;
                   newData.convert(data);
                   hash.add(newData);
               }
               cout << endl << "Initial Hash Table Created" << endl;


           }else{
               cout << "Error opening file" << endl;
               inputFile.close();
           }
       }else if(choice == 2){      // adding user data entry
           DataEntry newData;
           string entry;
           cout << "Enter Data Entry in the format with no spaces (date,country,cases,deaths): ";
           getline(cin >> ws, entry);
           newData.convert(entry);
           if(hash.add(newData))
               cout << endl << "Data entry added to hash table" << endl;          


       }else if(choice == 3){      // getting data entry
           string country;
           cout << "Enter country you would like to get: ";
           getline(cin >> ws, country);
           hash.getStats(country);
          
       }else if(choice == 4){      // removing data entry
           string country;
           cout << "Enter country you would like to remove: ";
           getline(cin >> ws, country);
           hash.remove(country);
        
       }else if(choice == 5){      // displaying data entry
           cout << endl << "Displaying Hash Table: " << endl;
           hash.display();


       }else
           cout << "Invalid Choice. Try again" << endl;


      
       choice = menu();
  
   }	


   cout << endl << "Thanks for visiting! " << endl << endl;
}


// This function displays the menu as well as asks the user what they want to do
// it returns the number of their choice
int menu(){
   int num;


   cout << endl << "Covid Tracker " << endl;
   cout << "1. Create the initial hash table " << endl;
   cout << "2. Add a new data entry " << endl;
   cout << "3. Get a data entry " << endl;
   cout << "4. Remove a data entry" << endl;
   cout << "5. Display hash table " << endl;
   cout << "0. Quit the system" << endl;


   cout << "Please choose the operation you want: ";
   cin >> num;
   return num;
}
