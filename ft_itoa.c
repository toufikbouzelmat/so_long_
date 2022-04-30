/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:28:32 by tbouzalm          #+#    #+#             */
/*   Updated: 2022/04/22 17:30:25 by tbouzalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

static size_t	get_len(long n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	len;
	size_t	i;
	char	*result;
	long	nbr;

	nbr = n;
	len = get_len(nbr);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == 0)
		return (NULL);
	result[len] = '\0';
	if (nbr < 0)
	{
		result[0] = '-';
		i = 1;
		nbr = -nbr;
	}
	else
		i = 0;
	while (len-- > i)
	{
		result[len] = '0' + nbr % 10;
		nbr = nbr / 10;
	}
	return (result);
}
