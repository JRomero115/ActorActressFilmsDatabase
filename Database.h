#ifndef DATABASE_H
#define DATABASE_H

#include <vector>

#include "ActorActress.h"
#include "Films.h"

using namespace std;

class Database  {
    public:
        Database();
        // Create read functions
        void readActorFile(string userFile);
        void readFilmsFile(string userFile);
        // Create save functions
        void saveActorFile();
        void saveFilmsFile();
        // Create new record functions
        void newActorActress();
        void newFilms();
        // Search for record functions
        void searchActorFile();
        void searchFilmsFile();
        // Edit record functions
        void editActor(char searchMethod);
        void editFilms(char searchMethod);
        // Delete record functions
        void deleteActor(char searchMethod);
        void deleteFilms(char searchMethod);
        // Sort functions
        void sortActorFile(ifstream& userFile);
        void sortFilmsFile(ifstream& userFile);  
        // Sort comparators
        static bool sortActorYear(ActorActress year1, ActorActress year2);
        static bool sortActorName(ActorActress actor1, ActorActress actor2);
        static bool sortFilmsYear(Films year1, Films year2);
        static bool sortFilmsName(Films actor1, Films actor2);
        // Process user's option function
        void processOption(string userOption);
        // Ask if user wants to continue
        void askAgain();
    private:
        // Initialize function inputs for ActorActress
        string fullName;
        string firstName;
        string lastName;
        string theYear;
        string theFilm;
        // Initalize user inputs
        string userOption;
        char searchMethod;
        // Initalize function inputs for Films
        string picFilm;
        string picYear; 
        string theNom;            
        string theRate; 
        string dura; 
        string gen1; 
        string gen2; 
        string release;
        // Create vectors to save files
        vector<ActorActress> ActorActressList;
        vector<Films> FilmsList;
        // Create vectors for sorted file
        vector<ActorActress> sortedAAyear;
        vector<ActorActress> sortedAAname;
        vector<Films> sortedFyear;
        vector<Films> sortedFname;
};

#endif /* DATABASE_H */