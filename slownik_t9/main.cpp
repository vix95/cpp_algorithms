#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

const int WIELKOSC_ALFABETU = 26;
const int ILOSC_ZNAKOW = 100;

using namespace std;

//lista jednokierunkowa - z wyciagnietymi slowami; potrzebna do sortowania
struct lista
{
	lista *kolejny;
	char znak[ILOSC_ZNAKOW];
	int klawisz[ILOSC_ZNAKOW];
} *LShead;

//drzewo TRIE - slownik
struct drzewoTRIE
{
	char znak;
	int klawisz;
	bool czyKoniec;
	char wyraz[ILOSC_ZNAKOW];
	int kod[ILOSC_ZNAKOW];
	struct drzewoTRIE *dziecko[WIELKOSC_ALFABETU];
} *Thead;

void dodajSlowo(lista *&LShead, drzewoTRIE *l)
{
	lista *p, *n;

	n = new lista;
	n->kolejny = NULL;

	//dodawanie znakow
	int ind = 0;
	for (int i = 0; i < ILOSC_ZNAKOW; i++)
	{
		n->znak[i] = l->wyraz[i];
		n->klawisz[i] = l->kod[i];
		n->klawisz[i + 1] = 0; //zeby zaznaczyc koniec
	}

	p = LShead;
	if (p != nullptr)
	{
		while (p->kolejny) p = p->kolejny;
		p->kolejny = n;
	}
	else LShead = n;
}

void zamien(lista *&p, lista *&e, lista *&LShead)
{
	lista *temp = LShead;
	lista *pp = p;
	lista *pe = e;

	if (p == LShead)
	{
		//zamieniamy
		temp = p->kolejny;
		p->kolejny = e->kolejny;
		e->kolejny = temp;
		LShead = temp;
		LShead->kolejny = p;
	}
	else
	{
		//szukamy poprzedzajace wezly
		do
		{
			if (temp->kolejny == p)
			{
				pp = temp;
				pe = temp->kolejny;
				break;
			}
			temp = temp->kolejny;
		} while (temp->kolejny != nullptr);

		//zamieniamy
		pp->kolejny = e;
		p->kolejny = p;

		temp = e->kolejny;
		e->kolejny = p->kolejny;
		p->kolejny = temp;

		return;
	}

	return;
}

void sortujSlowa(lista *&LShead, int ilosc_znakow_w_kodzie)
{
	lista *p = LShead;
	if (p == nullptr || p->kolejny == nullptr) return;

	lista *e = p->kolejny;

	//lec po znakach od konca
	for (int i = ILOSC_ZNAKOW; i > 0; i--)
	{
		do
		{
			//jesli p > e
			if (p->klawisz[i] > e->klawisz[i])
			{
				//zamiana
				zamien(p, e, LShead);

				p = LShead;
				e = LShead->kolejny;
			}
			else
			{
				p = p->kolejny;
				e = e->kolejny;
			}
		} while (p->kolejny != nullptr);
		p = LShead;
		e = LShead->kolejny;
	}
}

void wypiszSlowa(lista *LShead)
{
	lista *p = LShead;

	if (p == nullptr) cout << "-";
	else
	{
		do
		{
			for (int i = 0; i < ILOSC_ZNAKOW; i++)
			{
				if (p->znak[i] == '\0') break;
				cout << p->znak[i];
			}

			cout << " ";
			p = p->kolejny;
		} while (p != nullptr);
	}

	cout << "\n";
}

void zwolnijListeSlow(lista *&LShead)
{
	lista *p = LShead;

	if (p == nullptr) return;

	do
	{
		p = LShead;
		LShead = p->kolejny;
		delete p;
	} while (LShead != nullptr);
}

