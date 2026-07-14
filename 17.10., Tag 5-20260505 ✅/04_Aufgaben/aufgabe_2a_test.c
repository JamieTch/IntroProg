#include <stdio.h>

int hailstone(int n) {
        // Variablen defintion.
        int hailstone = 0;
        
        // While-Schleife mit If-Bedingung zum Berechnen der Hailstone-Zahl.
        while (n != 1)
        {
            if (n % 2 == 0)
            {
                n = n / 2;
                hailstone = hailstone + 1;
            }
            else
            {
                n = n * 3 + 1;
                hailstone = hailstone + 1;
            }
        }
        return hailstone;
    }

int kaprekar_count_steps(int x) {
    // Datentyp-Definition.
    typedef struct b_adische_darstellung_
    {
        int erste_stelle;
        int zweite_stelle;
        int dritte_stelle;
    } b_adische_darstellung;
    
    b_adische_darstellung test_zahl = {.erste_stelle = 1, .zweite_stelle = 2, .dritte_stelle = 3};

    test_zahl.erste_stelle = x % 10;
    x = x / 10;
    test_zahl.zweite_stelle = x % 10;
    x = x / 10;
    test_zahl.dritte_stelle = x % 10;

    b_adische_darstellung test_zahl_aufsteigend;

    if (test_zahl.erste_stelle > test_zahl.zweite_stelle)
    {
        test_zahl_aufsteigend.erste_stelle = test_zahl.erste_stelle;
        test_zahl_aufsteigend.zweite_stelle = test_zahl.zweite_stelle;
    }
    else
    {
        test_zahl_aufsteigend.erste_stelle = test_zahl.zweite_stelle;
        test_zahl_aufsteigend.zweite_stelle = test_zahl.erste_stelle;
    }
    
    if (test_zahl_aufsteigend.zweite_stelle > test_zahl.dritte_stelle)
    {
        test_zahl_aufsteigend.dritte_stelle = test_zahl.dritte_stelle;
    }
    else
    {

        test_zahl_aufsteigend.dritte_stelle = test_zahl_aufsteigend.zweite_stelle;
        test_zahl_aufsteigend.zweite_stelle = test_zahl.dritte_stelle;

        if (test_zahl_aufsteigend.erste_stelle < test_zahl_aufsteigend.zweite_stelle)
        {
            int zwischenspeicher = test_zahl_aufsteigend.erste_stelle;
            test_zahl_aufsteigend.erste_stelle = test_zahl_aufsteigend.zweite_stelle;
            test_zahl_aufsteigend.zweite_stelle = zwischenspeicher;
        }
    }
    
    printf("%d%d%d", test_zahl_aufsteigend.erste_stelle, test_zahl_aufsteigend.zweite_stelle, test_zahl_aufsteigend.dritte_stelle);
}

int sortier_zahl_nach_ziffern_absteigend(int x) {
    // Datentyp-Definition.
    typedef struct b_adische_darstellung_
    {
        int erste_stelle;
        int zweite_stelle;
        int dritte_stelle;
    } b_adische_darstellung;
    
    // Variablen-Definition.
    b_adische_darstellung test_zahl = {.erste_stelle = 1, .zweite_stelle = 2, .dritte_stelle = 3};
    b_adische_darstellung test_zahl_absteigend;
    int x_zwischenspeicher = x;
    // int stellen_test = 0;

    // Bestimme einzelne Ziffern und ordne sie dem Datentyp zu.
    test_zahl.erste_stelle = x % 10;

    // Falls x einstellig ist, füge zwei führende Nullen an.
    if (x_zwischenspeicher < 10)
    {
        test_zahl.zweite_stelle = 0;
        test_zahl.dritte_stelle = 0;
    }
    else
    {
        x = x / 10;
        test_zahl.zweite_stelle = x % 10;

        // Falls x zweistellig ist, füge eine führende Null an.
        if (x_zwischenspeicher / 10 < 10)
        {
            test_zahl.dritte_stelle = 0;
        }
        else
        {
            x = x / 10;
            test_zahl.dritte_stelle = x % 10;
        }
    }

    // printf("%d%d%d", test_zahl.erste_stelle, test_zahl.zweite_stelle, test_zahl.dritte_stelle);

    // Sortierung absteigend durch If-Bedingungen.
    if (test_zahl.erste_stelle > test_zahl.zweite_stelle)
    {
        test_zahl_absteigend.erste_stelle = test_zahl.erste_stelle;
        test_zahl_absteigend.zweite_stelle = test_zahl.zweite_stelle;
    }
    else
    {
        test_zahl_absteigend.erste_stelle = test_zahl.zweite_stelle;
        test_zahl_absteigend.zweite_stelle = test_zahl.erste_stelle;
    }
    
    if (test_zahl_absteigend.zweite_stelle > test_zahl.dritte_stelle)
    {
        test_zahl_absteigend.dritte_stelle = test_zahl.dritte_stelle;
    }
    else
    {
        test_zahl_absteigend.dritte_stelle = test_zahl_absteigend.zweite_stelle;
        test_zahl_absteigend.zweite_stelle = test_zahl.dritte_stelle;

        if (test_zahl_absteigend.erste_stelle < test_zahl_absteigend.zweite_stelle)
        {
            int zwischenspeicher = test_zahl_absteigend.erste_stelle;
            test_zahl_absteigend.erste_stelle = test_zahl_absteigend.zweite_stelle;
            test_zahl_absteigend.zweite_stelle = zwischenspeicher;
        }
    }
    
    // Gib Zahl in absteigender Ziffernfolge als int aus.
    int zahl_absteigend_int = 100 * test_zahl_absteigend.erste_stelle + 10 * test_zahl_absteigend.zweite_stelle + 1 * test_zahl_absteigend.dritte_stelle;

return zahl_absteigend_int;
}

int main() {
    /*int hailstone_number = hailstone(1);
    printf("Hailstone number is: %d", hailstone_number);
    */
    int sortierte_zahl_test = sortier_zahl_nach_ziffern_absteigend(891);
    printf("Sortierte Zahl ist: %d", sortierte_zahl_test);
}