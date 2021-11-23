/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 22:40:29 by rsetoue           #+#    #+#             */
/*   Updated: 2021/10/14 21:17:38 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief allocate memory for an array of 'n' elements of 'size' bytes each
 *
 * @param n number of elements to allocate
 * @param size size of each element
 *
 * @return void* pointer to the allocated memory
 * @return NULL if allocation failed
 *
**/
void	*ft_calloc(size_t n_elem, size_t type_size)
{
	void	*ptr;
	size_t	i;

	ptr = malloc(n_elem * type_size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < n_elem * type_size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
