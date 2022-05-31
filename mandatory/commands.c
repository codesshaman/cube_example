/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltapioca <ltapioca@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:08:04 by ltapioca          #+#    #+#             */
/*   Updated: 2022/05/22 14:20:48 by ltapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_esc(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
}

int	commands(int keycode, t_vars *vars)
{
	check_esc(keycode, vars);
	check_movements_up_down(keycode, vars);
	check_movements_left_right(keycode, vars);
	check_rotation_left(keycode, vars);
	check_rotation_right(keycode, vars);
	return (0);
}

int	closed_win(void)
{
	exit (0);
}
