/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keymenu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 21:00:47 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/03/23 22:34:36 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/fdf.h"

int		ft_keymenu(int keycode, t_mlx *param)
{
	int x;
	int	y;
 	
	if (keycode == 86) 
	{
		x = 97;
		while (++x < 130)
		{
			y = 65;
			while (++y < 95)
				mlx_pixel_put(param->mlx, param->win, x, y, 0xFF000000);
		}
	}
	if (keycode == 88) 
	{
		x = 160;
		while (++x < 195)
		{
			y = 65;
			while (++y < 95)
				mlx_pixel_put(param->mlx, param->win, x, y, 0x00000000);
		}
	}
	if (keycode == 87) 
	{
		x = 130;
		while (++x < 160)
		{
			y = 65;
			while (++y < 95)
				mlx_pixel_put(param->mlx, param->win, x, y, 0x00000000);
		}
	}
	if (keycode == 86) 
	{
		x = 97;
		while (++x < 130)
		{
			y = 65;
			while (++y < 95)
				mlx_pixel_put(param->mlx, param->win, x, y, 0x00000000);
		}
	}
	if (keycode == 86) 
	{
		x = 97;
		while (++x < 130)
		{
			y = 65;
			while (++y < 95)
				mlx_pixel_put(param->mlx, param->win, x, y, 0x00000000);
		}
	}
	ft_menu(param);
	return (keycode);
}
