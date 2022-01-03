#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

#include "Database.h"

// Initialize option as nothing
Database::Database() {
    string userOption = "";
}

// Function to ask if user would like to continue
void Database::askAgain() {
    // Initialize user ask again option
    string again;    
    // Jump back up to repeat
    Backup:
    // Do-while user option is no
    do {
        cout << "\nWould you like to continue? (y/n) ";
        cin >> again;
        // If option is yes, return to last function
        if (again == "y" || again == "Y") {
            return;
        } // If option is no, exit program
        if (again == "n" || again == "N") {
            cout << "\nQuitting..." << endl;
            exit(0);
        } else { // Every other option is invalid
            cout << "Invalid option. Try again.";
            goto Backup;
        }
    // Stop when option is no
    } while (again != "n" || again != "N");
}

// (R1) Function to read the actor file
void Database::readActorFile(string userFile) {
    // Create and open file
    ifstream fileName;
    fileName.open(userFile); 
    // While file works
    while (fileName.good()) {
        // Initialize variables in file
        string Year;
        string Award;
        string Winner; 
        string Name;
        string Film;
        // Seperate variables by comma
        getline(fileName, Year, ',');
        getline(fileName, Award, ',');
        getline(fileName, Winner, ',');
        getline(fileName, Name, ',');
        getline(fileName, Film, '\n');
        // Add to ActorActress vector
        ActorActressList.push_back(ActorActress(Year, Award, Winner, Name, Film));  
    } // Close file
    fileName.close();
}

// (R2) Function to read the pictures file
void Database::readFilmsFile(string userFile) {   
    // Create and open file
    ifstream fileName;
    fileName.open(userFile); 
    // While file works
    while (fileName.good()) {
        // Initialize variables in file
        string name;
        string year;
        string nominations;
        string rating;
        string duration;
        string genre1;
        string genre2;
        string release;
        string metacritic;
        string synopsis;  
        // Seperate variables by comma
        getline(fileName, name, ',');
        getline(fileName, year, ',');
        getline(fileName, nominations, ',');
        getline(fileName, rating, ',');
        getline(fileName, duration, ',');
        getline(fileName, genre1, ',');
        getline(fileName, genre2, ',');
        getline(fileName, release, ',');
        getline(fileName, metacritic, ',');   
        getline(fileName, synopsis, '\n');
        // Add to Films vector
        FilmsList.push_back(Films(name, year, nominations, rating, duration,
                               genre1, genre2, release, metacritic, synopsis));        
    } // Close file
    fileName.close();
}

// (R3) Function to add a new record for actor-actress
void Database::newActorActress() {
    // Initialize user's information
    string userYear;
    string userAward;
    string userWinner; 
    string userName;
    string userFilm;
    // User enters a year
    cout << "\n\nEnter a new year: ";
    cin >> userYear;
    // No need to read in spaces for year
    cin.ignore();
    // User enters an award
    cout << "\nEnter the new award: ";
    getline(cin, userAward);
    // User enters a winner
    cout << "\nEnter new winner (0 or 1): ";
    getline(cin, userWinner);
    // User enters a actor/actress name
    cout << "\nEnter the new actor/actress name: ";
    getline(cin, userName);
    // User enters a film
    cout << "\nEnter the new film: ";
    getline(cin, userFilm);
    // Add to ActorActress vector
    ActorActressList.push_back(ActorActress(userYear, 
    userAward, userWinner, userName, userFilm));
}

// (R4) Function to add a new record for films
void Database::newFilms() {
    // Initialize user's information
    string userName;
    string userYear;
    string userNominations;
    string userRating;
    string userDuration;
    string userGenre1;
    string userGenre2;
    string userRelease;
    string userMetacritic;
    string userSynopsis;  
    // User enters a year
    cout << "\n\nEnter the year released: ";
    cin >> userYear;
    // No need to read in spaces for year
    cin.ignore();
    // User enters a name
    cout << "\nEnter the name of the film: ";
    getline(cin, userName);
    // User enters the number of nominations
    cout << "\nEnter the number of nominations: ";
    getline(cin, userNominations);
    // User enters the rating
    cout << "\nEnter the rating (out of 10): ";
    getline(cin, userRating);
    // User enters the duration
    cout << "\nEnter the duration (in minutes): ";
    getline(cin, userDuration);
    // User enters the first genre
    cout << "\nEnter the first genre: ";
    getline(cin, userGenre1);
    // User enters the second genre
    cout << "\nEnter the second genre: ";
    getline(cin, userGenre2);        
    // User enters the month released
    cout << "\nEnter the month released: ";
    getline(cin, userRelease);  
    // User enters the metacritic score
    cout << "\nEnter the metacritic score (out of 100): ";
    getline(cin, userMetacritic);
    // User enters the synopsis
    cout << "\nEnter the synopsis: ";
    getline(cin, userSynopsis);
    // Add to Films vector
    FilmsList.push_back(Films(userName, userYear, userNominations, userRating, 
                          userDuration, userGenre1, 
                          userGenre2, userRelease, 
                          userMetacritic, 
                          userSynopsis)); 
}

