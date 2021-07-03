#include "micro.h"

void	*ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	file_error()
{
	ft_putstr("Error: Operation file corrupted\n");
}

int	draw_background(FILE *fp, int i, int j, int k, t_back *inf)
{
	int		ret;
	float	width = 0;
	int		w;
	float	height = 0;
	int		h;
	char	c = 'a';
	char	error;

	ret = fscanf(fp, "%f %f %c %c", &width, &height, &c, &error);
	if (ret != 3)
		return 1;
	if (!(width > 0 && width <= 300))
		return 1;
	if (!(height > 0 && width <= 300))
		return 1;
	inf->width = width;
	inf->height = height;
	w = (int)width;
	h = (int)height;
	if (width > w)
		width++;
	if (height > h)
		height++;
	while (j < height)
	{
		draw_line(width, c);
		write(1, "\n", 1);
		j++;
	}
	return 0;
}

void	draw_line(int len, char c)
{
	int i;

	i = -1;
	while (++i < len)
		write(1, &c, 1);
}

int	drawing(FILE *fp, t_back inf)
{
	
	return 0;
}
