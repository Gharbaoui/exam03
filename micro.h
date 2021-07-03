#include <stdio.h>
#include <unistd.h>

typedef struct
{
	float width;
	float height;
}	t_back;

void	*ft_putstr(char *str);
void	file_error();
int	ft_draw(FILE *fp);
int	draw_background(FILE *fp, int i, int j, int k, t_back *inf);
void	draw_line(int len, char c);
int	drawing(FILE *fp, t_back inf);
