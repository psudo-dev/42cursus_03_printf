/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_itoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 03:00:34 by rsetoue           #+#    #+#             */
/*   Updated: 2021/11/11 12:08:38 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*ft_ll_str_digits(char *nbr, long long int n, int len)
{
	int	start;
	int	i;

	start = 0;
	i = len - 1;
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

char	*ft_ll_itoa(long long int n)
{
	char	*nbr;
	int		len;

	len = ft_nbr_len(n, 10);
	nbr = (char *)ft_calloc((len + 1), sizeof(char));
	if (!nbr || !len)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(nbr, "-2147483648"));
	nbr = ft_ll_str_digits(nbr, n, len);
	return (nbr);
}