// (R5) Search for a record in actor-actress
void Database::searchActorFile() {
    // For edit/delete option
    string option;
    // For if record was found
    bool foundRec = false;
    // Get vector location
    int index = 1;
    // Do-while record is not found
    do {
        // Ask user to search exact or contains
        cout << "\n\n(E)xact or (C)ontains? ";
        cin >> searchMethod;
        // If user selects exact search
        if (searchMethod == 'E' || searchMethod == 'e') {
            // Ask user what name to search
            cout << "\nEnter the full name to search: ";
            getline(cin, fullName);
            getline(cin, fullName);   
            // Ask user which year to select
            cout << "\nEnter the year: ";
            cin >> theYear;
            cin.ignore();
            // Go through records and search for name and year
            for (int i = 1; i < ActorActressList.size(); i++)
            { // Make name in file into string to compare  
                string name = ActorActressList[i].getName();
                string year = ActorActressList[i].getYear();
                // If full name and year was found
                if ((name.compare(fullName) == 0) && (year.compare(theYear) == 0)) {   // Output actor-actress list to a console
                    cout << "\n{" << year;
                    cout << ", " << ActorActressList[i].getAward();
                    cout << ", " << ActorActressList[i].getWinner();        
                    cout << ", " << name;
                    cout << ", " << ActorActressList[i].getFilm() << "}" << endl;
                    foundRec = true; // Record found
                    index = i; // To get information later
                }
            }   
        } // If user selects contains search
        if (searchMethod == 'C' || searchMethod == 'c') {
            // Ask user what name to search
            cout << "\nEnter the first name to search: ";
            cin >> firstName;
            cout << "\nEnter the last name to search: ";
            cin >> lastName;      
            // Ask user which year to select
            cout << "\nEnter the year: ";
            cin >> theYear;
            cin.ignore(); // Ignore rest
            // Go through records and search for name and year
            for (int i = 1; i < ActorActressList.size(); i++)
            {   // Make name in file into string to compare  
                string name = ActorActressList[i].getName();
                string year = ActorActressList[i].getYear();
                // Search for first, last, and year
                size_t foundFirst = name.find(firstName);
                size_t foundLast = name.find(lastName);
                size_t foundYear = year.find(theYear); 
                // If full name and year was found
                if (foundFirst != string::npos && foundLast != string::npos && foundYear != string::npos) {
                    // Output actor-actress list to a console
                    cout << "\n{" << year;
                    cout << ", " << ActorActressList[i].getAward();
                    cout << ", " << ActorActressList[i].getWinner();        
                    cout << ", " << name;
                    cout << ", " << ActorActressList[i].getFilm() << "}" << endl;
                    foundRec = true; // Record found
                    index = i; // To get information later
                }
            }
        } // If record was not found, tell user
        if (foundRec == false) {
            cout << "\n\nError finding record. Try again.\n";   
        }
    } while (!foundRec);
    // Tell user record was found
    cout << "\nRecord was found!" << endl;
    TryAgain:
    cout << "\nWould you like to edit or delete? (edit/delete) ";
    cin >> option;
    // Go to correct function for user's option
    if (option == "edit" || option == "Edit") {
        editActor(searchMethod);
        return;
    } if (option == "delete" || option == "Delete") {
        deleteActor(searchMethod);
        return;
    } else { // If invalid option
      cout << "\n\nInvalid option. Try again.\n"; 
      goto TryAgain;
    }
    return;
}

// (R5.1) Edit the selected record
void Database::editActor(char searchMethod) {
    // Clear screen
    system("clear");
    // R5.1 title
    cout << "\nR5.1 – Edit the selected record.";
    cout << "\n(Case Sensitive)" << endl;
    // If vector is empty, try again
    if (ActorActressList.empty()) {
        cout << "\n\nPlease save a file first.";
        return;
    }
    // Go here to retry inputs
    Retry:
    // For if record was found
    bool foundRec;
    // Get vector location
    int index = 1;
    // Do-while search method valid
    do { // If user want to search "exact"
        if (searchMethod == 'E' || searchMethod == 'e')
        {   // Search for exact name and year
            for (int i = 1; i < ActorActressList.size(); i++)
            { // Make name in file into string to compare  
                string name = ActorActressList[i].getName();
                string year = ActorActressList[i].getYear();
                // If full name and year was found
                if ((name.compare(fullName) == 0) && (year.compare(theYear) == 0)) {
                    foundRec = true; // Record found
                    index = i; // To get information later
                }
            }
        } // If user want to search "contains"
        if (searchMethod == 'C' || searchMethod == 'c')
        {   // Show all user records found
            for (int i = 1; i < ActorActressList.size(); i++)
            {   // Find substring in file  
                string name = ActorActressList[i].getName();
                string year = ActorActressList[i].getYear();
                // Search for first, last, and year
                size_t foundFirst = name.find(firstName);
                size_t foundLast = name.find(lastName);
                size_t foundYear = year.find(theYear); 
                // If full name and year was found
                if (foundFirst != string::npos && foundLast != string::npos && foundYear != string::npos) {
                    // Output actor-actress list to a console
                    cout << "\n{" << year;
                    cout << ", " << ActorActressList[i].getAward();
                    cout << ", " << ActorActressList[i].getWinner();        
                    cout << ", " << name;
                    cout << ", " << ActorActressList[i].getFilm() << "}";
                    foundRec = true; // Record found
                    index = i; // To get information later
                }
            } // To get correct record, ask for film
            cout << "\n\nChoose the record by entering the film name: ";
            getline(cin, theFilm);
            getline(cin, theFilm); 
            // Go through records and search for name, year, and film 
            for (int i = 1; i < ActorActressList.size(); i++) 
            {   // Find past substrings and exact film
                string name = ActorActressList[i].getName();
                string year = ActorActressList[i].getYear();
                string film = ActorActressList[i].getFilm();
                // Search for first, last, and year
                size_t foundFirst = name.find(firstName);
                size_t foundLast = name.find(lastName);
                size_t foundYear = year.find(theYear);
                // If full name and year was found
                if (foundFirst != string::npos && foundLast != string::npos && foundYear != string::npos && (film.compare(theFilm) == 0)) {
                    foundRec = true; // Record found
                    index = i; // To get information later
                }
            }
        } // Tell user record was found
        if (foundRec) {
            goto Restart;
        } else { // If not found or other error
            cout << "\n\nError finding record. Try again.\n";
            goto Retry;
        }
    } while (searchMethod != 'E' ||searchMethod != 'E' || searchMethod != 'C' || searchMethod != 'c');
    Restart:
    // For editing and updating
    string edit;
    string update;
    // Initialize user's information
    string updateYear = ActorActressList[index].getYear();
    string updateAward = ActorActressList[index].getAward();
    string updateWinner = ActorActressList[index].getWinner();
    string updateName = ActorActressList[index].getName();
    string updateFilm = ActorActressList[index].getFilm();
    // Tell user which record was selected
    cout << "\nSelected record:" << endl;
    cout << "{" << updateYear << ", ";
    cout << updateAward << ", ";
    cout << updateWinner << ", ";
    cout << updateName << ", ";    
    cout << updateFilm << "}" << endl;
    // Editing prompts 
    cout << "\nWhat would you like to edit?";
    cout << "\n(Year/Award/Winner/Name/Film) ";
    cin >> edit;
    // Change edit based on user
    if (edit == "Year" || edit == "year") {
        // User enters a year
        cout << "\nEnter the edited year: ";
        cin >> update;
        cin.ignore(); // Ignore rest
        // Make old year, edited year
        updateYear = update;
        goto Next; 
    } if (edit == "Award" || edit == "award") {    
        // User enters an award
        cout << "\nEnter the edited award: ";
        getline(cin, update);
        getline(cin, update); // Count spaces 
        // Make old award, edited award        
        updateAward = update;
        goto Next;    
    } if (edit == "Winner" || edit == "winner") {
        // User enters a winner
        cout << "\nEnter the edited winner (0 or 1): ";
        cin >> update;
        cin.ignore(); // Ignore rest
        // Make old winner, edited winner  
        updateWinner = update;
        goto Next;   
    } if (edit == "Name" || edit == "name") {    
        // User enters a actor/actress name
        cout << "\nEnter the edited actor/actress name: ";
        getline(cin, update);
        getline(cin, update); // Count spaces 
        // Make old name, edited name   
        updateName = update;
        goto Next;   
    } if (edit == "Film" || edit == "film") {    
        // User enters a film
        cout << "\nEnter the edited film: ";
        getline(cin, update);
        getline(cin, update); // Count spaces 
        // Make old film, edited film   
        updateFilm = update;
        goto Next;
    } else {
        cout << "\nError in editing record. Try again.\n";
        goto Restart;
    }
    Next:
    // Replace old record with edited record
    ActorActressList.erase(ActorActressList.begin()+index);
    // Add to ActorActress vector
    ActorActressList.push_back(ActorActress(updateYear, updateAward, updateWinner, updateName, updateFilm));
    // Display new record
    cout << "\nNew Record:";
    cout << "\n{" << updateYear;
    cout << ", " << updateAward;
    cout << ", " << updateWinner;
    cout << ", " << updateName;
    cout << ", " << updateFilm << "}" <<endl;
    return; 
}

