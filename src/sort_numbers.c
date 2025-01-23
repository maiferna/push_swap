/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:14:23 by maiferna          #+#    #+#             */
/*   Updated: 2025/01/10 13:14:25 by maiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/* static void print_stack(t_stack *stack)
{
    t_stack *current = stack;
    //printf("Contenido de la pila:\n");
    while (current)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
} */

void	sort_numbers(t_stack **stack_a, t_stack **stack_b)
{
	int		len_a;
	t_stack	*min_value;

	len_a = ft_lstsize(*stack_a);
	while (len_a-- > 3)
		pb(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		init_nodes_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	set_index(*stack_a);
	min_value = min_node(*stack_a);
	if (min_value->above_median)
		while (*stack_a != min_value)
			ra(stack_a);
	else
		while (*stack_a != min_value)
			rra(stack_a);
}
