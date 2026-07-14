#include <stdio.h>
#include <stdint.h> /* Für Typen wie `int16_t` und `uint16_t` */

int main()
{
    uint8_t unsigned_byte = 255; /* 255 = 2^8 - 1 */
    printf("Is 255 the maximum value for an unsigned 8-bit integer? %d\n", unsigned_byte == UINT8_MAX);
    unsigned_byte = unsigned_byte + 1;
    printf("Incrementing 255 gives %d\n", unsigned_byte);

    int8_t signed_byte = 127; /* 127 = 2^7 - 1 */
    printf("Is 127 the maximum value for a signed 8-bit integer? %d\n", signed_byte == INT8_MAX);
    signed_byte = signed_byte + 1;
    printf("Incrementing 127 gives %d\n", signed_byte);

    int large_int = 32767; /* 32767 = 2^15 - 1 */
    large_int = large_int + 1;
    printf("Incrementing the large_int gives %d\n", large_int);

    float some_float = 0.1;
    printf("some_float is %f\n", some_float); /* Benutze %f um floats zu printen */
    printf("floats include some non-numerical values: %f\n", 1.0 / 0.0);
    printf("floats include some non-numerical values: %f\n", -1.0 / 0.0);
    printf("floats include some non-numerical values: %f\n", (1.0 / 0.0) - (1.0 / 0.0));
}

enum TrafficLightColor
{
    Red,
    Yellow,
    Green,
};

enum TrafficLightColor next_color(enum TrafficLightColor c)
{
    enum TrafficLightColor some_variable = Red;

    if (c == Red)
    {
        return Yellow;
    }
    else if (c == Yellow)
    {
        return Green;
    }
    else
    {
        return Red;
    }
}

enum CoinFace_
{
    Heads,
    Tails,
};
typedef enum CoinFace_ CoinFace;

typedef enum FruitSpread_
{
    Jam,
    Jelly,
} FruitSpread;

typedef struct Point3d_
{
    float x;
    float y;
    float z;
} Point3d;

Point3d add(Point3d p1, Point3d p2)
{
    Point3d my_point = { .x = 0.5, .y = 3.14, .z = -123.4 };
    
    Point3d result = p1;
    result.x = result.x + p2.x;
    result.y = result.y + p2.y;
    result.z = result.z + p2.z;
    return result;
}