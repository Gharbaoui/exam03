#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_back
{
	int		width;
	int		height;
	char	c;
}	t_back;

typedef struct s_line
{
	char	f;
	float	x;
	float	y;
	float	width;
	float	height;
	char	c;
	struct s_line *next;
}	t_line;


typedef struct
{
	char 	c1;
	char	c2;
	float 	a;
	float 	b;
	float	c;
	float 	d;
}	t_f;

typedef struct 
{
	float x;
	float y;
}	t_point;

typedef struct
{
	t_point topl;
	t_point topr;
	t_point botl;
	t_point botr;
}	t_rect;

void	ft_putstr(char *str);
int	file_error();
int	arg_error();
int	collect_data(t_line **lines, t_back *back, FILE *fp);
int	get_back(t_back *back, FILE *fp);
int	free_before(t_line *lines);
int	add_to_list(t_line **lines, t_f holder);
int	copy_one(t_line **line, t_f holder);
void	paint(t_line *lines, t_back back);
char	**get_background(t_back back);
void	fill_tmp(char *str, t_back back);
void	print_term(char **paint);
void	draw_complete(t_line line, t_back back, char **palette);
void	draw_border(t_line line, t_back back, char **palette);
t_rect get_rect(t_line line);
t_point get_point(float x, float y);
void	print_rect(t_rect rect);
t_rect get_back_rect(t_back back);
int	is_point_inside_rect(t_rect rect, t_point p);
int	point_in_border(t_rect rect, t_point p);
float ft_abs(float val);
