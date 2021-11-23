/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 22:40:53 by rsetoue           #+#    #+#             */
/*   Updated: 2021/10/14 21:17:07 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief converts an integer to a string
 *
 * @param nbr - pointer to the string to be returned
 * @param n - integer to be converted
 * @param i - max index of the string
 *
 * @return char*
 *
**/
static char	*ft_str_digits(char *nbr, int n, int i)
{
	int	start;

	start = 0;
	if (n == 0)
	{
		nbr[0] = '0';
		return (nbr);
	}
	else if (n < 0)
	{
		nbr[0] = '-';
		start++;
		n = -n;
	}
	while (n && i >= start)
	{
		nbr[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (nbr);
}

/**
 * @brief converts integer to ASCII string
 *
 * @param n
 *
 * @return char*
 *
**/
char	*ft_itoa(int n)
{
	char	*nbr;
	int		len;

	len = ft_nbr_len(n, 10);
	nbr = (char *)ft_calloc ((len + 1), sizeof(char));
	if (!nbr || !len)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(nbr, "-2147483648"));
	nbr = ft_str_digits(nbr, n, len - 1);
	return (nbr);
}
