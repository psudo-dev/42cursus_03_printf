/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 22:41:21 by rsetoue           #+#    #+#             */
/*   Updated: 2021/10/14 21:17:40 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putstr_fd(char *str, int fd)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		write(fd, (str + i), 1);
		i++;
	}
}
