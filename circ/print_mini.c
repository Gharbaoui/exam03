#include "mini.h"

void    ft_putstr(char *str)
{
    while (*str)
    {
        write(1, str, 1);
        str++;
    }
}

int arg_error()
{
    ft_putstr("Error: argument\n");
    return 1;
}

int file_error()
{
    ft_putstr("Error: Operation file corrupted\n");
    return 1;
}

void    print_info(t_line *line, t_back back)
{
    printf("background {width: %d , height: %d , char: %c}\n", back.width, back.heigth, back.c);
    while (line)
    {
        printf("fill: %c X: %f Y: %f raduis: %f %c\n", line->fill, line->x, line->y, line->radius, line->c);
        line = line->next;
    }
}

void    print_palette(char **p)
{
    int i;

    i = -1;
    while (p[++i])
    {
        ft_putstr(p[i]);
        write(1, "\n", 1);
    }
}
