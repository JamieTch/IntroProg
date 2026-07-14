/*
Willkommen zum fünften Aufgabenblatt vom Programmierkurs. Auf diesem Aufabenblatt geht es um Rekursion.

Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
clang -std=c11 -g -Wall 05ex_test.c -o 05ex_test.o -lm && ./05ex_test.o
*/

#include "05_canvas.h"
#include <stdio.h>
#include <math.h>

/*
Aufgabe 1a:
Zeichnen Sie eine horizontale Linie der Länge `width`, deren am weitesten links liegender Pixel bei `(x, y)` ist.
Wenn Teile der Linie außerhalb der Canvas liegen, dann sollen diese Teile ignoriert werden. Alles was in die Canvas passt, muss aber gezeichnet werden.

_Benutzen Sie keine Schleifen - Die Aufgabe soll über Rekursion gelöst werden!_

*/
Canvas recursive_line(Canvas c, int x, int y, int width) {

    // If-Bedingung, die direkt c zurückgegeben, falls der Punkt (x, y) auf der y-Achse außerhalb der Canvas liegt.
    if (y < 0)
    {
        return c;
    }
    else
    {   
        // Falls width größer als Null ist wird die Rekursion fortgesetzt, andernfalls wird c zurückgegeben.
        if (width > 0)
        {
            // If-Bedingung, welche c zurückgibt, falls x die maximale Canvas Breite erreicht.
            if (x <= canvas_width(c) - 1)
            {
                // If-Bedingung falls x kleiner als 0 ist (d.h. links außerhalb der zulässigen Canvas-Bound).
                if (x < 0)
                {
                    // Die Länge wird um die außerhalb der Canvas-Bound liegende "Strecke" verkürzt.
                    width = width + x;
                    // Setzt Start-x auf 0.
                    x = x + (-x);
                    // printf("x is: %d", x);
                }
                // Färbt den aktuellen Pixel, erhöht x um eins, senkt width um eins und ruft die Funktion erneut auf.
                c = canvas_set_black(c, x, y);
                x = x + 1;
                width = width - 1;
                return recursive_line(c, x, y, width);
            }
            else
            {
                return c;
            }
        }
        else
        {
            return c;
        }
    }
}

/*
Aufgabe 1b:
Zeichnen Sie ein Rechteck mit der Breite `width` und der Höhe `height`. Der Pixel der linken unteren Ecke liegt bei `(x, y)`.
Wenn Teile des Rechtecks außerhalb der Canvas liegen, dann sollen diese Teile ignoriert werden. Alles was in die Canvas passt, muss aber gezeichnet werden.

_Benutzen Sie keine Schleifen, die Aufgabe soll über Rekursion gelöst werden!_
*/

int x_start;
int y_start;
int width_zwischenspeicher = 0;

Canvas recursive_rectangle(Canvas c, int x, int y, int width, int height) {

    if (height > 0)
    {
        if (y <= canvas_height(c) - 1)
        {
            if (y < 0)
            {
            // Die Höhe wird um die außerhalb der Canvas-Bound liegende "Strecke" verkürzt.
                height = height + y;
                // Setzt Start-y auf 0.
                y = y + (-y);
                // printf("y is: %d", y);
            }

            recursive_line(c, x, y, width);
            y = y + 1;
            height = height - 1;
            recursive_rectangle(c, x, y, width, height);
        }
        else
        {
            return c;
        }
    }
    else
    {
        return c;
    }
return c;
}

/*
Aufgabe 2:
Die Fibonaccizahlen sind wie folgt definiert:

- die nullte Fibonaccizahl ist 1,
- die erste Fibonaccizahl ist ebenfalls 1, und
- jede weitere Fibonaccizahl ist die Summe der zwei vorigen Fibonaccizahlen.

Berechne die `n`-te Fibonaccizahl.
*/

