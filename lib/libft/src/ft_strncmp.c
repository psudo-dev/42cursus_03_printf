/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 22:41:45 by rsetoue           #+#    #+#             */
/*   Updated: 2021/10/14 21:17:40 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief ft_strncmp() lexicographically compares the NULL
 * terminated strings str1 and str2
 *
 * @param str1
 * @param str2
 * @param n function will only search string s1 to it's nth position.
 * Then is given in the parameters.
 * @return The function returns an integer greater than, equal to, or less
 * than 0 depending on whether the string str1 is greater than, equal to,
 * or less than string str2. The comparison is done using unsigned characters,
 * so that '\200' is greater than '\0'
 */
int	ft_strncmp(const char *str1, const char *str2, size_t size)
{
	size_t	i;
	char	*string1;
	char	*string2;

	i = 0;
	string1 = (char *) str1;
	string2 = (char *) str2;
	if (!size)
		return (0);
	while (string1[i] && string2[i] && size - 1 > i)
	{
		if (string1[i] != string2[i] || i + 1 == size)
			return ((unsigned char)string1[i] - (unsigned char)string2[i]);
		i++;
	}
	return ((unsigned char)string1[i] - (unsigned char)string2[i]);
}
