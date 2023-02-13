/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:07:33 by seozkan           #+#    #+#             */
/*   Updated: 2023/02/10 21:46:04 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/// @brief Bu fonksiyon verilen stack'ı sıralı olup olmadığını kontrol eder.
/// @param stack_a
/// @return Stack sıralı ise 0, değilse 1
int	ft_is_sorted(t_stack *stack_a)
{
	int	i;

	i = stack_a->nbr;
	while (stack_a)
	{
		if (i > stack_a->nbr)
			return (0);
		i = stack_a->nbr;
		stack_a = stack_a->next;
	}
	return (1);
}

/// @brief Bu fonksiyon stack'ın içinde aynı sayının iki kez tekrar edip
/// etmediğini kontrol eder. Tmp adlı değişken her döngü başında stack'in
/// içindeki bir sonraki sayıya eşitlenir. Böylece Stack'in içindeki sayı
/// sırasıyla stack'in içinde bulunan diğer sayılarla karşılaştırılır.
/// @param stack
/// @return Sayı tekrarı varsa 1, yoksa 0
int	ft_is_duplicate(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->nbr == tmp->nbr)
				return (1);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}

/// @brief Bu fonskiyon argv'nin içindeki tüm karakterlerin
/// alphanumeric olduğunu teyit eder ve check_error isimli
/// fonksiyonu çağırır.
/// @param argv
/// @return
int	ft_check_args(int argc, char **argv, t_stack *stack)
{
	int	i;
	int	j;

	i = 1;
	if (ft_is_duplicate(stack))
		return (0);
	while (i < argc)
	{
		j = 0;
		if (!argv[i][0])
			return (0);
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
				j++;
			else if (!is_digit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
