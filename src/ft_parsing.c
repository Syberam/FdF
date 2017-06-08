/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 10:12:40 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/09 00:00:11 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

t_peak			*ft_parsing_file(char **path)
{
	int		fd;
	t_peak	*start;

	if (!path || !path[1] || !ft_strrchr(path[1], '.')
			|| ft_strcmp(ft_strrchr(path[1], '.'), ".fdf"))
	{
		ft_putendl_fd("wrong file: usage: ./fdf map.fdf", 2);
		return (NULL);
	}
	if ((fd = open(path[1], O_RDONLY)) < 0)
	{
		ft_putendl_fd("wrong file: usage: ./fdf map.fdf", 2);
		return (NULL);
	}
	if (!(start = (t_peak *)ft_memalloc(sizeof(t_peak) + 1)))
	{
		ft_putendl_fd("t_peak malloc failes", 2);
		return (NULL);
	}
	return (start);
}
