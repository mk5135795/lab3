#pragma once
#include <string>
#include <vector>

using namespace std;

class Slav
{
private:
	static void init();

	static std::vector <string> names;
	static int _counter;
	static map<gender, Slav *> sex_map;

	string _name;
	int _id;

public:

	Slav();

	static int counter() { return _counter; }
	static vector<Slav *> get_sex_vec(sex g);

	string name() { return _name; }
	int id() { return _id; }
    enum sex {male, female};

	string description();
	sex gender();
};