//do slownika
void dodajWyraz(char *slowo)
{
	drzewoTRIE *p = Thead;

	long poz = 0;
	do
	{
		int litera = int(slowo[poz]) - 97;

		if (p->dziecko[litera] == nullptr)
		{
			p->dziecko[litera] = new drzewoTRIE();
		}

		if (slowo[poz] >= 'a' && slowo[poz] <= 'c') p->dziecko[litera]->klawisz = 2;
		if (slowo[poz] >= 'd' && slowo[poz] <= 'f') p->dziecko[litera]->klawisz = 3;
		if (slowo[poz] >= 'g' && slowo[poz] <= 'p') p->dziecko[litera]->klawisz = 4;
		if (slowo[poz] >= 'j' && slowo[poz] <= 'l') p->dziecko[litera]->klawisz = 5;
		if (slowo[poz] >= 'm' && slowo[poz] <= 'o') p->dziecko[litera]->klawisz = 6;
		if (slowo[poz] >= 'p' && slowo[poz] <= 's') p->dziecko[litera]->klawisz = 7;
		if (slowo[poz] >= 't' && slowo[poz] <= 'v') p->dziecko[litera]->klawisz = 8;
		if (slowo[poz] >= 'w' && slowo[poz] <= 'z') p->dziecko[litera]->klawisz = 9;

		p->dziecko[litera]->znak = slowo[poz];
		p = p->dziecko[litera];
		poz++;
	} while (slowo[poz] != NULL);

	p->czyKoniec = true;
	//wstaw cale slowo do listy
	for (int i = 0; i < ILOSC_ZNAKOW; i++)
	{
		if (slowo[i] == '\0') break;
		p->wyraz[i] = slowo[i];

		//konwersja slowa na odpowiednik T9
		if (slowo[i] >= 'a' && slowo[i] <= 'c') p->kod[i] = 2;
		if (slowo[i] >= 'd' && slowo[i] <= 'f') p->kod[i] = 3;
		if (slowo[i] >= 'g' && slowo[i] <= 'i') p->kod[i] = 4;
		if (slowo[i] >= 'j' && slowo[i] <= 'l') p->kod[i] = 5;
		if (slowo[i] >= 'm' && slowo[i] <= 'o') p->kod[i] = 6;
		if (slowo[i] >= 'p' && slowo[i] <= 's') p->kod[i] = 7;
		if (slowo[i] >= 't' && slowo[i] <= 'v') p->kod[i] = 8;
		if (slowo[i] >= 'w' && slowo[i] <= 'z') p->kod[i] = 9;
	}

}

void wyszukajSlowa(drzewoTRIE *&p, char *kod, int &ind, long ilosc_znakow_w_kodzie, lista *&LShead)
{
	if (p->czyKoniec == true)
	{
		//zlicz dlugosc slowa
		long licz = 0;
		for (int i = 0; i < ILOSC_ZNAKOW; i++)
		{
			if (p->wyraz[i] == '\0') break;
			licz = i;
		}

		//sprawdz czy dlugosc slowa odpowiada minimalnej ilosci znakow w kodzie
		//jesli slowo jest dluzsze od ilosci znakow w kodzie to ignoruj
		if (licz >= ilosc_znakow_w_kodzie) dodajSlowo(LShead, p); //dodaj slowo do listySlow
	}

	//przelec przez caly alfabet
	for (int i = 0; i < WIELKOSC_ALFABETU; i++)
	{
		//jesli jest litera
		if (p->dziecko[i] != NULL)
		{
			int klawisz = p->dziecko[i]->klawisz;
			char znak = p->dziecko[i]->znak;
			//to porownanie jest potrzebne zeby zaglebic sie do konkretnego miejsca
			if (ind >= ilosc_znakow_w_kodzie)
			{
				ind++;
				wyszukajSlowa(p->dziecko[i], kod, ind, ilosc_znakow_w_kodzie, LShead);
				ind--;

			}
			else if (p->dziecko[i]->klawisz == int(kod[ind]) - 48)
			{
				ind++;
				wyszukajSlowa(p->dziecko[i], kod, ind, ilosc_znakow_w_kodzie, LShead);
				ind--;
			}
		}
	}
}

void zwolnijSlownik(drzewoTRIE *&p)
{
	//sprawdz czy wskaznik nie jest pusty
	if (p != nullptr)
	{
		for (int i = 0; i < WIELKOSC_ALFABETU; i++)
		{
			if (p->dziecko[i] != nullptr)
			{
				zwolnijSlownik(p->dziecko[i]);
			}
			else delete p->dziecko[i];
		}
		delete p;
	}
}

int main()
{
	Thead = new drzewoTRIE();
	Thead->czyKoniec = false;

	LShead = new lista;
	LShead = NULL;

	long n; //ilosc wpisywanych slow
	long m; //ilosc zapytan slow
	char *slowo = new char[10];
	char *kod = new char[10];

	scanf(" %d", &n);
	for (int i = 0; i < n; i++)
	{
		cin >> slowo;
		dodajWyraz(slowo);
	}

	scanf(" %d", &m);
	for (int i = 0; i < m; i++)
	{
		cin >> kod;

		//zlicza ilosc znakow w kodzie
		long ilosc_znakow_w_kodzie = 0;
		do
		{
			ilosc_znakow_w_kodzie++;
		} while (kod[ilosc_znakow_w_kodzie] != NULL);

		//operacja wypisywania
		int ind = 0; //pozycja znaku
		wyszukajSlowa(Thead, kod, ind, ilosc_znakow_w_kodzie, LShead);
		sortujSlowa(LShead, ilosc_znakow_w_kodzie);
		wypiszSlowa(LShead);

		zwolnijListeSlow(LShead); //zwolnij pamiec listySlow
	}

	zwolnijSlownik(Thead); //zwolnij slownik

	//delete slowo;
	//delete kod;

	return 0;
}