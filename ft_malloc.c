/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:08:30 by escura            #+#    #+#             */
/*   Updated: 2024/05/04 15:28:14 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_alloc.h"

void	*ft_malloc(size_t size)
{
	t_allocs	*allocs;
	void		*ptr;

	allocs = ft_allocs(NULL);
	if (allocs == NULL)
		return (malloc(size));
	ptr = malloc(size);
	if (ptr == NULL)
	{
		printf("Memory allocation failed for %p\n", ptr);
		ft_destructor();
		exit(EXIT_FAILURE);
	}
	create_alloc(&allocs, add_alloc(ptr));
	return (ptr);
}
