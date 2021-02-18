/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurichar <jurichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:33:58 by jurichar          #+#    #+#             */
/*   Updated: 2021/02/18 10:33:59 by jurichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	write_header(unsigned char *header, int param)
{
	header[0] = (unsigned char)(param);
	header[1] = (unsigned char)(param >> 8);
	header[2] = (unsigned char)(param >> 16);
	header[3] = (unsigned char)(param >> 24);
}

void	write_img(t_p *par, t_save *save, int fd)
{
	int j;
	int x;
	int y;

	j = -1;
	while (++j < par->res.height)
	{
		x = -1;
		while (++x < par->res.width)
		{
			y = par->res.height - 1 - j;
			save->rgb = par->buf[y][x];
			write(fd, &save->rgb, 3);
		}
		x = -1;
		while (++x < (4 - ((int)par->res.width * 3) % 4) % 4)
			write(fd, &save->padding, 1);
	}
}

void	manage_header(t_p *par, t_save *save, int fd)
{
	int i;

	i = 0;
	while (i < 14)
		save->header[i++] = 0;
	save->header[0] = 'B';
	save->header[1] = 'M';
	save->header[10] = 54;
	i = 0;
	while (i < 40)
		save->data[i++] = 0;
	save->data[0] = 40;
	save->data[12] = 1;
	save->data[14] = 24;
	i = 0;
	while (i < 3)
		save->padding[i++] = 0;
	write_header(&save->header[2], save->size);
	write_header(&save->data[4], par->res.width);
	write_header(&save->data[8], par->res.height);
	write(fd, save->header, 14);
	write(fd, save->data, 40);
}

void	manage_save(t_p *par)
{
	int		img_size;
	int		fd;

	img_size = 3 * par->res.width * par->res.height;
	par->save->size = 54 + img_size;
	if (!(par->save->img = malloc((sizeof(char) * (img_size + 1)))))
		error_manager(0, par);
	ft_memset(par->save->img, 0, img_size);
	fd = open("save.bmp", O_CREAT | O_WRONLY, S_IRWXU);
	manage_header(par, par->save, fd);
	write_img(par, par->save, fd);
	free(par->save->img);
	close(fd);
	exit_all(par);
}
