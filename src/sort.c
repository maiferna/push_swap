/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:11:31 by maiferna          #+#    #+#             */
/*   Updated: 2024/12/11 15:11:33 by maiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = ft_lstsize(*stack_a);
	if (len == 3)
		sort_three(stack_a);
	else if (len == 5)
		sort_five(stack_a, stack_b);
	else if (len > 5)
		sort_numbers(stack_a, stack_b);
}
