/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:18:07 by maiferna          #+#    #+#             */
/*   Updated: 2024/12/18 12:18:09 by maiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
// Prepara el numero que se va a pasar al a para que esté en la cima del b
void	ready_to_push(t_stack **stack, t_stack *node, char identifier)
{
	int	size;

	size = ft_lstsize(*stack);
	while (*stack != node)
	{
		if (identifier == 'a')
		{
			if (node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (identifier == 'b')
		{
			if (node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*stack_b);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		reverse_rotate_both(stack_a, stack_b, cheapest_node);
	ready_to_push(stack_b, cheapest_node, 'b');
	ready_to_push(stack_a, cheapest_node->target_node, 'a');
	pa(stack_b, stack_a);
}
