#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct listaCykliczna
{
	listaCykliczna *kolejny;
	int proces;
	int priorytet;
};

void usun(listaCykliczna *&head, int &proces)
{
	if (head != nullptr)
	{
		listaCykliczna *p;
		listaCykliczna *e;

		p = head;

		//wyjatek - jesli chce skasowac ostatni wpis a tym samym head
		if (p->kolejny == head)
		{
			head = nullptr;
			delete p;
			return;
		}

		//wyszukaj proces
		do
		{
			if (p->kolejny->proces == proces)
			{
				e = p->kolejny; //e kasujemy

				if (e == head)
				{
					p = head->kolejny;
					while (p->kolejny != e)
					{
						p = p->kolejny;
					}
					p->kolejny = e->kolejny;
					head = p;
					delete e;

					break;
				}
				else
				{
					p = head;
					while (p->kolejny != e)
					{
						p = p->kolejny;
					}
					p->kolejny = e->kolejny;
					delete e;

					break;
				}
			}
			p = p->kolejny;
		} while (p != head);
	}
}

void dodaj(listaCykliczna *&head, int proces, int priorytet)
{
	listaCykliczna *n = new listaCykliczna;
	listaCykliczna *p;

	//przypisuje wartosci do nowego elementu
	n->proces = proces;
	n->priorytet = priorytet;

	if (head != nullptr)
	{
		//znajdz pozycje ostatniego procesu z tym priorytetem
		int count = 0;
		p = head;

		do
		{
			if (p->priorytet == priorytet)
			{
				count++;
			}
			p = p->kolejny;
		} while (p != head);

		//mamy pozycje, teraz za ta pozycje wstaw nowy element
		p = head;
		do
		{
			if (p->kolejny->priorytet == priorytet)
			{
				count--;
				if (count == 0)
				{
					//znalazlem ostatni proces z tym priorytetem
					//do nastepnika nowego procesu wstaw proces znaleziony
					n->kolejny = head->kolejny;
					//do nastepnika znalezionego procesu wstaw nowy proces
					head->kolejny = n;
					//jako glowe ustaw nowy proces
					head = n;
					return;
				}
			}
			p = p->kolejny;
		} while (p != head);
		n->kolejny = head->kolejny;
		head->kolejny = n;
		return;

	}
	else
	{
		//to jest pierwszy element
		//na jego nastepnika wskaz siebie samego
		n->kolejny = n;
		head = n;
	}

}

void wypisz(listaCykliczna *&head)
{
	listaCykliczna *p;

	int size;

	p = head;

	//wyjatek - jesli nie ma nic na liscie
	if (p == nullptr)
	{
		cout << "idle\n";
		return;
	}

	//sprawdz jaki jest najwiekszy priorytet
	int max = -1;

	do
	{
		if (max < p->priorytet) max = p->priorytet;
		p = p->kolejny;
	} while (p != head);

	p = head;
	//wypisz proces - pamietaj o przejsciu dalej
	do
	{
		if (p->kolejny->priorytet == max)
		{
			//przerzuc proces na ostatnie miejsce
			//1 - skasuj
			//2 - utworz
			int proc = p->kolejny->proces;
			int pr = p->kolejny->priorytet;
			cout << p->kolejny->proces << "\n";
			usun(head, proc);
			dodaj(head, proc, pr);
			break;
		}
		p = p->kolejny;
	} while (p != head);
}

void listaZadan(listaCykliczna *head)
{
	listaCykliczna *p;

	int size;

	//1:
	//0:
	//-1:

	for (int i = 1; i >= -1; i--)
	{
		p = head;
		cout << i << ": ";

		if (head != nullptr)
		{
			do
			{
				if (p->kolejny->priorytet == i)
				{
					cout << p->kolejny->proces << " ";
				}
				p = p->kolejny;
			} while (p != head);
			cout << "\n";
		}
	}

}

int main()
{
	listaCykliczna *lista;
	lista = NULL;

	char polecenie;

	while (cin >> polecenie)
	{
		int proces;
		int priorytet;
		char znak;

		znak = polecenie;

		//c id p - utworzenie procesu o numerze id i priorytecie p na koniec kolejki o danym priorytecie
		//1 - priorytet wysoki
		//0 - normalny
		//-1 - priorytet niski
		if (znak == 'c')
		{
			scanf(" %d%d", &proces, &priorytet);
			dodaj(lista, proces, priorytet);
		}
		//n - wypisanie procesu z najwyzszym priorytetem - po kolei
		else if (znak == 'n')
		{
			wypisz(lista);
		}
		//t id - zakonczenie procesu
		else if (znak == 't')
		{
			scanf(" %d", &proces);
			usun(lista, proces);
		}
		//p id p - zmiana priorytetu procesu o numerze id na p
		//(rownowa¿ne usuniêciu priorytetu id i dodaniu go z nowym priorytetem),
		else if (znak == 'p')
		{
			scanf(" %d%d", &proces, &priorytet);
			usun(lista, proces);
			dodaj(lista, proces, priorytet);
		}
		//lista zadañ
		//1:
		//0:
		//-1:
		else if (znak == 'l')
		{
			listaZadan(lista);
		}

	}

	listaCykliczna *e;

	do
	{
		e = lista;
		lista = lista->kolejny;
		delete e;
	} while (lista != nullptr);

	return 0;
}