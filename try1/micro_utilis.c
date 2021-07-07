#include "micro.h"

void	paint(t_line *lines, t_back back)
{
	char **palette;

	palette = get_background(back);
	while (lines)
	{
		if (lines->f == 'r')
			draw_border(*lines, back, palette);
		else
			draw_complete(*lines, back, palette);
		lines = lines->next;
	}
	print_term(palette);
}

void	draw_complete(t_line line, t_back back, char **palette)
{
	t_rect rect;
	t_rect back_rect;
	t_point cp;
	int	i;
	int	j;

	rect = get_rect(line);
	back_rect = get_back_rect(back);
	i = -1;
	while (++i < back.height)
	{
		j = -1;
		while (++j < back.width)
		{
			cp = get_point(j, i);
			if (is_point_inside_rect(rect, cp) && is_point_inside_rect(back_rect, cp))
				palette[i][j] = line.c;
		}
	}
}

void	draw_border(t_line line, t_back back, char **palette)
{
	t_rect rect;
	t_rect back_rect;
	t_point cp;
	int	i;
	int	j;

	rect = get_rect(line);
	back_rect = get_back_rect(back);
	i = -1;
	while (++i < back.height)
	{
		j = -1;
		while (++j < back.width)
		{
			cp = get_point(j, i);
			if (is_point_inside_rect(rect, cp) && is_point_inside_rect(back_rect, cp) && point_in_border(rect, cp))
				palette[i][j] = line.c;
		}
	}
}

int	point_in_border(t_rect rect, t_point p)
{
	if (p.y - rect.topl.y < 1 || rect.botl.y - p.y < 1)
		return 1;
	if (p.x - rect.topl.x < 1 || rect.topr.x - p.x < 1)
		return 1;
	return 0;
}
