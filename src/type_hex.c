/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:20:29 by rsetoue           #+#    #+#             */
/*   Updated: 2021/11/13 17:21:27 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char	*ft_itoh_printf(unsigned long long nbr, char c)
{
	int		len;
	char	*hex_map[2];
	char	*hex;

	len = ft_nbr_ulen(nbr, 16);
	hex_map[0] = "0123456789ABCDEF";
	hex_map[1] = "0123456789abcdef";
	hex = (char *)ft_calloc(len + 1, sizeof(char));
	if (!hex)
		return (NULL);
	while (len)
	{
		if (c == 'X')
			hex[--len] = hex_map[0][nbr % 16];
		else if (c == 'x' || c == 'p')
			hex[--len] = hex_map[1][nbr % 16];
		nbr /= 16;
	}
	return (hex);
}

void	ft_type_hex(va_list ap, t_data **data, t_id **id)
{
	(*data)->unsigned_int = va_arg(ap, unsigned int);
	if (!(*data)->unsigned_int)
		(*id)->empty = 1;
	(*data)->parse = ft_itoh_printf((*data)->unsigned_int, (*id)->type);
	(*data)->parse_len = ft_strlen((*data)->parse);
}

void	ft_type_ptr(va_list ap, t_data **data, t_id **id)
{
	(*data)->unsigned_long = va_arg(ap, unsigned long);
	if (!(*data)->unsigned_long)
		(*id)->empty = 1;
	(*data)->parse = ft_itoh_printf((*data)->unsigned_long, (*id)->type);
	(*data)->parse_len = ft_strlen((*data)->parse);
}
