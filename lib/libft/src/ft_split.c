/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 04:14:31 by rsetoue           #+#    #+#             */
/*   Updated: 2021/10/14 21:17:40 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t	ft_split_len(char *str, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			while (str[i] != c && str[i])
				i++;
			len++;
		}
		if (str[i])
			i++;
	}
	return (len);
}

static void	ft_split_str(char *str, char c, char **result, size_t str_len)
{
	size_t	i;
	size_t	i_start;
	size_t	i_r;

	i = 0;
	i_r = 0;
	while (str[i] && i_r < str_len)
	{
		if (str[i] == c)
			i++;
		else
		{
			i_start = i;
			while (str[i] != c && str[i])
				i++;
			result[i_r++] = ft_substr(str, i_start, i - i_start);
		}
	}
}

/**
 * @brief Allocates (with malloc(3)) and returns an array of strings obtained by
*	splitting ’str’ using the character ’c’ as a delimiter. The array must be
*	ended by a NULL pointer.
 *
 * + library:
 * + description:
 *
 * @param s The str to be split.
 * @param c The delimiter character.
 *
 * @return char**
 * The array of new strings resulting from the split.
 * NULL if the allocation fails.
**/
char	**ft_split(char const *str, char c)
{
	char	**result;
	size_t	str_len;

	result = 0;
	if (str)
	{
		str_len = ft_split_len((char *) str, c);
		result = (char **)ft_calloc(str_len + 1, sizeof(char *));
		if (!result)
			return (0);
		ft_split_str((char *) str, c, result, str_len);
	}
	return (result);
}
