/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 23:20:48 by rsetoue           #+#    #+#             */
/*   Updated: 2021/10/14 21:17:07 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
/**
 * @brief Counts the number of elements in a list.
 *
 * @param list The beginning of the list.
 *
 * @return int
 * Length of the list.
**/
int	ft_lstsize(t_list *list)
{
	int	i;

	if (!list)
		return (0);
	i = 0;
	while (list -> next)
	{
		list = list -> next;
		i++;
	}
	return (++i);
}
