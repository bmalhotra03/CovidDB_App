// Implementation file to implement functions from class CovidDB

#include "CovidDB.h"
#include <vector>

// Function displays hash table
void CovidDB :: display(){
   for(int i = 0; i < TABLE_SIZE; i ++){
       int size = hash[i].size();
       for(int j = 0; j < size; j++){
           cout << endl << hash[i][j].getDate() << ", " << hash[i][j].getCountry();
           cout << ", " << hash[i][j].getCases() << ", " << hash[i][j].getDeaths() << endl;
       }
   }
}

// Function gets and returns a data entry based on the country
DataEntry CovidDB :: search(string country){
   int i = hashKey(country);
   int length = hash[i].size();


   for(int j = 0; j < length; j++){
       if(hash[i][j].getCountry() == country){
           return hash[i][j];
       }
   }
   DataEntry null;
   return null;
}


// Function adds new element to the hash table if it doesn't already exist
bool CovidDB :: add(DataEntry newEntry){
   if(!check(newEntry)){
       int index = hashKey(newEntry.getCountry());
       hash[index].push_back(newEntry);
       return true;
   }else
       return false;
}

// Function removes a data entry from the hash based on country's name
void CovidDB :: remove(string country){
   if(search(country).getCountry() == "")
       cout << endl << "Country does not exist" << endl;

   else{
       cout << endl << "Deleting Country..." << endl;
       int i = hashKey(country);
       int track = 0;
       int length = hash[i].size();


       for(int j = 0; j < length; j++){
           if(hash[i][j].getCountry() == hash[i][track].getCountry())
               break;


           track++;
       }
      
       hash[i].erase(hash[i].begin() + track);
   }
}


// Function computes the hash key for the country and returns it
int CovidDB :: hashKey(string country){
   int stringLength = country.length();
   int sum = 0;
   for(int i = 0; i < stringLength; i++){
       sum = ((i + 1) * country[i]) % TABLE_SIZE;
   }
   return sum;
}


// Function checks if the new data entry is already in the table. if it is, then it returns true.
// It then updates the data entry as long as the date is newer than the already existing data entry
bool CovidDB :: check(DataEntry newData){
   int i = hashKey(newData.getCountry());
   int length = hash[i].size();


   for(int j = 0; j < length; j++){
       if(hash[i][j].getCountry() == newData.getCountry()){
           // changing dates to integers to compare with eachother
           string ogDate = hash[i][j].getDate();
           string newDate = newData.getDate();
          
           // comparing dates and updating if necessary
           if(compareDates(ogDate, newDate)){
               hash[i][j].setDate(newData.getDate());
               hash[i][j].setCases(newData.getCases());
               hash[i][j].setDeaths(newData.getDeaths());


           }else{
               cout << endl << "That date is already in the hash table for that Country" << endl;
           }


           return true;
       }
   }
   return false;
}

// Function takes in two string dates and turns them into integers based on month, day, and year.
// Then, it compares the two dates, if the original date already in the hash table is older then
// the newer date, then it returns true.
bool CovidDB :: compareDates(string old, string newer){
   string oldArr[3];
   string newArr[3];
   int counter = 0;
   int i = 0;
   int end = old.length();


   // putting first date in array: 0 index is month, 1 is day, 2 is year
   while(counter < 3){
       if(i != end && old[i] != '/'){
           oldArr[counter] += old[i];
       }else
           counter++;
       i++; 
   }


   counter = 0;
   i = 0;
   end = newer.length();


   // putting second date in array: 0 index is month, 1 is day, 2 is year
   while(counter < 3){
       if(i != end && newer[i] != '/'){
           newArr[counter] += newer[i];
       }else
           counter++;
       i++;
      
   }


   // checks if the newer date added is more recent than the orginal date already there
   if(stoi(oldArr[2]) < stoi(newArr[2]))              // checks years
       return true;


   else if(stoi(oldArr[2]) == stoi(newArr[2])){


       if(stoi(oldArr[0]) < stoi(newArr[0]))           // checks months
           return true;


       else if(stoi(oldArr[0]) == stoi(newArr[0])){


           if(stoi(oldArr[1]) < stoi(newArr[1]))       // checks days
               return true;
       }
   }
   return false;

}