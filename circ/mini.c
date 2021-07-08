#include "mini.h"

int main(int argc, char **argv)
{
    FILE *fp;
    t_back back;
    t_line *line;

    if (argc == 2)
    {
        fp = fopen(argv[1], "r");
        line = NULL;
        if (!fp)
            return file_error();
        if (collect_data(fp, &line, &back))
            return file_error();
        draw_palette(line, back);
    }
    else
        return arg_error();
}

int get_background(FILE *fp, t_back *back)
{
    int ret;

    ret = fscanf(fp, "%d %d %c\n",
    &back->width, &back->heigth, &back->c);
    if (ret == 3)
    {
        if (!(back->width > 0 && back->width <= 300))
            return 1;
        if (!(back->heigth > 0 && back->heigth <= 300))
            return 1;
    }
    else
        return 1;
    return 0;
}
int   free_back(t_line *l)
{
    t_line *next;
    
    if (l)
    {
        next = l->next;
        while (l)
        {
            free(l);
            l = next;
            if (l)
                next = l->next;
        }
    }
    return 1;
}

int add_to_list(t_line **l, t_line holder)
{
    t_line *cp;
    t_line *last;
    if (all_good(holder))
        return 1;
    cp = malloc(sizeof(t_line)); 
    cp->fill = holder.fill;
    cp->x = holder.x;
    cp->y = holder.y;
    cp->radius = holder.radius;
    cp->c = holder.c;
	cp->next = NULL;
    if (*l)
    {
        last = *l;
        while (last->next)
            last = last->next;
        last->next = cp;
    }
    else
        *l = cp;
    return 0;
}

int all_good(t_line line)
{
    if (line.fill != 'c' && line.fill != 'C')
        return 1;
    if (line.radius <= 0)
        return 1;
    return 0;
}

int collect_data(FILE *fp, t_line **line, t_back *back)
{
    int ret;
    t_line *l, holder;

    ret = 1;
    l = NULL;
    if (get_background(fp, back))
        return 1;
    while (1)
    {
        ret = fscanf(fp, "%c %f %f %f %c\n",
        &holder.fill, &holder.x, &holder.y,
        &holder.radius, &holder.c);
        if (ret > 0)
        {
            if (ret != 5)
                return free_back(l);
            if (add_to_list(&l, holder))
                return free_back(l);
        }
        else
            break ;
    }
    *line = l;
    return 0;
}

char    **get_start_palette(t_back back)
{
    char **tmp;
    int i;

    i = -1;
    tmp = malloc(sizeof(char *) * (back.heigth + 1));
    tmp[back.heigth] = NULL;

    while (++i < back.heigth)
    {
        tmp[i] = malloc(back.width + 1);
        fill_tmp(tmp[i], back);
    }
    return tmp;
}

void    fill_tmp(char *str, t_back back)
{
    int i;

    i = -1;
    while (++i < back.width)
        str[i] = back.c;
    str[i] = 0;
}


t_circ	get_c(t_line line)
{
	t_circ c;

	c.center = get_point(line.x, line.y);
	c.radius = line.radius;
	return c;
}

t_point get_point(float x, float y)
{
	t_point p;

	p.x = x;
	p.y = y;
	return p;
}

t_rect get_back_rect(t_back back)
{
	t_rect r;
	
	r.topl = get_point(0, 0);
	r.topr = get_point(back.width, 0);
	r.botl = get_point(0, back.heigth);
	r.botr = get_point(back.width, back.heigth);
	return r;
}

int	p_in_circ(t_point p, t_circ c)
{
	float p_dist;

	p_dist = get_distance(p, c.center);
	if (p_dist <= c.radius)
		return 1;
	return 0;
}

int	p_in_rect(t_point p, t_rect rect)
{
	if (p.x >= rect.topl.x && p.x <= rect.topr.x)
	{
		if (p.y >= rect.topl.y && p.y <= rect.botl.y)
			return 1;
	}
	return 0;
}

float	get_distance(t_point a, t_point b)
{
	float dist;

	dist = sqrt(square(a.x - b.x) + square(a.y - b.y));
	return dist;
}

float square(float a)
{
	return a * a;
}
