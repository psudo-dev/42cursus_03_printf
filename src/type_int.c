/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:33:05 by rsetoue           #+#    #+#             */
/*   Updated: 2021/11/30 12:50:11 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char	*ft_int_to_str(long long int n)
{
	char	*nbr;
	int		len;

	len = ft_nbr_len(n, 10);
	nbr = (char *)ft_calloc((len + 1), sizeof(char));
	if (!nbr)
		return (NULL);
	while (len)
	{
		nbr[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (nbr);
}

static char	*ft_nosign_itoa(long long int n, t_spec **spec)
{
	char	*result;

	result = NULL;
	if (!n)
		return (ft_strdup("0"));
	else if (n < 0)
	{
		(*spec)->sign = '-';
		if (n == -2147483648)
			return (ft_strdup("2147483648"));
		n = -n;
	}
	result = ft_int_to_str(n);
	return (result);
}

void	ft_type_dec(va_list ap, t_data **data, t_spec **spec)
{
	(*data)->signed_int = va_arg(ap, int);
	if (!(*data)->signed_int)
		(*spec)->empty = 1;
	(*data)->parse = ft_nosign_itoa((*data)->signed_int, &(*spec));
	(*data)->parse_len = ft_strlen((*data)->parse);
}

void	ft_type_uint(va_list ap, t_data **data, t_spec **spec)
{
	(*data)->unsigned_int = va_arg(ap, unsigned int);
	if (!(*data)->unsigned_int)
		(*spec)->empty = 1;
	(*data)->parse = ft_ll_utoa((*data)->unsigned_int);
	(*data)->parse_len = ft_strlen((*data)->parse);
}