// (R5.2) Delete the selected record
void Database::deleteActor(char searchMethod) {
    // Clear screen
    system("clear");
    // R5.2 title
    cout << "\nR5.2 – Delete the selected record." << endl;
    // If vector is empty, try again
    if (ActorActressList.empty()) {
        cout << "\n\nPlease save a file first.";
        return;
    }
    // Go here to retry inputs
    Retry:
    // For if record was found
    bool foundRec;
    // Get vector location
    int index = 1;
    // Do-while search method valid
    do { // If user want to search "exact"
        if (searchMethod == 'E' || searchMethod == 'e')
        {   // Search for exact name and year
            for (int i = 1; i < ActorActressList.size(); i++)
            { // Make name in file into string to compare  
                string name = ActorActressList[i].getName();
                string year = ActorActressList[i].getYear();
                // If full name and year was found
                if ((name.compare(fullName) == 0) && (year.compare(theYear) == 0)) {
                    foundRec = true; // Record found
                    index = i; // To get information later
                }
            }
        } // If user want to search "contains"
        if (searchMethod == 'C' || searchMethod == 'c')
        {   // Show all user records found
            for (int i = 1; i < ActorActressList.size(); i++)
            {   // Find substring in file  
                string name = ActorActressList[i].getName();
                string year = ActorActressList[i].getYear();
                // Search for first, last, and year
                size_t foundFirst = name.find(firstName);
                size_t foundLast = name.find(lastName);
                size_t foundYear = year.find(theYear); 
                // If full name and year was found
                if (foundFirst != string::npos && foundLast != string::npos && foundYear != string::npos) {
                    // Output actor-actress list to a console
                    cout << "\n{" << year;
                    cout << ", " << ActorActressList[i].getAward();
                    cout << ", " << ActorActressList[i].getWinner();        
                    cout << ", " << name;
                    cout << ", " << ActorActressList[i].getFilm() << "}"; //// << endl;
                    foundRec = true; // Record found
                    index = i; // To get information later
                }
            } // To get correct record, ask for film
            cout << "\n\nChoose the record by entering the film name: ";
            getline(cin, theFilm);
            getline(cin, theFilm); 
            // Go through records and search for name, year, and film 
            for (int i = 1; i < ActorActressList.size(); i++) 
            {   // Find past substrings and exact film
                string name = ActorActressList[i].getName();
                string year = ActorActressList[i].getYear();
                string film = ActorActressList[i].getFilm();
                // Search for first, last, and year
                size_t foundFirst = name.find(firstName);
                size_t foundLast = name.find(lastName);
                size_t foundYear = year.find(theYear);
                // If full name and year was found
                if (foundFirst != string::npos && foundLast != string::npos && foundYear != string::npos && (film.compare(theFilm) == 0)) {
                    foundRec = true; // Record found
                    index = i; // To get information later
                }
            }
        } // Tell user record was found
        if (foundRec) {
            goto Restart;
        } else { // If not found or other error
            cout << "\n\nError finding record. Try again.\n";
            goto Retry;
        }
    } while (searchMethod != 'E' ||searchMethod != 'E' || searchMethod != 'C' || searchMethod != 'c');
    Restart:
    // For editing and updating
    string edit;
    string update;
    // Tell user which record was selected
    cout << "\nSelected record:" << endl;
    cout << "{" << ActorActressList[index].getYear() << ", ";
    cout << ActorActressList[index].getAward() << ", ";
    cout << ActorActressList[index].getWinner() << ", ";
    cout << ActorActressList[index].getName() << ", ";    
    cout << ActorActressList[index].getFilm() << "}" << endl;
    // For user's option
    char op;
    // Ask user if they are sure of selection
    cout << "\nAre you sure you would like to delete this record? (y/n) ";
    cin >> op;
    // If option is yes, continue to next step
    if (op == 'y' || op == 'Y') {
        goto Continue;
    } // If option is no, exit program
    if (op == 'n' || op == 'N') {
        return;
    } // Every other option is invalid
    else {
        cout << "Invalid option. Try again.";
        goto Restart;
    }
    Continue:
    // Erase old record
    ActorActressList.erase(ActorActressList.begin()+index);
    // Tell user record was deleted
    cout << "\nRecord was deleted.\n";
    return; 
}

