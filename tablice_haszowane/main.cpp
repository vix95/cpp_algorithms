#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

const long SIZE_ARRAY = 26;

using namespace std;

struct lista
{
	lista *next;
	char tekst[32];
	int kasa;
};

int haszuj(char *s)
{
	int hash = 0;

	for (int i = 0; i < 9; i++)
	{
		if (s[i] == '\0') break;
		hash = hash + (s[i] - 65);
	}

	return hash % 26;
}

int main()
{
	lista tab[SIZE_ARRAY];
	lista *p = NULL;

	for (int i = 0; i < SIZE_ARRAY; i++)
	{
		tab[i].next = NULL;
		for (int j = 0; j < 32; j++)
		{
			tab[i].tekst[j] = NULL;
		}
		tab[i].kasa = 0;
	}

	char cmd;
	int ile;

	while (cin >> cmd)
	{
		int poz = 0;
		int ile = 0;
		char slowo[32];
		char polecenie[50];

		//zerujemy tablice
		for (int i = 0; i < 32; i++)
		{
			slowo[i] = NULL;
		}
		
		int ind = 0;
		char znak;

		fgets(polecenie, 50, stdin);
		for (int i = 0; i < 50; i++)
		{
			znak = polecenie[i];
			if (znak == '\n') break;

			if (znak >= 48 && znak <= 57) ile = ile * 10 + (znak - 48); //liczenie pieniedzy
			else if (znak != 32)
			{
				slowo[ind] = znak;
				poz = poz + cmd;
				ind++;
			}
		}

		if (cmd == '+')
		{
			poz = haszuj(slowo);

			p = tab[poz].next;
			while (p != nullptr)
			{
				//sprawdzamy czy slowa sa rowne
				bool czyJest = true; //z zalozenia jest rowne
				for (int i = 0; i < 32; i++)
				{
					if (slowo[i] == '\0') break;
					if (p->tekst[i] != slowo[i])
					{
						czyJest = false;
						break;
					}
				}

				//jesli jest rowne to dodaj kase
				if (czyJest == true)
				{
					p->kasa = p->kasa + ile;
					break;
				}
				p = p->next;
			}

			//jesli lista jest pusta to stworz nowy element
			if (p == nullptr)
			{
				lista *n = new lista;
				for (int i = 0; i < 32; i++)
				{
					if (slowo[i] == '\0') break;
					n->tekst[i] = slowo[i];
				}
				n->kasa = ile;
				n->next = tab[poz].next;
				tab[poz].next = n;
			}
		}
		else if (cmd == '?')
		{
			poz = haszuj(slowo);
			p = tab[poz].next;
			if (p == nullptr) cout << 0 << '\n';
			else
			{
				//jest kilka elementow pod ta pozycja
				//sprawdzamy, ktory jest rowny slowu
				bool czyJest;
				while (p != nullptr)
				{
					//sprawdzamy czy slowa sa rowne
					czyJest = true; //z zalozenia jest rowne
					for (int i = 0; i < 32; i++)
					{
						if (slowo[i] == '\0') break;
						if (p->tekst[i] != slowo[i])
						{
							czyJest = false;
							break;
						}
					}

					//jesli jest rowne to dodaj kase
					if (czyJest == true)
					{
						p->kasa = p->kasa + ile;
						cout << p->kasa << '\n';
						break;
					}
					p = p->next;
				}
				if (czyJest == false) cout << 0 << '\n';
			}
		}
	}

	//czyszczenie tablicy
	for (int i = 0; i < SIZE_ARRAY; i++)
	{
		if (tab[i].next != nullptr)
		{
			p = tab[i].next;
			while (p != nullptr)
			{
				tab[i].next = p->next;
				delete p;
				p = tab[i].next;
			}
		}
	}

	return 0;
}