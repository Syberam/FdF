/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 19:49:21 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/08 21:35:43 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static void	ft_menu_frame(t_mlx *param)
{
	int		x;
	int		y;

	x = 2;
	while (++x <= 340)
	{
		y = 2;
		while (++y <= 320)
		{
			if (x < 8 || x > 335 || y < 8 || y > 315)
				mlx_pixel_put(param->mlx, param->win, x, y, 0x00FFFFFF);
		}
	}
}

static void	ft_pad_grid(t_mlx *param)
{
	int		x;
	int		y;

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
	x = 200;
	while (++x <= 301)
	{
		y = 39;
		while (++y <= 125)
		{
			if (x < 204 || x > 298 || y < 43 || y > 122 || x == 236 || x == 266
					|| y == 65 || y == 95)
				mlx_pixel_put(param->mlx, param->win, x, y, 0x00FFFFFF);
		}
	}
}

void		ft_menu(t_mlx *param)
{
	ft_menu_frame(param);
	mlx_string_put(param->mlx, param->win, 20, 10, 0x99FFFFFF, "MENU (m)");
	mlx_string_put(param->mlx, param->win, 20, 70, 0x00FFFFFF, "Move : ");
	mlx_string_put(param->mlx, param->win, 100, 40, 0x00FFFFFF, " 7  8  9");
	mlx_string_put(param->mlx, param->win, 100, 70, 0x00FFFFFF, " 4  5  6");
	mlx_string_put(param->mlx, param->win, 100, 100, 0x00FFFFFF, " 1  2  3");
	mlx_string_put(param->mlx, param->win, 205, 40, 0x00FFFFFF, " \\  ^  /");
	mlx_string_put(param->mlx, param->win, 205, 70, 0x00FFFFFF, " <- o ->");
	mlx_string_put(param->mlx, param->win, 205, 100, 0x00FFFFFF, " /  v  \\");
	ft_pad_grid(param);
	mlx_string_put(param->mlx, param->win, 20, 130, 0x00FFFFFF, "zoom +");
	mlx_string_put(param->mlx, param->win, 170, 130, 0x00FFFFFF, ": +");
	mlx_string_put(param->mlx, param->win, 20, 160, 0x00FFFFFF, "zoom -");
	mlx_string_put(param->mlx, param->win, 170, 160, 0x00FFFFFF, ": -");
	mlx_string_put(param->mlx, param->win, 20, 190, 0x00FFFFFF, "rotations");
	mlx_string_put(param->mlx, param->win, 170, 190, 0x00FFFFFF, ": -> <- ^ v");
	mlx_string_put(param->mlx, param->win, 20, 220, 0x00FFFFFF, "zoom JPP");
	mlx_string_put(param->mlx, param->win,
			170, 220, 0x00FFFFFF, ": page up/down");
	mlx_string_put(param->mlx, param->win,
			20, 250, 0x00FFFFFF, "h index + ou -");
	mlx_string_put(param->mlx, param->win,
			170, 250, 0x00FFFFFF, ": * ou / ou =");
	mlx_string_put(param->mlx, param->win, 20, 280, 0x00FFFFFF, "Reinit");
	mlx_string_put(param->mlx, param->win, 170, 280, 0x00FFFFFF, ": 0");
}