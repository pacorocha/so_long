/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 01:46:44 by jfrancis          #+#    #+#             */
/*   Updated: 2021/09/09 01:46:46 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/so_long.h"

int	close_window(t_my_mlx *my_mlx)
{
	mlx_destroy_window(my_mlx->mlx, my_mlx->mlx_win);
	exit(0);
	return (0);
}
