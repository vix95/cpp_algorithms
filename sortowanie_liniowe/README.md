# Sortowanie liniowe
Napisz program sortujący stabilnie w czasie liniowym pary liczb. Sortowanie niestabilne może liczyć na 40% punktów.

### Input
Na wejściu zostanie podana liczba par liczb: n. Po niej podanych będzie n par liczb. Ostatnią liczbą na wejściu będzie rodzaj testu (0 lub 1). Wartości liczb będą nieujemne nie przekroczą n-1.

### Output
W przypadku testu typu 0 należy wypisać posortowane niemalejąco pierwsze wartości z każdej pary (rozdzielone białym znakiem). W przypadku testu typu 1 należy wypisać pary liczb (rozdzielone przecinkiem, bez żadnych białych znaków pomiędzy) posortowane stabilnie niemalejąco według pierwszej wartości z pary.

# Tests
### Input
10 <br />
2 3 <br />
2 2 <br />
2 1 <br />
1 1 <br />
1 2 <br />
1 3 <br />
3 2 <br />
3 3 <br />
3 1 <br />
4 0 <br />
0

### Output
1 <br />
1 <br />
1 <br />
2 <br />
2 <br />
2 <br />
3 <br />
3 <br />
3 <br />
4

### Input
10 <br />
2 3 <br />
2 2 <br />
2 1 <br />
1 1 <br />
1 2 <br />
1 3 <br />
3 2 <br />
3 3 <br />
3 1 <br />
4 0 <br />
1

### Output
1,1 <br />
1,2 <br />
1,3 <br />
2,3 <br />
2,2 <br />
2,1 <br />
3,2 <br />
3,3 <br />
3,1 <br />
4,0