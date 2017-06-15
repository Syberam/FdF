/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 19:49:21 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/15 21:26:25 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void		ft_clean_menu(t_mlx *param)
{
	int		x;
	int		y;

	x = 2;
	while (++x <= 340)
	{
		y = 2;
		while (++y <= 320)
			mlx_pixel_put(param->mlx, param->win, x, y, 0x00000000);
	}
}

static void	ft_menu_frame(t_mlx *param)
{
	int		x;
	int		y;

	mlx_string_put(param->mlx, param->win, 20, 70, 0x00FFFFFF, "Move : ");
	mlx_string_put(param->mlx, param->win, 100, 40, 0x00FFFFFF, " 7  8  9");
	mlx_string_put(param->mlx, param->win, 100, 70, 0x00FFFFFF, " 4  5  6");
	mlx_string_put(param->mlx, param->win, 100, 100, 0x00FFFFFF, " 1  2  3");
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
	x += 5;
	y = 0;
	while (++y < (WI_H + param->h))
		mlx_pixel_put(param->mlx, param->win, x, y, 0x00FFFFFF);
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
	mlx_string_put(param->mlx, param->win, 20, 10, 0xFFFFFF, "MENU (m)");
	if (!param->menu)
		return ;
	ft_menu_frame(param);
	mlx_string_put(param->mlx, param->win, 205, 40, 0xFFFFFF, " \\  ^  /");
	mlx_string_put(param->mlx, param->win, 205, 70, 0xFFFFFF, " <- o ->");
	mlx_string_put(param->mlx, param->win, 205, 100, 0xFFFFFF, " /  v  \\");
	ft_pad_grid(param);
	mlx_string_put(param->mlx, param->win, 20, 130, 0xFFFFFF, "zoom +");
	mlx_string_put(param->mlx, param->win, 170, 130, 0xFFFFFF, ": +");
	mlx_string_put(param->mlx, param->win, 20, 160, 0xFFFFFF, "zoom -");
	mlx_string_put(param->mlx, param->win, 170, 160, 0xFFFFFF, ": -");
	mlx_string_put(param->mlx, param->win, 20, 190, 0xFFFFFF, "rotations");
	mlx_string_put(param->mlx, param->win, 170, 190, 0xFFFFFF, ": -> <- ^ v");
	mlx_string_put(param->mlx, param->win, 20, 220, 0xFFFFFF, "zoom JPP");
	mlx_string_put(param->mlx, param->win,
			170, 220, 0xFFFFFF, ": page up/down");
	mlx_string_put(param->mlx, param->win,
			20, 250, 0xFFFFFF, "h index + ou -");
	mlx_string_put(param->mlx, param->win,
			170, 250, 0xFFFFFF, ": * ou / ou =");
	mlx_string_put(param->mlx, param->win, 20, 280, 0xFFFFFF, "Reinit");
	mlx_string_put(param->mlx, param->win, 170, 280, 0xFFFFFF, ": 0");
}
