#include "micro.h"

int	main(int argc, char **argv)
{
	FILE	*fp;
	t_background	back;
	t_lines			*lines;

	if (argc == 2)
	{
		fp = fopen(argv[1], "r");
		if (!fp)
		{
			print_file_error();
			return 1;
		}
		lines = malloc(sizeof(t_lines));
		if (collect_data(fp, &back, lines))
		{
			print_file_error();
			return 1;
		}
		draw_all(lines, back);
	}
	else
	{
		ft_putstr("Error: argument\n");
		return 1;
	}
}

/*void	print_all(t_lines *ls)
{
	while (ls->next)
	{
		printf("ch: %c X: %f Y: %f width: %f height: %f c: %c\n",
		ls->fill, ls->x, ls->y, ls->width, ls->height, ls->c);
		ls = ls->next;
	}
}*/

int	collect_data(FILE *fp, t_background *back, t_lines *lines)
{
	t_lines *help;
	int ret, err;
	if (fill_back(fp, back))
		return 1;
	help = lines;
	while (1)
	{
		help->fill = 0;
		help->x = 0;
		help->y = 0;
		help->width = 0;
		help->height = 0;
		help->c = 0;
		help->next = NULL;
		err = 0;
		ret = fscanf(fp, "%c %f %f %f %f %c\n",
		&(help->fill), &(help->x), &(help->y),
		&(help->width), &(help->height), &(help->c));
		if (ret > 0)
		{
			if (ret != 6 || (help->fill != 'r' && help->fill != 'R'))
				return 1;
			help->width = round_number(help->width, &err);
			if (err)
				return 1;
			help->height = round_number(help->height, &err);
			if (err)
				return 1;
		}
		else
			break ;
		help->next = malloc(sizeof(t_lines));
		help = help->next;
	}
	return 0;
}

void	draw_to_screen(char **paint)
{
	int j;

	j = -1;
	while (paint[++j])
	{
		ft_putstr(paint[j]);
		write(1, "\n", 1);
	}
}
