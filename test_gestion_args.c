#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    printf("il y a %d arguments.\n Et les arguments sont :\n",argc-1);
    for(int i = 1; i < argc; i++) {
        if(strcmp(argv[i], "-arg1")){
            if(i+1 <= argc-1){
                if(argv[i+1][0] != '-'){
                    if(strcmp(argv[i+1], (char*)'1')) {
                        printf("Oui");
                    } else {
                        printf("Non");
                    }
                }
            }
        }
        printf("%s\n",argv[i]);
    }
}