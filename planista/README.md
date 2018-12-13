# Planista
Jednym z zadań systemu operacyjnego jest przydział czasu procesora poszczególnym procesom. Napisz program realizujący prostego planistę. <br />
<br />
Czas procesora powinien być przydzielany według następujących zasad: <br />
<br />
każdy proces może mieć wysoki, normalny lub niski priorytet, <br />
procesy i niższym priorytecie nie będą otrzymywały procesora, jeżeli istnieją procesy o priorytecie wyższym, <br />
procesy o takim samym priorytecie wykonywane są na przemian, w kolejności ich utworzenia, <br />
procesy można tworzyć, usuwać i zmieniać im priorytet, <br />
jeżeli w systemie nie ma żadnego procesu, wykonywany jest specjalny proces o nazwie idle. <br />
Każdy proces jest jednoznacznie identyfikowany przez swój numer (dodatnia liczba całkowita, nie większa niż 231-1). <br />
<br />
Jeżeli w systemie są 3 procesy (1, 2, 3) o normalnym priorytecie, to będą one wykonywane w kolejności 1, 2, 3, 1, 2, 3, ... . Jeżeli dodamy w tym momencie proces 4 o priorytecie wysokim, to kolejnymi wykonywanymi procesami będą: 4, 4, 4, ... . <br />
<br />
Rozwiązanie wykorzystujące dynamiczne struktury danych (lista, lista cykliczna) będzie zdecydowanie wyżej punktowane (max. 100%) niż zadanie korzystające z tablic (max 30%). <br />

### Input
Na wejściu pojawi się ciąg komend:

### n
przydzielenie czasu procesora kolejnemu procesowi; na wyjście należy wypisać numer zadania, które ma otrzymać procesor lub idle jeżeli w systemie nie ma zadań,

### c id p
utworzenie procesu o numerze id i priorytecie p, 1 oznacza priorytet wysoki, 0 to priorytet normalny, zaś -1 - priorytet niski; nowo utworzone zadanie powinno trafiać na koniec kolejki o danym priorytecie, jeżeli w sytuacji 0: 2 3 1 wykonamy c 4 0 wynikiem powinno być 0: 2 3 1 4,

### t id
oznacza zakończenie zadania o numerze id,

### p id p
zmiana priorytetu zadania o numerze id na p (rownoważne usunięciu zadania id i dodaniu go z nowym priorytetem),

### l
(mała litera L) lista zadań; należy wypisać wszystkie zadania w formacie: <br />
1:  <br />
0:  <br />
-1:

### Output
Np. jeżeli w systemie są zadania 1, 2, 3, 4, 5, przy czym 1, 2, 3 mają normalny priorytet a 4 i 5 wysoki, 4 będzie wykonane wcześniej niż 5, a zadania 1, 2, 3 byłyby wykonane w takiej kolejności (np. po usunięciu zadań 4 i 5) to na wyjściu powinno pojawić się: <br />
1: 4 5 <br />
0: 1 2 3 <br />
-1:

# Tests
### Input
c 1 0 <br />
c 2 0 <br />
c 3 0 <br />
n <br />
n <br />
n <br />
n <br />
c 4 1 <br />
n <br />
n <br />
n <br />
t 4 <br />
n <br />
n <br />
n <br />
c 5 -1 <br />
t 1 <br />
t 2 <br />
n <br />
n <br />
t 3 <br />
n <br />
n <br />
c 6 -1 <br />
n <br />
n <br />
n

### Output
1 <br />
2 <br />
3 <br />
1 <br />
4 <br />
4 <br />
4 <br />
2 <br />
3 <br />
1 <br />
3 <br />
3 <br />
5 <br />
5 <br />
5 <br />
6 <br />
5

### Input
c 1 0 <br />
c 2 0 <br />
c 3 0 <br />
c 4 1 <br />
c 5 1 <br />
c 6 -1 <br />
c 7 -1 <br />
c 8 -1 <br />
l

### Output
1: 4 5 <br />
0: 1 2 3 <br />
-1: 6 7 8

### Input
c 1 0 <br />
c 2 0 <br />
c 3 0 <br />
c 4 -1 <br />
n <br />
n <br />
n <br />
n <br />
p 4 1 <br />
n <br />
n <br />
p 1 1 <br />
n <br />
n <br />
n <br />
t 1 <br />
t 2 <br />
t 3 <br />
t 4 <br />
n <br />
n

### Output
1 <br />
2 <br />
3 <br />
1 <br />
4 <br />
4 <br />
4 <br />
1 <br />
4 <br />
idle <br />
idle