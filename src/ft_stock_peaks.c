/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_peaks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:18:03 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/13 01:41:03 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

static void		ft_setcolor(t_mlx *param)
{
	t_peak		*cur;
	int			moy;

	moy = param->total_z / param->nb_peaks;
	cur = param->start;
	while (cur && cur->next)
	{
		if (!cur->col)
			cur->col = 0xFF0000 - (0x00FFFF * (cur->z - moy));
		cur = cur->next;
	}
}

static void		ft_stock_values(t_peak *cur, int val[3], char **p,
									t_mlx *param)
{
	cur->z = ft_atoi(p[val[1]]);
	param->total_z += cur->z;
	param->max_z = (param->max_z > cur->z) ? param->max_z : cur->z;
	cur->y = val[2];
	param->max_y = (param->max_y > cur->y) ? param->max_y : cur->y;
	cur->x = val[1];
	param->max_x = (param->max_x > cur->x) ? param->max_x : cur->x;
	cur->col = ft_strchr(p[val[1]], 'x') ?
		ft_atoi_base(ft_strchr(p[val[1]], 'x') + 1, 16) : 0;
	param->nb_peaks++;
}

static t_peak	*ft_newpeak(t_peak *before)
{
	t_peak	*new;

	if (!(new = (t_peak *)ft_memalloc(sizeof(t_peak) + 1)))
		return (0);
	if (!before)
		return (new);
	new->next = NULL;
	before->next = new;
	return (new);
}

t_peak			*ft_stock_peaks(t_peak *start, char *path, t_mlx *param)
{
	t_peak		*cur;
	char		*line;
	char		**p;
	int			val[3];

	cur = start;
	param->start = start;
	val[2] = 0;
	val[0] = open(path, O_RDONLY);
	while (gnl(val[0], &line) != 0 && (val[1] = -1))
	{
		p = ft_strsplit(line, ' ');
		while (p[++val[1]])
		{
			ft_stock_values(cur, val, p, param);
			cur = ft_newpeak(cur);
		}
		val[2]++;
	}
	ft_setcolor(param);
	free(line);
	free(*p);
	free(p);
	return (start);
}
