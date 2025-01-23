/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:17:57 by maiferna          #+#    #+#             */
/*   Updated: 2024/12/05 11:17:58 by maiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	pb_min_value(t_stack **stack_a, t_stack **stack_b)
{
	int	len;
	int	middle_index;
	int	min_value;
	int	min_index;

	len = ft_lstsize(*stack_a);
	middle_index = len / 2;
	min_value = find_min_value(*stack_a);
	min_index = find_index(*stack_a, min_value);
	while (min_index > 0)
	{
		if (min_index <= middle_index)
			ra(stack_a);
		else
			rra(stack_a);
		min_index = find_index(*stack_a, min_value);
	}
	pb(stack_a, stack_b);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	pb_min_value(stack_a, stack_b);
	pb_min_value(stack_a, stack_b);
	sort_three(stack_a);
	if ((*stack_b)->value < (*stack_b)->next->value)
		sb(stack_b);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}
