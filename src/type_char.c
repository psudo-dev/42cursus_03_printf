/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:30:29 by rsetoue           #+#    #+#             */
/*   Updated: 2021/11/10 20:54:38 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_type_chr(va_list ap, t_data **data)
{
	(*data)->unsigned_int = va_arg(ap, unsigned int);
	(*data)->parse_len += 1;
}

void	ft_type_pct(t_data **data)
{
	(*data)->unsigned_int = '%';
	(*data)->parse_len += 1;
}

void	ft_type_str(va_list ap, t_data **data)
{
	char	*temp;

	temp = va_arg(ap, char *);
	if (!temp)
		(*data)->parse = ft_strdup("(null)");
	else
		(*data)->parse = ft_strdup(temp);
	(*data)->parse_len = ft_strlen((*data)->parse);
}
