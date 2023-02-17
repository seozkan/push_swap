/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:51:14 by seozkan           #+#    #+#             */
/*   Updated: 2023/02/17 23:57:32 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/// @brief Bu fonksiyon ekranı bir hata mesajı bastırır.
void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

/// @brief Bu fonksiyon verilen stack için ayrılan bellek alanını boşaltır.
/// @param stack
void	ft_free(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = (stack)->next;
		(stack)->nbr = 0;
		free(stack);
		stack = tmp;
	}
}

void	ft_freestr(char **str)
{
	char	*tmp;

	if (!str)
		return ;
	while (*str)
	{
		tmp = *str;
		str++;
		free(tmp);
	}
	*str = NULL;
}
