/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_peaks_to_plan.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:42:46 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/15 19:26:03 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static void	ft_img_size(t_peak *peak, t_mlx *param)
{
	t_peak	*current;
	int		w;
	int		h;

	w = 0;
	h = 0;
	current = peak;
	while (current)
	{
		if (current->xx > w)
			w = current->xx;
		if (current->yy > h)
			h = current->yy;
		current = current->next;
	}
	param->w = (!param->w) ? w : param->w;
	param->h = (param->h + WI_W + 355 > 2400) ? 2400 - WI_H - 350 : param->h;
	param->h = (!param->h) ? h : param->h;
	param->h = (param->h + WI_H > 1300) ? 1300 - WI_H : param->h;
	param->imw = w - ((WI_W + param->w) / 2);
	param->imh = h - ((WI_H + param->h) / 2);
}

void		ft_peaks_to_plan(t_peak *peak, t_pers *pers, t_mlx *param)
{
	t_peak	*start;

	start = peak;
	while (peak)
	{
		peak->xx = (pers->pozx) + (pers->zoom) * ((peak->x * pers->x)
					+ (peak->y * pers->yx) + (pers->zx * peak->z));
		peak->yy = (pers->pozy) + (pers->zoom) * ((peak->y * pers->y)
					- (pers->zy * peak->z) + (peak->x * pers->xy));
		peak = peak->next;
	}
	peak = start;
	ft_img_size(start, param);
}
