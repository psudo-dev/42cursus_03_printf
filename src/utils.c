/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:02:42 by rsetoue           #+#    #+#             */
/*   Updated: 2021/11/11 12:07:26 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_str_to_int(char *str)
{
	int		len;
	int		n;
	char	*nbr;

	len = 0;
	if (!str)
		return (0);
	while (ft_isdigit(str[len]))
		len++;
	nbr = ft_substr(str, 0, len);
	if (!nbr)
		return (0);
	n = ft_atoi(nbr);
	ft_free_null(&nbr);
	return (n);
}

int	ft_has_type(t_data **data, t_id **id)
{
	int		i;
	char	*type;
	char	*str;

	str = &(*data)->str[++(*data)->i];
	type = ft_strdup("csdiuxXp%");
	if (!type)
		return (0);
	while (str[(*data)->type_index])
	{
		i = 0;
		while (i <= 8)
		{
			if (str[(*data)->type_index] == type[i])
			{
				(*id)->type = type[i];
				ft_free_null(&type);
				return (1);
			}
			else
				i++;
		}
		(*data)->type_index++;
	}
	return (0);
}

void	ft_counter(t_data **data, t_id **id)
{
	(*data)->i += (*id)->i + 1;
	(*data)->total -= ((*data)->type_index + 2);
	if ((*data)->blank_pad)
		(*data)->total += (*data)->blank_pad;
	if ((*data)->zero_pad)
		(*data)->total += (*data)->zero_pad;
	if ((*data)->parse_len)
		(*data)->total += (*data)->parse_len;
}

/**
 * @brief handles prefix for hex and int
 * +description:
 * >if hex
 * ?	len +2
 * >if hex but ARG==0
 *  ?	free and null
 * >if int
 * ?	len +1
**/
void	ft_prefix_handler(t_data **data, t_id **id)
{
	if ((*id)->hash)
	{
		if ((*data)->unsigned_int)
			(*data)->parse_len += 2;
		else
			ft_free_null(&(*id)->hash);
	}
	else if ((*id)->type == 'p')
		(*data)->parse_len += 2;
	else if ((*id)->sign || (*id)->space)
		(*data)->parse_len += 1;
}

/**
 * @brief handles everything related with the PARSE string
 * +description:
 * > it handles the flags, width and precision
 * > prints the neccessary characters
 * > counts printed characters
 * > free and null PARSE and HASH strings
**/
void	ft_parse_handler(t_data **data, t_id **id)
{
	if ((*id)->dot)
		ft_precision_handler(&(*data), &(*id));
	ft_prefix_handler(&(*data), &(*id));
	if ((*id)->width > (*data)->parse_len)
		ft_width_handler(&(*data), &(*id));
	ft_parse_print(&(*data), &(*id));
	ft_counter(&(*data), &(*id));
}
