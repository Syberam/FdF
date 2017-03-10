/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpeaks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 10:17:44 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/03/10 13:39:06 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/fdf.h"

void	ft_alline(t_peak *start, t_peak *end, char *data)
{
	int dx;
	int	dy;
	int	cumul;
	int	x;
	int y;
	int	xi;
	int	yi;
	int i;

	i = 1;
	x = start->xx;
	y = start->yy;
	dx = end->xx - x;
	dy = end->yy - y;
	xi = (dx > 0) ? 1 : -1;
	yi = (dy > 0) ? 1 : -1;
	/*data[4 * (y * start->w + x) + 3] = 0xFF;*/
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

void		*ft_putpeaks(t_peak *peak, t_mlx *param)
{
	void	*img;
	char	*data;
	int		i;
	int		x;
	int		y;
	int		bpp;
	int		endian;
	int		size_line;
	int		h;
	int		w;
	t_peak	*down;

	h = peak->h;
	w = peak->w;
	if (!(img = mlx_new_image(param->mlx, peak->w, peak->h)))
		exit (0);
	bpp = 32;
	endian = 0;
	size_line = w ;
	data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	while (peak)
	{
	/*	i = 0;
		while (i < 4 * h * w)
		{
			x = (i / 4) % w;
			y = (i / 4) / h;
			if ((peak->xx == x && peak->yy == y) || x == 0 ||y == 0 || x == w - 1 || y == h - 1)
			{*/
					if (peak->z < 5)
					{
						data[4 * (peak->yy * w + peak->xx) + 0] = 0xFF;
						data[4 * (peak->yy * w + peak->xx) + 1] = 0xAA;
					}
					if (peak->z > 5)
						data[4 * (peak->yy * w + peak->xx) + 2] = 0xFF;
				data[4 * (peak->yy * w + peak->xx) + 3] = 0x00;
		/*}
			i += 4;
		}*/
		if (peak->next != NULL && peak->y == (peak->next)->y)
			ft_alline(peak, peak->next, data);
		if (peak->next)
		{
		down = peak->next;
		ft_putnbr(down->y);
		ft_putchar('\t');
		ft_putnbr(peak->y);
		ft_putchar('\n');
		while (down->y != peak->y && down->next)
			down = down->next;
		ft_alline(peak, down, data);
		}
		peak = peak->next;

	}
	return (img);
}
