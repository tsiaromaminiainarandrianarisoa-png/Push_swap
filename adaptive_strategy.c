/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_strategy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:15:02 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/24 16:21:53 by tsiarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_strategy(t_stack **a, t_stack **b, double disorder, int *move)
{
	if (!a || !(*a) || disorder == 0)
		return ;
	if (disorder < 0.2)
	{
		simple_strategy(a, b, move);
		return ;
	}
	else if (disorder >= 0.2 && disorder < 0.5)
	{
		medium_strategy(a, b, move);
		return ;
	}
	else if (disorder >= 0.5)
	{
		complex_strategy(a, b, move);
		return ;
	}
}
