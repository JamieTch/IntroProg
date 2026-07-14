#include <stdio.h>
int main() {
    /* Ignorieren Sie alles über diesem Kommentar */

    3 + 2;

    printf("3 + 2 is %i\n", 3 + 2);

    int x = 3 + 2;
    printf("x is %i\n", x);

    x = -2;
    printf("x is now %i\n", x);

    x = x + 5;
    printf("and now x is %i\n", x);

    if (x) {
        printf("Hubba Wubba!\n");
    }

    if (x > 99) {
        printf("Plömpf!%i%i\n", x, 30);
    }

    printf("beginnng to loop down from %i\n", x);
    while (x > 0) {
        printf("----I'm looping! %i\n", x);
        x = x - 1;
    }
    printf("stopped looping at %i\n", x);

    for (int xyz = 0; xyz < 6; xyz = xyz + x) {
        printf("xy is %i\n", xyz);
    }

    /* Ignorieren Sie alles unter diesem Kommentar */
    return 0;
}