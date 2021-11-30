/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:36:13 by rsetoue           #+#    #+#             */
/*   Updated: 2021/11/30 12:50:12 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/**
 * +description:
 * if there is precision ZERO padding is ignored
**/
void	t_zero_check(t_spec **spec)
{
	if (!(*spec)->minus)
	{
		if ((*spec)->type == 's' || !(*spec)->dot)
			(*spec)->zero = '0';
	}
}

/**
 * +description:
 * only works for hex
**/
void	ft_hash_check(t_spec **spec)
{
	if ((*spec)->type == 'x')
		(*spec)->hash = ft_strdup("0x");
	else if ((*spec)->type == 'X')
		(*spec)->hash = ft_strdup("0X");
}

/**
 * +description:
 * ZERO padding only works if there is no left justification (-)
**/
void	ft_minus_check(t_spec **spec)
{
	(*spec)->minus = '-';
	if ((*spec)->zero)
		(*spec)->zero = '\0';
}

/**
 * +description:
 * only works for i and d
 * SPACE is ignored when + or -
**/
void	ft_plus_check(t_spec **spec)
{
	if ((*spec)->type == 'd' || (*spec)->type == 'i')
	{
		if ((*spec)->sign != '-')
			(*spec)->sign = '+';
		if ((*spec)->space)
			(*spec)->space = '\0';
	}
}

/**
 * +description:
 * only works for i and d
 * SPACE only works if there is no + or -
**/
void	ft_space_check(t_spec **spec)
{
	if (((*spec)->type == 'd' || (*spec)->type == 'i'))
	{
		if (!(*spec)->sign)
			(*spec)->space = ' ';
	}
}
