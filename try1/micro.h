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


void	ft_putstr(char *str);
int	file_error();
int	arg_error();
int	collect_data(t_line **lines, t_back *back, FILE *fp);
int	get_back(t_back *back, FILE *fp);
int	free_before(t_line *lines);
int	add_to_list(t_line **lines, t_f holder);
int	copy_one(t_line **line, t_f holder);
