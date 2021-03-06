/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 01:59:31 by jfrancis          #+#    #+#             */
/*   Updated: 2021/09/09 01:59:38 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/so_long.h"

void	print_green(void)
{
	printf("\033[0;32m");
}

void	print_yellow(void)
{
	printf("\033[0;33m");
}

void	print_white(void)
{
	printf("\033[0;37m");
}

void	print_red(void)
{
	printf("\033[1;31m");
}
