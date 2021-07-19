/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 22:18:28 by jfrancis          #+#    #+#             */
/*   Updated: 2021/05/15 23:15:12 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		length;
	char	*ptr;

	length = ft_strlen(s);
	ptr = (char *)s + length;
	while (length >= 0)
	{
		if (*ptr == c)
		{
			return (ptr);
		}
		ptr--;
		length--;
	}
	return (NULL);
}
