#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<MLV/MLV_all.h>

/*projet du jeu de l'oie*/

/* définition du plateau*/

char* init_plateau()
{
    char plateau[100];
    char *plateau1 = plateau;
    for (int i = 0; i < 100; i++)
    {
        if(i % 9 == 0) plateau1[i] = 'O';

        if (i == 8) plateau1[i] = 'R';

        if (i == 53) plateau1[i] = 'T';

        if (i == 74) plateau1[i] = 'P';

        if (i == 31) plateau1[i] = 'H';

        if (i == 65) plateau1[i] = 'L';

        if (i == 94) plateau1[i] = 'X';

        else plateau1[i] = ' ';

        
    }

    return plateau1;
    
}


int main(int argc, char const *argv[])
{
    char* plateau = init_plateau();
    for (int i = 0; plateau[i] !='\0'; i++)
    {
        printf("%c\n",plateau[i]);
    }
    
    

    return 0;
}

 