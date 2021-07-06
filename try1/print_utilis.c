#include "micro.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	file_error()
{
	ft_putstr("Error: Operation file corrupted\n");
	return 1;
}

int	arg_error()
{
	ft_putstr("Error: argument\n");
	return 1;
}

int	get_back(t_back *back, FILE *fp)
{
	int ret;

	ret = fscanf(fp, "%d %d %c\n", &back->width, &back->height, &back->c);
	if (ret != 3)
		return 1;
	if (!(back->width > 0 && back->width <= 300))
		return 1;
	if (!(back->height > 0 && back->height <= 300))
		return 1;
	return 0;
}

int	free_before(t_line *lines)
{
	t_line *next;

	if (lines)
	{
		next = lines->next;
		while (lines)
		{
			free(lines);
			lines = next;
			if (lines)
				next = lines->next;
		}
	}
	return 1;
}

void	print_term(char **paint)
{
	int	i;

	i = -1;
	while (paint[++i])
	{
		ft_putstr(paint[i]);
		write(1, "\n", 1);
	}
}

char	**get_background(t_back back)
{
	char **tmp;
	int i;

	i = -1;
	tmp = malloc(sizeof(char *) * (back.height + 1));
	tmp[back.height] = 0;
	while (++i < back.height)
	{
		tmp[i] = malloc(back.width + 1);
		fill_tmp(tmp[i], back);
	}
	return tmp;
}

void	fill_tmp(char *str, t_back back)
{
	int i;

	i = -1;
	while (++i < back.width)
		str[i] = back.c;
	str[i] = 0;
}

void	draw_border(t_line line, t_back back)
{

}
