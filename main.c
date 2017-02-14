#include "minilibx/mlx.h"
#include "../LibFt/libft.h"

int	ft_putkeynbr(int keycode, void *param)
{
	int		x;
	int		y;

	ft_putnbr(keycode);
	ft_putendl(" correspond a la touche");
	while (x < 400)
	{
		y = -x;
		while ( y < x + 1)
		{
			mlx_pixel_put(param[0], param[1], 400 + (y / 2), 200 + x, 0x00FF000A - x * y);
		y++;
		}
	x++;
	}

	return (keycode);
}

int	main(void)
{
	void	*prs[2];

	prs[0] = mlx_init();
	prs[1] = mlx_new_window(prs[0], 800, 800, "mlx 42");
	mlx_key_hook(prs[1], ft_putkeynbr, &*prs);
	mlx_loop(prs[0]);
	return (0);
}
