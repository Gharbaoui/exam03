#include "micro.h"

int	collect_data(FILE *fp, t_line **lines, t_back *back)
{
	if (get_background(fp, back))
		return 1;
	if (get_rects(fp, lines))
		return 1;
	return 0;
}

int	get_rects(FILE *fp, t_line **lines)
{
	t_line fl;
	int	ret;

	while (1)
	{
		ret = fscanf(fp, "%c %f %f %f %f %c\n", &fl.fill, &fl.x, &fl.y,
			&fl.width, &fl.height, &fl.c);
		if (ret > 0)
		{
			if (ret != 6 || (fl.fill != 'r' && fl.fill != 'R'))
				return free_before(*lines);
			if (check_valuse(&fl))
				return free_before(*lines);
			if (fill_line(lines, fl))
				return free_before(*lines);
		}
		else
			break ;
	}
	return 0;
}

int	fill_line(t_line **lines, t_line line)
{
	t_line *cp;
	t_line *last;

	cp = get_one(line);
	if (*lines)
	{
		last = *lines;
		while (last->next)
			last = last->next;
		last->next = cp;
	}
	else
		*lines = cp;
	return 0;
}

t_line *get_one(t_line line)
{
	t_line *cp;

	cp = malloc(sizeof(t_line));
	cp->fill = line.fill;
	cp->x = line.x;
	cp->y = line.y;
	cp->c = line.c;
	cp->width = line.width;
	cp->height = line.height;
	cp->next = NULL;
	return cp;
}

void	start_draw(t_line *lines, t_back back)
{
	char	**paint;

	paint = get_paint(back);
	fill_paint_accor(lines, back, paint);
	print_map(paint);
}

void	fill_paint_accor(t_line *lines, t_back back, char **paint)
{
	while (lines)
	{
		if (lines->fill == 'r')
			draw_empty(*lines, back, paint);
		else
			draw_filled(*lines, back, paint);
		lines = lines->next;
	}
}

void	draw_empty(t_line line, t_back back, char **paint)
{
	int x;
	int y;

	y = line.y;
	while (line.y <= line.height && line.y <= back.height)
	{
		if (line.y >= 0)
		{
			x = line.x;
			while (x <= line.width && x <= back.width)
			{
				if (x >= 0)
				{
					if (y == line.y || line.y == line.height)
						paint[(int)line.y][x] = line.c;
					else if (x == line.x || x == line.width)
						paint[(int)line.y][x] = line.c;
				}
				x++;
			}
		}
		line.y++;
	}
}

void	draw_filled(t_line line, t_back back, char **paint)
{

}
