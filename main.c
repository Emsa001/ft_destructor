/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:06:43 by escura            #+#    #+#             */
/*   Updated: 2024/05/07 19:12:07 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_alloc.h"

int	main(void)
{
	// init list for allocations
	t_allocs *lst = ft_calloc(1, sizeof(t_allocs));
	if (lst == NULL)
		return (1);

	ft_allocs(lst);

	// allocations with ft_malloc
	char *str = ft_malloc(455 * sizeof(char));
	char *str2 = ft_malloc(455 * sizeof(char));
	char *str3 = ft_malloc(455 * sizeof(char));

	// manual free
	ft_free(str);  
	ft_free(str2);
	ft_free(str3);

	int i = 0;
	while (i < 10)
	{
		// allocation without ft_free
		char *str4 = ft_malloc(455 * sizeof(char));
		(void)str4;
		i++;
	}

	// original malloc - won't be freed with destructor
	char *str5 = malloc(455 * sizeof(char)); 
	(void)str5;

	// will free everything that was allocated with ft_malloc or ft_calloc
	ft_destructor();
	return (0);
}