/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancis <jfrancis@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:50:38 by jfrancis          #+#    #+#             */
/*   Updated: 2021/05/15 23:45:24 by jfrancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	make_str(char *s, int i, unsigned int number, size_t number_size)
{
	while (number > 0)
	{
		s[number_size - 1 + i] = number % 10 + '0';
		number = number / 10;
		number_size--;
	}
}

char	*ft_itoa(long int n)
{
	char			*s;
	unsigned int	number;
	size_t			number_size;
	int				i;

	i = 0;
	number = be_positive(n);
	number_size = num_size(number);
	if (n < 0)
		i = 1;
	s = (char *)malloc(number_size + 1 + i * sizeof(char));
	if (!s)
		return (NULL);
	if (n < 0)
		s[0] = '-';
	else if (n == 0)
		s[0] = '0';
	s[number_size + i] = '\0';
	make_str(s, i, number, number_size);
	free(s);
	return (s);
}
