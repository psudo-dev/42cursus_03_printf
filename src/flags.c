/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:36:13 by rsetoue           #+#    #+#             */
/*   Updated: 2021/11/10 20:42:22 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/**
 * +description:
 * if there is precision ZERO padding is ignored
**/
void	ft_zero_check(t_id **id)
{
	if (!(*id)->minus)
	{
		if ((*id)->type == 's' || !(*id)->dot)
			(*id)->zero = '0';
	}
}

/**
 * +description:
 * only works for hex
**/
void	ft_hash_check(t_id **id)
{
	if ((*id)->type == 'x')
		(*id)->hash = ft_strdup("0x");
	else if ((*id)->type == 'X')
		(*id)->hash = ft_strdup("0X");
}

/**
 * +description:
 * ZERO padding only works if there is no left justification (-)
**/
void	ft_minus_check(t_id **id)
{
	(*id)->minus = '-';
	if ((*id)->zero)
		(*id)->zero = '\0';
}

/**
 * +description:
 * only works for i and d
 * SPACE is ignored when + or -
**/
void	ft_plus_check(t_id **id)
{
	if ((*id)->type == 'd' || (*id)->type == 'i')
	{
		if ((*id)->sign != '-')
			(*id)->sign = '+';
		if ((*id)->space)
			(*id)->space = '\0';
	}
}

/**
 * +description:
 * only works for i and d
 * SPACE only works if there is no + or -
**/
void	ft_space_check(t_id **id)
{
	if (((*id)->type == 'd' || (*id)->type == 'i'))
	{
		if (!(*id)->sign)
			(*id)->space = ' ';
	}
}
