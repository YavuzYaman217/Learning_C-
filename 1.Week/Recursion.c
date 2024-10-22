#include <stdio.h>
#include <stdlib.h>

#define Size 100

int *memorySet;

void Allocate_memory(){
    memorySet = (int*)calloc(Size,sizeof(int));
}

int fib(int n){
    if(n <= 1){
        return 1;
    }else if(memorySet[n] != 0){
    return memorySet[n];
    }
    memorySet[n] = fib(n-1)+fib(n-2);
    return memorySet[n];
}




int Fib(int times,int i,int j){
     if (times == 0) {
        return i;
    }else{
        return Fib(times - 1,j,i+j);
    }

    /*if(time <= 1){
            return 1;
    }else{
        return Fib(times-1) + Fib(times-2);
    }*/

}





int Factorial(int Number) {
    if (Number == 0) {
        return 1;
    } else if(Number > 0) {
        return Number * Factorial(Number - 1);
    }
}

int main() {
    // printf("%d \n",Factorial(5));
    // printf("%d \n",Fib(3,1,1));
    Allocate_memory();
    printf("%d \n",fib(10));
    free(memorySet);

    return 0;
}
