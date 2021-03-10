# TP noté de complexité des algorithmes

# Stratégie 1

#### 1.
Voir la fonction `int *marqueurs_negatifs1(int *xp, *cptOP)` dans le fichier experimentateur.c

#### 2.
On calcule le nombre d'itérations à l'intérieur de la deuxième boucle `for`. En le faisant dans la deuxième boucle `for`, on obtient le nombre d'opérations dans la première boucle `for` ainsi que dans la deuxième.

#### 3.
Pour cet algorithme, il existe un pire des cas. Ce pire des cas se réalise lorsque le nombre de marqueurs positifs est égal au nombre total de marqueurs. Pour le voir autrement, le pire des cas se réalise lorsque m = p.

#### 4.
Comme dit ci-dessus, le pire des cas se réalise lorsque m = p. Donc on pose m = p = n où n est un entier positif ou nul.
On a alors f(n) = (n(n+1))/2.
##### Exemple
On essaie avec m = p = n = 10. f(10) = (10(10+1))/2 = (10(11))/2 = (110)/2 = 55. Ce qui correspond bien au nombre d'opération dans le pire des cas de la première stratégie quand m = 10.

# Stratégie 2

#### 1.
Voir la fonction `int *marqueurs_negatifs2(int *xp, *cptOP)` dans le fichier experimentateur.c

#### 2.
Pour cette algorithme, il existe aussi un pire des cas. Il se réalise, encore une fois, lorsque le nombre de marqueurs positifs est égal au nombre total de marqueurs. Donc lorsque m = p.

#### 3.
On note b la borne supérieure pour le nombre d'opérations c2(m,p). Prenons le cas où m = p = 10. Alors b = 29.

# Stratégie 3

#### 1.
Voir la fonction `int *marqueurs_negatifs3(int *xp, *cptOP)` dans le fichier experimentateur.c

#### 2.
Il existe, une fois de plus, un pire des cas. Celui-ci se réalise lorsque m = p.
Dans cet algorithme, il est possible de déterminer le nombre exact d'opérations c3(m,p) en fonction de m et de p.
Ceci car c3(m,p) = c3(n) = 2n - 1.

##### Exemple
On essaie avec n = 10. c3(10) = 2 * 10 - 1 = 20 - 1 = 19.

# 6 Recherche empirique des cas favorables

#### 1.
Voir la fonction ```c
void test(int p, int m)
``` dans le fichier experimentateur.c