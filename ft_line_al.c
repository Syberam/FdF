#include "src/fdf.h"

void	ft_line_al(t_peak *start, t_peak *end, char *data)
{
	int	dx;
	int	dy;
	int	cumul;
	int	x;
	int	y;
	int	xi;
	int	yi;
	int	i;

	i = 1;
	x = start->xx;
	y = start->yy;
	dx = end->xx - x;
	dy = end->yy - y;
	xi = (dx > 0) ? 1 : -1;
	yi = (dy > 0) ? 1 : -1;
	data[4 * (y * start->w + x) + 2] = 0xFF;
	dx = abs(dx);
	dy = abs(dy);
	if (dx > dy)
	{
		cumul = dx / 2;
		while (i <= dx)
		{
			x += xi;
			cumul += dy;
			if (cumul >= dx)
			{
				cumul -= dx;
				y += yi;
			}
			i++;
			data[4 * (y * start->w + x) + 2] = 0xFF;
		}
	}
	else
	{
		cumul = dy / 2;
		while (i <= dy)
		{
			y += yi;
			cumul += dx;
			if (cumul >= dy)
			{
				cumul -= dy;
				x += xi;
			}
			data[4 * (y * start->w + x) + 2] = 0xFF;
			i++;
		}		
	}
}
