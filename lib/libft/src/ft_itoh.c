/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:05:02 by rsetoue           #+#    #+#             */
/*   Updated: 2021/10/14 21:17:07 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_itoh(unsigned long long nbr)
{
	int		len;
	char	chr;
	char	*hex;

	len = ft_nbr_ulen(nbr, 16);
	if (!len)
		return (NULL);
	chr = 0;
	hex = (char *) ft_calloc(len + 1, sizeof(char));
	if (!hex)
		return (NULL);
	while (len - 1 >= 0)
	{
		chr = nbr % 16;
		nbr /= 16;
		if (chr < 10)
			chr += 48;
		else
			chr += 87;
		hex[len - 1] = chr;
		len--;
	}
	return (hex);
}
