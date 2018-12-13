#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct listaJednokierunkowa
{
	listaJednokierunkowa *kolejny;
	int wartosc;
};

void umiesc(listaJednokierunkowa *&head, int liczba)
{
	listaJednokierunkowa *n = new listaJednokierunkowa;
	n->wartosc = liczba;
	n->kolejny = head;
	head = n;
}

void wypisz(listaJednokierunkowa *head)
{
	while (head)
	{
		cout << head->wartosc << " ";
		head = head->kolejny;
	}
	cout << "\n";
}

void zamien(listaJednokierunkowa *&head)
{
	listaJednokierunkowa *e;
	listaJednokierunkowa *temp;

	e = head->kolejny;
	temp = e->kolejny;
	e->kolejny = head;
	head->kolejny = temp;
	head = e;
}

void zdejmij(listaJednokierunkowa *&head)
{
	if (head)
	{
		listaJednokierunkowa *e = head;
		head = head->kolejny;
		delete e;
	}
}

void sumuj(listaJednokierunkowa *&head)
{
	listaJednokierunkowa *p;
	int sumuj;
	p = head;
	sumuj = p->wartosc;
	zdejmij(head);
	p = head;
	sumuj = sumuj + p->wartosc;
	head->wartosc = sumuj;
}

void przenies(listaJednokierunkowa *&head, int poprzednia)
{
	listaJednokierunkowa *p;

	int przenoszony;
	int pamiec[100];

	//zawsze zdejmujemy wierzcholek
	p = head;
	przenoszony = p->wartosc;
	zdejmij(head);

	for (int i = 0; i < poprzednia - 1; i++)
	{
		p = head;
		pamiec[i] = p->wartosc;
		zdejmij(head);
	}

	umiesc(head, przenoszony);

	for (int i = poprzednia - 1; i > 0; i--)
	{
		umiesc(head, pamiec[i - 1]);
	}
}

int main()
{
	listaJednokierunkowa *lista;
	lista = nullptr;

	char polecenie = NULL;
	int poprzednia = NULL;

	while (polecenie = fgetc(stdin))
	{
		bool czyLiczba = false;
		int liczba = NULL;
		if (polecenie >= 48 && polecenie <= 57)
		{
			czyLiczba = true;
			liczba = polecenie - 48;
			while (polecenie = fgetc(stdin))
			{
				if (polecenie == ' ' || polecenie == '\n') break;
				liczba = liczba * 10 + (polecenie - 48);
			}
			poprzednia = liczba;
		}

		char znak = polecenie;

		//liczba - wlozenie na liste
		if (czyLiczba == true)
		{
			umiesc(lista, liczba);
		}
		//p - wypisanie
		else if (znak == 'p')
		{
			wypisz(lista);
		}
		//s - zamiana miejscami dwoch elementow na szczycie listy
		else if (znak == 's')
		{
			zamien(lista);
		}
		//x - usuniecie ze szczytu
		else if (znak == 'x')
		{
			zdejmij(lista);
		}
		//+ - zdjecie z listy 2 liczb i wlozenie na liste ich sumy
		else if (znak == '+')
		{
			sumuj(lista);
		}
		//s - zamien miejscami liczb na szczycie listy
		else if (znak == 'r')
		{
			//int r - zdjêcie z listy liczby n, przeniesienie liczby z wierzcho³ka
			//listy na n-te miejsce licz¹c od wierzcho³ka;
			//0 r oraz 1 r nic nie robi
			//2 r jest to¿same z s
			//3 r zamienia 3 2 1 na 2 1 3 itd.
			if (poprzednia == 0 || poprzednia == 1)
			{
				//nic nie rob
				zdejmij(lista);
			}
			else if (poprzednia == 2)
			{
				//zamien
				zdejmij(lista);
				zamien(lista);
			}
			else if (poprzednia >= 3)
			{
				//przenies
				zdejmij(lista);
				przenies(lista, poprzednia);
			}
		}
		//q - zakonczenie programu
		else if (znak == 'q')
		{
			break;
		}
	}

	listaJednokierunkowa *e;

	do
	{
		e = lista;
		lista = lista->kolejny;
		delete e;
	} while (lista != nullptr);

	return 0;
}