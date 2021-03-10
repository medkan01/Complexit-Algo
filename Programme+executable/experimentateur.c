#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Fonction pour echanger deux entiers
void echange(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fonction qui affiche un tableau de taille n
void affiche(int *t, int n)
{
    int i;

    for (i = 0; i < n; ++i)
    {
        printf("%d ", t[i]);
    }
    printf("\n");
}

// Structure representant une experience
// Un marqueur est un entier compris entre 0 et m
typedef struct
{
    int m;          // Nombre de marqueurs
    int *marqueurs; // Tous les marqueurs

    int p;                   // Nombre de marqueurs positifs
    int *marqueurs_positifs; // Les marqueurs positifs
} EXPERIENCE;

// Fonction qui cree une expérience et la stocke dans la structure passee en parametre
// Attention : il faut que p <= m
void cree_experience(EXPERIENCE *xp, int p, int m)
{
    int i, j;

    xp->m = m;

    xp->marqueurs = (int *)malloc(m * sizeof(int));
    for (i = 0; i < m; ++i)
        xp->marqueurs[i] = i;

    // On melange les marqueurs dans l'ensemble des marqueurs par l'algorithme de Fisher-Yates
    for (i = m - 1; i >= 0; --i)
    {
        j = rand() % (i + 1);
        echange(&xp->marqueurs[i], &xp->marqueurs[j]);
    }

    // On choisit p marqueurs parmi les m qui seront les marqueurs positifs
    int *tmp = (int *)malloc(m * sizeof(int));
    for (i = 0; i < m; ++i)
        tmp[i] = i;

    xp->p = p;

    xp->marqueurs_positifs = (int *)malloc(p * sizeof(int));
    for (int i = 0; i < p; ++i)
    {
        j = rand() % (m - i);
        xp->marqueurs_positifs[i] = xp->marqueurs[tmp[j]];
        tmp[j] = tmp[m - i - 1];
    }

    free(tmp);
}

// Algorithme de tri fusion
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
   are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
   are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
 sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Fonction qui libere la memoire dans une experience
void libere_experience(EXPERIENCE *xp)
{
    free(xp->marqueurs);
    free(xp->marqueurs_positifs);
}

// Fonction a completer - Strategie 1
// Le second argument servira a compter le nombre d'utilisation de l'opérateur OP
int *marqueurs_negatifs1(EXPERIENCE *xp, int *cptOP)
{
    *cptOP = 0;

    int *res = (int *)malloc((xp->m - xp->p) * sizeof(int));

    int contient;
    int iter = 0;

    for (int i = 0; i < xp->m; i++)
    {
        contient = 0;
        for (int j = 0; j < xp->p; j++)
        {
            *cptOP += 1;

            if (xp->marqueurs[i] == xp->marqueurs_positifs[j])
            {
                contient = 1;
                break;
            }
        }
        if (contient == 0)
        {
            res[iter] = xp->marqueurs[i];
            iter++;
        }
    }
    return res;
}

// Fonction a completer - Strategie 2
// Le second argument servira a compter le nombre d'utilisation de l'opérateur OP
int *marqueurs_negatifs2(EXPERIENCE *xp, int *cptOP)
{
    *cptOP = 0;

    int *res = (int *)malloc((xp->m - xp->p) * sizeof(int));

    int contient, iter = 0;

    mergeSort(xp->marqueurs_positifs, 0, xp->p - 1);
    int a, b, m;

    for (int i = 0; i < xp->m; i++)
    {
        contient = 0;

        a = 0;
        b = xp->p - 1;

        while (a <= b)
        {
            *cptOP = *cptOP + 1;

            m = (a + b) / 2;
            if (xp->marqueurs_positifs[m] == xp->marqueurs[i])
            {
                contient = 1;
                break;
            }
            else if (xp->marqueurs_positifs[m] < xp->marqueurs[i])
            {
                a = m + 1;
            }
            else
            {
                b = m - 1;
            }
        }

        if (contient == 0)
        {
            res[iter] = xp->marqueurs[i];
            iter++;
        }
    }

    return res;
}

// Fonction a completer - Strategie 3
// Le second argument servira a compter le nombre d'utilisation de l'opérateur OP
int *marqueurs_negatifs3(EXPERIENCE *xp, int *cptOP)
{
    *cptOP = 0;

    int *res = (int *)malloc((xp->m - xp->p) * sizeof(int));

    int contient, iter = 0, j = 0;

    mergeSort(xp->marqueurs, 0, xp->m - 1);
    mergeSort(xp->marqueurs_positifs, 0, xp->p - 1);

    for (int i = 0; i < xp->m; i++)
    {
        contient = 0;

        for (j = j; j < xp->p; j++)
        {
            *cptOP = *cptOP + 1;

            if (xp->marqueurs[i] < xp->marqueurs_positifs[j])
            {
                break;
            }
            else if (xp->marqueurs[i] == xp->marqueurs_positifs[j])
            {
                contient = 1;
                break;
            }
        }

        if (contient == 0)
        {
            res[iter] = xp->marqueurs[i];
            iter++;
        }
    }

    return res;
}

void test(int p, int m)
{
    EXPERIENCE xp;
    int cpt1, cpt2, cpt3, *marqueurs_neg1, *marqueurs_neg2, *marqueurs_neg3;

    // Creation de l'experience
    cree_experience(&xp, p, m);

    // Test strategie 1
    marqueurs_neg1 = marqueurs_negatifs1(&xp, &cpt1);
    free(marqueurs_neg1);

    // Test strategie 2
    marqueurs_neg2 = marqueurs_negatifs2(&xp, &cpt2);
    free(marqueurs_neg2);

    // Test strategie 3
    marqueurs_neg3 = marqueurs_negatifs3(&xp, &cpt3);
    free(marqueurs_neg3);

    // Affichage des valeurs obtenues
    printf("%i %i %i %i %i\n", xp.m, xp.p, cpt1, cpt2, cpt3);

    libere_experience(&xp);
}

int main(int argc, const char *argv[])
{
    int m;
    srand((unsigned int)time(NULL));

    printf("Entrez le nombre de marqueurs : ");
    scanf("%d", &m);

    for (int i = 1; i <= m; i++)
    {
        test(i, m);
    }

    return 0;
}