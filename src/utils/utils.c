/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:17:30 by maiferna          #+#    #+#             */
/*   Updated: 2024/11/19 13:17:31 by maiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atol(const char *str)
{
	int			sign;
	long long	i;

	i = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			print_error();
		i = i * 10 + (*str - '0');
		str++;
	}
	if ((sign * i) > INT_MAX || (sign * i) < INT_MIN)
		print_error();
	return (sign * i);
}

int	ft_lstsize(t_stack *lst)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = lst;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	find_index(t_stack *stack_a, int value)
{
	int		index;
	t_stack	*temp;

	index = 0;
	temp = stack_a;
	while (temp)
	{
		if (temp->value == value)
			return (index);
		temp = temp->next;
		index++;
	}
	return (-1);
}

void	set_index(t_stack *stack)
{
	int		i;
	int		stack_median;

	i = 0;
	stack_median = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= stack_median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}
