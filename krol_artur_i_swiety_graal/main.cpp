#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct lista
{
	lista *kolejny;
	int cel;
	int droga;
};

void sciezka(int n, bool *&zbior, int *&Koszt_dojscia, lista **Mapa, int *&Poprzednicy, int koszt_drogi_krzaka, int ni)
{
	lista *p;
	int osada = 0;
	int ind;

	for (int i = 0; i < n; i++)
	{
		//szukamy pierwszego nieodwiedzonego wierzcholka
		ind = 0;
		while (zbior[ind] == true)
		{
			ind++;
		}

		//szukamy kolejnej osady
		osada = ind; //osada to ostatni odwiedzony wierzcholek

		//szukamy po wszystkich wierzcholkach
		while (ind < n)
		{
			//jesli jest nieodwiedzony
			if (zbior[ind] == false)
			{
				//jesli koszt dojscia do tego wierzcholka jest mniejszy
				//niz koszt dojscia do pierwszej napotkanej osady to mamy osade
				//o mniejszym koszcie dojscia
				if (Koszt_dojscia[ind] < Koszt_dojscia[osada]) osada = ind;
			}

			ind++;
		}

		zbior[osada] = true; //osada zostala odwiedzona

		//zmieniamy wagi sasiednich wierzcholkow
		p = Mapa[osada];
		while (p != nullptr)
		{
			//dla drugiego wywolania
			//dodanie kosztu drogi po krzak
			if ((koszt_drogi_krzaka != 0) && (p->cel == ni))
			{
				p->droga = p->droga + koszt_drogi_krzaka;
			}

			//jesli osada nie zostala jeszcze odwiedzona
			if (zbior[p->cel] == false)
			{
				//wiekszy koszt mozna zastapic mniejszym
				if (Koszt_dojscia[p->cel] > Koszt_dojscia[osada] + p->droga)
				{
					Koszt_dojscia[p->cel] = Koszt_dojscia[osada] + p->droga;
					Poprzednicy[p->cel] = osada;
				}
			}

			p = p->kolejny;
		}
	}
}

int main()
{
	int n; //liczba osad
	int k; //czas na pokonanie czarnego rycerza
	scanf(" %d %d", &n, &k);

	int *Koszt_dojscia = new int[n];
	int *Poprzednicy = new int[n];
	bool *zbior = new bool[n];
	lista **Mapa = new lista *[n]; //tablica list sasiedztwa
	lista *p;
	int *Stos = new int[n];
	int poz = 0; //wskaznik w stosie

	for (int i = 0; i < n; i++)
	{
		Koszt_dojscia[i] = 9999;
		Poprzednicy[i] = -1;
		zbior[i] = false;
		Mapa[i] = NULL;
	}

	int zamek;
	int graal;
	int ni = -1;
	int krzak = -1;

	//wczytywanie
	for (int i = 0; i < n; i++)
	{
		//0 - zwyczajna osada
		//1 - sprzedawca krzakow
		//2 - obozowisko Czarnego Rycerza
		//3 - postój Rycerzy Mowiacych Ni
		//4 - zamek krola Artura(skad wyrusza na swoja misje)
		//5 - ukryty Swiety Graal

		int typ; //typ osady
		int m; //ilosc drog wychodzacych z osady
		scanf(" %d %d", &typ, &m);

		for (int j = 0; j < m; j++)
		{
			int osada_docelowa;
			int czas_drogi;

			scanf(" %d %d", &osada_docelowa, &czas_drogi);

			if (typ == 2) czas_drogi = czas_drogi + k; //Czarny rycerz - plus czas na jego pokonanie
			if (typ == 5) graal = i; //wezel koncowy - graal
			if (typ == 4) zamek = i; //wezel startowy - zamek krola artura
			if (typ == 3) ni = i;
			if (typ == 1) krzak = i;

			p = new lista;
			p->cel = osada_docelowa;
			p->droga = czas_drogi;
			p->kolejny = Mapa[i]; //i - wierzcholek, z ktorego wychodza drogi
			Mapa[i] = p;
		}
	}

	//jesli istnieja ni to zlicz ich koszt w razie potrzeby przejscia przez nich
	int *Koszt_dojsciaNI = new int[n];
	int *PoprzednicyNI = new int[n];
	int *StosNI = new int[n];
	bool *zbiorNI = new bool[n];
	int pozNI = 0; //wskaznik w stosie
	int koszt_drogi_krzaka = 0;

	for (int i = 0; i < n; i++)
	{
		Koszt_dojsciaNI[i] = 9999;
		PoprzednicyNI[i] = -1;
		zbiorNI[i] = false;
	}

	//jesli mamy osade z NI to sprawdzamy koszt drogi
	if (ni != -1)
	{
		Koszt_dojsciaNI[ni] = 0; //punkt startowy
		sciezka(n, zbiorNI, Koszt_dojsciaNI, Mapa, PoprzednicyNI, koszt_drogi_krzaka, ni);

		//ukladanie w stosie
		for (int j = krzak; j > -1; j = PoprzednicyNI[j])
		{
			StosNI[pozNI] = j;
			koszt_drogi_krzaka = koszt_drogi_krzaka + Koszt_dojsciaNI[j];
			pozNI++;
		}

		//koszt walki z czarnym rycerzem tez jest pomnozony * 2
		koszt_drogi_krzaka = koszt_drogi_krzaka * 2;
	}

	Koszt_dojscia[zamek] = 0; //punkt startowy
	sciezka(n, zbior, Koszt_dojscia, Mapa, Poprzednicy, koszt_drogi_krzaka, ni);

	//porzadkowanie w stosie
	for (int i = graal; i > -1; i = Poprzednicy[i])
	{
		Stos[poz] = i;
		poz++;
	}

	//wypisywanie
	while (poz != 0)
	{
		poz--;

		//jesli natrafiamy na osade ni, to wypisz sciezke od ni do krzaka
		if (Stos[poz] == ni)
		{
			while (pozNI != 0)
			{
				pozNI--;
				cout << StosNI[pozNI] << " ";
			}

			//i spowrotem
			pozNI++;
			while (StosNI[pozNI] >= 0)
			{
				cout << StosNI[pozNI] << " ";
				pozNI++;
			}
		}
		else cout << Stos[poz] << " ";

	}

	//czyszczenie
	delete[] Koszt_dojscia;
	delete[] Poprzednicy;
	delete[] zbior;
	delete[] Stos;

	delete[] Koszt_dojsciaNI;
	delete[] PoprzednicyNI;
	delete[] zbiorNI;
	delete[] StosNI;

	for (int i = 0; i < n; i++)
	{
		p = Mapa[i];
		while (p != nullptr)
		{
			lista *e = p;
			p = p->kolejny;
			delete e;
		}
	}
	delete[] Mapa;

	return 0;
}