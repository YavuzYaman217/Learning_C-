#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
     int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
    int temp = 1;
    for (int i = digitsSize - 1; i >= 0; i--) {
        int sum = digits[i] + temp;
        result[i + 1] = sum % 10;
        temp = sum / 10;
    }
    if (temp) {
        result[0] = temp;
        *returnSize = digitsSize + 1;
    } else {
        for (int i = 0; i < digitsSize; i++) {
            result[i] = result[i + 1];
        }
        *returnSize = digitsSize;
    }
    return result;
}



void  main(){
    int digits[3] = {4,7,9};
    plusOne(digits,sizeof(digits)/sizeof(digits[0]),sizeof(digits)/sizeof(digits[0]));
}
