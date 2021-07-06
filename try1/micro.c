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
		last = (*lines)->next;
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
