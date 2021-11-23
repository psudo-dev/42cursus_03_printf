/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 22:41:53 by rsetoue           #+#    #+#             */
/*   Updated: 2021/10/14 21:17:40 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief
 * Allocates (with malloc(3)) and returns a substring from the string ’str’.
 * The substring begins at index ’start’ and is of maximum size ’len’.
 * + library:
 * + description:
 *
 * @param s The string from which to create the substring.
 * @param start The start index of the substring in the string ’str’.
 * @param len The maximum length of the substring.
 *
 * @return char*
 * The substring. NULL if the allocation fails.
**/
char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	str_len;
	size_t	size;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	if (str_len < start)
		return (ft_calloc(1, sizeof(char)));
	if (str_len - start >= len)
		size = len + 1;
	else
		size = str_len - start + 1;
	substr = (char *) ft_calloc(size, sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, str + start, size);
	return (substr);
}
