/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:12:57 by jfrancis          #+#    #+#             */
/*   Updated: 2021/02/16 22:24:19 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*usc_s;

	usc_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (usc_s[i] == (unsigned char)c)
			return (&(usc_s[i]));
		i++;
	}
	return (NULL);
}
