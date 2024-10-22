#include <stdio.h>
#include <stdlib.h>

int sizeT = 2;

int main(int argc, char *argv[]) {
    char **string;
    string = (char**)calloc(sizeT,sizeof(char*));
    for(int i = 0;i<sizeT;i++){
        string[i] = (char*)calloc(25,sizeof(char));
    }
    for(int i = 0;i < sizeT;i++){
        fgets(string[i],25,stdin);
        printf("%d ---- %s \n",i,string[i]);
    }
    for(int i = 0;i<sizeT;i++){
        free(string[i]);
    }
    free(string);
    return 0;
}
