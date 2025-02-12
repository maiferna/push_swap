/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maiferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:34:02 by maiferna          #+#    #+#             */
/*   Updated: 2024/12/03 09:34:04 by maiferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_args(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		if (!ft_isdigit(argv[i][j]))
			return (0);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_duplicates(t_stack *a)
{
	t_stack	*temp;

	while (a)
	{
		temp = a->next;
		while (temp)
		{
			if (temp->value == a->value)
			{
				free_stack(a);
				print_error();
			}
			temp = temp->next;
		}
		a = a->next;
	}
	return (0);
}

int	check_if_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

t_stack	*process_two_args(char *argv)
{
	t_stack	*a;
	int		i;
	int		num;
	char	**args;

	a = NULL;
	i = 0;
	args = ft_split(argv, ' ');
	if (!(check_args(args)))
	{
		while (args[i])
			free(args[i++]);
		free(args);
		print_error();
	}
	while (args[i])
	{
		num = ft_atol(args[i]);
		add_to_stack(&a, num);
		free(args[i]);
		i++;
	}
	free(args);
	return (a);
}

t_stack	*process_args(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		num;

	a = NULL;
	if (argc < 2)
		print_error();
	if (argc == 2)
		return (process_two_args(argv[1]));
	else
	{
		if (!(check_args(argv + 1)))
			print_error();
		i = 1;
		while (i < argc)
		{
			num = ft_atol(argv[i]);
			add_to_stack(&a, num);
			free(argv[i]);
			i++;
		}
	}
	return (a);
}
