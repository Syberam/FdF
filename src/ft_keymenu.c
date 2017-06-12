/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keymenu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 21:00:47 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/13 01:42:27 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static int		ft_keymenu_v(int keycode, t_mlx *param, int x, int y)
{
	if (keycode == KEY_C)
	{
		x = 130;
		while (++x < 160)
		{
			y = 65;
			while (++y < 95)
				mlx_pixel_put(param->mlx, param->win, x, y, 0x00000000);
		}
	}
	ft_menu(param);
	return (keycode);
}

static int		ft_keymenu_iv(int keycode, t_mlx *param, int x, int y)
{
	if (keycode == KEY_UP)
	{
		x = 130;
		while (++x < 160)
		{
			y = 42;
			while (++y < 65)
				mlx_pixel_put(param->mlx, param->win, x, y, 0x00000000);
		}
	}
	if (keycode == KEY_DR)
	{
		x = 160;
		while (++x < 195)
		{
			y = 95;
			while (++y < 126)
				mlx_pixel_put(param->mlx, param->win, x, y, 0x00000000);
		}
	}
	return (keycode = ft_keymenu_v(keycode, param, x, y));
}

static int		ft_keymenu_iii(int keycode, t_mlx *param, int x, int y)
{
	if (keycode == KEY_UPL)
	{
		x = 97;
		while (++x < 130)
		{
			y = 42;
			while (++y < 65)
				mlx_pixel_put(param->mlx, param->win, x, y, 0x00000000);
		}
	}
	if (keycode == KEY_UPR)
	{
		x = 160;
		while (++x < 195)
		{
			y = 42;
			while (++y < 65)
				mlx_pixel_put(param->mlx, param->win, x, y, 0x00000000);
		}
	}
	return (keycode = ft_keymenu_iv(keycode, param, x, y));
}

static int		ft_keymenu_ii(int keycode, t_mlx *param, int x, int y)
{
	if (keycode == KEY_DL)
	{
		x = 97;
		while (++x < 130)
		{
			y = 95;
			while (++y < 126)
				mlx_pixel_put(param->mlx, param->win, x, y, 0x00000000);
		}
	}
	if (keycode == KEY_DOWN)
	{
		x = 130;
		while (++x < 160)
		{
			y = 95;
			while (++y < 126)
				mlx_pixel_put(param->mlx, param->win, x, y, 0x00000000);
		}
	}
	return (keycode = ft_keymenu_iii(keycode, param, x, y));
}

int				ft_keymenu(int keycode, t_mlx *param)
{
	int x;
	int	y;

	if (keycode == KEY_L)
	{
		x = 97;
		while (++x < 130)
		{
			y = 65;
			while (++y < 95)
				mlx_pixel_put(param->mlx, param->win, x, y, 0x00000000);
		}
	}
	if (keycode == KEY_R)
	{
		x = 160;
		while (++x < 195)
		{
			y = 65;
			while (++y < 95)
				mlx_pixel_put(param->mlx, param->win, x, y, 0x00000000);
		}
	}
	keycode = ft_keymenu_ii(keycode, param, x, y);
	return (keycode);
}
