/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 22:40:25 by rsetoue           #+#    #+#             */
/*   Updated: 2021/10/14 21:17:40 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief write n '\n' bytes to the memory area pointed to by str.
 *
 * @param str - the memory area to be filled with n '\0' bytes.
 * @param n - the number of '\0' bytes to be written.
 *
**/
void	ft_bzero(void *str, size_t n)
{
	ft_memset(str, 0, n);
}
