#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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
        
        if((i % 9 == 0 && i != 0) && i<92) plateau[i] = 'O';

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


void collisions(char* plateau,
                int* positions,
                int* attente,
                int nb_joueurs,
                int joueur_courant,
                int nouvelle_pos)

{
    int pos_ancien = positions[joueur_courant];
    if (nouvelle_pos == 53 || nouvelle_pos == 74)
    {
        positions[joueur_courant] = nouvelle_pos;

    } else {
        for (int i = 0; i < nb_joueurs; i++)
        {
            if (nouvelle_pos == positions[i] && i != joueur_courant) {
                positions[i] = pos_ancien;
                positions[joueur_courant] = nouvelle_pos;

                int cpt = 0;
                switch (plateau[nouvelle_pos])
                {
                case 'T':
                    cpt = 0;
                    for (int i = 0; i < nb_joueurs; i++) {
                        if (attente[i] == -1 && positions[i] == 53 && i!= joueur_courant) cpt++;
                    }
                    if (cpt % 2 == 0 || cpt == 0) {
                        attente[joueur_courant] = -1;
                    } else {
                        for (int i = 0; i < nb_joueurs; i++){
                            if (positions[i] == 53) attente[i] = 0;
                        }
                    }
                    break;

                case 'P':
                    cpt = 0;
                    for (int i = 0; i < nb_joueurs; i++) {
                        if (attente[i] == -1 && positions[i] == 74 && i!= joueur_courant) cpt++;
                    }
                    if (cpt % 2 == 0 || cpt == 0) {
                        attente[joueur_courant] = -1;
                    } else {
                        for (int i = 0; i < nb_joueurs; i++){
                            if (positions[i] == 74) attente[i] = 0;
                        }
                    }
                    break;

                case 'H':
                    attente[joueur_courant] = 2;
                    break;
                
                default:
                    break;
                }
                break;
            }
        }
        if(positions[joueur_courant] == pos_ancien) positions[joueur_courant] = nouvelle_pos;
    }
}











