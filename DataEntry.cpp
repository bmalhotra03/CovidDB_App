// Implements functions from class DataEntry

#include "DataEntry.h"

// function takes in string from user that is the format of a data entry
// it then converts the string into the data entry
void DataEntry :: convert(string entry){
   int i = 0;


   // Setting date, country, cases, and deaths all as strings
   date = set(entry, i);
   country = set(entry, i);
   string strgCases = set(entry, i);
   string strgDeaths = set(entry, i);


   // changing deaths and strings as ints
   c_cases = stoi(strgCases);
   c_deaths = stoi(strgDeaths);
}


// Functions sets each info from a string into the corresponding variable it takes in
string DataEntry :: set(string & entry, int & index){
   string variable;
   int end = entry.length();


   while(entry[index] != ',' && index != end){


       variable += entry[index];
       index++;
   }
   // moving i and resetting tracker
   index += 1;


   return variable;
}

