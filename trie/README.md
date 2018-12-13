# TRIE
Zaimplementuj drzewo TRIE przechowujące tłumaczenia słów. Słowo w języku oryginalnym i tłumaczenie nie będzie dłuższe niż 16 znaków i będzie zawierało jedynie małe litery. <br />
Program powinien obsługiwać następujące polecenia: <br />
### + s t
dodanie słowa s z tłumaczeniem t
### ? s
zapytanie o słowo s – należy wypisać tłumaczenie słowa s lub - (minus) gdy tłumaczenie nie zostało dodane
### * s
polecenie wypisania tłumaczeń wszystkich słów, których prefiksem jest s (włączając słowo s, jeżeli jest dodane do słownika)

# Tests
### Input
\+ dog pies <br />
\+ cat kot <br />
\+ do robic <br />
\+ doggie piesek <br />
\+ doggies pieski <br />
\+ dolphin delfin <br />
\+ ant mrowka <br />
\+ zzz xxx <br />
? dog <br />
? cat <br />
? do <br />
? doggie <br />
? dolphin <br />
? ant <br />
? zzz <br />
? d <br />
? dot <br />
? dom <br />
? dogg <br />
? dol <br />
? dolp <br />
? dolph <br />
? dolphi <br />
? dolphine <br />
\* a <br />
\* d <br />
\* do <br />
\* dog <br />
\* dogg <br />
\* doggie <br />
\* doggies <br />
\* z <br />
\* b <br />
\* dot <br />
\* dolphen <br />
\* doggiess

### Output
pies <br />
kot <br />
robic <br />
piesek <br />
delfin <br />
mrowka <br />
xxx <br />
\- <br />
\- <br />
\- <br />
\- <br />
\- <br />
\- <br />
\- <br />
\- <br />
\- <br />
mrowka <br />
robic <br />
pies <br />
piesek <br />
pieski <br />
delfin <br />
robic <br />
pies <br />
piesek <br />
pieski <br />
delfin <br />
pies <br />
piesek <br />
pieski <br />
piesek <br />
pieski <br />
piesek <br />
pieski <br />
pieski <br />
xxx <br />
\- <br />
\- <br />
\- <br />
\-
