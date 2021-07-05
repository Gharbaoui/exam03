#include "micro.h"

int main(int argc, char **argv)
{
	t_line	*lines;
	t_back	back;
	FILE *fp;

	if (argc == 2)
	{
		lines = NULL;
		fp = fopen(argv[1], "r");
		if (!fp)
			return file_error();
		if (collect_data(fp, &lines, &back))
			return file_error();
		start_draw(lines, back);
	}
	else
	{
		ft_putstr("Error: argument\n");
		return 1;
	}
}

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

int	get_background(FILE *fp, t_back *back)
{
	int ret;

	ret = fscanf(fp, "%f %f %c\n", &back->width, &back->height, &back->c);
	if (ret != 3)
		return 1;
	back->width = get_exact_num(back->width);
	if (back->width <= 0 || back->width > 300)
		return 1;
	back->height= get_exact_num(back->height);
	if (back->height <= 0 || back->height > 300)
		return 1;
	return 0;
}

float	get_exact_num(float num)
{
	int n;

	n = (int)num;
	if (num < 0.00000000)
	{
		if (num < n)
			num = n - 1;
	}
	else
	{
		if (num > n)
			num = n + 1;
	}
	return num;
}

int	free_before(t_line *lines)
{
	t_line  *next;

	if (lines)
	{
		next = lines->next;
		while (lines)
		{
			free(lines);
			lines = next;
			if (lines)
				next = next->next;
		}
	}
	return 1;
}

int	check_valuse(t_line *ln)
{
	ln->x = get_exact_num(ln->x);
	ln->y = get_exact_num(ln->y);
	ln->width = get_exact_num(ln->width);
	if (ln->width <= 0)
		return 1;
	ln->height = get_exact_num(ln->height);
	if (ln->height <= 0)
		return 1;
	ln->width++;
	ln->height++;
	return 0;
}

void	print_info(t_line *lines, t_back back)
{
	printf("width: %f height: %f c: %c\n", back.width, back.height, back.c);
	while (lines)
	{
		printf("X: %f Y: %f width: %f height: %f c: %c\n", 
			lines->x, lines->y, lines->width, lines->height, lines->c);
		lines = lines->next;
	}
}

void	print_map(char **str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		ft_putstr(str[i]);
		write(1, "\n", 1);
	}
}

char	**get_paint(t_back back)
{
	char **paint;
	int i;

	i = -1;
	paint = malloc(sizeof(char *) * (back.height + 1));
	paint[(int)back.height] = NULL;
	while (++i < back.height)
	{
		paint[i] = malloc(back.width + 1);
		fill_paint(paint[i], back.c, back.width);
	}
	return paint;
}

void	fill_paint(char *str, char c, int size)
{
	int i;

	i = -1;
	while (++i < size)
		str[i] = c;
	str[i] = 0;
}
