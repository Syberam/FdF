/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpeaks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 10:17:44 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/03/01 16:41:23 by sbonnefo         ###   ########.fr       */
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

	h = 200;
	w = 200;
	if (!(img = mlx_new_image(param->mlx, w, h)))
		exit (0);
	data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	while (peak)
	{
		i = 0;
		while (i < (peak->xx) * (peak->yy))
		{
			x = i % h;
			y = i / h;
			if (peak->xx == x && peak->yy == y)
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
