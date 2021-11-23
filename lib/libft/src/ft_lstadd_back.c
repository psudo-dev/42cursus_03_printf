/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 23:19:34 by rsetoue           #+#    #+#             */
/*   Updated: 2021/11/12 23:25:31 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Adds the element ’new_list’ at the end of the list.
 *
 * @param list The address of a pointer to the first link ofa list.
 * @param new_list The address of a pointer to the element to added to the list.
 *
 **/
void	ft_lstadd_back(t_list **list, t_list *new_list)
{
	t_list	*last;

	if (!new_list)
		return ;
	last = ft_lstlast(*list);
	if (!*list)
		*list = new_list;
	else
		last->next = new_list;
}
