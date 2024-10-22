#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if (x < 0) return false;
    char str[256];
    sprintf(str,"%d",x);

    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return false;
        }
    }
    return true;
}


void main(){
    printf("%d",isPalindrome(121));
}
