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
char Z = 'A';

while (z <= 'z')
{
putchar(z);
z++;
}
while (Z <= 'Z')
{
putchar(Z);
Z++;
}
putchar('\n');
return (0);
}
