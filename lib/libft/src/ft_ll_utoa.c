/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_utoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 03:00:34 by rsetoue           #+#    #+#             */
/*   Updated: 2021/11/06 21:46:09 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_ll_utoa(unsigned long long n)
{
	char	*nbr;
	int		len;

	len = ft_nbr_ulen(n, 10);
	if (!n)
	{
		nbr = ft_strdup("0");
		return (nbr);
	}
	nbr = (char *)ft_calloc ((len + 1), sizeof(char));
	if (!nbr)
		return (NULL);
	while (len)
	{
		nbr[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (nbr);
}
