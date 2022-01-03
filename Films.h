#ifndef FILMS_H
#define FILMS_H

using namespace std;

class Films {
    public:
        Films();
        Films(string name, string year,  string nominations, string rating, string duration, string genre1, string genre2, string release, string metacritic, string synopsis);
        // Get functions
        string getName() {return name;}
        string getYear() {return year;}
        string getNominations() {return nominations;}
        string getRating() {return rating;}
        string getDuration() {return duration;}
        string getGenre1() {return genre1;}
        string getGenre2() {return genre2;}
        string getRelease() {return release;}
        string getMetacritic() {return metacritic;}
        string getSynopsis() {return synopsis;} 
    private:
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
};

#endif /* FILMS_H */