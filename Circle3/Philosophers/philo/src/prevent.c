/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prevent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:27:46 by jramos-a          #+#    #+#             */
/*   Updated: 2025/04/02 16:27:46 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*malloc_prevent(size_t bytes)
{
	void	*res;

	res = malloc(bytes);
	if (!res)
	{
		return (NULL);
		free(res);
	}
	return (res);
}
