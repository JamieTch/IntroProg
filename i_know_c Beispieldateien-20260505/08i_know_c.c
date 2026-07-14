#include <stdio.h>

int main()
{
    /* C hat einige vordefinierte Typen, wie zum Beispiel `int` */
    /* C gibt uns Syntax um Werte von diesen Typen zu erhalten. */
    /* Man kann Werte Namen zuweisen indem man Variablen deklariert. */
    int x = 42;
    /* Es gibt vordefinierte Operatoren für diese Typen in C, um Werte dieser Typen zu verwenden. */
    int y = 9 * 17;
    /* Wenn man diese Operatoren anwendet gibt es keinen Unterschied zwischen Literalen, Variablen, oder anderen Ausdrücken. */
    int z = 4 * (x * 0);

    /* Das selbe gilt für Pointer: */
    /* Es gibt Syntax zum erstellen von Pointern, und */
    /* man kann Pointer-Werte Namen zuweisen indem man Variablen deklariert. */
    int *my_ptr = &x;
    /* Es gibt zwei Operationen die C uns für Pointer zur Verfügung stellt. */
    /* Man kann den Wert an der Stelle auf die der Pointer zeigt _lesen_: */
    int same_value_as_x = *my_ptr;
    /* Und man kann an die Stelle auf die der Pointer zeigt _schreiben_: */
    *my_ptr = 43;
    printf("Do x and same_value_as_x still hold equal values? %d\n", x == same_value_as_x);



    /* Naja, wir haben gelogen. */
    /* Einige Pointer haben Superkräfte und C stellt dafür eine _dritte_ vordefinierte Operation zur Verfügung: */
    /* Man kann neue Pointer zu neuen Stellen durch diese superstarken Pointer erstellen. */
    
    /* Um einen solchen superstarken Pointer zu erhalten müssen wir spezielle Syntax verwenden: */
    int superpowered_ptr[] = { 4, 3, 7, 7, 2 };
    /* Lass dich von den eckigen Klammern nicht täuschen, das ist wirklich ein Pointer: */
    int *equivalent_normallooking_pointer = superpowered_ptr;

    /* Dieser Pointer zeigt auf eine Speicheradresse welche den ersten der gelisteten Werte enthält. */
    printf("These are equal: %d == %d == %d\n", 4, *superpowered_ptr, *equivalent_normallooking_pointer);

    /* Wir müssen diese Pointer offiziel "Array-Pointer" nennen, da AkademikerInnen sich vor Superkräften fürchten. */
    /* Ausgehend von dem Array-Pointer können wir mithilfe von einem vordefinierten Operator neue Pointer erstellen. */
    int *look_ma_no_kaufmannsund = superpowered_ptr + 1;
    printf("These are equal: %d == %d == %d\n", 3, *look_ma_no_kaufmannsund, *(superpowered_ptr + 1));

    /* Diese neu berechneten Pointer können wir auch zum Schreiben verwenden. */
    *look_ma_no_kaufmannsund = 55;
    printf("These are equal: %d == %d == %d\n", 55, *look_ma_no_kaufmannsund, *(superpowered_ptr + 1));

    /* Das initiale Array legt dabei die Grenzen fest, wie viele  Pointer wir berechnen können. */
    printf("All good: %d == %d == %d\n", 2, *(superpowered_ptr + 4), *(look_ma_no_kaufmannsund + 3));
    /* printf("Nooooope: %d == %d == %d\n", 999, *(superpowered_ptr + 71), *(look_ma_no_kaufmannsund + 70)); */

    /* Pointer ohne Superkräfte sind identisch zu Array-Pointern der Länge eins. */
    /* Für diese ist der einzig erlaubte Weg neue Pointer zu erstellen eine null zu addieren, was wieder den Pointer selbst ergibt. */
    printf("Legal but pointless: %d == %d\n", *my_ptr, *(my_ptr + 0));

    /* Wie immer können wir auch beliebige Ausdrücke verwenden. */
    printf("These are equal: %d == %d == %d\n", *look_ma_no_kaufmannsund, *(look_ma_no_kaufmannsund + z), *(superpowered_ptr + (2 - 1)));

    /* Und C hat sogar praktische Syntax um einen neuen Pointer zu berechnen und direkt zu dereferenzieren! Alles auf einmal: */
    printf("Completely equivalent: %d == %d\n", *(superpowered_ptr + 1), superpowered_ptr[1]);

    /* Zum Abschluß: Es gibt verschiedene Wege ein Array zu initialiseren, aber die sind alle langweilig und man kann sie
     * sich im Internet raussuchen wenn man sie braucht. */
}
