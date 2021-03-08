# TP noté de complexité des algorithmes

# Stratégie 1

#### 1.
Voir marqueurs_negatifs1 dans le fichier experimentateur.c

#### 2.
On calcule le nombre d'itérations à l'intérieur de la deuxième boucle `for`. En le faisant dans la deuxième boucle `for`, on obtient le nombre d'opérations dans la première boucle `for` ainsi que dans la deuxième.

#### 3.
Pour cet algorithme, il existe un pire des cas. Ce pire des cas se réalise lorsque le nombre de marqueurs positifs est égal au nombre total de marqueurs. Pour le voir autrement, le pire des cas se réalise lorsque m = p.

#### 4.
Comme dit ci-dessus, le pire des cas se réalise lorsque m = p. Donc on pose m = p = n où n est un entier positif ou nul.
On a alors f(n) = (n(n+1))/2.
##### Exemple
On essaie avec m = p = n = 10. f(10) = (10(10+1))/2 = (10(11))/2 = (110)/2 = 55. Ce qui correspond bien au nombre d'opération dans le pire des cas de la première stratégie.
