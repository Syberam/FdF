/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putkeynbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:22:44 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/09 01:00:15 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void			ft_redraw(t_mlx *param)
{
	char		*data;

	data = NULL;
	mlx_destroy_image(param->mlx, param->imgs->img);
	mlx_clear_window(param->mlx, param->win);
	ft_peaks_to_plan(param->imgs->start, param->pers);
	param->imgs->img = ft_putpeaks(param->imgs->start, param, data);
	ft_menu(param);
}

static int		ft_putkeynbr_iv(int keycode, t_mlx *param, int x, int y)
{
	if (keycode == KEY_C)
	{
		x = 130;
		while (++x < 160)
		{
			y = 65;
			while (++y < 95)
				mlx_pixel_put(param->mlx, param->win, x, y, 0x00FF00AA);
		}
	}
	ft_rotate_z(keycode, param);
	ft_rotate_x(keycode, param);
	ft_redraw(param);
	mlx_put_image_to_window(param->mlx, param->win, param->imgs->img,
				((1800 - param->imgs->start->w) / 2 + param->pers->pozx),
				((1200 - param->imgs->start->h) / 2 + param->pers->pozy));
	ft_move(keycode, param);
	return (keycode);
}

static int		ft_putkeynbr_iii(int keycode, t_mlx *param, int x, int y)
{
	if (keycode == KEY_DOWN)
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
	if (keycode == KEY_UP)
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
	if (keycode == KEY_L)
	{
		x = 97;
		while (++x < 130)
		{
			y = 65;
			while (++y < 95)
				mlx_pixel_put(param->mlx, param->win, x, y, 0x00FF00AA);
		}
	}
	if (keycode == KEY_R)
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
	mlx_do_key_autorepeaton(param->mlx);
	if (keycode == KEY_HUP)
		param->pers->zy *= (param->imgs->start->w * 0.6 < 10000) ? 0.6 : 1;
	if (keycode == KEY_HDO)
		param->pers->zy *= (param->imgs->start->w * 1.4 < 10000) ? 1.4 : 1;
	if (keycode == KEY_HINIT)
		param->pers->zy = 1;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(param->mlx, param->imgs->img);
		mlx_destroy_window(param->mlx, param->win);
		exit(0);
	}
	if (keycode == KEY_ZM)
		param->pers->zoom *= (param->imgs->start->w * 0.8 > 50
							&& param->imgs->start->h * 0.8 > 50) ? 0.6 : 1;
	if (keycode == KEY_ZP)
		param->pers->zoom *= (param->imgs->start->w * 1.2 < 15000
							&& param->imgs->start->h * 1.2 < 15000) ? 1.4 : 1;
	return (ft_putkeynbr_ii(keycode, param, x, y));
}
