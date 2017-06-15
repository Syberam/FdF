/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putkeynbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:22:44 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/15 03:52:26 by sbonnefo         ###   ########.fr       */
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
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(param->mlx, param->img);
		mlx_destroy_window(param->mlx, param->win);
		exit(0);
	}
	ft_rotate_z(keycode, param);
	ft_rotate_x(keycode, param);
	ft_redraw(param);
	mlx_put_image_to_window(param->mlx, param->win, param->img, 350, 0);
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
	ft_clean_menu(param);
	mlx_do_key_autorepeaton(param->mlx);
	ft_putpeaks(param->start, param);
	if (keycode == KEY_HUP)
		param->pers->zy *= 0.6;
	if (keycode == KEY_HDO)
		param->pers->zy *= 1.4;
	if (keycode == KEY_HINIT)
		param->pers->zy = 1;
	if (keycode == KEY_ZM)
		param->pers->zoom *= 0.6;
	if (keycode == KEY_ZP)
		param->pers->zoom *= 1.4;
	return (ft_putkeynbr_ii(keycode, param, x, y));
}
