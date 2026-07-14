/*
Willkommen zum dritten Übungsblatt vom Programmierkurs.

Nachdem Sie in einem Terminal mittels des 'cd' Befehls in das Verzeichnis gewechselt sind, in dem diese Datei liegt,
können Sie mit folgendem Befehl ihre Lösungen überprüfen:
clang -std=c11 -g -Wall 03practice_test.c -o 03practice_test.o -lm && ./03practice_test.o

Auf diesem Blatt geht es unter anderem um:

- Funktionsaufrufe
- Die Canvas
*/

#include <stdio.h>
#include "03_canvas.h"

/*
Geben Sie '1' zurück falls 'x' gerade ist, und '0' falls 'x' ungerade ist.
*/
int is_even(int x) {
    if (x % 2 == 0)
    {
        return(1);
    }
    else
    {
        return 0;
    }
}

/*
Geben Sie '1' zurück falls 'x' ungerade ist, und '0' falls 'x' gerade ist.
Die Ziffer '2' soll nicht direkt in Ihrer Lösung vorkommen. Nutzen Sie stattdessen 'is_even'.
*/
int is_odd(int x) {
    if (is_even(x) == 1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/*
Erstellen Sie folgende Zeichnung auf der Canvas:
(Jedes X symbolisiert einen schwarzen Pixel an den jeweiligen (x,y)-Koordinaten)

5---------
4-X-----X-
3---------
2-X-----X-
1--XXXXX--
0---------
/012345678

Nutzen Sie am besten eine Schleife für die Mundlinie.
*/
Canvas draw_smiley(Canvas c) {
    int i;
    c = canvas_set_black(c, 1, 4);
    c = canvas_set_black(c, 7, 4);
    c = canvas_set_black(c, 1, 2);
    c = canvas_set_black(c, 7, 2);
    for (i = 2; i <= 6; i++)
    {
        c = canvas_set_black(c, i, 1);
    }
    return c;
}

/*
Zeichnen Sie ein klassisches Schachbrettmuster, startend bei (0,0) mit Schwarz
*/
Canvas draw_chessboard(Canvas c) {
    // Variablen
    int start_witdh;
    int witdh;
    int height;
    // Äußere For-Schleife, welche über die Y-Reihen iteriert und als Abbruchbedingung die Canvas Höhe (Y-Wert) hat.
    for (height = 0; height <= canvas_height(c) - 1; height++)
    {
        // If-Bedingung für die innere For-Schleife, welche sicherstellt, dass nur die Reihen mit ungeraden Y-Werten eingefärbt werden.
        if (is_odd(height) == 1)
        {
            start_witdh = 1;
        }
        else
        {
            start_witdh = 0;
        }
        // Innere For-Schleife färbt die Reihen und erhöht die Schleifenvariablen nach jeder Iteration um +2, wodurch mit der obigen If-Bedingung das Schachbrettmuster entsteht.
        for (witdh = start_witdh; witdh <= canvas_width(c) - 1; witdh = witdh + 2)
        {
            c = canvas_set_black(c, witdh, height);
        }
    }
    return c;
}

/*
Diese Funktion soll gefüllte Stufen zeichnen, welche von unten links anfangend nach rechts aufsteigen.
Jede Stufe soll eine Breite von `step_width` haben und eine Höhe von `step_height` (beide sind immer größer als null).
Für mehr Details schauen Sie einfach in das Test-Feedback für den ersten Testfall.
*/
Canvas i_told_you_about_stairs(Canvas c, int step_width, int step_height) {
    int height;
    int witdh;
    int witdh_raised = 0;
    int step_witdh_start_value = step_width;
    int step_height_start_value = step_height;
    int flag = 1;
    for (height = 0; height <= step_height - 1; height++)
    {
        // printf("Height: %d", height);
        if (height >= canvas_height(c) - 1)
        {
            step_width = canvas_width(c);
            // height = -1;
        }
        for (witdh = witdh_raised; witdh <= step_width; witdh++)
        {
            // printf("witdh: %d", witdh);
            // printf("-> Witdh: %d - Height: %d <-", witdh, height);
            if (witdh <= canvas_width(c) - 1)
            {
                c = canvas_set_black(c, witdh, height);
                // return c;
                // printf("step_witdh: %d", step_width);
            }
            else
            {
                step_width = canvas_width(c) - 1;
            }
        }
        /*if (witdh == canvas_width(c))
        {
            step_width = canvas_width(c);
        }
        */

    // if (height == canvas_height(c))
    // {
        // step_height = canvas_height(c);
    // }
        // printf("%d", height);

        // If-Bedinung zum Anpassen der Koordinatenrahmen der Stufen.
        if (height == step_height - 1 && flag == 1)
        {
            step_height = step_height + step_height_start_value;
            witdh_raised = witdh_raised + step_witdh_start_value;
            step_width = step_width + step_witdh_start_value;
            height = - 1;
            // printf("Height in If-Statement: %d", height);
        }
        // If-Bedingung, falls Canvas-Höhe erreicht wurde.
        if ((height == canvas_height(c) - 1) && ((height != canvas_height(c) - 1) || (witdh != canvas_width(c) - 1)))
        {
            // printf("If-Condition set at -> Height: %d, Witdh: %d", height, witdh);
            step_height = canvas_height(c) - 1;
            height = -1;
            step_width = canvas_width(c) - 1;
            flag = 0;
            // return c;
        }
        //  printf("->Witdh: %d - Height: %d<-", witdh, height);
        /*if (witdh == canvas_width(c))
        {
            return c;
        }
        */        
    }
    return c;
}