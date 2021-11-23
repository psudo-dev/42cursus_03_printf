/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 22:41:27 by rsetoue           #+#    #+#             */
/*   Updated: 2021/10/14 21:17:10 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*joined;
	size_t	dst_size;
	size_t	src_size;

	if (!str1 || !str2)
		return (NULL);
	joined = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!joined)
		return (NULL);
	dst_size = ft_strlen(str1) + 1;
	src_size = ft_strlen(str2) + 1;
	ft_strlcpy(joined, str1, dst_size);
	ft_strlcpy(joined + dst_size - 1, str2, src_size);
	return (joined);
}