// (R6) Search for a record in films
void Database::searchFilmsFile() {
    // For edit/delete option
    string option;
    // For if record was found
    bool foundRec = false;
    // Get vector location
    int index = 1;
    // Do-while record is not found
    do {
        // Ask user to search exact or contains
        cout << "\n\n(E)xact or (C)ontains? ";
        cin >> searchMethod;
        // If user selects exact search
        if (searchMethod == 'E' || searchMethod == 'e') {
            // Ask user what name to search
            cout << "\nEnter the film name to search: ";
            getline(cin, picFilm);
            getline(cin, picFilm);   
            // Ask user which year to select
            cout << "\nEnter the year: ";
            cin >> picYear;
            cin.ignore();
            // Go through records and search for name and year
            for (int i = 1; i < FilmsList.size(); i++) 
            {   // Make name in file into string to compare  
                string name = FilmsList[i].getName();
                string year = FilmsList[i].getYear();     
                // Search for film
                size_t foundFilm = name.find(picFilm);
                // If film name and year was found
                if (foundFilm != string::npos && (year.compare(picYear) == 0)) {
                    // Output actor-actress list to a console
                    cout << "\n{" << name;
                    cout << ", " << year;
                    cout << ", " << FilmsList[i].getNominations();        
                    cout << ", " << FilmsList[i].getRating();
                    cout << ", " << FilmsList[i].getGenre1();
                    cout << ", " << FilmsList[i].getGenre2();
                    cout << ", " << FilmsList[i].getRelease();
                    cout << ", " << FilmsList[i].getMetacritic();
                    cout << ", " << FilmsList[i].getSynopsis() <<  "}" <<endl;
                    foundRec = true; // Record found
                    index = i; // To get information later
                }
            }   
        } // If user selects contains search
        if (searchMethod == 'C' || searchMethod == 'c') {
            // Ask user what name to search
            cout << "\nEnter the film name to search: ";
            getline(cin, picFilm);
            getline(cin, picFilm);        
            // Ask user which year to select
            cout << "\nEnter the year: ";
            cin >> theYear;
            cin.ignore(); // Ignore rest
            // Go through records and search for name and year
            for (int i = 1; i < FilmsList.size(); i++) 
            {   // Make name in file into string to compare  
                string name = FilmsList[i].getName();
                string year = FilmsList[i].getYear();
                // Search for film and year
                size_t foundFilm = name.find(picFilm);
                size_t foundYear = year.find(picYear);        
                // If full name and year was found
                if (foundFilm != string::npos && foundYear != string::npos) {
                    // Output actor-actress list to a console
                    cout << "\n{" << name;
                    cout << ", " << year;
                    cout << ", " << FilmsList[i].getNominations();        
                    cout << ", " << FilmsList[i].getRating();
                    cout << ", " << FilmsList[i].getGenre1();
                    cout << ", " << FilmsList[i].getGenre2();
                    cout << ", " << FilmsList[i].getRelease();
                    cout << ", " << FilmsList[i].getMetacritic();
                    cout << ", " << FilmsList[i].getSynopsis() <<  "}" <<endl;
                    foundRec = true; // Record found
                    index = i; // To get information later
                }
            } 
        } // If record was not found, tell user
        if (foundRec == false) {
            cout << "\n\nError finding record. Try again.\n";   
        }
    } while (!foundRec);
    // Tell user record was found
    cout << "\nRecord was found!" << endl;
    TryAgain:
    cout << "\nWould you like to edit or delete? (edit/delete) ";
    cin >> option;
    // Go to correct function for user's option
    if (option == "edit" || option == "Edit") {
        editFilms(searchMethod);
        return;
    } if (option == "delete" || option == "Delete") {
        deleteFilms(searchMethod);
        return;
    } else { // If invalid option
      cout << "\n\nInvalid option. Try again.\n"; 
      goto TryAgain;
    }
    return;
}

