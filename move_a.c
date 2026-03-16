/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 07:31:00 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/15 20:57:59 by tsanjara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	int	tmp;
	int	tmp2;

	if (!a || !(*a) || !((*a)->next))
		return ;
	tmp = (*a)->value;
	tmp2 = (*a)->index;
	(*a)->value = ((*a)->next)->value;
	(*a)->index = ((*a)->next)->index;
	((*a)->next)->value = tmp;
	((*a)->next)->index = tmp2;
	write(1, "sa\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!b || !(*b))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "pa\n", 3);
}

void	ra(t_stack **a)
{
	t_stack	*tmp;
	int		first;
	int		first2;

	if (!a || !(*a) || !((*a)->next))
		return ;
	tmp = *a;
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
	write(1, "ra\n", 3);
}

static void	rra_value(t_stack **a)
{
	t_stack	*tmp;
	int		last;
	int		stock;
	int		result;

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

static void	rra_index(t_stack **a)
{
	t_stack	*tmp;
	int		last;
	int		stock;
	int		result;

	tmp = *a;
	last = (ft_stacklast(*a))->index;
	result = tmp->index;
	while (tmp->next)
	{
		stock = (tmp->next)->index;
		(tmp->next)->index = result;
		tmp = tmp->next;
		result = stock;
	}
	(*a)->index = result;
}

void	rra(t_stack **a)
{
	if (!a || !(*a) || !((*a)->next))
		return ;
	rra_value(a);
	rra_index(a);
	write(1, "rra\n", 4);
}
