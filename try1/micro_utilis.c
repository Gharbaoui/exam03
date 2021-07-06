#include "micro.h"

void	paint(t_line *lines, t_back back)
{
	char **palette;

	palette = get_background(back);
	while (lines)
	{
		if (lines->f == 'r')
			draw_border(*lines, back);
		else
			draw_complete(*lines, back);
		lines = lines->next;
	}
	print_term(palette);
}

void	draw_complete(t_line line, t_back back)
{
	t_corners	cors;
	t_corners	back_corners;
	t_rect		realCorn;

	cors = get_corners(line);
	back_corners = get_back_corners(back);
	realCorn = get_real_corners(line);
	printf("topl: {x: %d, y: %d}\n", cors.topl.x, cors.topl.y);
	printf("topr: {x: %d, y: %d}\n", cors.topr.x, cors.topr.y);
	printf("botl: {x: %d, y: %d}\n", cors.botl.x, cors.botl.y);
	printf("botr: {x: %d, y: %d}\n", cors.botr.x, cors.botr.y);
	printf("-----------------------------------------\n");
	printf("topl: {x: %f, y: %f}\n", realCorn.topl.x, realCorn.topl.y);
	printf("topr: {x: %f, y: %f}\n", realCorn.topr.x, realCorn.topr.y);
	printf("botl: {x: %f, y: %f}\n", realCorn.botl.x, realCorn.botl.y);
	printf("botr: {x: %f, y: %f}\n", realCorn.botr.x, realCorn.botr.y);
	printf("-----------------------------------------\n");
	printf("topl: {x: %, y: %d}\n", back_corners.topl.x, back_corners.topl.y);
	printf("topr: {x: %, y: %d}\n", back_corners.topr.x, back_corners.topr.y);
	printf("botl: {x: %, y: %d}\n", back_corners.botl.x, back_corners.botl.y);
	printf("botr: {x: %, y: %d}\n", back_corners.botr.x, back_corners.botr.y);
}

t_corners get_corners(t_line line)
{
	t_corners corn;

	corn.topl = get_point(line.x - 1, line.y - 1);
	corn.topr = get_point(line.x + line.width + 1, line.y - 1);
	corn.botl = get_point(line.x - 1, line.y + line.height + 1);
	corn.botr = get_point(line.x + line.width + 1, line.y + line.height + 1);
	return corn;
}

t_point get_point(float x, float y)
{
	t_point p;

	p.x = (int)x;
	p.y = (int)y;
	return p;
}

t_p real_point(float x, float y)
{
	t_p p;

	p.x = x;
	p.y = y;
	return p;
}

t_rect	get_real_corners(t_line line)
{
	t_rect rect;

	rect.topl = real_point(line.x, line.y);
	rect.topr = real_point(line.x + line.width, line.y);
	rect.botl = real_point(line.x, line.y + line.height);
	rect.botr = real_point(line.x + line.width, line.y + line.height);
	return rect;
}

t_corners	get_back_corners(t_back back)
{
	t_corners corn;

	corn.topl = get_point(0, 0);
	corn.topr = get_point(back.width, 0);
	corn.botl = get_point(0, back.height);
	corn.topr = get_point(back.width, back.height);
	return corn;
}
