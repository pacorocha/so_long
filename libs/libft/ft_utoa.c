/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:49:41 by jfrancis          #+#    #+#             */
/*   Updated: 2021/05/15 22:25:16 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(unsigned int n)
{
	unsigned int	count;
	unsigned int	num;
	char			*temp;

	count = 1;
	num = n;
	while (n >= 10 && count++)
		n /= 10;
	temp = malloc((count + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	*(temp + count) = '\0';
	while (count--)
	{
		*(temp + count) = num % 10 + '0';
		num /= 10;
	}
	free(temp);
	return (temp);
}
