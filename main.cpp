// Kontenery
#include <vector>	// Tablica
#include <set>		// Zbiór
#include <map>		// Słownik

// Adaptery
#include <queue>	// Kolejka
#include <stack>	// Stos

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "Slav.h"

#define REPORT_ADAPTERS showMeAdapterSizes(queueOfSlavs,stackOfSlavs)
#define REPORT_CONTAINERS showMeContainerSizes(vectorOfSlavs,setOfSlavs,mapOfSlavs)

using namespace std;

void showMeContainerSizes(vector <Slav *>, set <Slav *>, map <Slav *, Slav*>);
void showMeAdapterSizes(queue <Slav *>, stack <Slav *>);

void containers(Slav *, int);
void adapters(Slav *, int);

int main(int argc, char const *argv[])
{
	int n = 2 * atoi(argv[1]);
	Slav *slavs = new Slav[n];
	cout << "# Generated Slavs" << endl;
	for (int i = 0; i < n; ++i)
		cout << slavs[i].description() << endl;

	containers(slavs, n);
	adapters(slavs, n);

	delete [] slavs;
}

void containers(Slav * slavs, int n)
{
	vector <Slav *> vectorOfSlavs;
	set <Slav *> setOfSlavs;
	map <Slav *, Slav *> mapOfSlavs;

	vector<Slav *>::iterator v_it_slv;
    set<Slav *>::iterator s_it_slv;
    map<Slav *, Slav *>::iterator m_it_slv;

	printf("# Containers\n");
	REPORT_CONTAINERS;
	printf("## vector\n");

	// Umieść Słowian w losowej kolejności w wektorze.
	for(int i(0); i < n; i++)
    {
        v_it_slv = vectorOfSlavs.begin() + rand() % (vectorOfSlavs.size() + 1);
        vectorOfSlavs.insert(v_it_slv, &slavs[i]);
    }

	// Wykorzystując iterator i funkcję description(), wyświetl wszystkich Słowian w wektorze
    for(v_it_slv = vectorOfSlavs.begin(); v_it_slv != vectorOfSlavs.end(); v_it_slv++)
        vectorOfSlavs[vectorOfSlavs.begin() - v_it_slv]->description();
	REPORT_CONTAINERS;
	printf("## set\n");

	// Przenieś wszystkich Słowian z wektoru do zbioru.
    for(int i(0); i < n; i++)
        setOfSlavs.insert(s_it_slv++, vectorOfSlavs[n]);
    //vectorOfSlavs.clear();
	REPORT_CONTAINERS;
	printf("## map\n");

	// Stwórz słownik tworzący pary Słowian, z tych znajdujących się w zbiorze, czyszcząc zbiór
    s_it_slv = setOfSlavs.begin();
    for(int i(0); i < n/2; i++)
    {
        mapOfSlavs.insert(pair<Slav *, Slav *>(*setOfSlavs.begin(), *setOfSlavs.begin() + 1));
        setOfSlavs.erase(setOfSlavs.begin());
        setOfSlavs.erase(setOfSlavs.begin());
    }

	// Wykorzystując iterator, wyświetl wszystkie pary Słowian
	for(m_it_slv = mapOfSlavs.begin(); m_it_slv != mapOfSlavs.end(); m_it_slv++)
        printf("%s - %s\n", (m_it_slv->first)->description(), (m_it_slv->second)->description());//#############################################################################################
	REPORT_CONTAINERS;
}

void adapters(Slav * slavs, int n)
{
	queue <Slav *> queueOfSlavs;
	stack <Slav *> stackOfSlavs;

	printf("# Adapters\n");
	REPORT_ADAPTERS;
	printf("## queue\n");

	// Umieść Słowian w kolejce.
    for(int i(0); i < n; i++)
        queueOfSlavs.push(&slavs[i]);
	REPORT_ADAPTERS;

	printf("## stack\n");
	// Przenieś Słowian z kolejki do stosu.
    for(int i(0); i < n; i++)
    {
        stackOfSlavs.push(queueOfSlavs.back());
        queueOfSlavs.pop();
    }
	REPORT_ADAPTERS;

	// Wyświetl Słowian zdejmowanych ze stosu.
    for(int i(0); i < n; i++)
    {
        printf("%s", (stackOfSlavs.top())->description());
        stackOfSlavs.pop();
    }
	REPORT_ADAPTERS;
}

void showMeContainerSizes(vector <Slav *> vector, set <Slav *> set, map <Slav *, Slav*> map)
{
	printf("[vector_size = %lu, set_size = %lu, map_size = %lu, existingSlavs = %i]\n",
		vector.size(),
		set.size(),
		map.size(),
		Slav::counter());
}

void showMeAdapterSizes(queue <Slav *> queue, stack <Slav *> stack)
{
	printf("[queue_size = %lu, stack_size = %lu, existingSlavs = %i]\n",
		queue.size(),
		stack.size(),
		Slav::counter());

}
