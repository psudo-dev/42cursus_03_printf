/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:20:29 by rsetoue           #+#    #+#             */
/*   Updated: 2021/12/01 01:02:07 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_printf(const char *string, ...)
{
	va_list		ap;
	t_data		*data;
	t_spec		*spec;
	int			total;

	total = 0;
	data = ft_new_data();
	spec = ft_new_spec();
	if (!string || !spec || !data)
		return (0);
	data->str = (char *) string;
	va_start(ap, string);
	total = ft_printer(ap, &data, &spec);
	va_end(ap);
	return (total);
}
