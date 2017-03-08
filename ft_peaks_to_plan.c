/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_peaks_to_plan.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:42:46 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/03/08 19:34:56 by sbonnefo         ###   ########.fr       */
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
		while(current)
		{
			current->w = w;
			current->h = h;
			current = current->next;
		}

}

void		ft_peaks_to_plan(t_peak *peak)
{
	int		ox;
	int		oy;
	t_peak	*start;

	start = peak;
	ox = (peak->w) / 2; 
	oy = (peak->h) / 2; 
	while (peak)
	{
		peak->xx = ox - (peak->y * 30) + (peak->x * 30);
		peak->yy = oy + (peak->y * 30) - (30 * peak->z);
		peak = peak->next;
	}
	ft_img_size(start);
}