// (R6.1) Edit the selected record
void Database::editFilms(char searchMethod) {
    // Clear screen
    system("clear");
    // R6.1 title
    cout << "\nR6.1 – Edit the selected record.";
    cout << "\n(Case Sensitive)" << endl;
    // If vector is empty, try again
    if (FilmsList.empty()) {
        cout << "\n\nPlease save a file first.";
        return;
    }
    // For if record was found
    bool foundRec;
    // Get vector location
    int index = 1;
    if (searchMethod == 'E' || searchMethod == 'e') {
        for (int i = 1; i < FilmsList.size(); i++) 
        {   // Make name in file into string to compare  
            string name = FilmsList[i].getName();
            string year = FilmsList[i].getYear();     
            // Search for film
            size_t foundFilm = name.find(picFilm);
            // If film name and year was found
            if (foundFilm != string::npos && (year.compare(picYear) == 0)) {
                // Output actor-actress list to a console
                cout << "\n{" << name;
                cout << ", " << year;
                cout << ", " << FilmsList[i].getNominations();        
                cout << ", " << FilmsList[i].getRating();
                cout << ", " << FilmsList[i].getGenre1();
                cout << ", " << FilmsList[i].getGenre2();
                cout << ", " << FilmsList[i].getRelease();
                cout << ", " << FilmsList[i].getMetacritic();
                cout << ", " << FilmsList[i].getSynopsis() <<  "}" <<endl;
                foundRec = true; // Record found
                index = i; // To get information later
            }
        }
    }
    else if (searchMethod == 'C' || searchMethod == 'c') {
        for (int i = 1; i < FilmsList.size(); i++) 
        {   // Make name in file into string to compare  
            string name = FilmsList[i].getName();
            string year = FilmsList[i].getYear();
            // Search for film and year
            size_t foundFilm = name.find(picFilm);
            size_t foundYear = year.find(picYear);        
            // If full name and year was found
            if (foundFilm != string::npos && foundYear != string::npos) {
                // Output actor-actress list to a console
                cout << "\n{" << name;
                cout << ", " << year;
                cout << ", " << FilmsList[i].getNominations();        
                cout << ", " << FilmsList[i].getRating();
                cout << ", " << FilmsList[i].getGenre1();
                cout << ", " << FilmsList[i].getGenre2();
                cout << ", " << FilmsList[i].getRelease();
                cout << ", " << FilmsList[i].getMetacritic();
                cout << ", " << FilmsList[i].getSynopsis() <<  "}" <<endl;
                foundRec = true; // Record found
                index = i; // To get information later
            }
        }
    }

    // Go here to retry inputs
    Retry:
    cout << "\n\n= Choose the record by entering the rating and the month released =";
    cout << "\n\nRating: ";
    cin >> theRate;
    cin.ignore();
    cout << "\nMonth released: ";
    cin >> release;
    cin.ignore();
    // Go through records and search for name and year
    for (int i = 1; i < FilmsList.size(); i++) 
    {   // Make name in file into string to compare  
        string name = FilmsList[i].getName();
        string year = FilmsList[i].getYear();
        string rate = FilmsList[i].getRating();
        string rel = FilmsList[i].getRelease();
        // Search for film, year, rate, and release
        size_t foundFilm = name.find(picFilm);
        size_t foundYear = year.find(picYear);
        size_t foundRate = rate.find(theRate);      
        size_t foundRel = rel.find(release);   
        // If full name and year was found
        if (foundFilm != string::npos && foundYear != string::npos && foundRate != string::npos && foundRel != string::npos) {
            foundRec = true; // Record found
            index = i; // To get information later
        }
    }
    // Tell user record was found
    if (foundRec) {
        goto Restart;
    } else { // If record was not found or other error
        cout << "\n\nError finding record. Try again.\n";
        goto Retry;
    }
    Restart:
    // For editing and updating
    string edit;
    string update;
    // Initialize user's information
    string updateName = FilmsList[index].getName();
    string updateYear = FilmsList[index].getYear();
    string updateNom = FilmsList[index].getNominations();
    string updateRate = FilmsList[index].getRating();
    string updateDur = FilmsList[index].getDuration();
    string updateGen1 = FilmsList[index].getGenre1();
    string updateGen2 = FilmsList[index].getGenre2();    
    string updateRel = FilmsList[index].getRelease();
    string updateMeta = FilmsList[index].getMetacritic();
    string updateSyno = FilmsList[index].getSynopsis();
    // Tell user which record was selected
    cout << "\nSelected record:" << endl;
    cout << "{" << updateName;
    cout << ", " << updateYear;
    cout << ", " << updateNom;        
    cout << ", " << updateRate;
    cout << ", " << updateDur;
    cout << ", " << updateGen1;
    cout << ", " << updateGen2;
    cout << ", " << updateRel;
    cout << ", " << updateMeta;    
    cout << ", " << updateSyno <<  "}" <<endl;
    // Editing prompts 
    cout << "\nWhat would you like to edit?";
    cout << "\n(Name/Year/Nominations/Rating/Duration/Genre1/Genre2/Release/Metacritic/Synopsis)\n";
    cin >> edit;
    // Change edit based on user
    if (edit == "Name" || edit == "name") {
        // User enters a year
        cout << "\nEnter the edited movie name: ";
        getline(cin, update);
        getline(cin, update); // Count spaces 
        // Make old name, edited name
        updateName = update;
        goto Next; 
    } if (edit == "Year" || edit == "year") {
        // User enters a year
        cout << "\nEnter the edited year: ";
        cin >> update;
        cin.ignore(); // Ignore rest
        // Make old year, edited year
        updateYear = update;
        goto Next; 
    } if (edit == "Nominations" || edit == "nominations") {    
        // User enters an award
        cout << "\nEnter the edited number of nominations: ";
        cin >> update;
        cin.ignore(); // Ignore rest
        // Make old award, edited award        
        updateNom = update;
        goto Next;    
    } if (edit == "Rating" || edit == "rating") {
        // User enters a winner
        cout << "\nEnter the edited rating (out of 10): ";
        getline(cin, update);
        getline(cin, update); // Count if "."
        // Make old winner, edited winner  
        updateRate = update;
        goto Next;   
    } if (edit == "Duration" || edit == "duration") {
        // User enters a actor/actress name
        cout << "\nEnter the edited duration of movie (in minutes): ";
        cin >> update;
        cin.ignore(); // Ignore rest
        // Make old name, edited name   
        updateName = update;
        goto Next;   
    } if (edit == "Genre1" || edit == "genre1") {
        // User enters a film
        cout << "\nEnter the edited first genre: ";
        getline(cin, update);
        getline(cin, update); // Count spaces 
        // Make old film, edited film   
        updateGen1 = update;
        goto Next;
    } if (edit == "Genre2" || edit == "genre2") {
        // User enters a film
        cout << "\nEnter the edited second genre: ";
        getline(cin, update);
        getline(cin, update); // Count spaces 
        // Make old film, edited film   
        updateGen2 = update;
        goto Next;
    } if (edit == "Release" || edit == "release") {    
        // User enters a film
        cout << "\nEnter the edited month released: ";
        getline(cin, update);
        getline(cin, update); // Count spaces 
        // Make old film, edited film   
        updateRel = update;
        goto Next;
    } if (edit == "Metacritic" || edit == "metacritic")
    {   // User enters a film
        cout << "\nEnter the edited metacritic score (out of 100): ";
        getline(cin, update);
        getline(cin, update); // Count spaces 
        // Make old film, edited film   
        updateMeta = update;
        goto Next;
    } if (edit == "Synopsis" || edit == "synopsis") {      // User enters a film
        cout << "\nEnter the edited synopsis: ";
        getline(cin, update);
        getline(cin, update); // Count spaces 
        // Make old film, edited film   
        updateSyno = update;
        goto Next;
    } else {
        cout << "\nError in editing record. Try again.\n";
        goto Restart;
    }
    Next:
    // Replace old record with edited record
    FilmsList.erase(FilmsList.begin()+index);
    // Add to Films vector
    FilmsList.push_back(Films(updateName, updateYear, updateNom, updateRate, 
                          updateDur, updateGen1, 
                          updateGen2, updateRel, 
                          updateMeta, 
                          updateSyno));
    // Display new record
    cout << "\nNew Record:";
    cout << "\n{" << updateName;
    cout << ", " << updateYear;
    cout << ", " << updateNom;
    cout << ", " << updateRate;
    cout << ", " << updateDur;
    cout << ", " << updateGen1;
    cout << ", " << updateGen2;
    cout << ", " << updateRel; 
    cout << ", " << updateMeta;   
    cout << ", " << updateSyno << "}" <<endl;
    return;   
}

// (R6.2) Delete the selected record
void Database::deleteFilms(char searchMethod) {
    // Clear screen
    system("clear");
    // R6.2 title
    cout << "\nR6.2 – Delete the selected record.";
    // If vector is empty, try again
    if (FilmsList.empty()) {
        cout << "\n\nPlease save a file first.";
        return;
    }
    // Go here to retry inputs
    Retry:
    // For if record was found
    bool foundRec;
    // Get vector location
    int index = 1;
    // Go through records and search for name and year
    for (int i = 1; i < FilmsList.size(); i++) 
    {   // Make name in file into string to compare  
        string name = FilmsList[i].getName();
        string year = FilmsList[i].getYear();
        // Search for film and year
        size_t foundMovie = name.find(picFilm);
        size_t foundYear = year.find(picYear);        
        // If full name and year was found
        if (foundMovie != string::npos &&  foundYear != string::npos) {
            // Output actor-actress list to a console
            cout << "\n\n{" << FilmsList[i].getName();
            cout << ", " << FilmsList[i].getYear();
            cout << ", " << FilmsList[i].getNominations();        
            cout << ", " << FilmsList[i].getRating();
            cout << ", " << FilmsList[i].getGenre1();
            cout << ", " << FilmsList[i].getGenre2();
            cout << ", " << FilmsList[i].getRelease();
            cout << ", " << FilmsList[i].getMetacritic();
            cout << ", " << FilmsList[i].getSynopsis() <<  "}" <<endl;
            foundRec = true; // Record found
            index = i; // To get information later
        }
    } // Tell user record was found
    if (foundRec) {
        goto Restart;
    } else { // If record was not found or other error
        cout << "\n\nError finding record. Try again.\n";
        goto Retry;
    }
    Restart:
    char option;
    cout << "\nAre you sure you would like to delete this record? (y/n) ";
    cin >> option;
    // If option is yes, return to last function
    if (option == 'y' || option == 'Y') {
        goto Continue;
    } // If option is no, exit program
    if (option == 'n' || option == 'N') {
        return;
    } // Every other option is invalid
    else {
        cout << "Invalid option. Try again.";
        goto Restart;
    }
    Continue:
    // Erase record
    FilmsList.erase(FilmsList.begin()+index);
    // Tell user record was deleted
    cout << "\nRecord was deleted.\n";
    return; 
}

