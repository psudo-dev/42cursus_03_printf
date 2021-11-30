/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:36:13 by rsetoue           #+#    #+#             */
/*   Updated: 2021/11/30 12:50:11 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_precision_check(t_data **data, t_spec **spec)
{
	char	*str;
	int		precision;

	precision = 0;
	str = (*data)->str;
	if (ft_isdigit(str[(*data)->i + (*spec)->i + 1]))
	{
		precision = ft_str_to_int(&str[(*data)->i + (*spec)->i + 1]);
		(*spec)->i += ft_nbr_len(precision, 10);
	}
	if ((*spec)->type != 'c' && (*spec)->type != '%')
	{
		(*spec)->dot = '.';
		(*spec)->precision = precision;
		if ((*spec)->type != 's')
			(*spec)->zero = '\0';
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
void	ft_precision_handler(t_data **data, t_spec **spec)
{
	char	*parse;

	parse = NULL;
	if ((*spec)->type == 's')
	{
		if ((*spec)->precision < (*data)->parse_len)
		{
			parse = (*data)->parse;
			(*data)->parse_len = (*spec)->precision;
			(*data)->parse = ft_calloc(sizeof(char), (*spec)->precision + 1);
			ft_strlcpy((*data)->parse, parse, (*data)->parse_len + 1);
			ft_free_null(&parse);
		}
		else
			(*spec)->precision = 0;
	}
	else if ((*spec)->empty && !(*spec)->precision)
		(*data)->parse_len = 0;
	else if ((*spec)->precision > (*data)->parse_len)
		(*data)->zero_pad = (*spec)->precision - (*data)->parse_len;
}
