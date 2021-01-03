#include <stdio.h>


int main(int argc, char **argv)
{
    int x = 3, y =4, z = 5;
    z = z * 3 + x - y;
    x = z + 3 + x - y;
    y = x * 2 + 1 - z * x;
    printf("%d,%d,%d", x,y,z);
    return 0;
}