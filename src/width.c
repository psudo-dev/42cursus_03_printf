/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:36:13 by rsetoue           #+#    #+#             */
/*   Updated: 2021/11/30 12:50:11 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_width_check(t_data **data, t_spec **spec)
{
	char	*str;

	str = (*data)->str;
	(*spec)->width = ft_str_to_int(&str[(*data)->i + (*spec)->i]);
	(*spec)->i += ft_nbr_len((*spec)->width, 10) - 1;
}

/**
 * @brief handles width
 * width only counts if it's bigger than PARSE LEN
 * +description:
 * >if there is precision and type!='s'
 * ?	width has to be bigger than precision
**/
void	ft_width_handler(t_data **data, t_spec **spec)
{
	if ((*spec)->width > (*spec)->precision
		&& (*spec)->precision)
	{
		(*data)->blank_pad
			= (*spec)->width - (*data)->zero_pad - (*data)->parse_len;
	}
	else if ((*spec)->zero)
		(*data)->zero_pad = (*spec)->width - (*data)->parse_len;
	else if (!(*spec)->precision && !(*spec)->zero)
		(*data)->blank_pad = (*spec)->width - (*data)->parse_len;
}
