/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_al.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:37:23 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/13 01:33:16 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static void	ft_pix_to_img(int x, int y, char *data, t_lp par)
{
	data[4 * (y * (par.w * 2) + x) + 0] = par.col >> 0;
	data[4 * (y * (par.w * 2) + x) + 1] = par.col >> 8;
	data[4 * (y * (par.w * 2) + x) + 2] = par.col >> 16;
	data[4 * (y * (par.w * 2) + x) + 3] = par.col >> 24;
}

static void	ft_peaks_to_img(char *data, t_peak *start, int col, t_mlx *param)
{
	data[4 * ((int)start->yy * param->w * 2 + (int)start->xx) + 0] = col >> 0;
	data[4 * ((int)start->yy * param->w * 2 + (int)start->xx) + 1] = col >> 8;
	data[4 * ((int)start->yy * param->w * 2 + (int)start->xx) + 2] = col >> 16;
	data[4 * ((int)start->yy * param->w * 2 + (int)start->xx) + 3] = col >> 24;
}

static void	ft_do_line(t_peak *start, t_lp par, char *data, int dir)
{
	par.i = 0;
	par.x = (dir == 1) ? start->xx : start->yy;
	par.y = (dir == 1) ? start->yy : start->xx;
	par.xi = (par.dx > 0) ? 1 : -1;
	par.yi = (par.dy > 0) ? 1 : -1;
	par.dx = abs(par.dx);
	par.dy = abs(par.dy);
	par.cumul = par.dx / 2;
	while (++par.i <= par.dx)
	{
		par.x += par.xi;
		par.cumul += par.dy;
		if (par.cumul >= par.dx)
		{
			par.cumul -= par.dx;
			par.y += par.yi;
		}
		if ((dir == 1) && (par.y * par.w + par.x < par.w * par.h)
				&& par.x > -1 && par.y >= 0)
			ft_pix_to_img(par.x, par.y, data, par);
		else if (dir == 2 && (par.x * par.w + par.y < par.w * par.h)
				&& par.x >= 0 && par.y >= 0)
			ft_pix_to_img(par.y, par.x, data, par);
	}
}

void		ft_line_al(t_peak *start, t_peak *end, char *data, t_mlx *param)
{
	t_lp	par;
	int		swp;

	ft_peaks_to_img(data, end, end->col, param);
	par.dx = end->xx - start->xx;
	par.dy = end->yy - start->yy;
	par.w = param->w;
	par.h = param->h;
	par.col = (start->col + end->col) / 2;
	if (abs(par.dx) > abs(par.dy))
		ft_do_line(start, par, data, 1);
	else
	{
		swp = par.dx;
		par.dx = par.dy;
		par.dy = swp;
		ft_do_line(start, par, data, 2);
	}
}
