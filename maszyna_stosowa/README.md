# Maszyna stosowa
Napisz program wykonujący następujące operacje na stosie liczb całkowitych. Stos powinien być zaimplementowany jako lista jednokierunkowa. <br />

### liczba
włożenie na stos danej liczby

### p
wypisanie stosu (od wierzchołka do spodu)

### s
zamiana miejscami dwóch liczb na szczycie stosu

### x
usunięcie elementu ze szczytu stosu

### +
zdjęcie dwóch liczb ze stosu i włożenie na stos ich sumy

### r
zdjęcie ze stosu liczby n, przeniesienie liczby z wierzchołka stosu na n-te miejsce licząc od wierzchołka; 0 r oraz 1 r nic nie robi, 2 r jest tożsame z s, 3 r zamienia 3 2 1 na 2 1 3 itd.

### q
zakończenie programu

*Uwaga: operacje s i r mogą modyfikować jedynie wskaźniki.*

### Input
Na wyjściu zostanie podany ciąg poleceń. Każde polecenie będzie składało się z jednego znaku.

### Output
Na wyjście należy wypisać wynik poleceń p, rozdzielając je znakami nowej linii.

# Tests
### Input
1 p <br />
2 p <br />
3 p <br />
4 p <br />
5 p <br />
x p <br />
x p <br />
x p <br />
x p <br />
x p <br />
1 2 3 4 5 p <br />
\+ p <br />
\+ p <br />
\+ p <br />
\+ p <br />
x p <br />
1 2 3 4 5 p <br />
s p <br />
s p <br />
1 r p <br />
2 r p <br />
2 r p <br />
3 r p <br />
3 r p <br />
3 r p <br />
4 r p <br />
4 r p <br />
4 r p <br />
4 r p <br />
5 r p <br />
5 r p <br />
5 r p <br />
5 r p <br />
5 r p <br />
q

### Output
1  <br />
2 1  <br />
3 2 1  <br />
4 3 2 1  <br />
5 4 3 2 1  <br />
4 3 2 1  <br />
3 2 1  <br />
2 1  <br />
1  <br />

5 4 3 2 1 <br /> 
9 3 2 1  <br />
12 2 1  <br />
14 1  <br />
15  <br />

5 4 3 2 1  <br />
4 5 3 2 1  <br />
5 4 3 2 1  <br />
5 4 3 2 1  <br />
4 5 3 2 1  <br />
5 4 3 2 1  <br />
4 3 5 2 1  <br />
3 5 4 2 1  <br />
5 4 3 2 1  <br />
4 3 2 5 1  <br />
3 2 5 4 1  <br />
2 5 4 3 1  <br />
5 4 3 2 1  <br />
4 3 2 1 5  <br />
3 2 1 5 4  <br />
2 1 5 4 3  <br />
1 5 4 3 2  <br />
5 4 3 2 1 