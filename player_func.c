#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int randint(int min, int max){
    /**
     * Return a int between @param min and @param max, both included.
    */
    return min + rand()%(max+1);
}





int main(void){
    srand(time(NULL)); //Initialisation de la seed pour les nombre random
    printf(randint(1, 6));
    return 0;
}