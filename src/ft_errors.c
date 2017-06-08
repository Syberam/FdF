/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 15:00:26 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/08 18:26:57 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

void	ft_exit(void)
{
	exit(1);
}

void	ft_malloc_error(void)
{
	ft_putstr_fd("malloc error\n", 2);
	ft_exit();
}

void	ft_map_error(void)
{
	ft_putstr_fd("map error\n", 2);
	ft_exit();
}

void	ft_im_error(void)
{
	ft_putstr_fd("image creation error\n", 2);
	ft_exit();
}

void	ft_arg_error(void)
{
	ft_putstr_fd("Un seul argument pris en compte.\n", 2);
	ft_exit();
}
