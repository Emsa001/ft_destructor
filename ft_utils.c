/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:09:06 by escura            #+#    #+#             */
/*   Updated: 2024/05/08 15:20:05 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_alloc.h"

t_allocs	*ft_allocs(t_allocs *lst)
{
	static t_allocs	*allocs;

	if (lst != NULL)
	{
		allocs = lst;
		return (NULL);
	}
	return (allocs);
}

int	ft_allocsize(void)
{
	t_allocs	*lst;
	int			size;

	lst = ft_allocs(NULL);
	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

t_allocs	*ft_lstlast(t_allocs *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	add_allocnode(t_allocs **lst, t_allocs *nnew)
{
	if (DEBUG)
		printf("Creating new alloc %p\n", nnew->ptr);
	if (!lst || !nnew)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = nnew;
	else
		*lst = nnew;
}

t_allocs	*create_alloc(void *ptr)
{
	t_allocs	*new;

	new = malloc(sizeof(t_allocs));
	if (new == NULL)
	{
		printf("Memory allocation failed\n");
		ft_destructor();
		exit(EXIT_FAILURE);
	}
	new->ptr = ptr;
	new->next = NULL;
	return (new);
}
