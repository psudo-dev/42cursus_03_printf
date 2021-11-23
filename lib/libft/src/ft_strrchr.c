/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 22:41:50 by rsetoue           #+#    #+#             */
/*   Updated: 2021/10/14 21:17:10 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strrchr(const char *str, int c)
{
	size_t	str_len;

	str_len = ft_strlen(str);
	if (!c)
		return ((char *)str + str_len);
	while (str_len > 0)
	{
		if ((char) str[--str_len] == (char) c)
			return ((char *) str + str_len);
	}
	return (NULL);
}
