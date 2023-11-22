#include<stdio.h>
#include<stdlib.h>

/*projet du jeu de l'oie*/

/* définition du plateau*/



char* plateau_oie(void) {
    int taille = 100;
    // Allouer de la mémoire pour le tableau de caractères
    char *plateau = (char*)malloc(taille * sizeof(char));

    if (plateau == NULL) {
        // Gestion de l'échec d'allocation de mémoire
        printf("Erreur d'allocation de mémoire.\n");
        exit(EXIT_FAILURE);
    }

    // Initialiser le tableau de caractères (vous pouvez remplacer cela par une logique spécifique)
    for (int i = 0; i < taille; ++i) {
        
        if(i % 9 == 0 && i<92) plateau[i] = 'O';

        else if (i == 8) plateau[i] = 'R';

        else if (i == 53) plateau[i] = 'T';

        else if (i == 74) plateau[i] = 'P';

        else if (i == 31) plateau[i] = 'H';

        else if (i == 65) plateau[i] = 'L';

        else if (i == 94) plateau[i] = 'X';


        else plateau[i] = ' ';

        
    
       
    }

    return plateau;
}







// affichage du plateau en spirale
void affichePlateauEnSpirale()
{
    int plateau[][10] = {
        {0  ,1, 2, 3, 4, 5, 6, 7, 8, 9},
        {35,36,37,38,39,40,41,42,43,10},
        {34,63,64,65,66,67,68,69,44,11},
        {33,62,83,84,85,86,87,70,45,12},
        {32,61,82,95,96,97,88,71,46,13},
        {31,60,81,94,99,98,89,72,47,14},
        {30,59,80,93,92,91,90,73,48,15},
        {29,58,79,78,77,76,75,74,49,16},
        {28,57,56,55,54,53,52,51,50,17},
        {27,26,25,24,23,22,21,20,19,18}
    };

    int lignes = sizeof(plateau) / sizeof(plateau[0]);
    int colonnes = sizeof(plateau[0]) / sizeof(plateau[0][0]);

    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j < colonnes; ++j) {
            if (i == 0) printf("%d  ", plateau[i][j]);
            else printf("%d ", plateau[i][j]);
        }
        printf("\n");
    }
    printf("%ld",sizeof(plateau[0]));
}




int main() {
    affichePlateauEnSpirale(); // affiche le plateau en spirale
    //int attente[4]; // Vérifie si le joueur peut jouer (On variera avec scanf)
    //int positions[4]; // même chose qu'avec attente
    return 0;
}
