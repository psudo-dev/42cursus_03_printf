/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 23:19:53 by rsetoue           #+#    #+#             */
/*   Updated: 2021/10/14 21:17:07 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Takes as a parameter an element and frees the memory of the element’s
 * content using the function’del’ given as a parameter and free the element.
 * The memory of ’next’ must not be freed.
 *
 * @param list The element to free.
 * @param del The address of the function used to delete the content.
 *
**/
void	ft_lstdelone(t_list *list, void (*del)(void*))
{
	if (!list || !del)
		return ;
	del(list -> content);
	free(list);
}
