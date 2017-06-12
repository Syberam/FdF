/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_peaks_to_plan.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:42:46 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/13 00:48:03 by sbonnefo         ###   ########.fr       */
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
	param->w = w;
	param->h = h;
}

void		ft_keep_good_img_size(t_peak *peak, t_peak *start)
{
	int		ox;
	int		oy;

	ox = 0;
	oy = 0;
	while (peak)
	{
		if (ox > peak->xx)
			ox = peak->xx;
		if (oy > peak->yy)
			oy = peak->yy;
		peak = peak->next;
	}
	peak = start;
	while (peak)
	{
		peak->xx = peak->xx - ox;
		peak->yy = peak->yy - oy;
		peak = peak->next;
	}
}

void		ft_peaks_to_plan(t_peak *peak, t_pers *pers, t_mlx *param)
{
	t_peak	*start;

	start = peak;
	while (peak)
	{
		peak->xx = (pers->zoom) * ((peak->x * pers->x)
					+ (peak->y * pers->yx) + (pers->zx * peak->z));
		peak->yy = (pers->zoom) * ((peak->y * pers->y)
					- (pers->zy * peak->z) + (peak->x * pers->xy));
		peak = peak->next;
	}
	peak = start;
	ft_keep_good_img_size(peak, start);
	ft_img_size(start, param);
}
