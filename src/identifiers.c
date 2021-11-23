/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:22:04 by rsetoue           #+#    #+#             */
/*   Updated: 2021/11/11 22:16:25 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/**
 * @brief gets all the data from TYPE
 * ~(*data)->str: original string from ft_printf
 * +description: collects the arguments and converts it to be printed
 *
**/
void	ft_type_handler(va_list ap, t_data **data, t_id **id)
{
	char	*str;

	str = (*data)->str;
	if ((*id)->type == 'c')
		ft_type_chr(ap, &(*data));
	else if ((*id)->type == '%')
		ft_type_pct(&(*data));
	else if ((*id)->type == 's')
		ft_type_str(ap, &(*data));
	else if ((*id)->type == 'd' || (*id)->type == 'i')
		ft_type_dec(ap, &(*data), &(*id));
	else if ((*id)->type == 'u')
		ft_type_uint(ap, &(*data), &(*id));
	else if ((*id)->type == 'X' || (*id)->type == 'x')
		ft_type_hex(ap, &(*data), &(*id));
	else if ((*id)->type == 'p')
		ft_type_ptr(ap, &(*data), &(*id));
}

void	ft_id_check(t_data **data, t_id **id)
{
	char	*str;

	str = (*data)->str;
	while ((*id)->i < (*data)->type_index)
	{
		if (str[(*data)->i + (*id)->i] == '0')
			ft_zero_check(&(*id));
		else if (str[(*data)->i + (*id)->i] == ' ')
			ft_space_check(&(*id));
		else if (str[(*data)->i + (*id)->i] == '+')
			ft_plus_check(&(*id));
		else if (str[(*data)->i + (*id)->i] == '-')
			ft_minus_check(&(*id));
		else if (str[(*data)->i + (*id)->i] == '#')
			ft_hash_check(&(*id));
		else if (ft_isdigit(str[(*data)->i + (*id)->i]))
			ft_width_check(&(*data), &(*id));
		else if (str[(*data)->i + (*id)->i] == '.')
			ft_precision_check(&(*data), &(*id));
		(*id)->i++;
	}
}

void	ft_id_handler(va_list ap, t_data **data, t_id **id)
{
	char		*str;

	str = (*data)->str;
	ft_type_handler(ap, &(*data), &(*id));
	ft_id_check(&(*data), &(*id));
	ft_parse_handler(&(*data), &(*id));
	ft_clear_reset_id(&(*id), 1);
	ft_clear_reset_data(&(*data), 1);
}
