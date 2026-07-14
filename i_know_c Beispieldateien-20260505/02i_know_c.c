#include <stdio.h>
int main() {
    /* Ignorieren Sie alles über diesem Kommentar */

    if (0 == 1 || 2 == 3) {
        printf("Huh, that's odd.\n");
    } else if (0 == 0 && 2 == 3) {
        printf("Pretty disconcerting.\n");
    } else {
        printf("Everything is going according to plan.\n");
    }

    for (int x = 0; x < 6; x = x + 1) {
        for (int y = 0; y < 4; y = y + 1) {
            printf("(%d, %d)\n", x, y);
        }

        // printf("y ist %d\n", y); // Was würde hier passieren?
    }


    /* Ignorieren Sie alles unter diesem Kommentar */
    return 0;
}