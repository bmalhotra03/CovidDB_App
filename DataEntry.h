//Header file to define class DataEntry

#include <iostream>
#include <string>

using namespace std;

#ifndef DATAENTRY_H
#define DATAENTRY_H

class DataEntry{
   private:
       string date;
       string country;
       int c_cases;       // cumulative cases up to date
       int c_deaths;      // cumulative deaths up to date
       string set(string &, int &);
   public:
       // constructor
       DataEntry(){
           date = "";
           country = "";
           c_cases = 0;
           c_deaths = 0;
       }
      
       void convert(string);


       // getter functions
       string getDate(){ return date; }
       string getCountry(){ return country; }
       int getCases(){ return c_cases; }
       int getDeaths(){ return c_deaths; }


       // setter functions
       void setDate(string d){ date = d; }
       void setCases(int num){ c_cases += num; }
       void setDeaths(int num){ c_deaths += num; }
};


#endif
