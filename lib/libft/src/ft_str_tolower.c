/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tolower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 21:11:36 by rsetoue           #+#    #+#             */
/*   Updated: 2021/10/14 21:17:40 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_str_tolower(char *str)
{
	char	*lower;
	int		i;
	int		size;

	if (!str)
		return (NULL);
	i = 0;
	size = ft_strlen(str) + 1;
	lower = ft_calloc(sizeof(char), size);
	if (!lower)
		return (NULL);
	while (str[i] && i < size)
	{
		lower[i] = ft_tolower(str[i]);
		i++;
	}
	return (lower);
}
