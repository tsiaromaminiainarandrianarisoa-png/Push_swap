/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b_ab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:55:58 by tsanjara          #+#    #+#             */
/*   Updated: 2026/03/15 20:54:40 by tsanjara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb_ab(t_stack **b)
{
	int	tmp;
	int	tmp2;

	if (!b || !(*b) || !((*b)->next))
		return ;
	tmp = (*b)->value;
	tmp2 = (*b)->index;
	(*b)->value = ((*b)->next)->value;
	(*b)->index = ((*b)->next)->index;
	((*b)->next)->value = tmp;
	((*b)->next)->index = tmp2;
}

void	pb_ab(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!a || !(*a))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
}

void	rb_ab(t_stack **b)
{
	t_stack	*tmp;
	int		first;
	int		first2;

	if (!b || !(*b) || !((*b)->next))
		return ;
	tmp = *b;
	first = tmp->value;
	first2 = tmp->index;
	while (tmp->next)
	{
		tmp->value = (tmp->next)->value;
		tmp->index = (tmp->next)->index;
		tmp = tmp->next;
	}
	tmp->value = first;
	tmp->index = first2;
}

static void	rrb_ab_value(t_stack **b)
{
	t_stack	*tmp;
	int		last;
	int		stock;
	int		result;

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
}

static void	rrb_ab_index(t_stack **b)
{
	t_stack	*tmp;
	int		last;
	int		stock;
	int		result;

	tmp = *b;
	last = (ft_stacklast(*b))->index;
	result = tmp->index;
	while (tmp->next)
	{
		stock = (tmp->next)->index;
		(tmp->next)->index = result;
		tmp = tmp->next;
		result = stock;
	}
	(*b)->index = result;
}

void	rrb_ab(t_stack **b)
{
	if (!b || !(*b) || !((*b)->next))
		return ;
	rrb_ab_value(b);
	rrb_ab_index(b);
}
