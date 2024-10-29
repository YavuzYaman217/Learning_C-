#include <stdio.h>
#include <stdlib.h>


int hammingWeight(int n) {
    int *BinArr = (int*)malloc(32*sizeof(int));
    int j = 0,outp = 0;
    int number = n;

    do{
        BinArr[j++] = number%2;
        number /=2;
    }while(number >= 1);

    for(int i = 0;i < size;i++){
        printf(" %d ",BinArr[i]);
        if(BinArr[i] == 1){
            outp++;
        }
    }

    free(BinArr);
    printf("\n");
    return outp;

}

int main(){
    printf("%d",hammingWeight(11));
    return 0;
}
