/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:07:14 by seozkan           #+#    #+#             */
/*   Updated: 2023/02/09 23:40:41 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/// @brief Bu fonksiyon yeni bir stack oluşturur ve oluşturulan stack'ın
/// nbr'ına parametre olarak verilen nbr'ı atar.
/// @param nbr ft_atoi'den alınarak okunan sayı
/// @return stack
t_stack	*ft_create_new_stack(int nbr)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		ft_error();
	stack->nbr = nbr;
	stack->next = NULL;
	return (stack);
}

int	is_digit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int		mod;
	long	i;

	i = 0;
	mod = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		mod = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
		ft_error();
	return (mod * i);
}

/// @brief Bu fonksiyon argv'nin içindeki parametereleri ft_atoi yardımıyla
/// tam sayıya çevirir ve çevrilen bu sayıdan yeni bir stack oluşturur.
/// Oluşturulan bu stack, stack_a nın yeni bir elemanı olarak stack_a'ya
/// bağlanır.
/// @param argc Argüman Sayısı
/// @param argv Argüman Listesi
/// @return stack_a
t_stack	*ft_create_and_fill_stack(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;
	int		nbr;

	i = 1;
	stack_a = NULL;
	if (argc < 2)
		exit(1);
	else
	{
		while (i < argc)
		{
			nbr = ft_atoi(argv[i]);
			ft_add_back(&stack_a, ft_create_new_stack(nbr));
			i++;
		}
	}
	return (stack_a);
}

/// @brief Bu fonksiyon verilen yeni stack'ı mevcut stack'ın sonuna ekler.
/// Başka bir değişle verilen yeni stack'ı önceki stack'e bağlar.
/// @param stack Mevcut stack'in bellek adresi
/// @param stack_new Bağlanacak olan yeni stack
void	ft_add_back(t_stack **stack, t_stack *stack_new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		(ft_stack_last(*stack))->next = stack_new;
}
