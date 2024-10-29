#include <stdio.h>
#include <stdlib.h>

int singleNumber(int* nums, int numsSize) {
    int result = 0;
    for(int i = 0;i < numsSize;i++){
        result ^= nums[i];
    }
    return result;
}



int main(){
    int Numbers[3] = {2,2,1};
    printf("%d",singleNumber(Numbers,3));

    return 0;
}
