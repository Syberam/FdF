/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_al.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:37:23 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/03/17 19:14:35 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/fdf.h"

void	ft_do_line(t_peak *start, t_lp par, char *data, int dir)
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
		if (dir == 1)
			data[4 * (par.y * start->w + par.x) + 2] = 0xFF;
		else
			data[4 * (par.x * start->w + par.y) + 2] = 0xFF;
	}
}

void	ft_line_al(t_peak *start, t_peak *end, char *data)
{
	t_lp	par;
	int		swp;

	par.dx = end->xx - start->xx;
	par.dy = end->yy - start->yy;
	data[(int)(4 * (start->yy * start->w + start->xx)) + 2] = 0xFF;
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
