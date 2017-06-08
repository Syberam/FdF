/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keymenu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 21:00:47 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/09 00:55:29 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static int		ft_keymenu_v(int keycode, t_mlx *param, int x, int y)
{
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
	ft_menu(param);
	return (keycode);
}

static int		ft_keymenu_iv(int keycode, t_mlx *param, int x, int y)
{
	if (keycode == 91)
	{
		x = 130;
		while (++x < 160)
		{
			y = 42;
			while (++y < 65)
				mlx_pixel_put(param->mlx, param->win, x, y, 0x00000000);
		}
	}
	if (keycode == 85)
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
	if (keycode == 89)
	{
		x = 97;
		while (++x < 130)
		{
			y = 42;
			while (++y < 65)
				mlx_pixel_put(param->mlx, param->win, x, y, 0x00000000);
		}
	}
	if (keycode == 92)
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
	if (keycode == 83)
	{
		x = 97;
		while (++x < 130)
		{
			y = 95;
			while (++y < 126)
				mlx_pixel_put(param->mlx, param->win, x, y, 0x00000000);
		}
	}
	if (keycode == 84)
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
	keycode = ft_keymenu_ii(keycode, param, x, y);
	return (keycode);
}
