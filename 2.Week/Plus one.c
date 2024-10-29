#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
     digits[digitsSize-1]++;
     int temp;
    for(int i = digitsSize-1;i >= 0 ;i--){
     if(digits[i] > 9){
        temp = digits[i] / 10;
        if(i >= 1){
            digits[i-1]+=temp;
            digits[i] = 0;
        }else{
            digits[i] /= 10;
            digitsSize++;
            digits[digitsSize-1] = digits[i]/10;
            }
        }
    }

}

int main(){
    int digits[] = {1,3,8};
    plusOne(digits,sizeof(digits)/sizeof(digits[0]),3);

}

/*

#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // Allocate memory for the worst-case scenario (e.g., [9,9,9] -> [1,0,0,0])
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));

    int carry = 1;  // Start by adding 1
    for (int i = digitsSize - 1; i >= 0; i--) {
        int sum = digits[i] + carry;
        result[i + 1] = sum % 10;  // Store the digit
        carry = sum / 10;           // Update the carry
    }

    // If there’s a leftover carry, place it at the start
    if (carry) {
        result[0] = carry;
        *returnSize = digitsSize + 1;  // New size with extra digit
    } else {
        // Shift the result array to ignore the first position (no carry case)
        for (int i = 0; i < digitsSize; i++) {
            result[i] = result[i + 1];
        }
        *returnSize = digitsSize;  // Size remains the same
    }

    return result;
}

// Example usage
int main() {
    int digits[] = {9, 9, 9};  // Example input
    int digitsSize = 3;
    int returnSize;

    int* result = plusOne(digits, digitsSize, &returnSize);

    printf("Result: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(result);

    return 0;
}

*/
