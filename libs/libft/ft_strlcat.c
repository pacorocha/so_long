/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 20:57:43 by jfrancis          #+#    #+#             */
/*   Updated: 2021/02/17 22:34:44 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dst_len;

	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (size + ft_strlen(src));
	while (*src && dst_len < size - 1)
		*(dst + dst_len++) = *src++;
	*(dst + dst_len) = '\0';
	return (dst_len + ft_strlen(src));
}
