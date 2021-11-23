/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 22:41:15 by rsetoue           #+#    #+#             */
/*   Updated: 2021/10/24 23:27:15 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief *ft_memset() writes n bytes of char c into string str
 * The *ft_memset() function writes n bytes of value c (converted to an
 * unsigned char) to the string str.
 * @param str string to write to
 * @param c character to write
 * @param n number of bytes to write
 * @return The memset() function returns its first argument
 */

#include <libft.h>

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)str)[i] = c;
		i++;
	}
	return (str);
}
