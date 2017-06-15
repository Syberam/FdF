/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putkeynbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:22:44 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/15 21:25:39 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void			ft_redraw(t_mlx *param)
{
	ft_peaks_to_plan(param->start, param->pers, param);
	param->img = ft_putpeaks(param->start, param);
	ft_menu(param);
}

static int		ft_putkeynbr_iv(int keycode, t_mlx *param, int x, int y)
{
	if (keycode == KEY_C && param->menu)
	{
		x = 130;
		while (++x < 160)
		{
			y = 65;
			while (++y < 95)
				mlx_pixel_put(param->mlx, param->win, x, y, 0x00FF00AA);
		}
	}
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(param->mlx, param->img);
		mlx_destroy_window(param->mlx, param->win);
		exit(0);
	}
	ft_rotate_z(keycode, param);
	ft_rotate_x(keycode, param);
	ft_redraw(param);
	mlx_put_image_to_window(param->mlx, param->win, param->img, 350, 2);
	ft_move(keycode, param);
	return (keycode);
}

static int		ft_putkeynbr_iii(int keycode, t_mlx *param, int x, int y)
{
	if (keycode == KEY_DOWN && param->menu)
	{
		ft_move(keycode, param);
		x = 130;
		while (++x < 160)
		{
			y = 95;
			while (++y < 124)
				mlx_pixel_put(param->mlx, param->win, x, y, 0x00FF00AA);
		}
	}
	if (keycode == KEY_UP && param->menu)
	{
		ft_move(keycode, param);
		x = 130;
		while (++x < 160)
		{
			y = 40;
			while (++y < 66)
				mlx_pixel_put(param->mlx, param->win, x, y, 0x00FF00AA);
		}
	}
	return (ft_putkeynbr_iv(keycode, param, x, y));
}

static int		ft_putkeynbr_ii(int keycode, t_mlx *param, int x, int y)
{
	if (keycode == KEY_RINIT)
		ft_pers_init(param);
	if (keycode == KEY_L && param->menu)
	{
		x = 97;
		while (++x < 130)
		{
			y = 65;
			while (++y < 95)
				mlx_pixel_put(param->mlx, param->win, x, y, 0x00FF00AA);
		}
	}
	if (keycode == KEY_R && param->menu)
	{
		x = 160;
		while (++x < 195)
		{
			y = 65;
			while (++y < 95)
				mlx_pixel_put(param->mlx, param->win, x, y, 0x00FF00AA);
		}
	}
	return (ft_putkeynbr_iii(keycode, param, x, y));
}

int				ft_putkeynbr(int keycode, t_mlx *param)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (keycode == 46)
		param->menu = (!param->menu) ? 1 : 0;
	ft_clean_menu(param);
	ft_putpeaks(param->start, param);
	param->pers->zy *= (keycode == KEY_HUP) ? 0.6 : 1;
	param->pers->zy *= (keycode == KEY_HOP) ? 1.4 : 1;
	param->pers->zy = (keycode == KEY_HINIT) ? 1 : param->pers->zy;
	if (keycode == KEY_ZM)
	{
		param->pers->zoom *= 0.6;
		param->pers->pozx += param->imw / 2;
		param->pers->pozy += param->imh / 2;
	}
	if (keycode == KEY_ZP)
	{
		param->pers->zoom *= 1.4;
		param->pers->pozx -= param->imw / 2;
		param->pers->pozy -= param->imh / 2;
	}
	return (ft_putkeynbr_ii(keycode, param, x, y));
}
