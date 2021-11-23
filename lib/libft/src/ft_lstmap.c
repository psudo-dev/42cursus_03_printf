/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 23:20:37 by rsetoue           #+#    #+#             */
/*   Updated: 2021/10/14 21:17:07 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Iterates the list and applies the function to each element.
 *
 * @param list The adress of a pointer to an element
 * @param ft The adress of the function used to iterate on the list
 * @param del The adress of the function used to delete the content of
 * an element if needed
 *
 * @return t_list*
 * The new mapped list.  NULL if the allocation fails.
 *
**/
t_list	*ft_lstmap(t_list *list, void *(*ft)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*node;
	void	*content;

	if (!list || !del)
		return (NULL);
	head = NULL;
	while (list && node)
	{
		content = ft(list->content);
		node = ft_lstnew(content);
		if (node)
			ft_lstadd_back(&head, node);
		else
			ft_lstclear(&head, del);
		list = list->next;
	}
	return (head);
}
