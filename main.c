/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:06:43 by escura            #+#    #+#             */
/*   Updated: 2024/05/04 15:30:56 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_alloc.h"

int	main(void)
{
	t_allocs *lst = ft_calloc(1, sizeof(t_allocs));
	if (lst == NULL)
		return (1);

	ft_allocs(lst);

	char *str = ft_malloc(455 * sizeof(char));
	char *str2 = ft_malloc(455 * sizeof(char));
	char *str3 = ft_malloc(455 * sizeof(char));
	(void)str;
	(void)str2;
	(void)str3;

	int i = 0;
	while (i < 10)
	{
		char *str4 = ft_malloc(455 * sizeof(char));
		(void)str4;
		i++;
	}

	ft_free(str);
	ft_free(str2);
	ft_free(str3);

	char *str5 = ft_malloc(455 * sizeof(char));
	(void)str5;

	ft_destructor();
	return (0);
}