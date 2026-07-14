/*
Willkommen zum vierten Übungsblatt vom Programmierkurs.

Nachdem Sie in einem Terminal mittels des 'cd' Befehls in das Verzeichnis gewechselt sind, in dem diese Datei liegt,
können Sie mit folgendem Befehl ihre Lösungen überprüfen:
clang -std=c11 -g -Wall 04practice_test.c -o 04practice_test.o -lm && ./04practice_test.o

Auf diesem Blatt geht es primär darum, komplexe Probleme erfolgreich anzugehen.
*/

#include <stdio.h>
#include "04_canvas.h"

/*
Nehme eine dreistellige Zahl, sortiere ihre Ziffern absteigend, und subtrahiere von dieser Zahl die Zahl die
sich aus den aufsteigend sortierten Ziffern ergibt.
Wiederhole, bis zwei mal in Folge die gleiche Zahl herauskommt.

Beispiel:

792 ~> 972 - 279 = 693
693 ~> 963 - 369 = 594
594 ~> 954 - 459 = 495
495 ~> 954 - 459 = 495

Gebe in dieser Funktion zurück, wie viele Schritte die dreistellige Eingabezahl 'n' braucht, um bei einer Zahl anzukommen,
bei der die sortiere-und-subtrahiere Prozedur wieder die Zahl selbst ausgibt.

Beispiele: 'kaprekar_count_steps(792) == 3', 'kaprekar_count_steps(693) == 2',
           'kaprekar_count_steps(594) == 1', 'kaprekar_count_steps(495) == 0'

Hinweis: Sollte die Eingabe 'x' kleiner als 100 sein (also weniger als 3 Dezimalstellen besitzen), sollte sie trotzdem
dreistellig behandelt werden, indem Nullen vorangesetzt werden. D.H. 64 ~> 640 - 046 = 594.
*/

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

int sortier_zahl_nach_ziffern_aufsteigend(int x) {
    // Datentyp-Definition.
    typedef struct b_adische_darstellung_
    {
        int erste_stelle;
        int zweite_stelle;
        int dritte_stelle;
    } b_adische_darstellung;
    
    // Variablen-Defintion.
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
    
    // Gib Zahl in aufsteigender Ziffernfolge als int aus.
    int zahl_aufsteigend = 100 * test_zahl_absteigend.dritte_stelle + 10 * test_zahl_absteigend.zweite_stelle + 1 * test_zahl_absteigend.erste_stelle;

return zahl_aufsteigend;
}

int kaprekar_count_steps(int x) {
    // Variablendefinition.
    int count = 0;
    
    int n1 = sortier_zahl_nach_ziffern_absteigend(x) - sortier_zahl_nach_ziffern_aufsteigend(x);
    int n2 = sortier_zahl_nach_ziffern_absteigend(n1) - sortier_zahl_nach_ziffern_aufsteigend(n1);

    /*
    printf("n1 = %d", n1);
    printf("n2 = %d", n2);

    if (n1 == n2 && x == n1)
    {
        return count;
    }
    else if (n1 == n2)
    {
        count = count + 1;
        return count;
    }
    else
    {
        count = count + 2;
        return kaprekar_count_steps(n2);
    }
    */

    if (n1 != x)
    {
        count = count + 1;
    }
    else if (n1 != x && n1 != n2)
    {
        count = count + 2;
    }
    else if (x == n1 && n1 != n2)
    {
        count = count + 1;
    }
    
    x = n2;

    while (n1 != n2)
    {
        int n1 = sortier_zahl_nach_ziffern_absteigend(x) - sortier_zahl_nach_ziffern_aufsteigend(x);
        int n2 = sortier_zahl_nach_ziffern_absteigend(n1) - sortier_zahl_nach_ziffern_aufsteigend(n1);

        if (n1 == n2 && x == n1)
        {
            count = count + 1;
            return count;
        }
        else if (n1 == n2)
        {
            count = count + 2;
            return count;
        }
        else
        {
            count = count + 2;
            x = n2;
        }
    }
    return n2;
}

/*
Färbe alle Pixel (mit den Koordinaten '(x, y)') auf dem Canvas schwarz, für welche die sortiere-und-subtrahiere Aktion
von 'x' die Zahl 'y' ergibt.

Bonus: Gibt es ein Muster, dass man ausnutzen kann um 'kaprekar_count_steps' effizienter zu implementieren als
alle Schritte durchzuführen?
*/
Canvas plot_kaprekar(Canvas c) {
    // Variablen-Definition.
    int height;
    int witdh;

    // Äußere und innere For-Schleifen zum färben des Canvas.
    for (height = 0; height <= canvas_height(c) - 1; height++)
    {
        for (witdh = 0; witdh <= canvas_width(c) - 1; witdh++)
        {
            if (sortier_zahl_nach_ziffern_absteigend(witdh) - sortier_zahl_nach_ziffern_aufsteigend(witdh) == height)
            {
                c = canvas_set_black(c, witdh, height);
            }
        }
    }
    return c;
}