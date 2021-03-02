#include "cub3d.h"

void	check_buffer_rest(char **map, t_p *p)
{
	while (*map)
	{
		if (**map)
			error_manager(22, p);
		map++;
	}
}
