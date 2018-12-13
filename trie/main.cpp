#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

const int WIELKOSC_ALFABETU = 26;
const int SIZE_ARRAY = 16;

using namespace std;

struct drzewoTRIE
{
	char ang;
	char pol[SIZE_ARRAY];
	bool czyKoniec;
	struct drzewoTRIE *dziecko[26]; //ilosc znakow w alfabecie
} *head;

void dodaj(char *ang, char *pl)
{
	drzewoTRIE *p = head;

	long poz = 0;
	do
	{
		int litera = int(ang[poz]) - 97;

		if (p->dziecko[litera] == nullptr)
		{
			p->dziecko[litera] = new drzewoTRIE();
		}

		p->dziecko[litera]->ang = ang[poz];
		p = p->dziecko[litera];
		poz++;
	} while (ang[poz] != NULL);

	p->czyKoniec = true;

	poz = 0;
	do
	{
		p->pol[poz] = pl[poz];
		poz++;
	} while (pl[poz] != NULL);

}

void wypisz(drzewoTRIE *&p, char *prefix, int &ind, int ilosc_znakow, bool &czyJest)
{
	if (p->czyKoniec == true)
	{
		//sprawdz czy ilosc znakow wyszukanego slowa jest wieksza rowna od ilosci znakow w prefixie
		if (ind >= ilosc_znakow)
		{
			czyJest = true;
			int i = 0;
			do
			{
				cout << p->pol[i];
				i++;
			} while (p->pol[i] != '\0');
			cout << "\n";
		}
	}

	//przelec przez caly alfabet
	for (int i = 0; i < WIELKOSC_ALFABETU; i++)
	{
		//jesli jest litera
		if (p->dziecko[i] != NULL)
		{
			//jesli sie dostatecznie zaglebilismy to bierz wszystko
			if (ind >= ilosc_znakow)
			{
				ind++;
				wypisz(p->dziecko[i], prefix, ind, ilosc_znakow, czyJest);
				ind--;
			}
			else if (p->dziecko[i]->ang == prefix[ind])
			{
				ind++;
				wypisz(p->dziecko[i], prefix, ind, ilosc_znakow, czyJest);
				ind--;
			}
		}
	}
}

void znajdz(drzewoTRIE *head, char *ang)
{
	//dlugosc slowa
	int count = 0;
	do
	{
		count++;
	} while (ang[count] != '\0');

	drzewoTRIE *p = head;
	for (int i = 0; i < count; i++)
	{
		int litera = int(ang[i]) - 97;
		if (p->dziecko[litera] == NULL)
		{
			//nie znaleziono
			cout << "-";
			return;
		}
		p = p->dziecko[litera];
	}

	if (p->czyKoniec == false)
	{
		//jednak nie ma
		cout << "-";
		return;
	}

	for (int i = 0; i < SIZE_ARRAY; i++)
	{
		if (p->pol[i] == '\0') break;
		cout << p->pol[i];
	}

	return;
}

void zwolnijDrzewo(drzewoTRIE *&p)
{
	//sprawdz czy wskaznik nie jest pusty
	if (p != nullptr)
	{
		for (int i = 0; i < WIELKOSC_ALFABETU; i++)
		{
			if (p->dziecko[i] != nullptr)
			{
				zwolnijDrzewo(p->dziecko[i]);
			}
			else delete p->dziecko[i];
		}
		delete p;
	}
}

int main()
{
	head = new drzewoTRIE();
	head->czyKoniec = false;

	char *polecenie = new char[35];

	while (cin >> polecenie)
	{
		char *cmd = polecenie;
		if (*cmd == '+')
		{
			char *ang = new char[SIZE_ARRAY];
			char *pl = new char[SIZE_ARRAY];
			cin >> ang;
			cin >> pl;
			dodaj(ang, pl);
			delete[] ang;
			delete[] pl;
		}
		else if (*cmd == '?')
		{
			char *ang = new char[SIZE_ARRAY];
			cin >> ang;
			znajdz(head, ang);
			cout << "\n";
			delete[] ang;
		}
		else if (*cmd == '*')
		{
			char *prefix = new char[SIZE_ARRAY];
			cin >> prefix;

			//zlicz ilosc znakow w prefixie
			int i = 0;
			do
			{
				i++;
			} while (prefix[i] != '\0');

			bool czyJest = false; //marker, jesli nie znalazl ani jednego slowa to bedzie na false
			int ind = 0;
			wypisz(head, prefix, ind, i, czyJest);

			if (czyJest == false) cout << "-\n";

			delete[] prefix;
		}
	}

	zwolnijDrzewo(head);
	delete[] polecenie;

	return 0;
}