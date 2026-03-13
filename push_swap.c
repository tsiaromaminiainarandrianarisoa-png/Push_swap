/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiarran <tsiarran@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 20:48:38 by tsiarran          #+#    #+#             */
/*   Updated: 2026/03/12 15:55:43 by tsiarran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	convert(t_stack **a, t_stack **b)
{
	int		min;
	int		ind;
	int		loc;
	char	id[count_size(a) + 1];

	ind = 0;
	loc = 0;
	while (*a)
	{
		min = find_min_value(a);
		while ((*a)->value != min)
		{
			ra_ab(a);
			id[loc] = 'r';
			loc++;
		}
		pb_ab(a, b);
		id[loc] = 'p';
		loc++;
		(*b)->index = ind;
		ind++;
	}
	loc = loc - 1;
	while (loc >= 0)
	{
		if (id[loc] == 'p')
			pa_ab(a, b);
		else
			rra_ab(a);
		loc--;
	}
}

void	push_swap(char **argv)
{
    t_stack *a;
    t_stack *b;
	double	disorder;

	a = NULL;
	b = NULL;
    parsing(argv, &a);
	convert(&a, &b);
	disorder = count_disorder(&a);
	//choose strategy in function of flag.
	if (disorder)
		adaptive_strategy(&a, &b, disorder);
	return ;
}
