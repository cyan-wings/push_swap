/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:14:27 by myeow             #+#    #+#             */
/*   Updated: 2024/04/07 01:15:58 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/checker.h"

static int	ps_checker_error(t_error status, t_list **a, t_list **b)
{
	if (status)
	{
		ft_error(status);
		ft_lstclear(a, ft_memclear);
		ft_lstclear(b, ft_memclear);
		return (1);
	}
	else
		return (0);
}

static t_error	ps_checker_perform_operation_helper(char *str,
		t_list **a, t_list **b)
{
	if (!ft_strcmp(str, "ss"))
	{
		ft_lstswap(a);
		ft_lstswap(b);
	}
	else if (!ft_strcmp(str, "rr"))
	{
		ft_lstrotate(a);
		ft_lstrotate(b);
	}
	else if (!ft_strcmp(str, "rrr"))
	{
		ft_lstrevrotate(a);
		ft_lstrevrotate(b);
	}
	else
		return (PARSE_ERROR);
	return (OK);
}

static t_error	ps_checker_perform_operation(char *str, t_list **a, t_list **b)
{
	if (!ft_strcmp(str, "sa"))
		ft_lstswap(a);
	else if (!ft_strcmp(str, "sb"))
		ft_lstswap(b);
	else if (!ft_strcmp(str, "ra"))
		ft_lstrotate(a);
	else if (!ft_strcmp(str, "rb"))
		ft_lstrotate(b);
	else if (!ft_strcmp(str, "rra"))
		ft_lstrevrotate(a);
	else if (!ft_strcmp(str, "rrb"))
		ft_lstrevrotate(b);
	else if (!ft_strcmp(str, "pa"))
		ft_lstpush(b, a);
	else if (!ft_strcmp(str, "pb"))
		ft_lstpush(a, b);
	else
		return (ps_checker_perform_operation_helper(str, a, b));
	return (OK);
}

static t_error	ps_checker_parse(t_list **a, t_list **b)
{
	char	*line;
	int		read_chars;

	line = (char *) malloc(sizeof(char) * 5);
	if (!line)
		return (MALLOC_ERROR);
	read_chars = 1;
	while (read_chars)
	{
		if (ps_checker_get_next_line(0, line))
		{
			free(line);
			return (PARSE_ERROR);
		}
		read_chars = ft_strlen(line);
		if (!read_chars)
			break ;
		if (ps_checker_perform_operation(line, a, b))
		{
			free(line);
			return (PARSE_ERROR);
		}
	}
	free(line);
	return (OK);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_error	parse_status;

	if (argc == 1)
		return (1);
	a = 0;
	b = 0;
	parse_status = ps_parselst(&a, argc, argv);
	if (ps_checker_error(parse_status, &a, &b))
		return (1);
	parse_status = ps_checker_parse(&a, &b);
	if (ps_checker_error(parse_status, &a, &b))
		return (1);
	if (a && !b && ft_lstissorted(a))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_lstclear(&a, ft_memclear);
	ft_lstclear(&b, ft_memclear);
	return (0);
}
