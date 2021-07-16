/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:45:22 by jfrancis          #+#    #+#             */
/*   Updated: 2021/03/10 14:28:30 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*str_dest;
	char	*str_src;
	char	*ptr;

	str_dest = (char *)dest;
	str_src = (char *)src;
	i = 0;
	ptr = 0;
	while (i < n && ptr == 0)
	{
		str_dest[i] = str_src[i];
		if (str_src[i] == ((char)c))
			ptr = str_dest + i + 1;
		i++;
	}
	return (ptr);
}
