/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurichar <jurichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:26:17 by jurichar          #+#    #+#             */
/*   Updated: 2021/02/19 10:28:23 by jurichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		loop(t_p *p)
{
	game(p);
	draw_line(p);
	if (p->save->save == 1)
		manage_save(p);
	deal_key(p);
	return (0);
}

void	set_res(t_p *p)
{
	char	*res;
	char	*s;
	int		i;

	res = p->info->r;
	i = -1;
	s = malloc(sizeof(char) * ft_strlen(res));
	while (res[++i] != ' ')
	{
		s[i] = res[i];
	}
	s[i] = 0;
	p->res.width = (ft_atoi(s) >= p->screen_s_x) ? p->screen_s_x : ft_atoi(s);
	p->res.height = (ft_atoi(&res[i]) >= p->screen_s_y) ?
	p->screen_s_y : ft_atoi(&res[i]);
	free(s);
}

t_p		*mlx_first(void)
{
	t_p	*p;

	p = (t_p*)malloc(sizeof(t_p));
	p->mlx_ptr = mlx_init();
	return (p);
}

int		ext(void)
{
	exit(0);
	return (0);
}

int		main(int ac, char **av)
{
	t_p *p;
	int fd;

	p = mlx_first();
	set_info_to_null(p);
	manage_args(ac, av, p);
	fd = open(av[1], O_RDONLY);
	if (fd < 1)
		exit_all(p);
	manage_map(fd, p, -1);
	close(fd);
	mlx_get_screen_size(p->mlx_ptr, &p->screen_s_x, &p->screen_s_y);
	set_res(p);
	init(p);
	load_texture(p);
	get_rgb(p);
	p->pos_x = p->info->spawn_coord[1] + 0.5;
	p->pos_y = p->info->spawn_coord[0] + 0.5;
	mlx_hook(p->win_ptr, 2, (1L << 0), key_press, (void *)p);
	mlx_hook(p->win_ptr, 3, (1L << 1), key_release, (void *)p);
	mlx_loop_hook(p->mlx_ptr, loop, (void *)p);
	mlx_hook(p->win_ptr, 33, 1L << 5, ext, (void *)p);
	mlx_loop(p->mlx_ptr);
	return (0);
}
