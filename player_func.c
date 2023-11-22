#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int randint(int min, int max){
    /**
     * Return a int between @param min and @param max, both included.
    */
    return min + rand()%(max+1);
}

int avancerJoueur(char plateau[],
                  int positions[],
                  int attente[],
                  int joueur_courant,
                  int nb_joueurs){
    int pos_init = positions[joueur_courant];
    




    return -1;
}



int main(void){
    int position[4] = {0, 0, 0, 0};
    int attente[4]  = {0, 0, 0, 0};
    srand(time(NULL)); //Initialisation de la seed pour les nombre random
    printf(randint(1, 6));
    return 0;
}