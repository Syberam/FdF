/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 16:30:11 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/02/22 12:43:58 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/fdf.h"

typedef struct	s_peak
{
	int			x;
	int			y;
	int			z;
	s_peak		*next;
}				t_peak;

int		main(int argc, char **argv)
{
	char		*line;
	char		**point;
	int			fd;
	int			x;
	int			y;
	int			z;
	t_mlx		*param;
	int			si;


	if (argc < 2)
		ft_putstr("usage : fdf <nom_fichier.fdf>");
	si = 50;
	param = ft_memalloc(sizeof(t_mlx));
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, 800,800, "mlx 42");
	fd = (const int)open(argv[1], O_RDONLY);
	y = 0;
	while (get_next_line(fd, &line) != 0)
	{
		point = ft_strsplit(line, ' ');
		x = 0;
		while (point[x])
		{
			z = ft_atoi(point[x]);
		mlx_string_put(param->mlx, param->win, 100 + 30 * x, 100 + 30 * y, 0x00FFFFFF - 100000 * z, point[x]);
			x++;
		}
		y++;
	}
	mlx_loop(param->mlx);
}
