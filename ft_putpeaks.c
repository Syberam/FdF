/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpeaks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 10:17:44 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/03/08 20:00:33 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/fdf.h"

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

	h = peak->h;
	w = peak->w;
			ft_putnbr(h);
	if (!(img = mlx_new_image(param->mlx, peak->w, peak->h)))
		exit (0);
	bpp = 32;
	endian = 0;
	size_line = 100;
	data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	while (peak)
	{
		i = 0;
		while (i < 4 * h * w)
		{
			x = (i / 4) % w;
			y = (i / 4) / h;
			if ((peak->xx == x && peak->yy == y) || x == 0 ||y == 0 || x == h - 1 || y == w - 1)
			{
				data[i + 0] = 0x00;
				data[i + 1] = 0x00;
				data[i + 2] = 0xF0;
				data[i + 3] = 0x00;
			}
			i += 4;
		}
		peak = peak->next;

	}
	return (img);
}
