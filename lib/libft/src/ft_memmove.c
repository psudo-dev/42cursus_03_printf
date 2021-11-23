/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 22:41:12 by rsetoue           #+#    #+#             */
/*   Updated: 2021/10/14 21:17:40 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief memmove() - copy byte string
 *
 * The memmove() function copies size bytes from string src to string dst.
 * The two strings may overlap; the copy is always done in a nondestructive
 *
 * @param dst The destiny pointer in which to copy.
 * @param src The source pointer to copy.
 * @param n The number of bytes to copy the source string.
 * @return The memmove() function returns the original value of dst.
 */
void	*ft_memmove(void *dst, const void *src, size_t size)
{
	char	*dst2;
	char	*src2;

	dst2 = (char *) dst;
	src2 = (char *) src;
	if (dst < src)
		return (ft_memcpy(dst2, src2, size));
	else if (dst > src)
	{
		while (size > 0)
		{
			dst2[size - 1] = src2[size - 1];
			size--;
		}
	}
	return (dst);
}
