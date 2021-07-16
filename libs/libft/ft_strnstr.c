/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 21:52:54 by jfrancis          #+#    #+#             */
/*   Updated: 2021/02/18 22:57:33 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	size_t	little_len;

	i = 0;
	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	if (*big == '\0')
		return (NULL);
	while (i <= (int)(len - little_len))
	{
		if ((big[0] == little[0]) && (0 == ft_strncmp(big, little, little_len)))
			return ((char *)big);
		big++;
		i++;
	}
	return (NULL);
}
