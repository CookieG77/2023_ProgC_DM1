#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/* définition du plateau*/







char* plateau_oie(void) {
    int taille = 100;
    // Allouer de la mémoire pour le tableau de caractères
    char *plateau = malloc(taille * sizeof(char));

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

/*
void conversion(int pos, int* x, int* y)
{
    int plateau[][10] = {
        {0,1,2,3,4,5,6,7,8,9},
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
    
    for (int i = 0; i < 10 ; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (plateau[i][j] == pos)
            {
                
                *x = i;
                *y = j;
            }
        }
        
    }
    printf("numéro :%d,x :%d,y :%d",pos,*x,*y);
    printf("\n");

    
}
*/

void collisions(
    char* plateau,int* positions,int* attente,
    int nb_joueurs,int joueur_courant,int nouvelle_pos)

{
    int pos_ancien = positions[joueur_courant];
    if (nouvelle_pos == 54 || nouvelle_pos == 74)
    {
        positions[joueur_courant] = nouvelle_pos;

    } else {
        for (int i = 0; i < nb_joueurs; i++)
        {
            if (nouvelle_pos == positions[i] && i != joueur_courant) {
                positions[i] = pos_ancien;
                positions[joueur_courant] = nouvelle_pos;
                int des_nuls[2];
                avancer_joueur(plateau,positions,attente,
                i,nb_joueurs,des_nuls,false);
                break;
            }

        }
        
    }

}











int avancer_joueur(char *plateau,int *positions,int *attente,int joueur_courant, int nb_joueurs,int des[2],bool premier_tour)
{
    int pos_jcourant = positions[joueur_courant]+des[0]+des[1];
    if (premier_tour) {
        if ((des[0] == 6 && des[1]== 3) ||(des[0] == 3 && des[1]== 6))
        {
            pos_jcourant = 40;
            //Premier lancer direction case 40
        } else if ((des[0] == 4 && des[1]== 5) ||(des[0] == 5 && des[1]== 4)){

            pos_jcourant = 89;
            //Premier lancer direction case 89
        }
    

    } 
    switch (plateau[pos_jcourant])
    {
    case 'O':
        pos_jcourant+des[0]+des[1];
        break;

    case 'T':
        attente[joueur_courant] = -1;
        break;

    case 'R':
        pos_jcourant = 16;
        break;

    case 'P':
        int cpt = 0;
        for (int i = 0; i < nb_joueurs; i++) {
            if (attente[i] = -1 && positions[i] == 74 && i!= joueur_courant) cpt++;
        }
        if (cpt % 2 != 0)
        {
            attente[pos_jcourant] = -1;

        } else {
            for (int i = 0; i < nb_joueurs; i++){
                if (positions[i] == 74) attente[i] = 0;
            }
            
        }
        
        break;

    case 'H':
        attente[pos_jcourant] = 2;
        break;

    case 'L':
        pos_jcourant = 52;
        break;

    case 'X':
        pos_jcourant = 0;
        break;

    
    default:
        break;
    }
    positions[joueur_courant] = pos_jcourant;
    if (pos_jcourant ==  99) return joueur_courant;
    return -1;
      
}


void afficherPlateau(char *plateau,int *positions,int nb_joueurs)
{
printf("Affichage du tableau avec représentation des cases \n");
printf("<");
for (int i = 0; i < nb_joueurs; i++)
{
    for (int j = 0;j<100; j++)
    {
        if (j == positions[i]) 
        {
        
        printf("Joueur %d: case %d:(%c) ",i,positions[i],plateau[j]);
       
        }

    }
    
}
 printf(">");
}