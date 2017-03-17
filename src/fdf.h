/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 18:30:34 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/03/17 10:50:37 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>

typedef struct		s_peak
{
	float			x;
	float			y;
	float			z;
	float			xx;
	float			yy;
	int				w;
	int				h;
	struct s_peak	*next;
}					t_peak;

typedef struct			s_pers
{
	float				zoom;
	float				x;
	float				yx;
	float				zx;
	float				y;
	float				zy;
	float				xy;
}						t_pers;

typedef struct			s_fdf_img
{
	void				*img;
	t_peak				*start;	
	struct s_fdf_img	*next;
}						t_fdfi;

typedef	struct			s_mlx
{
	void				*content;
	void				*win;
	void				*mlx;
	t_fdfi				*imgs;
	t_pers				*pers;
	size_t				content_size;
	struct s_mlx		*next;
}						t_mlx;

int		ft_putkeynbr(int keycode, t_mlx *param);
t_peak	*ft_stock_peaks(char *file_path);
void	ft_peaks_to_plan(t_peak *peak, t_pers *pers);
void	*ft_putpeaks(t_peak *peak, t_mlx *param);
void	ft_line_al(t_peak *start, t_peak *end, char *data);

#endif
