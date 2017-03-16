/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_peaks_to_plan.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:42:46 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/03/16 20:46:55 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/fdf.h"

void			ft_img_size(t_peak *peak)
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
		current = peak;
		while(current)
		{
			current->w = w + 1;
			current->h = h + 1;
			current = current->next;
		}
}

void		ft_peaks_to_plan(t_peak *peak, t_pers *pers)
{
	int		ox;
	int		oy;
	t_peak	*start;

	start = peak;
	while (peak)
	{
		peak->xx = (peak->x * pers->x * pers->zoom) + (peak->y * pers->yx * pers->zoom);
		peak->yy = (peak->y * pers->y * pers->zoom) - (pers->zy * peak->z * pers->zoom);
		peak = peak->next;
	}
	peak = start;
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
	ft_img_size(start);
}
