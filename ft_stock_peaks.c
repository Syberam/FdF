/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_peaks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:18:03 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/03/08 17:00:11 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/fdf.h"

t_peak	*ft_newpeak(t_peak *before)
{
	t_peak	*new;

	if (!(new = (t_peak *)ft_memalloc(sizeof(t_peak))))
		return (0);
	if (!before)
		return(new);
	before->next = new;
	return (new);
}

t_peak	*ft_stock_peaks(char *file_path)
{
	t_peak		*start;
	t_peak		*current;
	char		*line;
	char		**point;
	int			val[3];

	if (!(val[0] = (const int)open(file_path, O_RDONLY)))
		return (0);
	start = NULL;
	if (!(start = (t_peak *)ft_memalloc(sizeof(t_peak))))
		return (0);
	current = start;
	val[2] = 0;
	while (get_next_line(val[0], &line) != 0)
	{
		point = ft_strsplit(line, ' ');
		val[1] = -1;
		while (point[++val[1]])
		{
			current->z = ft_atoi(point[val[1]]);
			current->y = val[2];
			current->x = val[1];
			current = ft_newpeak(current);
		}
		val[2]++;
	}
	return (start);
}
