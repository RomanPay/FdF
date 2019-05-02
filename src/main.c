/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrost-g <ofrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:29:20 by ofrost-g          #+#    #+#             */
/*   Updated: 2019/04/24 20:33:56 by ofrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		keys(int key, t_glob *com)
{
	if (key == 53)
		exit(0);
	if (key == 69)
		com->img.zoom++;
	if (key == 78)
		com->img.zoom--;
	if (key == 126)
		com->img.stepy -= 5;
	if (key == 125)
		com->img.stepy += 5;
	if (key == 123)
		com->img.stepx -= 5;
	if (key == 124)
		com->img.stepx += 5;
	set_angle(key, com);
	com->ptr.img_ptr = mlx_new_image(com->ptr.mlx_ptr, WIDTH, HEIGHT);
	com->img_str = mlx_get_data_addr(com->ptr.img_ptr, &(com->bpp),
			&(com->s_l), &(com->endian));
	draw(*com);
	mlx_clear_window(com->ptr.mlx_ptr, com->ptr.win_ptr);
	mlx_put_image_to_window(com->ptr.mlx_ptr, com->ptr.win_ptr,
			com->ptr.img_ptr, 0, 0);
	mlx_destroy_image(com->ptr.mlx_ptr, com->ptr.img_ptr);
	return (0);
}

void	check_name_file(char *str)
{
	size_t len;

	len = ft_strlen(str) - 1;
	if (str[len - 3] != '.' && str[len - 2] != 'f' && str[len - 1] != 'd'
		&& str[len] != 'f')
	{
		ft_putstr("Error name file!!!11!!1");
		exit(0);
	}
}

void	check_argument(int ac, char **av, t_glob *com)
{
	if (ac < 2)
	{
		ft_putstr("Missing file");
		exit(0);
	}
	check_name_file(av[1]);
	if (ac == 3 || ac == 4)
		set_default_color(ac, av, com);
	if (ac > 4)
	{
		ft_putstr("Too many arguments");
		exit(0);
	}
}

int		main(int argc, char **argv)
{
	t_glob	com;

	set_fdf(&com);
	check_argument(argc, argv, &com);
	com.ptr.fd = open(argv[1], O_RDONLY);
	if (!get_map(&com))
	{
		close(com.ptr.fd);
		exit(0);
	}
	com.ptr.mlx_ptr = mlx_init();
	com.ptr.win_ptr = mlx_new_window(com.ptr.mlx_ptr, WIDTH, HEIGHT, argv[1]);
	mlx_hook(com.ptr.win_ptr, 2, 5, keys, &com);
	mlx_loop(com.ptr.mlx_ptr);
	return (0);
}
