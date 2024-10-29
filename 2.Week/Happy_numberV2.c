#include <stdio.h>
#include <stdbool.h>

int Square(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int a = n, b = n;
    do {
        a = Square(a);
        b = Square(Square(b));
    } while (a != b);
    return a == 1;
}

int main(){

    printf("%d\n",isHappy(7));

}
