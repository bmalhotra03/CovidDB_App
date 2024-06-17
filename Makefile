assignment4: assignment4.o DataEntry.o CovidDB.o
   g++ -o assignment4 assignment4.o DataEntry.o CovidDB.o
assignment4.o: assignment4.cpp DataEntry.h CovidDB.h
   g++ -c -Wall -Werror -pedantic assignment4.cpp
DataEntry.o: DataEntry.cpp DataEntry.h
   g++ -c -Wall -Werror -pedantic DataEntry.cpp
CovidDB.o: CovidDB.cpp CovidDB.h
   g++ -c -Wall -Werror -pedantic CovidDB.cpp