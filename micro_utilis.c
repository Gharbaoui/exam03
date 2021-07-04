#include "micro.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	print_file_error()
{
	ft_putstr("Error: Operation file corrupted\n");
}

int	fill_back(FILE *fp, t_background *back)
{
	int	error;

	error = fscanf(fp, "%f %f %c\n", &(back->width),
		&(back->height), &(back->back_c));
	if (error != 3)
		return 1;
	back->width = round_number(back->width, &error);
	if (error)
		return 1;
	back->height = round_number(back->height, &error);
	if (error)
		return 1;
	if (back->width > 300 || back->height > 300)
		return 1;
	return 0;
}

float	round_number(float o_num, int *error)
{
	int	num;
	
	num = (int)o_num;
	if (o_num > (float)num)
		o_num = num + 1;
	if (error)
	{
		*error = 0;
		if (o_num <= 0)
			*error = 1;
	}
	return o_num;
}

void	draw_all(t_lines *lines, t_background back)
{
	char	**paint;

	paint = get_paint(back);
	while (lines->next)
	{
		//// stops here
		lines = lines->next;
	}
}

char	**get_paint(t_background back)
{
	char	**paint;
	int		i;

	paint = malloc(sizeof(char *) * (back.height + 1));
	paint[(int)back.height] = NULL;
	i = -1;
	while (++i < back.height)
	{
		paint[i] = malloc(back.width + 1);
		fill_line(paint[i], back.back_c, (int)back.width);
	}
	return paint;
}

void	fill_line(char *str, char c, int size)
{
	int i;

	i = -1;
	while (++i < size)
		str[i] = c;
	str[i] = 0;
}
