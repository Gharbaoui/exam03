#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


typedef struct 
{
	float	width;
	float	height;
	char	back_c;
}	t_background;

typedef struct	s_lines
{
	char	fill;
	float	x;
	float	y;
	float	width;
	float	height;
	char	c;
	struct	s_lines *next;
}	t_lines;

void	ft_putstr(char *str);
void	print_file_error();
int	collect_data(FILE *fp, t_background *back, t_lines *lines);
int	fill_back(FILE *fp, t_background *back);
float	round_number(float o_num, int *error);
void	print_all(t_lines *ls);
char	**get_paint(t_background back);
void	draw_all(t_lines *lins, t_background back);
void	fill_line(char *str, char c, int size);
void	draw_to_screen(char **paint);
