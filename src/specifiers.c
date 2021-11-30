/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                      :+:      :+:    :+:   */
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
void	ft_type_handler(va_list ap, t_data **data, t_spec **spec)
{
	char	*str;

	str = (*data)->str;
	if ((*spec)->type == 'c')
		ft_type_chr(ap, &(*data));
	else if ((*spec)->type == '%')
		ft_type_pct(&(*data));
	else if ((*spec)->type == 's')
		ft_type_str(ap, &(*data));
	else if ((*spec)->type == 'd' || (*spec)->type == 'i')
		ft_type_dec(ap, &(*data), &(*spec));
	else if ((*spec)->type == 'u')
		ft_type_uint(ap, &(*data), &(*spec));
	else if ((*spec)->type == 'X' || (*spec)->type == 'x')
		ft_type_hex(ap, &(*data), &(*spec));
	else if ((*spec)->type == 'p')
		ft_type_ptr(ap, &(*data), &(*spec));
}

void	ft_spec_check(t_data **data, t_spec **spec)
{
	char	*str;

	str = (*data)->str;
	while ((*spec)->i < (*data)->type_index)
	{
		if (str[(*data)->i + (*spec)->i] == '0')
			ft_zero_check(&(*spec));
		else if (str[(*data)->i + (*spec)->i] == ' ')
			ft_space_check(&(*spec));
		else if (str[(*data)->i + (*spec)->i] == '+')
			ft_plus_check(&(*spec));
		else if (str[(*data)->i + (*spec)->i] == '-')
			ft_minus_check(&(*spec));
		else if (str[(*data)->i + (*spec)->i] == '#')
			ft_hash_check(&(*spec));
		else if (ft_isdigit(str[(*data)->i + (*spec)->i]))
			ft_width_check(&(*data), &(*spec));
		else if (str[(*data)->i + (*spec)->i] == '.')
			ft_precision_check(&(*data), &(*spec));
		(*spec)->i++;
	}
}

void	ft_spec_handler(va_list ap, t_data **data, t_spec **spec)
{
	char		*str;

	str = (*data)->str;
	ft_type_handler(ap, &(*data), &(*spec));
	ft_spec_check(&(*data), &(*spec));
	ft_parse_handler(&(*data), &(*spec));
	ft_clear_reset_spec(&(*spec), 1);
	ft_clear_reset_data(&(*data), 1);
}
