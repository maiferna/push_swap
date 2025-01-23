/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:38:08 by maiferna          #+#    #+#             */
/*   Updated: 2024/12/16 12:38:09 by maiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// La idea de la función es calcular los costos de mover
// cada elemento de a a la posición adecuada en b.

void	push_cost(t_stack *stack_a, t_stack *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(stack_a);
	len_b = ft_lstsize(stack_b);
	while (stack_b)
	{
		stack_b->push_cost = stack_b->index;
		if (!(stack_b->above_median))
			stack_b->push_cost = len_b - (stack_b->index);
		if (stack_b->target_node->above_median)
			stack_b->push_cost += stack_b->target_node->index;
		else
			stack_b->push_cost += len_a - (stack_b->target_node->index);
		stack_b = stack_b->next;
	}
}
