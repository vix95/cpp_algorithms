# Generator napisów cyklicznych
Generator Napisów Cyklicznych jest programowalnym urządzeniem do generowania napisów. Posiada 26 rejestrów, oznaczonych literami od A do Z. Każdy z nich przechowuje jeden napis. Zbiór poleceń dla generatora jest następujący:

### ZERUJ r
usunięcie zawartości rejestru r

### WYPISZ r
wpisanie na ekran zawartości rejestru r oraz znaku nowej linii

### ODWROC r
odwrócenie kolejności napisu w rejestrze r (z ABCDE dostajemy EDCBA)

### USTAW r napis
wpisanie do rejestru r napisu napis

### PRZESUN r n
przeniesienie n początkowych znaków rejestru r na jego koniec; dla A=ABCDEF PRZESUN A 2 spowoduje, że A=CDEFAB

### USUN r n
usunięcie n początkowych znaków rejestru r

### DOKLEJ r s
doklejenie zawartości rejestru s na koniec rejestru r; po wykonaniu tej operacji rejestr s jest zerowany

### SKOPIUJ r s
doklejenie zawartości rejestru s na koniec rejestru r; po wykonaniu tej operacji rejestr s zachowuje pierwotną wartość

### MIESZAJ r s
wstawienie do rejestru r napisu zawierającego na przemian znaki z r i s, gdy zawartość jednego z rejestrów się skończy, dodajemy tylko znaki z drugiego napisu; po wykonaniu tej operacji rejestr s jest zerowany; np. dla A=ABC i B=123 wykonanie MIESZAJ A B spowoduje, że A=A1B2C3 a B=puste <br />
r i s oznaczają rejestry (jedną z liter od A do Z), w każdym poleceniu r będzie różne od s. Napisami będą ciągi znaków składające się z liter (dużych i małych), cyfr, nawiasów, podkreślnika (_) lub operatorów +, -, *, /. Zaraz po uruchomieniu wszystkie rejestry przechowują puste napisy. Zaimplementuj Generator Napisów Cyklicznych. 

### Input
Na wejściu podane będą polecenia dla generatora.
### Output
Na wyjściu należy wypisać kolejne wyniki operacji WYPISZ.

# Tests
### Input
USTAW A ABCDEF <br />
WYPISZ A <br />
PRZESUN A 2 <br />
WYPISZ A <br />
USUN A 3 <br />
WYPISZ A <br />
ODWROC A <br />
WYPISZ A <br />
ZERUJ A <br />
WYPISZ A <br />
USTAW A 123 <br />
USTAW B 456 <br />
DOKLEJ A B <br />
WYPISZ A <br />
USTAW B STUVWXYZ <br />
MIESZAJ A B <br />
WYPISZ A <br />
USTAW A * <br />
WYPISZ A <br />
SKOPIUJ B A <br />
DOKLEJ A B <br />
WYPISZ A <br />
SKOPIUJ B A <br />
DOKLEJ A B <br />
WYPISZ A <br />
SKOPIUJ B A <br />
DOKLEJ A B <br />
WYPISZ A <br />

### Output
ABCDEF <br />
CDEFAB <br />
FAB <br />
BAF <br />
<br />
123456 <br />
1S2T3U4V5W6XYZ <br />
\* <br />
** <br />
**** <br />
******** <br />