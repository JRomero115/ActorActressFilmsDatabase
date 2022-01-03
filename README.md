****
*   **Name     :** Janine Romero
*   **Student ID:** 109385593
*   **Class     :** CSCI 2421
*   **Due Date  :** December 10th, 2021

# Read Me
## Description of the program: *Actor/Actress & Films Database*
Create a database of actors, actresses, and films. Show a main menu screen with 12 menu options ranging from reading, searching, editing/deleting, sorting, and outputting a selected file.

## Source files
- ***main.cpp***
Main program. This test driver program calls sub-functions from other files to display the results in the console.
- ***ActorActress.h***
Contains the *ActorActress* class.
- ***ActorActress.cpp***
Source code file from referenced *ActorActress.h* which initializes variables from the actor-actress.csv file.
- ***Database.h***
Contains the *Database* class.
- ***Database.cpp***
Source code file from referenced *Database.h* that contains the definitions of the read, save, new, and other functions: 

    void readActorFile(string userFile)
    void readFilmsFile(string userFile)

    void saveActorFile() 
    void saveFilmsFile()

    void newActorActress()
    void newFilms()

    void searchActorFile();
    void searchFilmsFile();

    void editActor(char searchMethod);
    void editFilms(char searchMethod);

    void deleteActor(char searchMethod);
    void deleteFilms(char searchMethod);

    void sortActorFile(ifstream& userFile);
    void sortFilmsFile(ifstream& userFile);  

    static bool sortActorYear(ActorActress year1, ActorActress year2);
    
    static bool sortActorName(ActorActress actor1, ActorActress actor2);
    
    static bool sortFilmsYear(Films year1, Films year2);
    
    static bool sortFilmsName(Films actor1, Films actor2);              

    void processOption(string userOption)

    void askAgain()

- ***Films.h***
Contains the *Films* class and getter functions for variables.
- ***Films.cpp***
Source code file from referenced *Films.h* which initializes variables from the pictures.csv file.

##  Circumstances of Programs

The program runs successfully. The program was developed and tested on gnu g++ 4.4.2. It was compiled, run, and tested on gcc ouray.cudenver.edu.

##  How to build and run the program
1. Begin by changing the directory and listing the files

        $ cd RomeroJanine_Phase3
        $ ls

1.  Uncompress the homework.  The homework file is compressed. To uncompress it use the following commands:

        $ unzip RomeroJanine_Phase3.zip 
        $ ls

2.  Build the program. Change to the directory that contains the file by:

        $ cd Phase3
        $ ls

Now you should see a directory named homework with the files:

    main.cpp

    actor-actress.csv

    ActorActress.h

    ActorActress.cpp

    Database.h

    Database.cpp

    films.csv

    Films.h

    Films.cpp

    makefile

    README.txt

3. Compile the program by:

        $ ls
        $ g++ -o phase3 main.cpp ActorActress.cpp Database.cpp Films.cpp

4.  Run the program by:

        $ ./phase3

5.  Delete the obj files, executables, and core dump by:

        $ ./make clean
