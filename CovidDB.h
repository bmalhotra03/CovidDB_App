// Header file that defines class CovidDB
#include <iostream>
#include "DataEntry.h"
#include <vector>

using namespace std;

#ifndef COVIDDB_H
#define COVIDDB_H

class CovidDB{
   private:
       int TABLE_SIZE = 17;
       vector<DataEntry> hash[17];


       // Private functions
       bool check(DataEntry);
       bool compareDates(string, string);
       int hashKey(string);
       DataEntry search(string);

   public:
       // constructor
       CovidDB(){}


       // Public Functions
       bool add(DataEntry);
       void remove(string);
       void display();


       // function gets country given by user and returns the data entry of that country
       void getStats(string c){
           DataEntry country = search(c);
           if(country.getCountry() != ""){
               cout << endl << country.getDate() << ", " << country.getCountry();
               cout << ", " << country.getCases() << ", " << country.getDeaths() << endl;
           }else
               cout << endl << "Country is not in the Hash Table" << endl;
       }

};

#endif