int avancer_joueur(char *plateau,
                   int *positions,
                   int *attente,
                   const int joueur_courant,
                   const int nb_joueurs,
                   int des[2],
                   const bool premier_tour)
{   
    int pos_jcourant = positions[joueur_courant]+des[0]+des[1];
    if(pos_jcourant>99) {
        pos_jcourant = 99 - (positions[joueur_courant]+des[0]+des[1]-99);
    }

    if (premier_tour) {
        if ((des[0] == 6 && des[1]== 3) ||(des[0] == 3 && des[1]== 6)) {
            pos_jcourant = 40;
            //Premier lancer direction case 40
        } else if ((des[0] == 4 && des[1]== 5) ||(des[0] == 5 && des[1]== 4)) {
            pos_jcourant = 89;
            //Premier lancer direction case 89
        }
    

    } 
    int cpt = 0;
    //Gestion des cases Oies.
    while(pos_jcourant%9 == 0 && pos_jcourant<=92) {
                pos_jcourant+=des[0]+des[1];
                if(pos_jcourant>99) {
                    pos_jcourant = 99 - (positions[joueur_courant]+des[0]+des[1]-99);
                }
            }
    //Gestion des autres cases.
    switch (plateau[pos_jcourant]) {
        case 'T':
            printf("entrer case trou\n");        
            cpt = 0;
            for (int i = 0; i < nb_joueurs; i++) {
                if (attente[i] == -1 && positions[i] == 53 && i != joueur_courant) cpt++;
            }
            if (cpt % 2 == 0 || cpt == 0) {
                attente[joueur_courant] = -1;
            } else {
                for (int i = 0; i < nb_joueurs; i++) {
                    if (positions[i] == 53) attente[i] = 0;
                }
            }
            break;

        case 'R':
            pos_jcourant = 16;
            break;

        case 'P':  
            cpt = 0;
            for (int i = 0; i < nb_joueurs; i++) {
                if (attente[i] == -1 && positions[i] == 74 && i != joueur_courant) cpt++;
            }
            if (cpt % 2 == 0 || cpt == 0) {
                attente[joueur_courant] = -1;
            } else {
                for (int i = 0; i < nb_joueurs; i++) {
                    if (positions[i] == 74) attente[i] = 0;
                }
            }
            break;

        case 'H':
            attente[joueur_courant] = 2;
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
    collisions(plateau, positions, attente, nb_joueurs, joueur_courant, pos_jcourant);
    if (pos_jcourant == 99) return joueur_courant;
    return -1;
      
}


void afficherPlateau(const char *plateau,const int *positions,const int nb_joueurs) {
    //printf("\033[0mAffichage du tableau avec représentation des cases \n\033[0;36m<");
    printf("\033[0;36m<");
    for (int i = 0; i < nb_joueurs; i++) {
        for (int j = 0;j<100; j++) {
            if (j == positions[i]) {
            printf("Joueur %d: case %d:(%c) ", i+1, positions[i], plateau[j]);
            }
        }
    }
    printf(">\033[0m\n");
}

bool desValides(int * des) {
    char rep[1];
    int a, b;
    scanf("%s",rep);
    if((int)rep[0] ==  'q') return false;
    scanf("%d", &b);
    a = (int)rep[0] - '0';
    while((a < 1 || a > 6 || b < 1 || b > 6)) {
        if ((int)rep[0] == 'q') break;
        printf("\033[1;31mValeurs de dés invalides !\033[0m\n");
        scanf("%s", rep);
        scanf("%d", &b);
        a = (int)rep[0] - '0';
    }
    if((int)rep[0] == 'q') return false;
    des[0] = a, des[1] = b;
    return true;
}


int playgame(int *attente,
             int *position,
             char* plateau,
             const int nb_joueurs,
             const int tours) {
    int i = tours;
    int des_joueur[2];
    bool continuer = true;
    int statut = -1;
    while(statut == -1){
        if(attente[i%nb_joueurs] == 0) {
            printf("\033[1;33mJoueur %d : ",i%nb_joueurs+1);
            des_joueur[0] = 0, des_joueur[1] = 1;
            continuer = desValides(des_joueur);
            if(!continuer) {
                //METTRE SAUVEGARDE ICI
                return -1; //retourne -1 en cas d'arrêt de partie
            }
            if (i < nb_joueurs) {
                statut = avancer_joueur(plateau, position, attente, i%nb_joueurs, nb_joueurs, des_joueur, true);
            } else {
                statut = avancer_joueur(plateau, position, attente, i%nb_joueurs, nb_joueurs, des_joueur, false);
            }
            afficherPlateau(plateau, position, nb_joueurs);
        } else if(attente[i%nb_joueurs] > 0) {
            printf("Joueur %d se repose à l'hotel. (encore %d tour)\n", i%nb_joueurs+1, attente[i%nb_joueurs]);
            attente[i%nb_joueurs] -= 1;
        } else {
            if (position[nb_joueurs] == 74) {
                printf("Joueur %d est en prison, il passe son tour.\n", i%nb_joueurs+1);
            } else {
                printf("Joueur %d est coincé dans le trou, il passe son tour.\n", i%nb_joueurs+1);
            }
        }
        i++;
        if(statut == -1) {
            statut = -2;
            for(int i = 0; i < nb_joueurs; i++) {
                if(attente[i] != -1) {
                    statut = -1;
                }
            }
        }
    }
    if(statut == -2) return -2;
    return i%nb_joueurs; //retourne l'index du gagnant
}


int main(int argc, char * argv[]) {
    char *plateau = plateau_oie();
    int res = -1;
    if(argc > 1){
        FILE *save_file = fopen(argv[1], "r");
        if(save_file == NULL) {
            //Si le fichier est introuvable, save est NULL donc on fait une erreur.
            printf("Erreur: fichier introuvable !\n");
            return 1;
        }
        //Recupération du contenu de la sauvegarde
        char line[4];
        int num_line = 0;
        int nb_joueurs;
        int attente[4]; // Vérifie si le joueur peut jouer (On variera avec scanf)
        int positions[4]; // même chose qu'avec attente
        int i;
        int statut = -1;
        for(; fgets(line, 4, save_file);) {
            line[strcspn(line, "\n")] = 0;
            if(num_line == 0 && !(line[0] == 'J' && line[1] == 'O')) {
                printf("Erreur : fichier de sauvegarde corrompu !\n");
                return 2;
            }
            
            if(strlen(line) != 0 && line[0] != ' ') {
                //Condition pour ignorer les lignes vides / retour à la lignes / etc...
                if(num_line == 1){
                //Recupération ud nombre de joueurs
                if((int)line[0] - '0' < 2 || (int)line[0] - '0' > 4) {
                    printf("Erreur : fichier de sauvegarde corrompu !\n");
                    return 2;
                }
                nb_joueurs = (int)line[0] - '0';
                i = 0;
                
            }
                if(num_line > 1){
                    int des[2] = {(int)line[0] - '0', (int)line[2] - '0'};
                    if(des[0] > 6 || des[0] < 1 || des[1] > 6 || des[1] < 1) {
                        printf("Erreur : fichier de sauvegarde corrompu !\n");
                        return 2;
                    }
                    if (attente[i%nb_joueurs] > 0) {
                        attente[i%nb_joueurs]--;
                    } else {
                        if (i<nb_joueurs-1){
                            statut = avancer_joueur(plateau, positions, attente, i%nb_joueurs, nb_joueurs, des, true);
                        } else {
                            statut = avancer_joueur(plateau, positions, attente, i%nb_joueurs, nb_joueurs, des, false);
                        }
                        if(statut != -1) break;
                    }
                    i++;
                }
                num_line++;
            }
        }
        fclose(save_file);//On ferme le fichier de sauvegarde.


        //On recréer la partie par rapport à la sauvegarde
        int nb_tours = num_line - 2;
        char *status_partie = "non ";
        if (statut != -1) status_partie = " ";
        printf("Chargement de partie : %d joueurs, %d tours simulés, partie %sterminée\n", nb_joueurs, nb_tours, status_partie);
        afficherPlateau(plateau, positions, nb_joueurs);
        printf("%s\n", plateau);
        if(statut == -1) res = playgame(attente, positions, plateau, nb_joueurs, i);
    } else {
        //On créer une nouvelle partie à partir de rien
        int nb_tours = 0;
        int nb_joueurs;
        char *status_partie = "non ";
        printf("\033[1;33mCombien de joueur ? ");
        scanf("%d", &nb_joueurs);printf("\033[0m");
        while(nb_joueurs < 2 || nb_joueurs > 4){
            scanf("%d", &nb_joueurs);
            printf("Valeur invalide, le total de joueur doit être entre 2 et 4 compris.\nCombien de joueur ? ");
        }
        int attente[4]; // Vérifie si le joueur peut jouer (On variera avec scanf)
        int positions[4]; // même chose qu'avec attente
        afficherPlateau(plateau, positions, nb_joueurs);
        res = playgame(attente, positions, plateau, nb_joueurs, 0);
    }
    if(res > -1)       printf("\033[1;32mPartie finit :\033[0m Le joueur gagnant est le numéro %d. Bravo !\n", res);
    else if(res == -2) printf("\033[1;31mPartie finit :\033[0m Tout les joueurs sont bloqués.\n");
    else if(res == -1) printf("\033[1;31mPartie finit :\033[0m Jeu arrêté, partie pas sauvegardé.\n");
    return 0;
}
