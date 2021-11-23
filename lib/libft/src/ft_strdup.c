/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 22:41:24 by rsetoue           #+#    #+#             */
/*   Updated: 2021/10/18 19:34:35 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief The srcdup() function allocates sufficient memory for a copy of the
 * string, src, does the copy, and returns a pointer to it.
 *
 * + library: #include <string.h>
 *
 * @param src The string to duplicate.
 *
 * @return char*
 * The srcdup() function returns the pointer to the copy of src.
**/
char	*ft_strdup(const char *src)
{
	char	*copy;
	size_t	size;

	size = ft_strlen((char *) src) + 1;
	copy = malloc(sizeof(char) * size);
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, src, size);
	return (copy);
}
