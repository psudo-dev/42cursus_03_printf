/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 22:41:48 by rsetoue           #+#    #+#             */
/*   Updated: 2021/10/14 21:17:40 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief The strnstr() function locates the first substring in str, where
 * not more than len characters are searched.
 *
 * + library: Standard C Library (libc, -lc)
 * + description:
 * Characters that appear after a NULL character are not searched. Since the
 * strnstr() function is a FreeBSD specific API, it should only be used when
 * portability is not a concern.
 *
 * @param str The string in which to check for the occurence of the substring.
 * @param substr The substring to check the occurence of.
 * @param len The number of bytes to check in str.
 *
 * @return char*
 * If substr is an empty string, str is returned; if substr occurs nowhere
 * in str, NULL is returned; otherwise a pointer to the first character of
 * the first occurrence of substr is returned.
**/
char	*ft_strnstr(const char *str, const char *substr, size_t size)
{
	size_t	i;
	size_t	sub_len;
	size_t	str_len;

	i = 0;
	sub_len = ft_strlen(substr);
	str_len = ft_strlen(str);
	if (!*substr)
		return ((char *) str);
	if (!str_len || !size || sub_len > str_len)
		return (NULL);
	while (i + sub_len <= size)
	{
		if (str[i] == *substr
			&& !ft_strncmp(str + i, substr, sub_len))
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
