/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 12:39:09 by jfrancis          #+#    #+#             */
/*   Updated: 2021/05/15 22:24:48 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	i;

	if (n < 0)
	{
		i = n * -1;
		ft_putchar_fd('-', fd);
	}
	else
		i = n;
	if (i > 9)
		ft_putnbr_fd(i / 10, fd);
	ft_putchar_fd((i % 10) + '0', fd);
}
