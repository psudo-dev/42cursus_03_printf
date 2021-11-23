/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsetoue <rsetoue@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 23:06:22 by rsetoue           #+#    #+#             */
/*   Updated: 2021/11/15 23:36:08 by rsetoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <libft.h>

typedef struct s_data
{
	int				signed_int;
	unsigned int	unsigned_int;
	unsigned long	unsigned_long;
	int				total;
	int				i;
	int				type_index;
	char			*str;
	char			*parse;
	int				parse_len;
	int				blank_pad;
	int				zero_pad;
}					t_data;

typedef struct s_id
{
	int				i;
	char			type;
	char			space;
	char			zero;
	char			minus;
	char			sign;
	char			dot;
	char			*hash;
	int				width;
	int				precision;
	int				empty;
}					t_id;

// < printers
int		ft_printf(const char *string, ...);
int		ft_printer(va_list ap, t_data **data, t_id **id);
void	ft_parse_print(t_data **data, t_id **id);
void	ft_print_n_chrs(int n, char c);

// > type char
void	ft_type_chr(va_list ap, t_data **data);
void	ft_type_pct(t_data **data);
void	ft_type_str(va_list ap, t_data **data);
// > type int
void	ft_type_dec(va_list ap, t_data **data, t_id **id);
// > type unsigned int
void	ft_type_uint(va_list ap, t_data **data, t_id **id);
void	ft_type_hex(va_list ap, t_data **data, t_id **id);
void	ft_type_ptr(va_list ap, t_data **data, t_id **id);

// + identifiers
void	ft_id_check(t_data **data, t_id **id);
void	ft_type_handler(va_list ap, t_data **data, t_id **id);
void	ft_id_handler(va_list ap, t_data **data, t_id **id);

// < flags
void	ft_zero_check(t_id **id);
void	ft_hash_check(t_id **id);
void	ft_minus_check(t_id **id);
void	ft_plus_check(t_id **id);
void	ft_space_check(t_id **id);
// < width
void	ft_width_check(t_data **data, t_id **id);
void	ft_width_handler(t_data **data, t_id **id);
// < precision
void	ft_precision_check(t_data **data, t_id **id);
void	ft_precision_handler(t_data **data, t_id **id);

// ~ structs
void	ft_free_null(char **str);
t_data	*ft_new_data(void);
void	ft_clear_reset_data(t_data **data, int reset);
t_id	*ft_new_id(void);
void	ft_clear_reset_id(t_id **id, int reset);

// ~ utils
int		ft_str_to_int(char *str);
int		ft_has_type(t_data **data, t_id **id);
void	ft_counter(t_data **data, t_id **id);
void	ft_prefix_handler(t_data **data, t_id **id);
void	ft_parse_handler(t_data **data, t_id **id);

#endif
