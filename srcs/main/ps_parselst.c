/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parselst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:36:16 by myeow             #+#    #+#             */
/*   Updated: 2024/04/03 16:01:16 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/push_swap.h"

/*
 * Checks whether the array has duplicated integers.
 * i immediately increments since 1st argv is the program name.
 * Assumption that all arguments are numerical string literals.
 */
static	int	check_dup(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = i;
		while (argv[++j])
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
	}
	return (0);
}

/*
 * If argc is less than 2, should do nothing, since it is only prog name
 * Otherwise, check duplicates.
 * Then, actual parsing is done.
 */
t_list	*ps_parselst(int argc, char **argv)
{
	t_list	*a;
	int		*iptr;

	a = 0;
	if (argc < 2 || check_dup(argv))
	{
		ft_error(PARSE_ERROR);
		return (0);
	}
	while (*++argv)
	{
		iptr = (int *) malloc(sizeof(int));
		if (!iptr)
			return (0);
		*iptr = ft_atoi(*argv);
		ft_lstadd_back(&a, ft_lstnew(iptr));
	}
	return (a);
}
