#include "../incl/cub3d.h"



/*
handler function which checks if the map fits to the requirements
[8] [1] [2]
[7] [S] [3]
[6] [5] [4]
*/
int	check_map(t_window *window)
{
	int	x;
	int y;
	int counter = 0;

	x = 0;
	y = 0;
	while (window->map->map[y][x] == ' ')
		x++;
	window->check->start_x = x;
	window->check->start_y = y;
	while (window->check->end_pos_flag)
	{
		printf("here1\n");
		if (window->check->start_x == x && window->check->start_y == y && counter >= 1)
			window->check->end_pos_flag = 0;
		else if (window->map->map[y - 1][x] && window->map->map[y - 1][x] == '1')					//1
			y--;
		else if (window->map->map[y - 1][x + 1] && window->map->map[y - 1][x + 1] == '1')			//2
		{
			y--;
			x++;
		}
		else if (window->map->map[y][x + 1] == '1' && window->map->map[y][x + 1])				//3
			x++;
		else if (window->map->map[y + 1][x + 1] == '1' && window->map->map[y + 1][x + 1])			//4
		{
			y++;
			x++;
		}
		else if (window->map->map[y + 1][x] == '1' && window->map->map[y + 1][x])				//5
			y++;
		else if (window->map->map[y + 1][x - 1] == '1' && window->map->map[y + 1][x - 1])			//6
		{
			y++;
			x--;
		}
		else if (window->map->map[y][x - 1] == '1' && window->map->map[y][x - 1])				//7
			x--;
		else if (window->map->map[y - 1][x - 1] == '1' && window->map->map[y - 1][x - 1])			//8
		{
			y--;
			x--;
		}
		else
			ft_end_process(ERR_INV_MAP);
		//check_end
		printf("Round[%d]: %d %d\n", counter++, x, y);
	}
	if (!init_colors(window))
		return (0);
	return (1);
}
