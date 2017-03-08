/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seg_to_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 14:44:08 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/03/01 12:42:31 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_seg_to_img(t_peak p1, t_peak p2)
{
	void	*img;
	char	*data;
	int		bpp;
	int		endian;
	int		size_line;
	int		x;
	int		y;

	bpp = 0;
	endian = 0;
	size_line = 0;
	x = 0;
	y = 0;
	if (!(img = mlx_new_image(param->mlx, 100, 100)))
		exit(0);
	data = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	while (i < 40000)
	{
		y = i / 100;
		x = i % 100;
		if (x = y)
		{
			data[i + 0] = 0x00;
			data[i + 1] = 0x00;
			data[i + 2] = 0xAF;
			data[i + 3] = 0x00;
		}
		i += 4;
	}
}
