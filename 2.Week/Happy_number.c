#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool isHappy(int n) {
    int z;
    if(n >= 10){
        int temp1 = n/10;
        int temp2 = n%10;
        z = pow(temp1,2)+pow(temp2,2);
    }else{
        z = pow(n,2);
    }

    if(z == 100 || z == 1 || z == 1000){
        return 1;
    }else if(z > 100){
        return 0;
    }else {
        return isHappy(z);
    }
}

int main(){
    printf("%d",isHappy(7));
    return 0;
}


