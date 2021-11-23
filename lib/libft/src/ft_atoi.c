/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 22:40:15 by rsetoue           #+#    #+#             */
/*   Updated: 2021/11/15 23:45:22 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief receives the integer as an unsigned long long value, so the atoi
 * function behaves like the original one.
 *
 * @param integer receives a long value
 * @param sign positive or negative
 *
 * @return int
 *
**/
static int	ft_unsignedlong(unsigned long long integer, int sign)
{
	if (integer >= 9223372036854775807 && sign == 1)
		return (-1);
	else if (integer > 9223372036854775807 && sign == -1)
		return (0);
	else
		return (integer * sign);
}

/**
 * @brief receives a string with numbers and converts it to an integer.
 *
 * @param str positive or negative numbers
 *
 * @return int
 * -1 if the number lower and the minimum value for long long
 * 0 if the number higher and the maximum value for long long
 * otherwise the integer itself
 *
**/
int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	long	integer;

	i = 0;
	sign = 1;
	integer = 0;
	while (ft_isspace(((char *) str)[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		integer = (integer * 10) + (str[i] - '0');
		i++;
	}
	return (ft_unsignedlong(integer, sign));
}
