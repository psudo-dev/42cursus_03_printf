/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 22:41:43 by rsetoue           #+#    #+#             */
/*   Updated: 2021/10/14 21:17:40 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief
 * Applies the function ’f’ to each character of thestring ’s’ to create a
 * new string (with malloc(3))resulting from successive applications of ’f’.
 *
 * @param s The string on which to iterate
 * @param f The function to apply to each character
 *
 * @return char*
 * The string created from the successive applications of ’f’.
 * Returns NULL if the allocation fails.
**/
char	*ft_strmapi(char const *str, char (*ft)(unsigned int, char))
{
	size_t	i;
	char	*c;

	i = 0;
	if (!str || !ft)
		return (NULL);
	c = ft_calloc((ft_strlen(str) + 1), sizeof(char));
	if (!c)
		return (NULL);
	while (str[i])
	{
		c[i] = ft(i, str[i]);
		i++;
	}
	return (c);
}