// Sorting ActorActress year comparator
bool Database::sortActorYear(ActorActress year1, ActorActress year2){
    return year1.getYear() < year2.getYear();
}

// Sorting ActorActress name comparator
bool Database::sortActorName(ActorActress actor1, ActorActress actor2){
    return actor1.getName() < actor2.getName();
}

// (R7) Sort Actor-Actress file
void Database::sortActorFile(ifstream& userFile) { 
    Restart:
    // Create sort by option
    char sortBy;
    // Ask user if they want to sort by year/name
    cout << "\n\nWould you like to sort by (Y)ear or (N)ame? ";
    cin >> sortBy;
    // If user selects sort by year
    if (sortBy == 'Y' || sortBy == 'y') {  
        // Output sorted vector to new file
        ofstream output("SortedActorYear.csv"); 
        sort(ActorActressList.begin(), ActorActressList.end(), sortActorYear);
        // Output by sorted year
        for (int i = 1; i < ActorActressList.size()-1; i++)
        {   // Excluding blanks and header
            output << ActorActressList[i].getYear();
            output << ", " << ActorActressList[i].getAward();
            output << ", " << ActorActressList[i].getWinner();        
            output << ", " << ActorActressList[i].getName();
            output << ", " << ActorActressList[i].getFilm() << endl;
        } // Add sorted list to a sorted vector
        sortedAAyear = ActorActressList;      
        cout << "\nThe actor-actress list is now in the output file: " 
              << "\nSortedActorYear.csv\n";
        // Close the file
        output.close();      
    } // If user selects sort by name
    else if (sortBy == 'N' || sortBy == 'n') {  
        // Output sorted vector to new file
        ofstream output("SortedActorName.csv");
        sort(ActorActressList.begin(), ActorActressList.end(), sortActorName);
        // Output by sorted year
        for (int i = 1; i < ActorActressList.size()-1; i++)
        {   // Excluding blanks and header
            output << ActorActressList[i].getYear();
            output << ", " << ActorActressList[i].getAward();
            output << ", " << ActorActressList[i].getWinner();        
            output << ", " << ActorActressList[i].getName();
            output << ", " << ActorActressList[i].getFilm() << endl;
        } // Add sorted list to a sorted vector
        sortedAAname = ActorActressList;  
        cout << "\nThe actor-actress list is now in the output file: " 
              << "\nSortedActorName.csv\n";
        // Close the file
        output.close();      
    } else { // Everything else is invalid
        cout << "\nInvalid input." << endl;
        goto Restart;
    }
    return;
}

// Sorting Films year comparator
bool Database::sortFilmsYear(Films year1, Films year2){
    return year1.getYear() < year2.getYear();
}

// Sorting Films name comparator
bool Database::sortFilmsName(Films actor1, Films actor2){
    return actor1.getName() < actor2.getName();
}

// (R8) Sort Films file
void Database::sortFilmsFile(ifstream& userFile) { 
    Restart:
    // Create sort by option
    char sortBy;
    // Ask user if they want to sort by year/name
    cout << "\n\nWould you like to sort by (Y)ear or (N)ame? ";
    cin >> sortBy;    
    // If user selects sort by year
    if (sortBy == 'Y' || sortBy == 'y') {  
        // Output sorted vector to new file
        ofstream output("SortedFilmsYear.csv");  
        sort(FilmsList.begin(), FilmsList.end(), sortFilmsYear);
        // Output by sorted year
        for (int i = 1; i < FilmsList.size()-1; i++)
        {   // Excluding blanks and header
            output << FilmsList[i].getName() << ","; 
            output << FilmsList[i].getYear() << ",";
            output << FilmsList[i].getNominations() << ",";
            output << FilmsList[i].getRating() << ",";
            output << FilmsList[i].getGenre1() << ","; 
            output << FilmsList[i].getGenre2() << ","; 
            output << FilmsList[i].getRelease() << ",";
            output << FilmsList[i].getMetacritic() << ",";     
            output << FilmsList[i].getSynopsis() << endl;
        } // Add sorted list to a sorted vector
        sortedFyear = FilmsList;
        cout << "\nThe films list is now in the output file: " 
              << "\nSortedFilmsYear.csv\n";
        // Close the file
        output.close();   
    } // If user selects sort by name
    else if (sortBy == 'N' || sortBy == 'n') {  
        // Output sorted vector to new file
        ofstream output("SortedFilmsName.csv");
        sort(FilmsList.begin(), FilmsList.end(), sortFilmsName);
        // Output by sorted name
        for (int i = 1; i < FilmsList.size()-1; i++)
        {   // Excluding blanks and header
            output << FilmsList[i].getName() << ","; 
            output << FilmsList[i].getYear() << ",";
            output << FilmsList[i].getNominations() << ",";
            output << FilmsList[i].getRating() << ",";
            output << FilmsList[i].getGenre1() << ","; 
            output << FilmsList[i].getGenre2() << ","; 
            output << FilmsList[i].getRelease() << ",";
            output << FilmsList[i].getMetacritic() << ",";     
            output << FilmsList[i].getSynopsis() << endl;
        } // Add sorted list to a sorted vector
        sortedFname = FilmsList;
        cout << "\nThe films list is now in the output file: " 
              << "\nSortedFilmsName.csv\n";
        // Close the file
        output.close();       
    } else { // Everything else is invalid
        cout << "\nInvalid input." << endl;
        goto Restart;
    }
    return;
}

