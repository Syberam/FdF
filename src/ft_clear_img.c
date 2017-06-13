/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 15:37:49 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/13 16:06:01 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

char	*ft_clear_img(char *data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		ft_putendl("l22");
		data[i] = 0x000000;
		i += 6;
	}
	return (data);
}
