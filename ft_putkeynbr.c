/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putkeynbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:22:44 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/03/16 17:22:16 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/fdf.h"

void	ft_redraw(t_mlx *param)
{
		mlx_clear_window(param->mlx, param->win);
		ft_peaks_to_plan(param->imgs->start, param->pers);
		param->imgs->img = ft_putpeaks(param->imgs->start, param);
		mlx_put_image_to_window(param->mlx, param->win, param->imgs->img, ((1800 - param->imgs->start->w) / 2),  ((1200 - param->imgs->start->h) / 2));	
}

int	ft_putkeynbr(int keycode, t_mlx *param)
{
	ft_putnbr(keycode);
	ft_putchar('\n');
	mlx_do_key_autorepeaton(param->mlx);
	if (keycode == 53)
	{
		exit (0);
		/*ad expose closure*/
	}
	if (keycode == 78)
	{
		param->pers->yx--;
		param->pers->x--;
		param->pers->y--;
		param->pers->zy--;
		ft_redraw(param);
	}
	if (keycode == 69)
	{
		param->pers->yx++;
		param->pers->x++;
		param->pers->y++;
		param->pers->zy++;
		ft_redraw(param);
	}
	if (keycode == 123)
	{
		param->pers->yx--;
		if (param->pers->yx < 0)
			param->pers->x = param->pers->x++;
		else
			param->pers->x = param->pers->x--;
		ft_redraw(param);
	}
	if (keycode == 125)
	{
		param->pers->y--;
		ft_redraw(param);
	}
	if (keycode == 126)
	{
		param->pers->y++;
		ft_redraw(param);
	}
	if (keycode == 124)
	{
		param->pers->yx++;
		if (param->pers->yx < 0)
			param->pers->x = param->pers->x++;
		else
			param->pers->x = param->pers->x--;
		ft_redraw(param);
	}
	if (keycode == 82)
	{
		param->pers->x = 1;
		param->pers->yx = 1;
		param->pers->y = 1;
		param->pers->zy = 1;
		ft_redraw(param);
	}
	return (keycode);
}
