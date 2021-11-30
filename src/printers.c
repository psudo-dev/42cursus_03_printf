/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:20:29 by rsetoue           #+#    #+#             */
/*   Updated: 2021/11/30 12:50:11 by rsetoue          ###   ########.fr       */
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

void	ft_parse_print(t_data **data, t_spec **spec)
{
	if ((*data)->blank_pad && !(*spec)->minus)
		ft_print_n_chrs((*data)->blank_pad, ' ');
	if ((*data)->parse && (*spec)->type == 'p')
		ft_putstr_fd("0x", 1);
	if ((*spec)->hash)
		ft_putstr_fd((*spec)->hash, 1);
	if ((*spec)->sign)
		ft_putchar_fd((*spec)->sign, 1);
	else if ((*spec)->space)
		ft_putchar_fd(' ', 1);
	if ((*data)->zero_pad)
		ft_print_n_chrs((*data)->zero_pad, '0');
	if ((*data)->parse_len)
		ft_putstr_fd((*data)->parse, 1);
	if ((*spec)->type == 'c' || (*spec)->type == '%')
		ft_putchar_fd((*data)->unsigned_int, 1);
	if ((*data)->blank_pad && (*spec)->minus)
		ft_print_n_chrs((*data)->blank_pad, ' ');
}

int	ft_printer(va_list ap, t_data **data, t_spec **spec)
{
	char	*str;
	int		total;

	if (!(*spec) || !(*data))
		return (0);
	str = (*data)->str;
	total = 0;
	while (str[(*data)->i])
	{
		if (str[(*data)->i] == '%' && ft_has_type(&(*data), &(*spec)))
			ft_spec_handler(ap, &(*data), &(*spec));
		else
		{
			ft_putchar_fd(str[(*data)->i], 1);
			(*data)->i++;
		}
	}
	total = (*data)->total + (*data)->i;
	ft_clear_reset_spec(&(*spec), 0);
	ft_clear_reset_data(&(*data), 0);
	return (total);
}

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
