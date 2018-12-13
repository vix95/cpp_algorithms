#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct Drzewo
{
	Drzewo* prawy;
	Drzewo* lewy;
	int liczba;
	int a;
	int b;
	int minimum;
	int maksimum;
};

void umiesc(int liczba, int a, int b, int i, Drzewo *p)
{
	int sr = (a + b) / 2; //srodkowa pozycja

	//szukamy wolnego wskaznika
	//jesli indeks jest wiekszy od polowy to umiesc go po prawej czesci
	if (i > sr)
	{
		if (a == b)
		{
			//ostatni lisc
			p->liczba = liczba;
			return;
		}
		else if (p->prawy == nullptr)
		{
			Drzewo *e = new Drzewo;
			e->a = sr + 1;
			e->b = b;
			e->lewy = nullptr;
			e->prawy = nullptr;
			e->minimum = -1;
			e->maksimum = -1;
			e->liczba = -1;

			p->prawy = e;
		}

		//sprawdzamy rekurencyjnie, czy mamy koniec przedzialu
		umiesc(liczba, sr + 1, b, i, p->prawy);
	}
	//jesli jest mniejszy od polowy to po lewej
	else if (i <= sr)
	{
		if (a == b)
		{
			//ostatni lisc
			p->liczba = liczba;
			return;
		}
		else if (p->lewy == nullptr)
		{
			Drzewo *e = new Drzewo;
			e = new Drzewo;
			e->a = a;
			e->b = sr;
			e->lewy = nullptr;
			e->prawy = nullptr;
			e->minimum = -1;
			e->maksimum = -1;
			e->liczba = -1;

			p->lewy = e;
		}

		//sprawdzamy rekurencyjnie, czy mamy koniec przedzialu
		umiesc(liczba, a, sr, i, p->lewy);
	}
}

void wpisz_przedzialy(int a, int b, Drzewo *p)
{
	if ((p->lewy != nullptr) && (p->prawy != nullptr))
	{
		wpisz_przedzialy(a, (a + b) / 2, p->lewy);
		wpisz_przedzialy((a + b) / 2 + 1, b, p->prawy);

		if (p->lewy->minimum > p->prawy->minimum)
		{
			p->minimum = p->prawy->minimum;
		}
		else
		{
			p->minimum = p->lewy->minimum;
		}

		if (p->lewy->maksimum > p->prawy->maksimum)
		{
			p->maksimum = p->lewy->maksimum;
		}
		else
		{
			p->maksimum = p->prawy->maksimum;
		}
	}
	else
	{
		p->minimum = p->liczba;
		p->maksimum = p->liczba;
	}
}

void wyszykaj_przedzialy(int a, int b, Drzewo *p, int &c, char typ)
{
	int sr = (p->a + p->b) / 2;

	//minimum
	if (typ == '-')
	{
		if ((a == p->a) && (b == p->b)) c = p->minimum;
		else
		{
			if ((a >= p->a) && (b <= sr)) wyszykaj_przedzialy(a, b, p->lewy, c, '-');
			else if ((a > sr) && (b <= p->b)) wyszykaj_przedzialy(a, b, p->prawy, c, '-');
			else
			{
				int aa;
				wyszykaj_przedzialy(a, sr, p->lewy, aa, '-');
				int bb;
				wyszykaj_przedzialy(sr + 1, b, p->prawy, bb, '-');

				if (bb > aa) c = aa;
				else c = bb;
			}
		}
	}
	//maksimum
	else if (typ == '+')
	{
		if ((a == p->a) && (b == p->b)) c = p->maksimum;
		else
		{
			if ((a >= p->a) && (b <= sr)) wyszykaj_przedzialy(a, b, p->lewy, c, '+');
			else if ((a > sr) && (b <= p->b)) wyszykaj_przedzialy(a, b, p->prawy, c, '+');
			else
			{
				int aa;
				wyszykaj_przedzialy(a, sr, p->lewy, aa, '+');
				int bb;
				wyszykaj_przedzialy(sr + 1, b, p->prawy, bb, '+');

				if (aa > bb) c = aa;
				else c = bb;
			}
		}
	}
}

void czysc(Drzewo *p)
{
	if (p->prawy != nullptr) czysc(p->prawy);
	if (p->lewy != nullptr) czysc(p->lewy);
	delete p;
}

int main()
{
	//tworzymy korzen
	Drzewo *p = new Drzewo;
	p->lewy = NULL;
	p->prawy = NULL;
	p->liczba = -1;
	p->minimum = -1;
	p->maksimum = -1;

	int ilosc;
	scanf(" %d", &ilosc);

	//rozmiar tablicy
	int size = 0;
	for (int i = 0; i < ilosc; i++)
	{
		size = size + 2 * 2;
	}

	p->a = 0; //otwarcie przedzialu
	p->b = size - 1; //zamkniecie przedzialu

	//wczytywanie
	int *Stos = new int[size];
	for (int i = 0; i < ilosc; i++)
	{
		int liczba;
		scanf(" %d", &liczba);
		Stos[i] = liczba;
	}

	//ukladanie przedzialami w Drzewie
	for (int i = 0; i < size; i++)
	{
		umiesc(Stos[i], 0, size - 1, i, p);
	}

	//wpisywanie przedzialow
	wpisz_przedzialy( 0, size - 1, p);

	scanf(" %d", &ilosc);
	for (int i = 0; i < ilosc; i++)
	{
		int a;
		int b;
		scanf(" %d", &a);
		scanf(" %d", &b);

		//szukamy przedzialami - krotszy czas wykonywania
		int c;
		wyszykaj_przedzialy(a, b, p, c, '-');
		cout << c << " ";
		wyszykaj_przedzialy(a, b, p, c, '+');
		cout << c << '\n';
	}

	//czyscimy
	delete[] Stos;
	czysc(p);
	p = nullptr;

	return 0;
}
