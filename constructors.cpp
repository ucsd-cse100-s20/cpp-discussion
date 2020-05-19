#include <string>
#include <iostream>

using namespace std;

class Pokemon {
public:
    string name;
    string nickName;
    int pokedexIndex;
    int level;

    // constructor 1
    Pokemon(string n, int p, int l=1) : name(n), pokedexIndex(p), level(l), nickName(n), hp(l * 50) {}

    // constructor 2
    Pokemon(string n, int p, string nn,int l=1) : name(n), pokedexIndex(p), nickName(nn), level(l), hp(l * 50) {}

    // constructor 3 : user-defined default constructor, because all arguments have default values
    Pokemon(int l=1, int hpMultiplier=50) : level(l), hp(l*hpMultiplier), pokedexIndex(1), name("Bulbasaur"), nickName("Bulba") {}

    // for printing Pokemon info. We need "friend" modifier so it can access private fields like hp
    friend ostream& operator <<(ostream& os, const Pokemon& pokemon);

private:
    int hp;
};

ostream& operator <<(ostream& os, const Pokemon& pokemon) {
    os << "Pokemon: " << pokemon.name
       << " | Nickname: " << pokemon.nickName
       << " | Pokedex Index: " << pokemon.pokedexIndex << endl
	   << "\tLevel: " << pokemon.level << endl
	   << "\tHP: " << pokemon.hp << endl;
}

int main() {
    Pokemon pikachu1("Pikachu", 25);                    // this calls constructor #1 using the default 3rd parameter
    cout << pikachu1;

    Pokemon pikachu2("Pikachu", 25, 2);                 // this calls constructor #1 and overrides the default 3rd parameter
    cout << pikachu2;

    Pokemon pikachu3("Pikachu", 25, "CHUUUUUUUUUUU");   // this calls constructor #2 using the default 4th parameter
    cout << pikachu3;

    Pokemon pikachu4("Pikachu", 25, "Pika Pika", 5);    // this calls constructor #2 and overrides the default 4th parameter
    cout << pikachu4;

    Pokemon bulbasaur1;                                 // this calls our default constructor (#3) with the default parameters
    cout << bulbasaur1;

    Pokemon bulbasaur2(2);                              // this calls our default constructor (#3) but overrides the default 1st parameter
    cout << bulbasaur2;

    Pokemon bulbasaur3(3, 100);                         // this calls our default constructor (#3) but overrides both default parameters
    cout << bulbasaur3;
}
