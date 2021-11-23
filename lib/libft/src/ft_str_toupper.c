/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_toupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 21:12:00 by rsetoue           #+#    #+#             */
/*   Updated: 2021/10/14 21:17:40 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_str_toupper(char *str)
{
	char	*upper;
	int		i;
	int		size;

	if (!str)
		return (NULL);
	i = 0;
	size = ft_strlen(str) + 1;
	upper = ft_calloc(sizeof(char), size);
	if (!upper)
		return (NULL);
	while (str[i] && i < size)
	{
		upper[i] = ft_toupper(str[i]);
		i++;
	}
	return (upper);
}
