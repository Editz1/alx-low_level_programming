#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
* main - Entry point
* Return: 0
*/

int main(void)
{
char z = 'a';

while (z <= 'z')
{
if (z != 'e' && z != 'q')
{
putchar(z);
}
z++;
}
putchar('\n');
return (0);
}
