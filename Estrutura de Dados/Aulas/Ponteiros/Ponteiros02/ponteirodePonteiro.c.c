#include <stdio.h>
#include <stdlib.h>

int n = 10;
int *p1 = &n;
int **p2 = &p1;


int main() {
    printf("&n = %p, n = %i\n", &n, n);
    printf("&p1 = %p, p1 = %p, *p1 = %i\n", &p1, p1, *p1);
    printf("&p2 = %p, p2 = %p, *p2 = %p, **p2 = %i\n\n", &p2, p2, *p2, **p2);
    return 0;
}