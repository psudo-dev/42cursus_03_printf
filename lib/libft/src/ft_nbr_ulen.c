/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_ulen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 03:01:57 by rsetoue           #+#    #+#             */
/*   Updated: 2021/11/06 21:46:41 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_nbr_ulen(unsigned long long n, int base)
{
	int	len;

	len = 0;
	while (n / base)
	{
		n /= base;
		len++;
	}
	len++;
	return (len);
}
