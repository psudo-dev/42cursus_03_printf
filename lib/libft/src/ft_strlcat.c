/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 22:41:29 by rsetoue           #+#    #+#             */
/*   Updated: 2021/10/14 21:17:10 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief strlcat() appends string src to the end of dst.
 * + library: #include <string.h>
 * + description:
 * It will append at most dstsize - strlen(dst) - 1 characters. It will then
 * NUL-terminate, unless dstsize is 0 or the original dst string was longer
 * than dstsize (in practice this should not happen as it means that either
 * dstsize is incorrect or that dst is not a proper string). If the src and
 * dst strings overlap, the behavior is undefined.
 *
 * @param dst The destiny string in which to concatenate.
 * @param src The source string to concatenate.
 * @param dst_size The total number of bytes in destiny.
 *
 * @return strlcat() function return the total length of the string
 *  they tried to create, that means the initial length of dst plus
 *  the length of src.
**/
size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	max_size;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen((char *) src);
	max_size = dst_size - dst_len;
	if (dst_size <= dst_len)
		return (dst_size + src_len);
	else if (dst_size > dst_len + 1)
		ft_strlcpy(dst + dst_len, src, max_size);
	return (dst_len + src_len);
}
