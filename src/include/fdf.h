/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 18:30:34 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/09 01:03:12 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <math.h>

typedef struct			s_peak
{
	float				x;
	float				y;
	float				z;
	float				xx;
	float				yy;
	int					w;
	int					h;
	int					col;
	struct s_peak		*next;
}						t_peak;

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
	int					img_x;
	int					img_y;
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

typedef struct			s_img_par
{
	int					bpp;
	int					endian;
	int					size_line;
}						t_img_par;

/*
**				DATA MANAGE
*/

t_mlx					*ft_init_mymlx(void);
t_peak					*ft_parsing_file(char **path);
t_peak					*ft_stock_peaks(t_peak *start, char *path);
t_pers					*ft_pers_init(t_mlx *param);
void					ft_peaks_to_plan(t_peak *peak, t_pers *pers);

/*
**				DRAWING
*/

void					*ft_putpeaks(t_peak *peak, t_mlx *param, char *data);
void					ft_line_al(t_peak *start, t_peak *end, char *data);
void					ft_line_antal(t_peak *start, t_peak *end, char *param);
void					ft_redraw(t_mlx *param);

/*
**				MENU
*/

void					ft_menu(t_mlx *param);
int						ft_keymenu(int keycode, t_mlx *param);

/*
**				KEY MANAGE
*/

int						ft_putkeynbr(int keycode, t_mlx *param);
void					ft_move(int keycode, t_mlx *param);
void					ft_rotate_z(int keycode, t_mlx *param);
void					ft_rotate_x(int keycode, t_mlx *param);

void					ft_exit(void);

/*
**				ERROS
*/
void					ft_malloc_error(void);
void					ft_map_error(void);
void					ft_im_error(void);
void					ft_arg_error(void);

#endif
