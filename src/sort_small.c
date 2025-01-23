/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:58:14 by maiferna          #+#    #+#             */
/*   Updated: 2025/01/23 11:58:17 by maiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two(t_stack **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	pb_min_value(stack_a, stack_b);
	pb_min_value(stack_a, stack_b);
	sort_two(stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}