// (R9) Save actor-actress list to output file
void Database::saveActorFile() {
    // Create an output file for contents
    ofstream output("OutputActors.csv");
    // Print out contents to file, except header
    for (int i = 1; i < ActorActressList.size()-1; i++)
    {   // Exclude blanks and header
        if (ActorActressList[i].getYear() != "") {
            // Output actor-actress list to a file
            output << ActorActressList[i].getYear();
            output << ", " << ActorActressList[i].getAward();
            output << ", " << ActorActressList[i].getWinner();        
            output << ", " << ActorActressList[i].getName();
            output << ", " << ActorActressList[i].getFilm() << endl;
        }
    }
    // Close file
    output.close();
    cout << "\n\nThe actor-actress list is now in the output file: " 
         << "OutputActors.csv\n";
    return;
}

// (R10) Save films list to output file
void Database::saveFilmsFile() {
    // Create an output file for contents
    ofstream output("OutputFilms.csv");
    // Print out contents to file, except header
    for (int i = 1; i < FilmsList.size()-1; i++) 
    {   // Exclude blanks and header
        if (FilmsList[i].getName() != "") {
            // Output films list to a file
            output << FilmsList[i].getName();
            output << ", " << FilmsList[i].getYear();
            output << ", " << FilmsList[i].getNominations();        
            output << ", " << FilmsList[i].getRating();
            output << ", " << FilmsList[i].getGenre1();
            output << ", " << FilmsList[i].getGenre2();
            output << ", " << FilmsList[i].getRelease();
            output << ", " << FilmsList[i].getMetacritic();
            output << ", " << FilmsList[i].getSynopsis() << endl;
        }
    }
    // Close file
    output.close();
    cout << "\n\nThe films list is now in the output file: " << "OutputFilms.csv\n";
    return;
}

