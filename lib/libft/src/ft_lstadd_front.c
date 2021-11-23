/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 22:48:48 by rsetoue           #+#    #+#             */
/*   Updated: 2021/10/14 21:17:07 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Adds the element ’new_list’ at the beginning of the list.
 *
 * @param lst The address of a pointer to the first link of a list.
 * @param new_list The address of a pointer to the element to added to the list.
 *
**/
void	ft_lstadd_front(t_list **list, t_list *new_list)
{
	if (!new_list)
		return ;
	new_list->next = *list;
	*list = new_list;
}
