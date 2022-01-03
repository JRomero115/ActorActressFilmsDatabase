#ifndef ACTORACTRESS_H
#define ACTORACTRESS_H

using namespace std;

struct ActorActress {
    public:
        ActorActress();
        ActorActress(string Year, string Award, string Winner, string Name, string Film);
        // Get functions
        string getYear() {return Year;}
        string getAward() {return Award;}
        string getWinner() {return Winner;} 
        string getName() {return Name;}
        string getFilm() {return Film;}        
    private:
        string Year;
        string Award;
        string Winner; 
        string Name;
        string Film;        
};

#endif /* ACTORACTRESS_H */