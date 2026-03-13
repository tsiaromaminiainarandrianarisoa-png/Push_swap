/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 07:19:41 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/10 12:30:39 by tsiarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	int	res;
	int	loc;
	int	sign;

	res = 0;
	loc = 0;
	sign = 1;
	while ((nptr[loc] >= 9 && nptr[loc] <= 13) || nptr[loc] == 32)
	{
		loc++;
	}
	if (nptr[loc] == '-' || nptr[loc] == '+')
	{
		if (nptr[loc] == '-')
			sign = sign * (-1);
		loc++;
	}
	while (nptr[loc] >= '0' && nptr[loc] <= '9')
	{
		res = (res * 10) + (nptr[loc] - '0');
		loc++;
	}
	return (sign * res);
}
