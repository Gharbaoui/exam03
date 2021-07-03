#include "micro.h"

int main(int argc, char **argv)
{
	FILE	*fp;

	if (argc == 2)
	{
		fp = fopen(argv[1], "r");
		if (!fp)
		{
			file_error();
			return 1;
		}
		if (ft_draw(fp))
		{
			file_error();
			return (1);
		}
	}
	else
	{
		ft_putstr("Error: argument\n");
		return 1;
	}
	return 0;
}

int	ft_draw(FILE *fp)
{
	t_back inf;
	if (draw_background(fp, 0, 0, 0, &inf))
		return (1);
	if (drawing(fp, inf))
		return 1;
	return (0);
}
