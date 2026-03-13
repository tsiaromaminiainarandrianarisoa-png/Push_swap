/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_ab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 07:31:00 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/12 15:12:03 by tsiarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_ab(t_stack **a)
{
	int	tmp;

	if (!a || !(*a) || !((*a)->next))
		return ;
	tmp = (*a)->value;
	(*a)->value = ((*a)->next)->value;
	((*a)->next)->value = tmp;
}

void	pa_ab(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!b || !(*b))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
}

void	ra_ab(t_stack **a)
{
	t_stack	*tmp;
	int		first;

	if (!a || !(*a) || !((*a)->next))
		return ;
	tmp = *a;
	first = tmp->value;
	while (tmp->next)
	{
		tmp->value = (tmp->next)->value;
		tmp = tmp->next;
	}
	tmp->value = first;
}

void	rra_ab(t_stack **a)
{
	t_stack	*tmp;
	int		last;
	int		stock;
	int		result;

	if (!a || !(*a) || !((*a)->next))
		return ;
	tmp = *a;
	last = (ft_stacklast(*a))->value;
	result = tmp->value;
	while (tmp->next)
	{
		stock = (tmp->next)->value;
		(tmp->next)->value = result;
		tmp = tmp->next;
		result = stock;
	}
	(*a)->value = result;
}
