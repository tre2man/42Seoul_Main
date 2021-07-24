#include "fract_ol.h"
#include <stdio.h>

void pixel_put(t_img *data, int x, int y, unsigned int color)
{
	// 	char	*dst;

	// dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	// *(unsigned int *)dst = color;

	// dst = data->addr + (y * data->line_length + x) * (data->bits_per_pixel / 8);
	// dst = data->addr + (y * data->line_length + x) * 4;
	// printf("%x %x\n", dst, (y * data->line_length + x) * (data->bits_per_pixel / 8));
	// *(unsigned int *)dst = color;
	// *dst = color & 0xFF0000;
	// *(dst + 1) = color & 0x00FF00;
	// *(dst + 2) = color & 0x0000FF;
	// printf("%d\n", y * WIDTH + x);
	(data->addr)[y * WIDTH + x] = color;
}

int throw_error(char *s)
{
	ft_putstr_fd(s, 2);
	return (0);
}
