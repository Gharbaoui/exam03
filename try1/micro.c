#include "micro.h"

int main(int argc, char **argv)
{
	t_back back;
	t_line *lines;
	FILE *fp;
	if (argc == 2)
	{
		fp = fopen(argv[1], "r");
		if (!fp)
			return file_error();
		lines = NULL;
		if (collect_data(&lines, &back, fp))
			return file_error();
		paint(lines, back);
	}
	else
		return arg_error();
}

int	collect_data(t_line **lines, t_back *back, FILE *fp)
{
	t_line *l;
	t_f hold;
	int ret;

	l = NULL;
	if (get_back(back, fp))
		return 1;
	while (1)
	{
		ret = fscanf(fp, "%c %f %f %f %f %c\n", &hold.c1, &hold.a, &hold.b,
		&hold.c, &hold.d, &hold.c2);
		if (ret > 0)
		{
			if (ret != 6)
				return free_before(l);
			if (add_to_list(&l, hold))
				return free_before(l);
		}
		else
			break ;
	}
	*lines = l;
	return 0;
}

int	add_to_list(t_line **lines, t_f holder)
{
	t_line *cp;
	t_line *last;

	if (copy_one(&cp, holder))
		return 1;
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

int	copy_one(t_line **line, t_f holder)
{
	t_line *cp;

	if (holder.c <= 0.00000000 || holder.d <= 0.00000000 ||
	(holder.c1 != 'r' && holder.c1 != 'R'))
		return 1;
	cp = malloc(sizeof(t_line));
	cp->f = holder.c1;
	cp->c = holder.c2;
	cp->x = holder.a;
	cp->y = holder.b;
	cp->width = holder.c;
	cp->height = holder.d;
	cp->next = NULL;
	*line = cp;
	return 0;
}

t_rect get_rect(t_line line)
{
	t_rect rect;

	rect.topl = get_point(line.x, line.y);
	rect.topr = get_point(line.x + line.width, line.y);
	rect.botl = get_point(line.x, line.y + line.height);
	rect.botr = get_point(line.x + line.width, line.y + line.height);
	return rect;
}

t_rect get_back_rect(t_back back)
{
	t_rect rect;

	rect.topl = get_point(0, 0);
	rect.topr = get_point(back.width, 0);
	rect.botl = get_point(0, back.height);
	rect.botr = get_point(back.width, back.height);
	return rect;
}

t_point get_point(float x, float y)
{
	t_point p;

	p.x = x;
	p.y = y;
	return p;
}

int	is_point_inside_rect(t_rect rect, t_point p)
{
	if (p.x >= rect.topl.x && p.x <= rect.topr.x)
	{
		if (p.y >= rect.topl.y && p.y <= rect.botl.y)
			return 1;
	}
	return 0;
}
