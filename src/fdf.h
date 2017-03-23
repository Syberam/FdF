/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 18:30:34 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/03/23 21:02:31 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
#include <math.h>

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
	float				pozx;
	float				pozy;
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

typedef struct			s_lpar
{
	int					cumul;
	int					dx;
	int					dy;
	int					xi;
	int					yi;
	int					x;
	int					y;
	int					i;
}						t_lp;

int		ft_putkeynbr(int keycode, t_mlx *param);
int		ft_keymenu(int keycode, t_mlx *param);
t_peak	*ft_stock_peaks(char *file_path);
t_pers	*ft_pers_init(t_mlx *param);
void	ft_peaks_to_plan(t_peak *peak, t_pers *pers);
void	*ft_putpeaks(t_peak *peak, t_mlx *param);
void	ft_line_al(t_peak *start, t_peak *end, char *data);
void	ft_line_antal(t_peak *start, t_peak *end, char *param);
void	ft_menu(t_mlx *param);
#endif
