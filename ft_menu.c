/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 19:49:21 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/03/23 22:18:51 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/fdf.h"

void	ft_menu(t_mlx *param)
{
	int		x;
	int		y;

	mlx_string_put(param->mlx, param->win, 40, 10, 0x99FFFFFF, "MENU (m)");
	mlx_string_put(param->mlx, param->win, 10, 70, 0x00FFFFFF, "Move : ");
	mlx_string_put(param->mlx, param->win, 100, 40, 0x00FFFFFF, " 7  8  9");
	mlx_string_put(param->mlx, param->win, 100, 70, 0x00FFFFFF, " 4  5  6");
	mlx_string_put(param->mlx, param->win, 100, 100, 0x00FFFFFF, " 1  2  3");
	x = 94;
	while (++x <= 195)
	{
		y = 39;
		while (++y <= 125)
		{
			if (x < 98 || x > 192 || y < 43 || y > 122 || x == 130 || x == 160
					|| y == 65 || y == 95)
				mlx_pixel_put(param->mlx, param->win, x, y, 0x00FFFFFF);
		}
	}
	mlx_string_put(param->mlx, param->win, 10, 130, 0x00FFFFFF, "---- CAM ----");
	mlx_string_put(param->mlx, param->win, 40, 130, 0x00FFFFFF, "---- CAM ----");
	mlx_string_put(param->mlx, param->win, 10, 160, 0x00FFFFFF, "---- CAM ----");
	mlx_string_put(param->mlx, param->win, 40, 160, 0x00FFFFFF, "---- CAM ----");
	mlx_string_put(param->mlx, param->win, 10, 190, 0x00FFFFFF, "---- CAM ----");
	mlx_string_put(param->mlx, param->win, 40, 190, 0x00FFFFFF, "---- CAM ----");
	mlx_string_put(param->mlx, param->win, 10, 220, 0x00FFFFFF, "---- CAM ----");
	mlx_string_put(param->mlx, param->win, 40, 220, 0x00FFFFFF, "---- CAM ----");
}
