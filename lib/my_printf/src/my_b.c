/*
** EPITECH PROJECT, 2023
** octal_conv
** File description:
** conversion in octal base
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int my_putstr (char const *str);

char *my_revstr(char *str);

static int nbr(int nb)
{
    int count = 0;
    while (nb > 10){
        nb = nb / 10;
        count = count + 1;
    }
    return count + 1;
}

int my_b(const char *format, va_list list, int nb)
{
    int va_int = va_arg(list, int);
    int count = 0;
    char *str = malloc(sizeof(int) * (nbr(va_int) + 1));
    while (va_int > 1){
        str[count] = va_int % 2 + 48;
        va_int = va_int / 2;
        count = count + 1;
    }
    str[count] = va_int + 48;
    my_putstr(my_revstr(str));
}