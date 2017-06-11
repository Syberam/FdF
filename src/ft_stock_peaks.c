/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_peaks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:18:03 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/09 00:52:22 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static void		ft_stock_values(t_peak *cur, int val[3], char **p)
{
	cur->z = ft_atoi(p[val[1]]);
	cur->y = val[2];
	cur->x = val[1];
	cur->col = ft_strchr(p[val[1]], 'x') ?
		ft_atoi_base(ft_strchr(p[val[1]], 'x') + 1, 16)
		: 0xFFFFFF - (0x001F1F * (int)cur->z);
}

static t_peak	*ft_newpeak(t_peak *before)
{
	t_peak	*new;

	if (!(new = (t_peak *)ft_memalloc(sizeof(t_peak) + 1)))
		return (0);
	if (!before)
		return (new);
	before->next = new;
	return (new);
}

t_peak			*ft_stock_peaks(t_peak *start, char *path)
{
	t_peak		*cur;
	char		*line;
	char		**p;
	int			val[3];

	cur = start;
	val[2] = 0;
	val[0] = open(path, O_RDONLY);
	while (gnl(val[0], &line) != 0 && (val[1] = -1))
	{
		p = ft_strsplit(line, ' ');
		while (p[++val[1]])
		{
			ft_stock_values(cur, val, p);
			cur = ft_newpeak(cur);
		}
		val[2]++;
	}
	free(line);
	free(*p);
	free(p);
	return (start);
}
