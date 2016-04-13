#include "Slav.h"
#include <fstream>

using namespace std;

vector <string> Slav::names;
int Slav::_counter = 0;

void Slav::init()
{
	srand(time(NULL));
	ifstream file("names.dat");
	copy(istream_iterator<string>(file),
		istream_iterator<string>(),
		back_inserter(names));
	file.close();
}

Slav::Slav()
{
	static int amountOfNames = (init(), names.size());
	//Deklarowana jest zmienna statyczna czyli taka która istnieje "do konca"
	//tzn nawet po wyjsciu z bliku w ktorym zostala zadeklarowana wciaz znajduje sie na stosie
	//wciaz mozna sie do niej odwolac tylko w obrebie bloku w ktorym zostala zadeklarowana.
	//najpierw wywoływana jest funkcja modyfikująca zmienna name,
	//a nastepnie zmiennej przypisywana jest wartosc name.size()
	//tzw leniwa inicjalizacja
	//jako ze zmienna jest statyczna cala definicja wykonywana jest tylko raz,
	//wiec dzieki polaczeniu funkcji operatorem(), obydwie sa wykonywane tylko raz
	//obydwie sa ze soba powiazane i nie ma potrzeby wywolywac i przypisywac ich wielokrotnie
	//zmienna jest definiowana ale uznalem ze przejzysciej bedzie podzielic ja na deklaracje i inicjalizacje
	_name = names[rand() % amountOfNames];
	_id = _counter++;
	sex_map.insert(pair<gender, Slav *>(this->gender(), this);
}

vector<Slav *> Slav::get_sex_vec(sex g){
    vector<Slav *> tmp;
    for(map<gender, Slav *>::iterator i(sex_map.begin()); i != sex_map.end(); i++)
        if(i->first == g)
            tmp.push_back(i->second);
    return tmp;
}

sex Slav::gender(){
    return (_name.back() == 'e' || _name.back() == 'a') ? female : male;
}

string Slav::description()
{
	return string("  ") + _name + " [" + to_string(_id) + "]";
}
