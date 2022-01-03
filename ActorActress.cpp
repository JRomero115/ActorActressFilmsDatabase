#include <iostream>

#include "ActorActress.h"

// Initialize variables as nothing
ActorActress::ActorActress() 
{
    Year = "";
    Award = "";
    Winner = "";
    Name = "";
    Film = "";
}

// Assign variables to those in file
ActorActress::ActorActress(string Year, string Award, string Winner, string Name, string Film) {
    this->Year = Year;   
    this->Award = Award;
    this->Winner = Winner;
    this->Name = Name;
    this->Film = Film;
}