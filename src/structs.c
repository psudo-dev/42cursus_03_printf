/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:44:19 by rsetoue           #+#    #+#             */
/*   Updated: 2021/11/30 12:50:11 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	ft_free_null(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

t_data	*ft_new_data(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->parse = NULL;
	data->str = NULL;
	data->i = 0;
	data->type_index = 0;
	data->blank_pad = 0;
	data->zero_pad = 0;
	data->parse_len = 0;
	data->total = 0;
	data->signed_int = 0;
	data->unsigned_int = 0;
	data->unsigned_long = 0;
	return (data);
}

void	ft_clear_reset_data(t_data **data, int reset)
{
	ft_free_null(&(*data)->parse);
	(*data)->type_index = 0;
	(*data)->blank_pad = 0;
	(*data)->zero_pad = 0;
	(*data)->parse_len = 0;
	(*data)->signed_int = 0;
	(*data)->unsigned_int = 0;
	(*data)->unsigned_long = 0;
	if (!reset && (*data))
	{
		free(*data);
		*data = NULL;
	}
}

t_spec	*ft_new_spec(void)
{
	t_spec	*spec;

	spec = (t_spec *)malloc(sizeof(t_spec));
	if (!spec)
		return (NULL);
	spec->type = '\0';
	spec->space = '\0';
	spec->zero = '\0';
	spec->minus = '\0';
	spec->sign = '\0';
	spec->dot = '\0';
	spec->width = 0;
	spec->precision = 0;
	spec->i = 0;
	spec->empty = 0;
	spec->hash = NULL;
	return (spec);
}

void	ft_clear_reset_spec(t_spec **spec, int reset)
{
	ft_free_null(&(*spec)->hash);
	(*spec)->i = 0;
	(*spec)->type = '\0';
	(*spec)->space = '\0';
	(*spec)->zero = '\0';
	(*spec)->minus = '\0';
	(*spec)->sign = '\0';
	(*spec)->dot = '\0';
	(*spec)->width = 0;
	(*spec)->precision = 0;
	(*spec)->empty = 0;
	if (!reset && (*spec))
	{
		free(*spec);
		*spec = NULL;
	}
}
