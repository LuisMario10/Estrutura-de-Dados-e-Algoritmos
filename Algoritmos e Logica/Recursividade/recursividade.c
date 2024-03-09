#include <stdio.h>

void count100(int num) {
    if(num <= 100) {
        printf("%i\n", num);
        count100(num + 1);
    }
}

int main(void) {
    count100(1);
    return 0;
}