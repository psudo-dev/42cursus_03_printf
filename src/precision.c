/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:36:13 by rsetoue           #+#    #+#             */
/*   Updated: 2021/11/16 00:53:11 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_precision_check(t_data **data, t_id **id)
{
	char	*str;
	int		precision;

	precision = 0;
	str = (*data)->str;
	if (ft_isdigit(str[(*data)->i + (*id)->i + 1]))
	{
		precision = ft_str_to_int(&str[(*data)->i + (*id)->i + 1]);
		(*id)->i += ft_nbr_len(precision, 10);
	}
	if ((*id)->type != 'c' && (*id)->type != '%')
	{
		(*id)->dot = '.';
		(*id)->precision = precision;
		if ((*id)->type != 's')
			(*id)->zero = '\0';
	}
}

/**
 * @brief handles precision
 * ~parse: string converted from ARG
 * +description:
 * >if there is precision and precision == 0 and ARG == 0
 * ?	ft_printf will print NOTHING from ARG
 * >for STRINGS it's the max number of characters to be printed
 * >for everything else, it's the minimum number of digits to be printed
 * ?	the rest is filled with ZEROs
**/
void	ft_precision_handler(t_data **data, t_id **id)
{
	char	*parse;

	parse = NULL;
	if ((*id)->type == 's')
	{
		if ((*id)->precision < (*data)->parse_len)
		{
			parse = (*data)->parse;
			(*data)->parse_len = (*id)->precision;
			(*data)->parse = ft_calloc(sizeof(char), (*id)->precision + 1);
			ft_strlcpy((*data)->parse, parse, (*data)->parse_len + 1);
			ft_free_null(&parse);
		}
		else
			(*id)->precision = 0;
	}
	else if ((*id)->empty && !(*id)->precision)
		(*data)->parse_len = 0;
	else if ((*id)->precision > (*data)->parse_len)
		(*data)->zero_pad = (*id)->precision - (*data)->parse_len;
}
