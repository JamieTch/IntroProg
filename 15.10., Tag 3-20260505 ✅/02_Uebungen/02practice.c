/*
Willkommen zum zweiten Übungsblatt vom Programmierkurs. Alles funktioniert wie auch beim ersten Aufgabenblatt.

Nachdem Sie in einem Terminal mittels des 'cd' Befehls in das Verzeichnis gewechselt sind, in dem diese Datei liegt,
können Sie mit folgendem Befehl ihre Lösungen überprüfen:
clang -std=c11 -g -Wall 02practice_test.c -o 02practice_test.o -lm && ./02practice_test.o

Auf diesem Blatt geht es unter anderem um:

- if, else und else-if
- logisches und und logisches oder (`&&` und `||`)
- verschachtelte while und for loops
*/

#include <stdio.h>

int is_prime(int n) {
   int result = 0;
    /*
    Eine Primzahl ist eine natürliche Zahl größer gleich 2, deren einzigen ganzzahligen Teiler die eins und die Zahl selbst sind.
    Die ersten Primzahlen sind 2, 3, 5, 7, 11, 13, ...

    Weisen Sie der Variable `result` den Wert `1` zu, falls `n` eine Primzahl ist, und ansonsten `0`.
    */
    /* BEGIN CHANGES */

    int i;

    /* Setzte standardgemäß 'result' auf 1 falls n >= 2. So kann nachfolgende For-Schleife 'result' nur dann auf 0 setzten, 
    falls Teiler von n ermittelt wird, welcher ungleich 1 oder n ist.*/
    if (n >= 2)
    {
        result = 1;
    }
    
    /* For-Schleife mit If-Bedingung durchläuft alle i <= n und überprüft, ob i Teiler von n ist wenn i gleichzeitig ungleich 1 und n ist. 
    Falls das eintritt, wird result auf 0 gesetzt, weil dann Teiler ungleich 1 und n existiert.*/
    for (i = 0; i <= n; i++)
    {
        if (n % i == 0 && i != n && i != 1)
        {
            result = 0;
        }
    }  

    /* END CHANGES */
    return result;
}

int sum_first_primes(int n) {
   int result = 0;
    /*
    Weisen Sie der Variable `result` die Summe der ersten `n` Primzahlen zu zu.
    Beispiel für `n = 4`: `2 + 3 + 5 + 7 = 17`.
    */
    /* BEGIN CHANGES */

    int i;
    // For-Schleife, welche über i iteriert und Abgebrochen wird, falls n echt kleiner wird als 1.
    for (i = 0; 0 < n; i++)
    {
        /* If-Bedingung innerhalb der For-Schleife, welche über die is_prime Funktion überprüft, ob über das iterierte i eine Primzahl ist. 
        Wenn i prim ist, wird i zu 'result' aufaddiert und n um 1 gesenkt. Die If-Bedingung sorgt dafür, dass nur wenn eine Primzahl ermittelt wurde,
        sich der Abbruchbedingung der äußeren For-Schleife in Einer-Schritten angenährt wird und addiert somit die ersten n-Primzahlen auf.*/
        if (is_prime(i) == 1)
        {
            result = result + i;
            n = n - 1;
        }
    }

    /* END CHANGES */
    return result;
}

int sum_first_powers(int n) {
    int result = 0;
    /*
    Sum First Powers:
    Weisen Sie der Variable `result` die Summe `n^0 + n^1 + n^2 + n^3 + ... + n^n` zu.
    Beispiel für `n = 4`: `4^0 + 4^1 + 4^2 + 4^3 + 4^4 = 1 + 4 + 16 + 64 + 256 = 341`.
    */
    /* BEGIN CHANGES */

    int i;
    int m = 1;
    result = 1;
    for (i = 1; i <= n; i++)
    {
        m = m * n;
        result = result + m;
    }

    /* END CHANGES */
    return result;
}

/*
Schreiben Sie ein paar nette Muster ins Terminal.


Muster 1: k-square (im Beispiel unten ist k := 8)

########
########
########
########
########
########
########
########

Muster 2: k-diagonal (im Beispiel unten ist k := 8)

#
##
###
####
#####
######
#######
########

Muster 3: k-arrow (im Beispiel unten ist k := 8)

#
##
###
####
####
###
##
#

Muster 4: k-chessboard (im Beispiel unten ist k := 8)

 # # # #
# # # # 
 # # # #
# # # # 
 # # # #
# # # # 
 # # # #
# # # # 

Muster 5: k-pyramid (im Beispiel unten ist k := 8)

   ##
  ####
 ######
########

Muster 6: k-spiral (im Beispiel unten ist k := 16)

################
               #
############## #
#            # #
# ########## # #
# #        # # #
# # ###### # # #
# # # ## # # # #
# # # #  # # # #
# # # #### # # #
# # #      # # #
# # ######## # #
# #          # #
# ############ #
#              #
################



*/