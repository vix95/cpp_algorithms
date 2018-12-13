#include <iostream>
#include <complex>

using namespace std;

struct wartosc
{
	wartosc* kolejny;
	wartosc* poprzedni;
	char znak;
};

class lista_cykliczna
{
	int n;
	wartosc* start;

public:
	lista_cykliczna() : start(nullptr), n(0)
	{
	}

	void zeruj()
	{
		usun(n);
	}

	void wypisz()
	{
		wartosc* q = start;

		for (int i = 0; i < n; i++)
		{
			std::cout << q->znak;
			q = q->kolejny;
		}
		std::cout << std::endl;
	}

	void odwroc()
	{
		wartosc* q = start;

		for (int i = 0; i < n; i++)
		{
			wartosc* temp = q->kolejny;
			q->kolejny = q->poprzedni;
			q->poprzedni = temp;
			q = temp;
		}

		start = q;
		przesun(1);
	}

	void ustaw(char* string)
	{
		zeruj();

		int dlugosc = strlen(string);

		for (int i = 0; i < dlugosc; i++)
		{
			dodaj(string[i]);
		}
	}

	void przesun(int char2int)
	{
		for (int i = 0; i < char2int; i++)
		{
			char zn = przenies();
			dodaj(zn);
		}
	}

	void usun(int char2int)
	{
		if (n < char2int || start == 0)
		{
			return;
		}
		for (int i = 0; i < char2int; i++)
		{
			przenies();
		}
	}

	void doklej(lista_cykliczna* lista)
	{
		int dlugosc = lista->n;

		for (int i = 0; i < dlugosc; i++)
		{
			char znak = lista->przenies();
			dodaj(znak);
		}
	}

	void skopiuj(lista_cykliczna* lista)
	{
		wartosc* q = lista->start;
		int dlugosc = lista->n;

		for (int i = 0; i < dlugosc; i++)
		{
			char znak = q->znak;
			dodaj(znak);
			q = q->kolejny;
		}
	}

	void mieszaj(lista_cykliczna* lista)
	{
		int dlugosc = lista->n + n;
		char* string = new char[dlugosc + 1];
		string[dlugosc] = '\0';

		for (int i = 0; i < dlugosc; i++)
		{
			char znak;

			if (i % 2 == 0)
			{
				znak = przenies();
				if (znak == 0)
				{
					znak = lista->przenies();
				}
			}
			else
			{
				znak = lista->przenies();

				if (znak == 0)
				{
					znak = przenies();
				}
			}

			string[i] = znak;
		}
		ustaw(string);
	}

	void dodaj(char z)
	{
		wartosc* q = new wartosc();
		q->znak = z;

		if (start != nullptr)
		{
			q->kolejny = start;
			q->poprzedni = start->poprzedni;
			start->poprzedni->kolejny = q;
			start->poprzedni = q;
		}
		else
		{
			q->kolejny = q;
			q->poprzedni = q;
			start = q;
		}

		n = n + 1;
	}

	char przenies()
	{
		if (start == nullptr || n == 0) return 0;
		char znak = start->znak;

		if (n > 1)
		{
			start->kolejny->poprzedni = start->poprzedni;
			start->poprzedni->kolejny = start->kolejny;
		}

		wartosc* nast = start->kolejny;
		delete start;
		start = nast;

		if (n == 1)
		{
			start = nullptr;
		}

		n = n - 1;

		return znak;
	}
};

int main()
{
	lista_cykliczna** lista = new lista_cykliczna*[26];
	char* polecenie = new char[10];
	char* p_wartosc = new char[2];
	char* d_wartosc = new char[100000];

	for (int i = 0; i <= 25; i++)
	{
		lista[i] = new lista_cykliczna();
	}

	while (cin >> polecenie)
	{
		if (strcmp(polecenie, "ZERUJ") == 0) {
			cin >> p_wartosc;

			if (p_wartosc[0] >= 65 && p_wartosc[0] <= 90)
			{
				lista[p_wartosc[0] - 65]->zeruj();
			}
		}

		if (strcmp(polecenie, "WYPISZ") == 0)
		{
			cin >> p_wartosc;

			if (p_wartosc[0] >= 65 && p_wartosc[0] <= 90)
			{
				lista[p_wartosc[0] - 65]->wypisz();
			}
		}

		if (strcmp(polecenie, "ODWROC") == 0)
		{
			cin >> p_wartosc;

			if (p_wartosc[0] >= 65 && p_wartosc[0] <= 90)
			{
				lista[p_wartosc[0] - 65]->odwroc();
			}
		}

		if (strcmp(polecenie, "USTAW") == 0)
		{
			cin >> p_wartosc;
			cin >> d_wartosc;

			if (p_wartosc[0] >= 65 && p_wartosc[0] <= 90)
			{
				lista[p_wartosc[0] - 65]->ustaw(d_wartosc);
			}
		}

		if (strcmp(polecenie, "PRZESUN") == 0)
		{
			cin >> p_wartosc;
			cin >> d_wartosc;

			int char2int = atoi(d_wartosc);

			if (p_wartosc[0] >= 65 && p_wartosc[0] <= 90)
			{
				lista[p_wartosc[0] - 65]->przesun(char2int);
			}
		}

		if (strcmp(polecenie, "USUN") == 0)
		{
			cin >> p_wartosc;
			cin >> d_wartosc;
			int char2int = atoi(d_wartosc);

			if (p_wartosc[0] >= 65 && p_wartosc[0] <= 90)
			{
				lista[p_wartosc[0] - 65]->usun(char2int);
			}
		}

		if (strcmp(polecenie, "DOKLEJ") == 0)
		{
			cin >> p_wartosc;
			cin >> d_wartosc;

			if (p_wartosc[0] >= 65 && p_wartosc[0] <= 90 && d_wartosc[0] >= 65 && d_wartosc[0] <= 90)
			{
				lista[p_wartosc[0] - 65]->doklej(lista[d_wartosc[0] - 65]);
			}
		}

		if (strcmp(polecenie, "SKOPIUJ") == 0)
		{
			cin >> p_wartosc;
			cin >> d_wartosc;

			if (p_wartosc[0] >= 65 && p_wartosc[0] <= 90 && d_wartosc[0] >= 65 && d_wartosc[0] <= 90)
			{
				lista[p_wartosc[0] - 65]->skopiuj(lista[d_wartosc[0] - 65]);
			}
		}

		if (strcmp(polecenie, "MIESZAJ") == 0)
		{
			cin >> p_wartosc;
			cin >> d_wartosc;

			if (p_wartosc[0] >= 65 && p_wartosc[0] <= 90 && d_wartosc[0] >= 65 && d_wartosc[0] <= 90)
			{
				lista[p_wartosc[0] - 65]->mieszaj(lista[d_wartosc[0] - 65]);
			}
		}
	}

	delete lista;
	delete polecenie;
	delete p_wartosc;
	delete d_wartosc;

	return 0;
}