// Function to process user's menu option
void Database::processOption(string userOption) {
    // If user's option is R1    
    if (userOption == "R1" || userOption == "r1") 
    {   // Clear screen
        system("clear");
        // R1 title
        cout << "\nR1 – Read in actors-actress data file and add them to\n"
             << "actors-actress list.\n";
        // Initialize correct file and user file
        string actorFile = "actor-actress.csv";  string userFile; 
        // Do-while file is correct
        do {   
            cout << "\nPlease enter the actors-actress data file: ";
            cin >> userFile;
            // Tell user file is invalid
            if (userFile != actorFile) {
                cout << "Invalid file. Try again. ";
            }
        } while (userFile != actorFile);
        // Read file
        cout << "\nReading file..." << endl;
        readActorFile(userFile);
        // Ask if user wants to continue
        askAgain();
        system("clear");
        return; 
    }
    // If user's option is R2
    if (userOption == "R2" || userOption == "r2") 
    {  // Clear screen
        system("clear");
        // R2 title
        cout << "\nR2 – Read in films data file and add them to films list.";
        // Initialize correct file and user file
        string filmsFile = "films.csv";
        string userFile;
        ifstream fileName;
        // Do-while file is correct
        do {   
            cout << "\n\nPlease enter the films data file: ";
            cin >> userFile;
            // Tell user file is invalid
            if (userFile != filmsFile) {
                cout << "Invalid file. Try again. ";
            }
        } while (userFile != filmsFile);
        // Read file
        cout << "\nReading file..." << endl;
        readFilmsFile(userFile);
        // Ask if user wants to continue
        askAgain();
        system("clear");
        return; 
    }
    // If user's option is R3
    if (userOption == "R3" || userOption == "r3") 
    {  // Clear screen
        system("clear");
        // R3 title
        cout << "\nR3 – Add a new record for actors-actress.";
        // If vector is empty, try again
        if (ActorActressList.empty()) {
            cout << "\n\nPlease save a file first.";
            return;
        }
        // Get new record from user
        newActorActress();
        // Ask if user wants to continue
        askAgain();
        system("clear");
        return; 
    }
    // If user's option is R4
    if (userOption == "R4" || userOption == "r4") 
    {   // Clear screen
        system("clear");
        // R4 title
        cout << "\nR4 – Add a new record for films.";
        // If vector is empty, try again
        if (FilmsList.empty()) {
            cout << "\n\nPlease save a file first.";
            return;
        }
        // Get new record from user
        newFilms();
        // Ask if user wants to continue
        askAgain();
        system("clear");
        return; 
    }
    // If user's option is R5
    if (userOption == "R5" || userOption == "r5") 
    {   // Clear screen
        system("clear");
        // R5 title
        cout << "\nR5 – Search for a record in actors-actress database by name.";
        cout << "\n(Case Sensitive)";
        // If vector is empty, try again
        if (ActorActressList.empty()) {
            cout << "\n\nPlease save a file first.";
            return;
        }
        // Search for record
        searchActorFile();
        // Ask if user wants to continue
        askAgain();
        system("clear");
        return; 
    }       
    // If user's option is R6
    if (userOption == "R6" || userOption == "r6") 
    {   // Clear screen
        system("clear");
        // R6 title
        cout << "\nR6 – Search for a record in films database by name.";
        cout << "\n(Case Sensitive)";
        // If vector is empty, try again
        if (FilmsList.empty()) {
            cout << "\n\nPlease save a file first.";
            return;
        }
        // Search for record
        searchFilmsFile();
        // Ask if user wants to continue
        askAgain();
        system("clear");
        return; 
    }     
    // If user's option is R7
    if (userOption == "R7" || userOption == "r7") 
    {   // Clear screen
        system("clear");
        // R7 title
        cout << "\nR7 – Sort the actor-actress database.";
        // If vector is empty, try again
        if (ActorActressList.empty()) {
            cout << "\n\nPlease save a file first.";
            return;
        }
        // Re-open updated file
        string userFile = "OutputActors.csv";
        ifstream fileName(userFile);
        // If user hasn't saved any edits
        if (!fileName.good()) {
            cout << "\n\nPlease make sure you have re-saved your newest updates (R9).";
            return;
        }
        // Sort the file and then close
        sortActorFile(fileName);
        fileName.close();
        // Ask if user wants to continue
        askAgain();
        system("clear");
        return; 
    }
    // If user's option is R8
    if (userOption == "R8" || userOption == "r8") 
    {   // Clear screen
        system("clear");
        // R8 title
        cout << "\nR8 – Sort the films database.";
        // If vector is empty, try again
        if (FilmsList.empty()) {
            cout << "\n\nPlease save a file first.";
            return;
        }
        // Re-open updated file
        string userFile = "OutputFilms.csv";
        ifstream fileName(userFile);
        // If user hasn't saved any edits
        if (!fileName.good()) {
            cout << "\n\nPlease make sure you have re-saved your newest updates (R10).";
            return;
        }
        // Sort the file and then close
        sortFilmsFile(fileName);
        fileName.close();
        // Ask if user wants to continue
        askAgain();
        system("clear");
        return; 
    } 
    // If user's option is R9
    if (userOption == "R9" || userOption == "r9")
    {   // Clear screen
        system("clear");
        // R9 title
        cout << "\nR9 – Save the actors-actress list into a csv file.";
        // If vector is empty, try again
        if (ActorActressList.empty()) {
            cout << "\n\nPlease read in a file first.";
            return;
        }
        // Call save file function
        saveActorFile();
        // Ask if user wants to continue
        askAgain();    
        system("clear");
        return;     
    }   
    // If user's option is R10
    if (userOption == "R10" || userOption == "r10") 
    {   // Clear screen
        system("clear");
        // R10 title
        cout << "\nR10 – Save films list into a csv file.";
        // If vector is empty, try again
        if (FilmsList.empty()) {
            cout << "\n\nPlease read in a file first.";
            return;
        }
        // Call save file function
        saveFilmsFile();
        // Ask if user wants to continue
        askAgain();   
        system("clear");
        return;      
    }       
    // If user's option is R11
    if (userOption == "R11" || userOption == "r11") 
    {   // Clear screen
        system("clear");
        // R11 title
        cout << "\nR11 – Display list of actors-actress on screen.";
        // If vector is empty, try again
        if (ActorActressList.empty()) {
            cout << "\n\nPlease save a file first.";
            return;
        }
        Retry:
        // Ask user what file they would like to display
        string theFile;
        cout << "\n\nWhat file would you like to display? ";
        cin >> theFile;
        // Open the file and collect records
        ifstream fileOpen(theFile);
        string record;
        // If file is OutputActors.csv
        if (theFile == "OutputActors.csv") {
            for (int i = 1; i < ActorActressList.size()-1; i++) 
            {   // Exclude blanks and header
                cout << ActorActressList[i].getYear();
                cout << ", " << ActorActressList[i].getAward();
                cout << ", " << ActorActressList[i].getWinner();        
                cout << ", " << ActorActressList[i].getName();
                cout << ", " << ActorActressList[i].getFilm() << endl;
            }
        } // If file is SortedActorYear.csv
        else if (theFile == "SortedActorYear.csv") {
            for (int i = 1; i < sortedAAyear.size()-1; i++) 
            {   // Exclude blanks and header
                cout << sortedAAyear[i].getYear();
                cout << ", " << sortedAAyear[i].getAward();
                cout << ", " << sortedAAyear[i].getWinner();        
                cout << ", " << sortedAAyear[i].getName();
                cout << ", " << sortedAAyear[i].getFilm() << endl;
            }
        } // If file is SortedActorName.csv
        else if (theFile == "SortedActorName.csv") {
            for (int i = 1; i < sortedAAname.size()-1; i++) 
            {   // Exclude blanks and header
                cout << sortedAAname[i].getYear();
                cout << ", " << sortedAAname[i].getAward();
                cout << ", " << sortedAAname[i].getWinner();        
                cout << ", " << sortedAAname[i].getName();
                cout << ", " << sortedAAname[i].getFilm() << endl;
            }
        } else { // Every other option is invalid
            cout << "\nInvalid input. Try again.";
            goto Retry;
        }
        // Ask if user wants to continue
        askAgain();  
        system("clear");
        return;       
    }   
    // If user's option is R12
    if (userOption == "R12" || userOption == "r12") 
    {   // Clear screen
        system("clear");
        // R12 title
        cout << "\nR12 – Display list of films on screen.";
        // If vector is empty, try again
        if (FilmsList.empty()) {
            cout << "\n\nPlease save a file first.";
            return;
        }
        Redo:
        // Ask user what file they would like to display
        string theFile;
        cout << "\n\nWhat file would you like to display? ";
        cin >> theFile;
        // Open the file and collect records
        ifstream fileOpen(theFile);
        string record;
        // If file is OutputFilms.csv
        if (theFile == "OutputFilms.csv") {
            for (int i = 1; i < FilmsList.size()-1; i++) 
            {   // Exclude blanks and header
                cout << FilmsList[i].getName();
                cout << ", " << FilmsList[i].getYear();
                cout << ", " << FilmsList[i].getNominations();
                cout << ", " << FilmsList[i].getRating();
                cout << ", " << FilmsList[i].getGenre1();
                cout << ", " << FilmsList[i].getGenre2();
                cout << ", " << FilmsList[i].getRelease();
                cout << ", " << FilmsList[i].getMetacritic();
                cout << ", " << FilmsList[i].getSynopsis() <<endl;
            }
        } // If file is SortedFilmsYear.csv
        else if (theFile == "SortedFilmsYear.csv") {
            for (int i = 1; i < sortedFyear.size()-1; i++) 
            {   // Exclude blanks and header
                cout << sortedFyear[i].getName();
                cout << ", " << sortedFyear[i].getYear();
                cout << ", " << sortedFyear[i].getNominations();
                cout << ", " << sortedFyear[i].getRating();
                cout << ", " << sortedFyear[i].getGenre1();
                cout << ", " << sortedFyear[i].getGenre2();
                cout << ", " << sortedFyear[i].getRelease();
                cout << ", " << sortedFyear[i].getMetacritic();
                cout << ", " << sortedFyear[i].getSynopsis() <<endl;
            }
        } // If file is SortedFilmsName.csv
        else if (theFile == "SortedFilmsName.csv") {
            for (int i = 1; i < sortedFname.size()-1; i++) 
            {   // Exclude blanks and header
                cout << sortedFname[i].getName();
                cout << ", " << sortedFname[i].getYear();
                cout << ", " << sortedFname[i].getNominations();        
                cout << ", " << sortedFname[i].getRating();
                cout << ", " << sortedFname[i].getGenre1();
                cout << ", " << sortedFname[i].getGenre2();
                cout << ", " << sortedFname[i].getRelease();
                cout << ", " << sortedFname[i].getMetacritic();
                cout << ", " << sortedFname[i].getSynopsis() <<endl;
            }
        } else { // Every other option is invalid
            cout << "\nInvalid input. Try again.";
            goto Redo;
        }
        // Ask if user wants to continue
        askAgain(); 
        system("clear");
        return;        
    }   
    // If user's option is Q
    if (userOption == "Q" || userOption == "q") {
        cout << "\nQuitting..." << endl;
        exit(0);
    }        
    // Every other option is invalid
    else {
        system("clear");
        cout << "Invalid option. Try again.";
        return;
    }
}