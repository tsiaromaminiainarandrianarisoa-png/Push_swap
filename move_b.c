/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:55:58 by tsanjara          #+#    #+#             */
/*   Updated: 2026/03/12 15:12:31 by tsiarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **b)
{
	int	tmp;

	if (!b || !(*b) || !((*b)->next))
		return ;
	tmp = (*b)->value;
	(*b)->value = ((*b)->next)->value;
	((*b)->next)->value = tmp;
	write(1, "sb\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!a || !(*a))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	write(1, "pb\n", 3);
}

void	rb(t_stack **b)
{
	t_stack	*tmp;
	int		first;

	if (!b || !(*b) || !((*b)->next))
		return ;
	tmp = *b;
	first = tmp->value;
	while (tmp->next)
	{
		tmp->value = (tmp->next)->value;
		tmp = tmp->next;
	}
	tmp->value = first;
	write(1, "rb\n", 3);
}

void	rrb(t_stack **b)
{
	t_stack	*tmp;
	int		last;
	int		stock;
	int		result;

	if (!b || !(*b) || !((*b)->next))
		return ;
	tmp = *b;
	last = (ft_stacklast(*b))->value;
	result = tmp->value;
	while (tmp->next)
	{
		stock = (tmp->next)->value;
		(tmp->next)->value = result;
		tmp = tmp->next;
		result = stock;
	}
	(*b)->value = result;
	write(1, "rrb\n", 4);
}
