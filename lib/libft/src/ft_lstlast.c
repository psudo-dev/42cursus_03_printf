/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 23:18:32 by rsetoue           #+#    #+#             */
/*   Updated: 2021/10/14 21:17:07 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Returns the last element of the list.
 *
 * @param list The beginning of the list.
 *
 * @return t_list*
 * Last element of the list.
**/
t_list	*ft_lstlast(t_list *list)
{
	if (!list)
		return (NULL);
	while (list -> next)
		list = list -> next;
	return (list);
}
