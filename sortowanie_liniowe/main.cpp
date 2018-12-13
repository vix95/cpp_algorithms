#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
typedef long typ;

using namespace std;

void SortowaniePrzezZliczanie(typ **zbior, typ **wyniki, typ n)
{
	typ *liczniki = new typ [n];

	//wczytaj liczby do tablicy zbioru
	for (typ i = 0; i < n; i++)
	{
		liczniki[i] = 0;
	}

	//dodawanie do licznika wlasnego wystapienia
	for (typ i = 0; i < n; i++)
	{
		liczniki[zbior[i][0]]++;
	}

	//zliczanie count -1
	for (typ i = 1; i < n; i++)
	{
		liczniki[i] = liczniki[i] + liczniki[i - 1];
	}

	//sortowanie
	for (typ i = n - 1; i >= 0; i--)
	{
		typ x = liczniki[zbior[i][0]];
		x--;
		wyniki[x][0] = zbior[i][0];
		wyniki[x][1] = zbior[i][1];
		liczniki[zbior[i][0]]--;
	}

	delete [] liczniki;
	
}

int main()
{
	typ n;

	scanf(" %d", &n);

	typ **zbior = new typ *[n];
	typ **wyniki = new typ *[n];

	//wczytaj liczby do tablicy zbioru
	for (typ i = 0; i < n; i++)
	{
		typ liczba1;
		typ liczba2;
		scanf(" %d%d", &liczba1, &liczba2);
		zbior[i] = new typ [2]; //alokacja pamieci
		zbior[i][0] = liczba1;
		zbior[i][1] = liczba2;
		wyniki[i] = new typ [2]; //alokacja pamieci
	}

	//rzodzaj testu
	int test;
	scanf(" %d", &test);
	SortowaniePrzezZliczanie(zbior, wyniki, n);

	//posrotowane rosnaco pierwsze wartosci z pary - wypisanie pierwszej wartosci z pary
	if (test == 0)
	{
		for (typ i = 0; i < n; i++)
		{
			cout << wyniki[i][0] << "\n";
		}
	}
	//posortowane rosnaco pierwsze wartosci z pary - wypisane pary rozdzielone przecinkiem
	else if (test == 1)
	{
		for (typ i = 0; i < n; i++)
		{
			cout << wyniki[i][0] << "," << wyniki[i][1] << "\n";
		}
	}

	for (int i = 0; i < n; i++)
	{
		delete [] zbior[i];
		delete [] wyniki[i];
	}

	delete [] zbior;
	delete [] wyniki;

	return 0;
}