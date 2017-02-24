/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 18:30:34 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/02/24 18:40:14 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>

typedef struct		s_fdf_img
{
	void			*img;
}					t_fdfi;

typedef	struct		s_mlx
{
	void			*content;
	void			*win;
	void			*mlx;
	t_fdfi			*img;
	size_t			content_size;
	struct s_mlx	*next;
}					t_mlx;

typedef struct		s_peak
{
	int				x;
	int				y;
	int				z;
	int				xx;
	int				yy;
	struct s_peak	next;
}

/*
typedef struct	s_fdf_pxl
{

}				t_fdfp;
*/
#endif
