#include <stdio.h>

int add(int x, int y) {
    return x + y;
}

void print_7() {
    int x = 5;
    x = add(x, 2);
    printf("%d\n", x);
}

int main() {
    print_7();
}