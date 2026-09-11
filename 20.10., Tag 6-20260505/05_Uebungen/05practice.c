/*
Willkommen zum fünften Übungsblatt vom Programmierkurs.

Nachdem Sie in einem Terminal mittels des `cd` Befehls in das Verzeichnis gewechselt sind, in dem diese Datei liegt,
können Sie mit folgendem Befehl ihre Lösungen überprüfen:
clang -std=c11 -g -Wall 05practice_test.c -o 05practice_test.o -lm && ./05practice_test.o

Auf diesem Blatt geht es um Rekursion.
*/

#include <stdio.h>
#include "05_canvas.h"
#include "/Users/Jamie.Tchassanti/Repositories/IntroProg/16.10., Tag 4-20260505 ✅/03_Uebungen/03practice.c"

/*
Zeichne eine vertikale Linie der Höhe `height` mit unterstem Pixel an Position `(x, y)`.

Löse die Aufgabe ohne Schleifen zu verwenden.
*/
Canvas vertical_line(Canvas c, int x, int y, int height) {
    
    /*
    if (height > 0)
    {
        c = canvas_set_black(c, x, y);
        vertical_line(c, x, y + 1, height - 1);
    }

    */

    // If-Bedingung, die direkt c zurückgegeben, falls der Punkt (x, y) auf der y-Achse außerhalb der Canvas liegt.
    if (x < 0)
    {
        return c;
    }
    else
    {   
        // Falls width größer als Null ist wird die Rekursion fortgesetzt, andernfalls wird c zurückgegeben.
        if (height > 0)
        {
            // If-Bedingung, welche c zurückgibt, falls x die maximale Canvas Breite erreicht.
            if (y <= canvas_height(c) - 1)
            {
                // If-Bedingung falls x kleiner als 0 ist (d.h. links außerhalb der zulässigen Canvas-Bound).
                if (y < 0)
                {
                    // Die Länge wird um die außerhalb der Canvas-Bound liegende "Strecke" verkürzt.
                    height = height + y;
                    // Setzt Start-x auf 0.
                    y = y + (-y);
                    // printf("x is: %d", x);
                }
                // Färbt den aktuellen Pixel, erhöht x um eins, senkt width um eins und ruft die Funktion erneut auf.
                c = canvas_set_black(c, x, y);
                return vertical_line(c, x, y + 1, height - 1);
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
Wie viele Dezimalstellen hat `n` (`n` ist nicht negativ)?

Löse die Aufgabe ohne Schleifen zu verwenden.
*/

int count_digits_helper_funtion(int n, int count) {

    if (n / 10 != 0)
    {
        return count_digits_helper_funtion(n = n / 10, count + 1);
    }

    return count;
}

int count_digits(int n) {
    
    int count = 1;

    count = count_digits_helper_funtion(n, count);

    return count;
}

/*
Zeichne eine Pyramide: die unterste Zeile ist komplett schwarz, die zweitunterste Zeile lässt den ersten und letzten Pixel weiß, die drittunterste Zeile lässt die ersten zwei und die letzten zwei Pixel weiß, usw..

Löse die Aufgabe ohne Schleifen zu verwenden.
*/

Canvas pyramid_help_function(Canvas c, int x, int y, int n, int m, int width_substraction) {

    // Äußerste If-Bedingung, begrenzt die Rekursion auf die Canvas Höhe.
    if (canvas_height(c) > y)
    {
        // Innere If-Bedingung subtrahiert die Variable n (Anzahl der ersten und letzten Pixel, welche in jeder Zeile weiß gelassen werden und mit jeder rekursiven Zeilenerhöhung um den in der Aufgabenstellung genannten Wert (+2) erhöht werden) von der Canvas Breite, um so die Anzahl der einzifärbenden Pixel ('Pyramidenstufen') für jede Zeile zu erlangen. 
        // Diese Differenz wird dann wiederrum für jedem eingefärbten x-Wert für jede Zeile um eins verringert, bis 0 erreicht wird. Dadurch wird für jede Zeile die korrekte Anzahl an Pixeln eingefärbt.
        if ((canvas_width(c) - n) - width_substraction > 0)
        {
            canvas_set_black(c, x + m, y);
            pyramid_help_function(c, x + 1, y, n, m, width_substraction + 1);
        }

        // Else-Statement für den Fall, dass alle nötigen Pixel einer Zeile eingefärbt wurden (Wenn canvas_width(c) - n) - width_substraction <= 0 gilt).
        // Dann wird x auf Null gesetzt, die Zeile um eins erhöht (y + 1), die Anzahl der ersten und letzten Pixel, welche weiß bleiben für die nächste Zeile um zwei erhöht (n + 2), die Startvariable für den ersten Pixel der nöchsten Zeile welcher eingefärbt wird um eins erhöht (m + 1) und width_substraction auf Null gestzt.
        else
        {
            /*
            n = n * 2;
            m = m + 1;
            height_substraction = height_substraction - 1;
            */
            pyramid_help_function(c, 0, y + 1, n + 2, m + 1, width_substraction = 0);
        }
    }
    else
    {
        return c;
    }
return c;
}

Canvas pyramid(Canvas c) {

    // Variablen-Definition.
    int x = 0;
    int y = 0;
    int width_substraction = 0;
    // Pyramidenbreite (Wird bei jeder y-Erhöhung um den Faktor Zwei erhöht, um die ersten und letzten Pixel zu bestimmen, welche freigelassen werden).
    int n = 0;
    // x-Offset.
    int m = 0;
    
    // Aufruf der rekursiven Hilfsfunktion.
    pyramid_help_function(c, x, y, n, m, width_substraction);

    return c;
}

/*
Zeichne ein Rechteck der Breite `width` und der Höhe `height` mit einem Schachbrettmuster. Der Pixel der linken unteren Ecke liegt bei `(x, y)` und ist schwarz.

Löse die Aufgabe ohne Schleifen zu verwenden.
*/

// Modifizierte Funktion aus '05ex.c' als Hilfsfunktion zum Line-zeichnen.
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
                x = x + 2;
                width = width - 2;
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

Canvas chessboard_rectangle(Canvas c, int x, int y, int width, int height) {

    // Rekursion läuft solange, wie height > 0. 'height ' wird nach jedem durchlaufen der Funktion, vor dem nächsten rekusriven Aufruf der Funktion, um eins reduziert.
    if (height > 0)
    {
        // Falls die y-Zeile die Canvas Höhe erreicht, bricht die Funktion ab und es wird 'c' zurückgegeben.
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
            
            // If-Bedinungen, welche festlegen, dass jede zweite Zeile ab x + 1 begonnen wird die Pixel zu färben. Dabei wrid geprüft, ob der erste Pixel der letzten Zeile weiß ist. Ist das der fall, wird der erste Pixel der aktuellen Zeile schwarz gefärbt. Wenn nicht, wird ab x + 1 angefangen zu färben. Eine Ausnahme bildet der Fall falls y == 0 ist. Da die 'pixel_is_white' Funktion bei y == -1 einen Fehler wiedergeben würde, wurde ein Ausnahmefall für diese Zeile kreiert.
            if (y == 0)
            {
                recursive_line(c, x, y, width);
            }
            
            else if (pixel_is_white(c, x, y - 1))
            {
                recursive_line(c, x, y, width);
            }

            else
            {
                recursive_line(c, x + 1, y, width - 1);
            }
            
            // y-Zeile wird um +1 erhöht, 'height' um eins reduziert und die Funktion erneut rekursiv aufgerufen.
            y = y + 1;
            height = height - 1;
            chessboard_rectangle(c, x, y, width, height);
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
Der Binomialkoeffizient von `n` und `k` ("n über k"), mit `0 <= k <= n` ist wie folgt definiert:

- bin(n, 0) = 1, sonst
- bin(n, n) = 1, sonst
- bin(n, k) = bin(n - 1, k - 1) + bin(n - 1, k)

Berechne `bin(n, k)`.
*/
int binomial_coefficient(int n, int k) {

    // If-Bedinung, welche festlegt in welchem Wertebereich k liegen muss (0 <= k <= n).
    if (0 <= k && k <= n)
    {
        // If-Bedinung für den Fall, dass 'bin(n, 0)'.
        if (k == 0)
        {
            return 1;
        }
        
        // If-Bedingung für den Fall, dass 'bin(n, n)'.
        else if (k == n)
        {
            return 1;
        }

        // Falls 'bin(n, k) = bin(n - 1, k - 1) + bin(n - 1, k)' wird die Funktion erneut rekursiv aufgerufen.
        else
        {
            return binomial_coefficient(n - 1, k - 1) + binomial_coefficient(n - 1, k);
        }
    }

    else
    {
        return 0;
    }

    return 0;
}

/*
Aufgabe 2:
Der *Sierpinski Carpet der Ordnung 0* ist ein einzelnes schwarzes Pixel.
Der *Sierpinski Carpet der Ordnung n+1* besteht aus acht Sierpinski Carpets der Ordnung n, angeordnet als drei-mal-drei
Quadrat dessen Mittelstück fehlt.

Beispiele (`X` stellt schwarze Pixel dar)
=========================================

Ordnung 0:

X

Ordnung 1:

XXX
X X
XXX

Ordnung 2:

XXXXXXXXX
X XX XX X
XXXXXXXXX
XXX   XXX
X X   X X
XXX   XXX
XXXXXXXXX
X XX XX X
XXXXXXXXX

Siehe auch die Datei `05sierpinski.jpg`

Um in der nächsten Aufgabe den Sierpinski-Carpet auf die Canvas zeichnen zu können müssen Potenzen berechnet werden.
Implementieren Sie die Berechnung der Potenz einer nicht-negativen, ganzzahligen Basis `b` mit einem
nicht-negativen, ganzzahligen Exponenten `exp`.

_Benutzen Sie keine Schleifen, die Aufgabe soll über Rekursion gelöst werden!_
*/
int power(int b, int exp){

    // Falls der Exponent == 0 ist, ist die Potenz gleich eins.
    if (exp == 0)
    {
        return 1;
    }
    
    // Andernfalls wird die Funktion solange rekursiv aufgerufen und ihr Ergebnis mit dem Wert der Basis multipliziert, wie der Exponent-Parameter größer als eins ist. Mit jedem rekursiven Aufruf wird 'exp' um eins verringert.
    else
    {
        if (exp > 1)
        {
            return b * power(b, exp - 1);
        }

        else
        {
            return b;
        }
    }

    return 0;
}

/*
Diese Funktion soll den Sierpinski Carpet der Ordnung `n` auf die Canvas zeichnen, mit unterer linker Ecke an Koordinate `(x, y)`.

_Benutzen Sie keine Schleifen, die Aufgabe soll über Rekursion gelöst werden!_
*/
/*
Canvas sierpinski_hilfsfunktion(Canvas c, int a, int n, int x, int y) { 
    
    if (n > 0)
    {   
        // If-Bedingungen für die erste Zeile.
        if (y < power(3, n - 1))
        {   
            // 
            if (x < a * power(3, n))
            {
            
                sierpinski_hilfsfunktion(c, a + 1, n - 1, x, y);
                
                // Debugging Statement
                if (n == 2 && x == 3)
                {
                    printf("Hilfsfunktion a = %d, n = %d, x = %d", a, n, x);
                }

                sierpinski_hilfsfunktion(c, a, n, x + power(3, n)/3, y);
            }
            return c;
        }
        
        // If-Bedingungen für das fehlen des Mittelstücks.
        
        else if (y > (power(3, n - 1)) - 1 && y < 2 * power(3, n - 1))
        {
            if (x < power(3, n - 1))
            {
                sierpinski_hilfsfunktion(c, a + 1, n - 1, x, y);
                sierpinski_hilfsfunktion(c, a, n, x + power(3, n)/3, y);
            }
            
            else if (x >= power(3, n - 1) && x < 2 * power(3, n - 1))
            {
                sierpinski_hilfsfunktion(c, a, n, x + power(3, n)/3, y);
            }
            
            else if (x >= 2 * power(3, n - 1) && x < power(3, n))
            {
                sierpinski_hilfsfunktion(c, a + 1, n - 1, x, y);
                sierpinski_hilfsfunktion(c, a, n, x + power(3, n)/3, y);
            }
        return c;
        }
        
        // If-Bedingung für die 'letzte' Zeile.
        else if (y >= 2 * power(3, n - 1) && y < power(3, n))
        {
            if (x < power(3, n))
            {
                sierpinski_hilfsfunktion(c, a + 1, n - 1, x, y);
                sierpinski_hilfsfunktion(c, a, n, x + power(3, n)/3, y);
            }
        }
        return c;
    }

    // Sierpinski-Carpet der Ordnung 0.
    else if (n == 0)
    {
        // printf("Hello!");
        c = canvas_set_black(c, x, y);
    }
    return c;
}

Canvas sierpinski_carpet(Canvas c, int n, int x, int y) {

    //
    if (n > 0)
    {
        // If-Bedingungen für die erste Zeile. !! -> Für n = 2 schlägt die Bedingung fälschlicherweise fehl.
        if (y < power(3, n) - 1)
        {   
            // Erneuter Funktionsaufruf mit n - 1 um rekursiv zu n = 0 zu kommen, was für die aktuellen Koordinaten den Pixel einzeichnet.
            sierpinski_carpet(c, n - 1, x, y);
            sierpinski_hilfsfunktion(c, 1, n, x + power(3, n)/3, y);
            
            // if (n == 2)
            // {
            //     printf("n = 2");
            // }
            
            sierpinski_carpet(c, n, x, y + power(3, n)/3);
        }

        // If-Bedinungen für das fehlen des Mittelstücks.
        else if (y > (power(3, n - 1)) - 1 && y < 2 * power(3, n - 1))
        {
            // printf("Mittlere Zeile Durchlauf");
            sierpinski_carpet(c, n - 1, x, y);
            sierpinski_hilfsfunktion(c, 1, n, x + power(3, n)/3, y);
            sierpinski_carpet(c, n, x, y + power(3, n)/3);
        }
        
        // If-Bedingung für die 'letzte' Zeile.
        else if (y >= 2 * power(3, n - 1) && y < power(3, n))
        { 
            sierpinski_carpet(c, n - 1, x, y);
            sierpinski_hilfsfunktion(c, 1, n, x + power(3, n)/3, y);
            sierpinski_carpet(c, n, x, y + power(3, n)/3);
        }
        // else
        // {
        //     return c;
        // }
    }

    // Sierpinski-Carpet der Ordnung 0.
    else if (n == 0)
    {
        c = canvas_set_black(c, x, y);
    }
    return c;
}
*/


Canvas sierpinski_hilfsfunktion(Canvas c, int x_Schranke, int y_Schranke, int x_addition, int y_addition, int n, int x, int y) {

    if (n > 0)
    {
        // If-Bedingungen für die erste Zeile.
        if (y < y_Schranke)
        {   
            if (x < x_Schranke)
            {
                /*
                if (x < 3) <- Das Problem hängt mit den Ungleichungen (Schranken) zusammen.
                {
                    sierpinski_hilfsfunktion(c, power(3, n), n - 1, x, y);
                }
                */
                
                // Das Problem hängt mit den Ungleichungen (Schranken) zusammen. Siehe nächste Zeile 'a'.
                sierpinski_hilfsfunktion(c, x + power(3, n - 1), y + power(3, n - 1), x, y, n - 1, x, y);
                
                // If-Bedingungen für die erste Zeile.
                if (y < y_addition + power(3, n - 1))
                {   
                    sierpinski_hilfsfunktion(c, x_Schranke, y_Schranke, x_addition, y_addition, n, x + power(3, n)/3, y);
                    /*
                    if (x < a * power(3, n))
                    {
                        sierpinski_hilfsfunktion(c, a, n, x + power(3, n)/3, y);
                    }
                    */
                }
                
                // If-Bedingungen für das fehlen des Mittelstücks.
                else if (y > y_addition + (power(3, n - 1)) - 1 && y < y_addition + 2 * power(3, n - 1))
                {
                    if (x < (x_addition + power(3, n - 1)))
                    {
                        sierpinski_hilfsfunktion(c, x_Schranke, y_Schranke, x_addition, y_addition, n, x + 2 * power(3, n)/3, y);
                    }
                    /*
                    else if (x >= x_addition + power(3, n - 1) && x < 2 * (x_addition + power(3, n - 1)))
                    {
                        // Hier liegt der Fehler des Mittelstücks, welches entgegen der Bedingung, eingezeichnet wird.
                        sierpinski_hilfsfunktion(c, x_Schranke, y_Schranke, x_addition, y_addition, n, x + (power(3, n)/3), y);
                    }
                    
                    else if (x >= 2 * (x_addition + power(3, n - 1)) && x < (x_addition + power(3, n)))
                    {
                        sierpinski_hilfsfunktion(c, x_Schranke, y_Schranke, x_addition, y_addition, n, x + power(3, n)/3, y);
                    }
                    */
                }
                
                // If-Bedingung für die 'letzte' Zeile.
                else if (y >= y_addition + 2 * power(3, n - 1) && y < (y_addition + power(3, n)))
                {
                    if (x < x_addition + power(3, n))
                    {
                        sierpinski_hilfsfunktion(c, x_Schranke, y_Schranke, x_addition, y_addition, n, x + power(3, n)/3, y);
                    }
                }
                
                /*
                // Rekursionsfunktionen die gebraucht werden.
                sierpinski_hilfsfunktion(c, a, n, x + power(3, n)/3, y);
                */
                
                if (x + 1 == x_Schranke)
                {
                    sierpinski_hilfsfunktion(c, x_Schranke, y_Schranke, x_addition, y_addition, n, x - (power(3, n) - 1), y + power(3, n)/3);
                }
                
                // else if (x < 2 * power(3, n)/3 && x + power(3, n)/3 == x_Schranke)
                // {
                //     sierpinski_hilfsfunktion(c, x_Schranke, y_Schranke, x_addition, y_addition, n, power(3, n)/3, y + power(3, n)/3);
                // }

                else if (x + power(3, n)/3 == x_Schranke)
                {
                    sierpinski_hilfsfunktion(c, x_Schranke, y_Schranke, x_addition, y_addition, n, 0, y + power(3, n)/3);
                }
            }
        }
    }
    
    else if (n == 0)
    {
        c = canvas_set_black(c, x, y);
    }
    return c;
}


Canvas sierpinski_carpet(Canvas c, int n, int x, int y) {
    sierpinski_hilfsfunktion(c, power(3, n), power(3, n), x, y, n, x, y);
    return c;
}


/*
Canvas sierpinski_carpet(Canvas c, int n, int x, int y) {
    if (n > 0)
    {
        // If-Bedingungen für die erste Zeile.
        if (y < power(3, n))
        {   
            if (x < power(3, n))
            {
                sierpinski_carpet(c, n - 1, x, y);
                sierpinski_carpet(c, n, x + power(3, n)/3, y);
                sierpinski_carpet(c, n, x , y + power(3, n)/3);
            }
        }
    }

    else if (n == 0)
    {
        c = canvas_set_black(c, x, y);
    }
    return c;
}
*/

/*
Hinweis: Diese Aufgabe ist deutlich schwieriger als die vorangegangen, und ist als besondere Herausforderung gedacht :)
Eine *knifflige* Zahl ist eine Zahl deren einzige Dezimalziffern die Vier und die Sieben sind, und in der nie zwei
Siebenen aufeinander folgen.
Berechne die Anzahl der kniffligen Zahlen mit genau `n` Dezimalziffern.

Beispiel: die kniffligen Zahlen mit drei Dezimalziffern sind 444, 447, 474, 744, 747.
*/
int tricky_numbers(int n) {
    return 0;
}
