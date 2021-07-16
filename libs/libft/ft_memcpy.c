/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:59:54 by jfrancis          #+#    #+#             */
/*   Updated: 2021/02/15 17:22:10 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*c_dest;
	char	*c_src;

	c_dest = (char *)dest;
	c_src = (char *)src;
	if ((c_dest != NULL) || (c_src != NULL))
	{
		while (n--)
		{
			*(c_dest++) = *(c_src++);
		}
	}
	return (dest);
}
