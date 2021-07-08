#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int     width;
    int     heigth;
    char    c;
}   t_back;

typedef struct s_line
{
    char    fill;
    float   x;
    float   y;
    float   radius;
    char    c;
    struct s_line *next;
}   t_line;

typedef struct
{
    float x;
    float y;
}   t_point;

typedef struct
{
    t_point center;
    float   radius;
}   t_circ;

typedef struct {
	t_point topl;
	t_point topr;
	t_point botl;
	t_point botr;
}	t_rect;

int arg_error();
int file_error();
int collect_data(FILE *fp, t_line **line, t_back *back);
int get_background(FILE *fp, t_back *back);
int free_back(t_line *l);
int add_to_list(t_line **l, t_line holder);
int all_good(t_line line);
void    print_info(t_line *line, t_back back);
char    **get_start_palette(t_back back);
void    draw_palette(t_line *line, t_back back);
void    fill_tmp(char *str, t_back back);
void    print_palette(char **p);
void    draw_plate(t_line line, t_rect back_rect, char **palette, t_back back);
void    draw_circle(t_line line, t_rect back_rect, char **palette, t_back back);
t_circ	get_c(t_line line);
t_point get_point(float x, float y);
t_rect get_back_rect(t_back back);
float	get_distance(t_point a, t_point b);
float square(float a);
int	p_in_circ(t_point p, t_circ c);
int	p_in_rect(t_point p, t_rect rect);
int	in_border(t_point p, t_circ c);
