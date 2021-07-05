#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct 
{
	float	width;
	float	height;
	char	c;
}	t_back;

typedef struct s_line
{
	char	fill;
	float	x;
	float	y;
	float	width;
	float	height;
	char	c;
	struct	s_line *next;
}	t_line;

void	ft_putstr(char *str);
int	file_error();
int	collect_data(FILE *fp, t_line **lines, t_back *back);
float	get_exact_num(float num);
int	get_background(FILE *fp, t_back *back);
int	get_rects(FILE *fp, t_line **lines);
int	free_before(t_line *lines);
int	fill_line(t_line **lines, t_line line);
t_line *get_one(t_line line);
int	check_valuse(t_line *ln);
void	print_info(t_line *lines, t_back back);
void	start_draw(t_line *lines, t_back back);
char	**get_paint(t_back back);
void	fill_paint(char *str, char c, int size);
void	print_map(char **str);
void	fill_paint_accor(t_line *lines, t_back back, char **paint);
void	draw_empty(t_line line, t_back back, char **paint);
void	draw_filled(t_line line, t_back back, char **paint);
int	get_start_index(float x, float *width, float back_width);
void	draw_em(int sx, int ex, int sy, int ey, t_line line, t_back back);

// -2 4
/*
jjjjjjj 
jjjjjjj
jjjjjjj
jjjjjjj
*/
