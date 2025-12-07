/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesus <jesus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:32:12 by jesus             #+#    #+#             */
/*   Updated: 2024/09/30 13:32:53 by jesus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_c(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formats(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_c(va_arg(args, int));
	else if (format == 's')
		len += ft_str(va_arg(args, char *));
	else if (format == 'p')
		len += ft_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		len += ft_nbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_uns(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		len += ft_percent();
	return (len);
}

int	ft_printf(char const *str, ...)
{
	int			i;
	va_list		args;
	int			len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			len += ft_c(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
