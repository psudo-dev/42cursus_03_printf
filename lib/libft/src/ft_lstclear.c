/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 23:20:10 by rsetoue           #+#    #+#             */
/*   Updated: 2021/10/14 21:17:07 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief Deletes and frees the given element and every successor of that
 * element, using the function ’del’and free(3). Finally, the pointer to the
 * list must be set to NULL
 *
 * @param list The adress of a pointer to an element
 * @param del The adress of the function used to delete thecontent of the elemen
 *
**/
void	ft_lstclear(t_list **list, void (*del)(void *))
{
	t_list	*tmp;

	if (!list || !del)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		ft_lstdelone(*list, del);
		(*list) = tmp;
	}
}
