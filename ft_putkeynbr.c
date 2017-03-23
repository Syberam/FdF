/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putkeynbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:22:44 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/03/23 22:34:39 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/fdf.h"

void	ft_redraw(t_mlx *param)
{
		mlx_clear_window(param->mlx, param->win);
		ft_peaks_to_plan(param->imgs->start, param->pers);
		param->imgs->img = ft_putpeaks(param->imgs->start, param);
		mlx_put_image_to_window(param->mlx, param->win, param->imgs->img,
				((1800 - param->imgs->start->w) / 2 + param->pers->pozx),
				((1200 - param->imgs->start->h) / 2 + param->pers->pozy));
		ft_menu(param);	
}

int	ft_putkeynbr(int keycode, t_mlx *param)
{
	int		x;
	int		y;

	ft_putnbr(keycode);
	ft_putchar('\n');
	mlx_do_key_autorepeaton(param->mlx);
	if (keycode == 75)
		param->pers->zy -= 0.5;
	if (keycode == 67)
		param->pers->zy += 0.5;
	if (keycode == 53)
	{
		mlx_destroy_window(param->mlx, param->win);
		free(param);
		exit (0);
		/*ad expose closure*/
	}
	if (keycode == 78)
	{
		param->pers->zoom--;
	}
	if (keycode == 69)
	{
		param->pers->zoom++;
	}
	if (keycode == 123)
	{
		param->pers->x++;
		param->pers->y--;
		param->pers->xy--;
	}
	if (keycode == 125)
	{
		param->pers->y--;
	}
	if (keycode == 126)
	{
		param->pers->y++;
	}
	if (keycode == 124)
	{
		param->pers->x--;
		param->pers->y++;
		param->pers->xy++;
	}
	if (keycode == 82)
	{
		ft_pers_init(param);
	}
	if (keycode == 86)
	{
		param->pers->pozx -= 30;
		x = 97;
		while (++x < 130)
		{
			y = 65;
			while (++y < 95)
				mlx_pixel_put(param->mlx, param->win, x, y, 0x00FF00AA);
		}	
	}
	if (keycode == 88)
	{
		param->pers->pozx += 30;
		x = 160;
		while (++x < 195)
		{
			y = 65;
			while (++y < 95)
			mlx_pixel_put(param->mlx, param->win, x, y, 0x00FF00AA);
		}	
	}
	if (keycode == 84)
	{
		param->pers->pozy += 30;
		x = 130;
		while (++x < 160)
		{
			y = 95;
			while (++y < 124)
			mlx_pixel_put(param->mlx, param->win, x, y, 0x00FF00AA);
		}	

	}
	if (keycode == 91)
	{
		param->pers->pozy -= 30;
		x = 130;
		while (++x < 160)
		{
			y = 40;
			while (++y < 66)
			mlx_pixel_put(param->mlx, param->win, x, y, 0x00FF00AA);
		}	
	}
	if (keycode == 89)
	{	
		param->pers->pozx -= 30;
		param->pers->pozy -= 30;
	}
	if (keycode == 85)
	{	
		param->pers->pozx += 30;
		param->pers->pozy += 30;
	}
	if (keycode == 83)
	{	
		param->pers->pozy += 30;
		param->pers->pozx -= 30;
	}
	if (keycode == 92)
	{	
		param->pers->pozy -= 30;
		param->pers->pozx += 30;
	}
	if (keycode == 87)
	{
		param->pers->pozx = 0;
		param->pers->pozy = 0;
		x = 130;
		while (++x < 160)
		{
			y = 65;
			while (++y < 95)
			mlx_pixel_put(param->mlx, param->win, x, y, 0x00FF00AA);
		}	
	}
	ft_redraw(param);
	return (keycode);
}
