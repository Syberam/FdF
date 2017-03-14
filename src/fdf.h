/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 18:30:34 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/03/14 17:17:23 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>

typedef struct		s_pers
{
	int				zoom;
	int				xxx;
	int				xz;
	int				yyy;
	int				yz;
}					t_pers;

typedef struct		s_fdf_img
{
	void			*img;
	t_pers			*pers;
	s_fdf_img		*next;
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
	int				w;
	int				h;
	struct s_peak	*next;
}					t_peak;

/*
typedef struct	s_fdf_pxl
{

}				t_fdfp;
*/
#endif

int		ft_putkeynbr(int keycode, t_mlx *param);
t_peak	*ft_stock_peaks(char *file_path);
void	ft_peaks_to_plan(t_peak *peak);
void	*ft_putpeaks(t_peak *peak, t_mlx *param);
void	ft_line_al(t_peak *start, t_peak *end, char *data);