int fibonacci_helper(int n1, int n2, int n) {

    // If-Bedingung, welche solange n > 1 ist, die letzten beiden Fibonaccizahlen addiert und die Variablen so speichert, dass die neu aufsummierte Zahl in 'n2' und die Zahl, welche vorher 'n2' zugewiesen war nun 'n1' zugewiesen ist.
    // n wird zusätzlich um eins verringert und die Hilfsfunktion rekursiv erneut aufgerufen.
    if (n > 1)
    {
        int n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
        n = n - 1;
        return fibonacci_helper(n1, n2, n);
    }
    
    // Else-Bedingung, falls n > 1 nicht mehr gilt, gibt die errechnete `n`-te Fibonaccizahl zurück.
    else
    {
        return n2;
    }
}

int fibonacci(int n) {
    // Variablen-Definition.
    int n1 = 1;
    int n2 = 1;
    
    // Hilfsfunktionsaufruf.
    n2 = fibonacci_helper(n1, n2, n);

    return n2;
}

/*
Aufgabe 3:
Implementieren Sie einen schwarzen Fülleimer. Gegeben eine Koordinate `(x, y)` auf einer (bereits bemalten) Canvas, soll die komplette
zusammenhängende Fläche aller Pixel der selben Farbe (schwarz oder weiß) schwarz gefärbt werden.
Zwei Pixel sind Teil der selben Fläche wenn sie die selbe Farbe haben und direkt benachbart sind. Jeder Pixel hat bis
zu vier direkte Nachbarn - die Diagonalen zählen nicht.

Funktionen, um die Farbe eines Pixels auf der Canvas zu bestimmen, sind im Headerfile der Canvas dokumentiert.
*/

Canvas bucket_fill_black(Canvas c, int x, int y) {

    // If-Bedingungen, falls x+1 weiß ist (Färbt den x+1'ten Pixel schwarz und ruft die Funktion erneut auf).
    // Äußere If-Bedingung stellt sicher, dass die innere If-Bedinung nicht in dem Fall 'x == canvas_width(c) - 1' durchgeführt wird, da es sonst durch die Prüfung des pixel_is_white zu einem Error an diesem Pixel kommt. Selbiges gilt für alle folgenden definierten If-Blöcke.
    if (x != canvas_width(c) - 1)
    {
        if (pixel_is_white(c, x + 1, y) == 1 && x + 1 <= canvas_width(c) - 1)
        {
            c = canvas_set_black(c, x + 1, y);
            bucket_fill_black(c, x + 1, y);
        }
    }

    // If-Bedingungen, falls x-1 weiß ist (Färbt den x-1'ten Pixel schwarz und ruft die Funktion erneut auf).
    if (x != 0)
    {
        if (pixel_is_white(c, x - 1, y) == 1 && x - 1 >= 0)
        {
            c = canvas_set_black(c, x - 1, y);
            bucket_fill_black(c, x - 1, y);
        }
    }

    // If-Bedingungen, falls y+1 weiß ist (Färbt den y+1'ten Pixel schwarz und ruft die Funktion erneut auf).
    if (y != canvas_height(c) - 1)
    {
        if (pixel_is_white(c, x, y + 1) == 1 && y + 1 <= canvas_height(c) - 1)
        {
            c = canvas_set_black(c, x, y + 1);
            bucket_fill_black(c, x, y + 1);
        }
    }
    
    // If-Bedingungen, falls y-1 weiß ist (Färbt den y-1'ten Pixel schwarz und ruft die Funktion erneut auf).
    if (y != 0)
    {
        if (pixel_is_white(c, x, y - 1) == 1 && y - 1 >= 0)
        {
            c = canvas_set_black(c, x, y - 1);
            bucket_fill_black(c, x, y - 1);
        }
    }
    return c;
}

Canvas bucket_fill(Canvas c, int x, int y) {
    
    // If-Bedinung prüft ob der Eingangspixel weiß ist. Falls true, wird die rekursive 'bucket_fill_black' Funktion aufgerufen und das Ergebnis zurückgegeben.
    if (pixel_is_white(c, x, y))
    {
        c = bucket_fill_black(c, x, y);
        return c;
    }
    return c;
}