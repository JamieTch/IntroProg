/*
Willkommen zum ersten Übungsblatt vom Programmierkurs. Alles funktioniert wie auch beim ersten Aufgabenblatt.

Nachdem Sie in einem Terminal mittels des `cd` Befehls in das Verzeichnis gewechselt sind, in dem diese Datei liegt,
können Sie mit folgendem Befehl ihre Lösungen überprüfen:
clang -std=c11 -g -Wall 01practice_test.c -o 01practice_test.o -lm && ./01practice_test.o

Auf diesem Blatt geht es unter anderem um:

- Variablendeklarationen (`int variable_name = expression;`)
- Variablenzuweisungen (`variable_name = expression;`)
- Arithmetische Ausdrücke (+, -, *, /, %)
- Vergleichsausdrücke (==, !=, <, <=, >, >=)
- if-Abfragen
- while und for Schleifen
*/

#include <stdio.h>

int bakery(int cupcake, int pie, int cake) {
    int result = 0;
    /*
    Bakery:
    Ein Muffin kostet zwei Euro, ein Kuchen kostet drei Euro, eine Torte kostet vier Euro. Wer acht oder mehr
    Backwaren kauft, zahlt lediglich 80% des Preises, abgerundet auf volle Euro.

    Weisen Sie der Variable `result` den Preis von `cupcake` vielen Muffins, `pie` vielen Kuchen, und `cake`
    vielen Torten zu.
    */
    /* BEGIN CHANGES */

    //Variablen für Backwarenpreise
    int cupcake_price = 2;
    int pie_price = 3;
    int cake_price = 4;

    /*Berechne jeweils das Produkt aus Backware und Preis für jede Backware und addiere die einzelnen Preise,
    um 'result zu erhalten'*/
    result = cupcake * cupcake_price + pie * pie_price + cake * cake_price;

    //if-Statement (Bedingte Anweisung), welche 'result' mit dem Rabattfaktor multipliziert, falls acht oder mehr Backwaren gekauft wurden.
    if (cupcake + pie + cake >= 8) {
        result = result * 0.8;
    }
    /* END CHANGES */
    return result;
}

int seconds_to_units(int input_seconds) {
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    /*
    Seconds to Units:
    Stellen Sie die durch `input_seconds` gegebene Anzahl Sekunden als möglichst viele volle Stunden, gefolgt von
    möglichst vielen übrigen vollen Minuten, gefolgt von den übrigbleibenden Sekunden dar.
    Beispiel: 12460 Sekunden ergeben 3 Stunden, 27 Minuten, und 40 Sekunden.

    Weisen Sie der Variable `hours` die Stunden, der Variable `minutes` die verbleibenden vollen Minuten, und der
    Variable `seconds` die verbleibenden Sekunden zu.
    */
    /* BEGIN CHANGES */

    //Berechne die totale Anzahl voller Minuten und speichere sie in Zwischenvariable.
    int minutes_total = input_seconds / 60;
    
    //Berechne die totale Anzahl an voller Stunden basierend auf den zuvor berechneten vollen Minuten.
    hours = minutes_total / 60;

    // Ermittle die nach Erhalt der vollen Stunden übrig bleibenden vollen Minuten und speichere sie in 'minutes'.
    // minutes = minutes_total - hours * 60;

    /*Ermittle die vollen Sekunden, indem das Produkt aus den anfänglichen totalen Minuten
    mit einem Faktor 60 von den Inputsekunden subtrahiert wird.*/
    // seconds = input_seconds - minutes_total * 60;

    // Alternative Ermittlung über Modulo-Operator.
    minutes = minutes_total % 60;
    seconds = input_seconds % 60;


    /* END CHANGES */
    return seconds + 256 * minutes + 256 * 256 * hours;
}

int is_square_root(int n) {
    int result = 0;
    /*
    Is Square Root:
    Eine Quadratzahl ist eine natürliche Zahl (oder die Null), die das Produkt einer natürlichen Zahl mit sich selbst ist.
    Die ersten Quadratzahlen sind 0, 1, 4, 9, 16, ...

    Weisen Sie der Variable `result` den Wert `1` zu, falls `n` eine Quadratzahl ist, und ansonsten `0`.
    */
    /* BEGIN CHANGES */

    int i = 0;
    for (i = 0; i <= n; i = i + 1) {
        if (i * i == n) {
            result = 1;
        }
    }

    /*while (i <= n) {
        if (i * i == n) {
            result = 1;
        }
        i = i + 1;
    }
    */

    /* END CHANGES */
    return result;
}

int digit_sum(int n) {
    int result = 0;
    /*
    Digits Sum:
    Die *Quersumme* einer natürlichen Zahl ist die Summe ihrer Dezimalstellen. Z.B. ist die Quersumme von 1234 die 10.
    Weisen Sie der Variable `result` die Quersumme von `n` zu.
    */
    /* BEGIN CHANGES */

    while (n > 0) {
        result = result + n % 10;
        n = n / 10;
    }

    /* END CHANGES */
    return result;
}

int reverse_digits(int n) {
    int result = 1;
    /*
    Reverse Digits:
    Die *Spiegelung* einer natürlichen Zahl ist gegeben durch die umgekehrte Reihenfolge ihrer Dezimalstellen.
    Z.B. ist die Spiegelung von 1234 die 4321.
    Weisen Sie der Variable `result` die Spiegelung von `n` zu.
    */
    /* BEGIN CHANGES */

    // int b = 1;
    int stellen = 0;
    int n_double = n;

    while (n_double > 0) {
        n_double = n_double / 10;
        stellen = stellen + 1;
    }

    int p = 1;
    int i = 0;
    while (i < (stellen - 1)) {
        p = 10 * p;
        i = i + 1;
    }
    // printf("%d\n", p);

    while (n > 0) {
        result = result + ((n % 10) * p);
        // printf("%d\n", result);
        p = p / 10;
        n = n / 10;
    }

    result = result - 1;

    /* END GURKENSALAT */
    return result;
}
