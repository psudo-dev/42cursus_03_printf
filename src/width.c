/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:36:13 by rsetoue           #+#    #+#             */
/*   Updated: 2021/11/11 00:07:43 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_width_check(t_data **data, t_id **id)
{
	char	*str;

	str = (*data)->str;
	(*id)->width = ft_str_to_int(&str[(*data)->i + (*id)->i]);
	(*id)->i += ft_nbr_len((*id)->width, 10) - 1;
}

/**
 * @brief handles width
 * width only counts if it's bigger than PARSE LEN
 * +description:
 * >if there is precision and type!='s'
 * ?	width has to be bigger than precision
**/
void	ft_width_handler(t_data **data, t_id **id)
{
	if ((*id)->width > (*id)->precision
		&& (*id)->precision)
	{
		(*data)->blank_pad
			= (*id)->width - (*data)->zero_pad - (*data)->parse_len;
	}
	else if ((*id)->zero)
		(*data)->zero_pad = (*id)->width - (*data)->parse_len;
	else if (!(*id)->precision && !(*id)->zero)
		(*data)->blank_pad = (*id)->width - (*data)->parse_len;
}
