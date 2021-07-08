#include "mini.h"

void    draw_palette(t_line *line, t_back back)
{
    char **palette;
	t_rect back_rect;
	
	back_rect = get_back_rect(back);
    palette = get_start_palette(back);
    while (line)
    {
        if (line->fill == 'c')
            draw_circle(*line, back_rect, palette, back);
        else
            draw_plate(*line, back_rect, palette ,back);
        line = line->next;
    }
    print_palette(palette);
}

void    draw_plate(t_line line, t_rect back_rect, char **palette, t_back back)
{
	int	i;
	int j;
	t_point p;
	t_circ c;

	i = -1;
	c = get_c(line);
	while (++i < back.heigth)
	{
		j = -1;
		while (++j < back.width)
		{
			p = get_point(j, i);
			if (p_in_circ(p, c) && p_in_rect(p, back_rect))
				palette[i][j] = line.c;
		}
	}
	
}

void    draw_circle(t_line line, t_rect back_rect, char **palette, t_back back)
{
	int	i;
	int j;
	t_point p;
	t_circ c;

	i = -1;
	c = get_c(line);
	while (++i < back.heigth)
	{
		j = -1;
		while (++j < back.width)
		{
			p = get_point(j, i);
			if (p_in_circ(p, c) && p_in_rect(p, back_rect) && in_border(p, c))
				palette[i][j] = line.c;
		}
	}
}

int	in_border(t_point p, t_circ c)
{
	float dist;

	dist = get_distance(p, c.center);
	if (dist <= c.radius)
	{
		if (c.radius - dist < 1)
			return 1;
	}
	return 0;
}
