/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:58:58 by tsanjara          #+#    #+#             */
/*   Updated: 2026/03/16 11:54:30 by tsiarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pb_numb(t_stack**a, t_stack **b, int numb_pb)
{
	pb(a, b);
	numb_pb++;
	return (numb_pb);
}

void	medium_strategy(t_stack **a, t_stack **b)
{
	int	chunk_start;
	int	chunk_end;
	int	chunk_size;
	int	numb_pb;

	chunk_start = 0;
	chunk_size = ft_sqrt(count_size(a));
	chunk_end = chunk_size;
	while (*a)
	{
		numb_pb = 0;
		while ((*a) && (numb_pb < chunk_size))
		{
			if (((*a)->index) >= chunk_start && ((*a)->index < chunk_end))
			{
				while ((*b) && ((*b)->next) && ((*a)->index) < (*b)->index)
					rb(b);
				numb_pb = pb_numb(a, b, numb_pb);
				while (((*b)->index) < (ft_stacklast(*b))->index)
					rrb(b);
			}
			else
				ra(a);
		}
		chunk_start = chunk_end;
		chunk_end = chunk_end + chunk_size;
	}
	while (*b)
		pa(a, b);
}
