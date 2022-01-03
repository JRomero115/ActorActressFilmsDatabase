#include <iostream>

#include "Films.h"

// Initialize variables as nothing
Films::Films() 
{
    name = "";
    year = "";
    nominations = "";
    rating = "";
    duration = "";
    genre1 = "";
    genre2 = "";
    release = "";
    metacritic = "";
    synopsis = "";   
}

// Assign variables to those in file
Films::Films(string name, string year,  string nominations, string rating, string duration, string genre1, string genre2, string release, string metacritic, string synopsis) {
    this->name = name;
    this->year = year;
    this->nominations = nominations;
    this->rating = rating;
    this->duration = duration;
    this->genre1 = genre1;
    this->genre2 = genre2;
    this->release = release;
    this->metacritic = metacritic;
    this->synopsis = synopsis;   
}