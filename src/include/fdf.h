/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 18:30:34 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/15 16:31:26 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include "fdf_keys.h"
# define WI_W 500
# define WI_H 600

typedef struct			s_peak
{
	int					x;
	int					y;
	int					z;
	float				xx;
	float				yy;
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

typedef	struct			s_mlx
{
	void				*content;
	void				*win;
	void				*mlx;
	void				*img;
	char				*data;
	int					total_z;
	int					nb_peaks;
	int					max_x;
	int					max_y;
	int					max_z;
	int					w;
	int					h;
	int					imw;
	int					imh;
	char				erase;
	t_peak				*start;
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
	int					w;
	int					h;
	int					i;
	int					col;
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

t_mlx					*ft_init_mymlx(t_mlx *para);
t_peak					*ft_parsing_file(char **path);
t_peak					*ft_stock_peaks(t_peak *start, char *path,
											t_mlx *param);
t_pers					*ft_pers_init(t_mlx *param);
void					ft_peaks_to_plan(t_peak *peak, t_pers *pers,
											t_mlx *param);

/*
**				DRAWING
*/

void					*ft_putpeaks(t_peak *peak, t_mlx *param);
void					ft_line_al(t_peak *start, t_peak *end, t_mlx *param);
void					ft_line_antal(t_peak *start, t_peak *end, char *param);
void					ft_redraw(t_mlx *param);
void					ft_clean_menu(t_mlx *param);

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
