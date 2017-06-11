/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_al.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:37:23 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/08 23:55:49 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static void	ft_pix_to_img(int x, int y, t_peak *start, char *data, t_lp par)
{
	data[4 * (y * start->w + x) + 0] = par.col >> 0;
	data[4 * (y * start->w + x) + 1] = par.col >> 8;
	data[4 * (y * start->w + x) + 2] = par.col >> 16;
	data[4 * (y * start->w + x) + 3] = par.col >> 24;
}

static void	ft_peaks_to_img(char *data, t_peak *start, int col)
{
	data[4 * ((int)start->yy * start->w + (int)start->xx) + 0] = col >> 0;
	data[4 * ((int)start->yy * start->w + (int)start->xx) + 1] = col >> 8;
	data[4 * ((int)start->yy * start->w + (int)start->xx) + 2] = col >> 16;
	data[4 * ((int)start->yy * start->w + (int)start->xx) + 3] = col >> 24;
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
		if ((dir == 1) && (par.y * start->w + par.x < start->w * start->h)
				&& par.x > -1 && par.y >= 0)
			ft_pix_to_img(par.x, par.y, start, data, par);
		else if (dir == 2 && (par.x * start->w + par.y < start->w * start->h)
				&& par.x >= 0 && par.y >= 0)
			ft_pix_to_img(par.y, par.x, start, data, par);
	}
}

void		ft_line_al(t_peak *start, t_peak *end, char *data)
{
	t_lp	par;
	int		swp;

	ft_peaks_to_img(data, end, end->col);
	par.dx = end->xx - start->xx;
	par.dy = end->yy - start->yy;
	par.col = (start->col + end->col) / 2;/*(start->col < end->col) ?
			end->col + ((start->col - end->col) / 2) :
			start->col + ((end->col - start->col) / 2);*/
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
