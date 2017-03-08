/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_peaks_to_plan.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:42:46 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/03/08 19:06:33 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/fdf.h"

void			ft_img_size(t_peak *peak)
{
		t_peak	*current;
		int		w;
		int		h;

		current = peak;
		while (peak->next)
		{
			w = peak->x;
			h = peak->y;
			peak = peak->next;
		}
		current = peak;
		while(peak)
		{
			peak->w = w;
			peak->w = w;
			peak = peak->next;
		}

}

void		ft_peaks_to_plan(t_peak *peak)
{
	int		ox;
	int		oy;

	ox = (peak->w) / 2; 
	oy = (peak->h) / 2; 
	while (peak)
	{
		peak->xx = ox - (peak->y * 10) + (peak->x * 10);
		peak->yy = oy + (peak->y * 10) - (10 * peak->z);
		peak = peak->next;
	}
	ft_img_size(peak);
}
