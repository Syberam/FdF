#include "minilibx/mlx.h"
#include "../LibFt/libft.h"

typedef struct		s_mlx
{
	void			*content;
	void			*win;
	void			*mlx;
	void			*img;
	size_t			content_size;
	struct s_list	*next;
}					t_mlx;

int	ft_putkeynbr(int keycode, t_mlx *param)
{
	int		si;
	void	*img;
/*	float		x;
	float		y;
	float		size;
	int			left;
	int			top;

	size = 100;
*/	si = 50;
	ft_putnbr(keycode);
	ft_putchar('\n');
/*	x = 1;
	left = 400;
	top = 200;
	size = 400;
*/	if (keycode == 53)
		exit(0);
/*	if (keycode == 69)
		size = size * 1.5;
	if (keycode == 78)
		size = size * 0.5;
	if (keycode == 123)
		left -= 10;
*/	if (keycode == 124)
		img = mlx_xpm_file_to_image(param->mlx, "button_right_arrow_dwn.xpm", &si, &si);
	if (keycode == 125)
		img = mlx_xpm_file_to_image(param->mlx, "button_right_arrow.xpm", &si, &si);
/*	if (keycode == 126)
		top -= 10;
	while (x < size)
	{
		y = -x;
		while ( y < x + 1)
		{
			mlx_pixel_put(param->mlx, param->win, left + (y / 2), top + x, 0x00606060 + 10 * keycode);
		y++;
		}
	x++;
	}
*/
	mlx_put_image_to_window(param->mlx, param->win, img, 100, 750);
	return (keycode);
}

int			main(void)
{
	t_mlx	*prs;
	int		si;
	void	*img;
	
	si = 50;
	prs = ft_memalloc(sizeof(t_mlx));
	prs->mlx = mlx_init();
	prs->win = mlx_new_window(prs->mlx, 800, 800, "mlx 42");
	img = mlx_xpm_file_to_image(prs->mlx, "button_right_arrow.xpm", &si, &si);
	mlx_put_image_to_window(prs->mlx, prs->win, img, 100, 750);
	mlx_key_hook(prs->win, ft_putkeynbr, prs);
	mlx_loop(prs->mlx);
	return (0);
}
