/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 23:20:26 by rsetoue           #+#    #+#             */
/*   Updated: 2021/10/14 21:17:07 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/**
 * @brief Iterates the list ’list’ and applies the function ’ft’ to the content
 * of each element.
 *
 * @param list The adress of a pointer to an element
 * @param ft The adress of the function used to iterate on the list
 *
**/
void	ft_lstiter(t_list *list, void (*ft)(void *))
{
	if (!list || !ft)
		return ;
	while (list)
	{
		ft(list -> content);
		list = list -> next;
	}
}
