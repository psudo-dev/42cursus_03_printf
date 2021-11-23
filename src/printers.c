/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:20:29 by rsetoue           #+#    #+#             */
/*   Updated: 2021/11/10 22:14:43 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/**
 * @brief prints a number a of the same character
 *
 * @param n number of characters
 * @param c which character to print
**/
void	ft_print_n_chrs(int n, char c)
{
	if (!n)
		return ;
	while (n > 0)
	{
		ft_putchar_fd(c, 1);
		n--;
	}
}

void	ft_parse_print(t_data **data, t_id **id)
{
	if ((*data)->blank_pad && !(*id)->minus)
		ft_print_n_chrs((*data)->blank_pad, ' ');
	if ((*data)->parse && (*id)->type == 'p')
		ft_putstr_fd("0x", 1);
	if ((*id)->hash)
		ft_putstr_fd((*id)->hash, 1);
	if ((*id)->sign)
		ft_putchar_fd((*id)->sign, 1);
	else if ((*id)->space)
		ft_putchar_fd(' ', 1);
	if ((*data)->zero_pad)
		ft_print_n_chrs((*data)->zero_pad, '0');
	if ((*data)->parse_len)
		ft_putstr_fd((*data)->parse, 1);
	if ((*id)->type == 'c' || (*id)->type == '%')
		ft_putchar_fd((*data)->unsigned_int, 1);
	if ((*data)->blank_pad && (*id)->minus)
		ft_print_n_chrs((*data)->blank_pad, ' ');
}

int	ft_printer(va_list ap, t_data **data, t_id **id)
{
	char	*str;
	int		total;

	if (!(*id) || !(*data))
		return (0);
	str = (*data)->str;
	total = 0;
	while (str[(*data)->i])
	{
		if (str[(*data)->i] == '%' && ft_has_type(&(*data), &(*id)))
			ft_id_handler(ap, &(*data), &(*id));
		else
		{
			ft_putchar_fd(str[(*data)->i], 1);
			(*data)->i++;
		}
	}
	total = (*data)->total + (*data)->i;
	ft_clear_reset_id(&(*id), 0);
	ft_clear_reset_data(&(*data), 0);
	return (total);
}

int	ft_printf(const char *string, ...)
{
	va_list		ap;
	t_data		*data;
	t_id		*id;
	int			total;

	total = 0;
	data = ft_new_data();
	id = ft_new_id();
	if (!string || !id || !data)
		return (0);
	data->str = (char *) string;
	va_start(ap, string);
	total = ft_printer(ap, &data, &id);
	va_end(ap);
	return (total);
}
