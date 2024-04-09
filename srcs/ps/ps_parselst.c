/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parselst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:36:16 by myeow             #+#    #+#             */
/*   Updated: 2024/04/07 02:28:23 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "../../includes/push_swap.h"

/*
 * Not the conventional ft_atoi.
 * Differences:
 * (1)	Returns a LONG to see if the numeric value exceeds an INT bound.
 * (2)	No whitespace removals at the beginnnig to adhere to push_swap.
 */
static long	ps_ft_atol(const char *str)
{
	int					sign;
	unsigned long		result;

	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign = -1;
	}
	result = 0;
	while (*str && ft_isdigit(*str))
		result = result * 10 + *str++ - '0';
	return ((long)(result * sign));
}

/*
 * Checks:
 * (1)	Whether string is valid to be converted to an INT.
 * 		No funny chars behind the digits.
 * (2)	Whether it fits the bounds of an INT.
 */
static int	check_valid(char **argv)
{
	int	i;
	int	j;

	i = -1;
	while (argv[++i])
	{
		j = 0;
		if (argv[i][j] == '+' || argv[i][j] == '-')
		{
			if (!ft_isdigit(argv[i][++j]))
				return (1);
		}
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j++]))
				return (1);
		}
		if (ps_ft_atol(argv[i]) > INT_MAX || ps_ft_atol(argv[i]) < INT_MIN)
			return (1);
	}
	return (0);
}

/* 
 * Checks whether the array has duplicated integers.
 * i immediately increments since 1st argv is the program name.
 * 
 */
static int	check_dup(char **argv)
{
	int	i;
	int	j;

	i = -1;
	while (argv[++i])
	{
		j = i;
		while (argv[++j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
		}
	}
	return (0);
}

/*
 * If there is a MALLOC_ERROR, we free everything.
 */
static t_error	ps_parselst_helper(t_list **lst, char **args)
{
	int	*iptr;

	--args;
	while (*++args)
	{
		iptr = (int *) malloc(sizeof(int));
		if (!iptr)
			return (MALLOC_ERROR);
		*iptr = ft_atoi(*args);
		ft_lstadd_back(lst, ft_lstnew(iptr));
	}
	return (OK);
}

/*
 * Precondition: argc > 1
 * (1) If argc = 2, check whether arguments are quoted.
 * 		(if it is, parse based on ft_split);
 * 		(if it is not, means that it is not quoted but a single num);
 * 		(regardless, outcome will be the same);
 * (2) Check duplicates.
 * Then, actual parsing is done.
 */
t_error	ps_parselst(t_list **a, int argc, char **argv)
{
	char	**argstrs;
	t_error	err_status;

	if (argc == 2)
		argstrs = ft_split(argv[1], ' ');
	else
		argstrs = ++argv;
	if (!argstrs || !*argstrs)
		return (PARSE_ERROR);
	if (check_valid(argstrs) + check_dup(argstrs))
	{
		if (argc == 2)
			ft_free_ft_split(argstrs);
		return (PARSE_ERROR);
	}
	err_status = ps_parselst_helper(a, argstrs);
	if (argc == 2)
		ft_free_ft_split(argstrs);
	if (err_status)
	{
		ft_lstclear(a, ft_memclear);
		return (err_status);
	}
	else
		return (OK);
}
