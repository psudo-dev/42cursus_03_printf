/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:44:19 by rsetoue           #+#    #+#             */
/*   Updated: 2021/11/10 21:14:15 by rsetoue          ###   ########.fr       */
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

t_id	*ft_new_id(void)
{
	t_id	*id;

	id = (t_id *)malloc(sizeof(t_id));
	if (!id)
		return (NULL);
	id->type = '\0';
	id->space = '\0';
	id->zero = '\0';
	id->minus = '\0';
	id->sign = '\0';
	id->dot = '\0';
	id->width = 0;
	id->precision = 0;
	id->i = 0;
	id->empty = 0;
	id->hash = NULL;
	return (id);
}

void	ft_clear_reset_id(t_id **id, int reset)
{
	ft_free_null(&(*id)->hash);
	(*id)->i = 0;
	(*id)->type = '\0';
	(*id)->space = '\0';
	(*id)->zero = '\0';
	(*id)->minus = '\0';
	(*id)->sign = '\0';
	(*id)->dot = '\0';
	(*id)->width = 0;
	(*id)->precision = 0;
	(*id)->empty = 0;
	if (!reset && (*id))
	{
		free(*id);
		*id = NULL;
	}
}
