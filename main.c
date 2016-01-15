/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 10:59:46 by fhuang            #+#    #+#             */
/*   Updated: 2016/01/15 12:36:37 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		exit_key(int keycode, t_env *env)
{
	if (env)
	if (keycode == 53)
		exit(0);
	printf("keycode :%i\n", keycode);
	return (0);
}

int		main()
{
	t_env	env;

	if (!(env.mlx = mlx_init()))
		return (-1);
	if (!(env.win = mlx_new_window(env.mlx, 500, 500, "TEST")))
		return (-1);
	mlx_key_hook(env.win, exit_key, &env);
	mlx_loop(env.mlx);
	return (0);
}
