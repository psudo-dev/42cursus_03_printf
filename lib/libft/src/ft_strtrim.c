/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 22:41:51 by rsetoue           #+#    #+#             */
/*   Updated: 2021/10/14 21:17:10 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief Allocates (with malloc(3)) and returns a copy of’str’ with the
 * characters specified in ’set’ removed from the beginning and the end
 * of the string.
 *
 * + library: n/a
 * + description:
 *
 * @param str The string to be trimmed
 * @param set The reference set of characters to trim
 *
 * @return char*
 * The trimmed string. NULL if the allocation fails
**/
char	*ft_strtrim(char const *str, char const *set)
{
	unsigned int	i_start;
	size_t			i_end;
	char			*substr;

	if (!str || !set)
		return (NULL);
	i_start = 0;
	i_end = ft_strlen(str) - 1;
	while (ft_strchr(set, str[i_start]))
		i_start++;
	while (ft_strchr(set, str[i_end]))
		i_end--;
	substr = ft_substr(str, i_start, ++i_end - i_start);
	return (substr);
}
