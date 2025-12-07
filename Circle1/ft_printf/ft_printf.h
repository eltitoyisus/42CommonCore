/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesus <jesus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:29:36 by jesus             #+#    #+#             */
/*   Updated: 2024/09/30 13:33:10 by jesus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

// PRINTF
int		ft_printf(char const *str, ...);
int		ft_formats(va_list args, const char format);
int		ft_c(int c);
// HEX 
int		ft_hex_len(unsigned	int num);
void	ft_put_hex(unsigned int num, const char format);
int		ft_hex(unsigned int num, const char format);
// PTR
int		ft_ptr_len(unsigned long long num);
void	ft_put_ptr(unsigned long long num);
int		ft_ptr(unsigned long long ptr);
// STR
void	ft_put_str(char *str);
int		ft_str(char *str);
// UNSIGNED
int		ft_num_len(unsigned	int num);
char	*ft_uitoa(unsigned int n);
int		ft_uns(unsigned int n);
// PERCENT
int		ft_percent(void);
// NBR
int		ft_nbr(int n);
// ITOA
int		ft_len(int n);
char	*ft_itoa(int n);
// PUTCHAR
void	ft_putchar_fd(char c, int fd);

#endif