/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_peaks_to_plan.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:42:46 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/03/09 18:01:10 by sbonnefo         ###   ########.fr       */
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
		while (current->next)
		{
			if (current->xx > w)
				w = current->xx;
			if (current->yy > h)
				h = current->yy;
			current = current->next;
		}
		current = peak;
		ft_putnbr(w);
		ft_putchar('\n');
		ft_putnbr(h);
		while(current)
		{
			current->w = w;
			current->h = h;
			current = current->next;
		}

}

void		ft_peaks_to_plan(t_peak *peak)
{
	int		init;
	int		ox;
	int		oy;
	t_peak	*start;

	start = peak;
	init = 0;
	while (peak)
	{
		peak->xx = -(peak->y * 20) + (peak->x * 20);
		peak->yy = (peak->y * 20) - (21 * peak->z);
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
