#include <iostream>

#include "Database.h"

using namespace std;

/***************************************************
* Summary: Actor/Actress & Films Database
*
*   Create a database of actors, actresses, and films. 
*   Show a main menu screen with 12 menu options ranging 
*   from reading, saving, editing/deleting, and printing 
*   a file based on the chosen database.
*
* Author: Janine Romero
* Created: November 14th, 2021
****************************************************/

// Main menu screen
void mainMenu() 
{
    cout << "\n~= Actor/Actress & Films Database =~\n" << endl;
    cout << "R1 – Read in actors-actress data file and add them to\nactors-actress list." <<
    "\nR2 – Read in films data file and add them to films list." <<
    "\nR3 – Add a new record for actors-actress." << 
    "\nR4 – Add a new record for films." <<   
    "\nR5 – Search for a record in actors-actress database by name." <<   
    "\nR6 – Search for a record in films database by name." <<     
    "\nR7 – Sort the actors-actress database." << 
    "\nR8 – Sort the films database." <<    
    "\nR9 – Save the actors-actress list into a csv file." <<
    "\nR10 – Save films list into a csv file." << 
    "\nR11 – Display list of actors-actress on screen." <<
    "\nR12 – Display list of films on screen." << 
    "\nQ - Quit" << endl;
    cout << "\nEnter option: ";
}

// Main test driver
int main() {
    // Delete past files just in case
    remove("OutputActors.csv");
    remove("OutputFilms.csv");
    remove("SortedActorYear.csv");
    remove("SortedActorName.csv");
    remove("SortedFilmsYear.csv");
    remove("SortedFilmsName.csv");    
    // Create objects
    Database menuOption;
    string option;
    // Print menu options
    do {
        // Show main menu
        mainMenu();
        // Read in user option
        std::cin >> option;
        // Call process option
        menuOption.processOption(option);
        cout << endl;
    // Continue asking until option is "Q"
    } while (option != "Q" || option != "q");
}