# Tablice haszowane
Napisz program śledzący ilość przelanych pieniędzy. Na wejście podane będą polecenia w formacie: <br />
\+ od do ile - od wpłaca na konto do ile pieniędzy <br />
? od do - polecenie wypisania na ekran dotychczasowej sumy pieniędzy przelanych przez od na konto do <br />

*Uwaga: nie należy liczyć stanu konta, tylko sumę przelanych pieniędzy:*
\+ A B 10 <br />
\+ A B 10 <br />
\+ B A 5 <br />
? A B <br />
? B A <br />
powinno wypisać: <br />
20 <br />
5 <br />
<br />
Nazwy od i do będą napisami składającymi się z maksymalnie 16 małych liter i znaku podkreślenia. Suma wpłat dla każdej pary nie przekroczy zakresu int-a. <br />
Należy skorzystać z tablicy haszowanej z łańcuchowaniem oddzielnym do rozwiązywania kolizji

# Tests
### Input
\+ rychu miro 10 <br />
\+ marek_d tomek 100 <br />
\+ marek_d lew 20 <br />
\+ lew adam 17 <br />
\+ miro rychu 10 <br />
? rychu miro <br />
? marek_d tomek <br />
? marek_d lew <br />
? lew adam <br />
? miro rychu <br />
? tomek marek_d <br />
? lew marek_d <br />
? adam lew

### Output
10 <br />
100 <br />
20 <br />
17 <br />
10 <br />
0 <br />
0 <br />
0
