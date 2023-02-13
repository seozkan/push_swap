/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 22:03:28 by seozkan           #+#    #+#             */
/*   Updated: 2023/02/10 21:47:50 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../gnl/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
}					t_stack;

int					ft_atoi(const char *str);
t_stack				*ft_create_and_fill_stack(int argc, char **argv);
void				ft_add_back(t_stack **stack, t_stack *stack_new);
int					ft_check_args(int argc, char **argv, t_stack *stack);
int					ft_is_duplicate(t_stack *stack);
int					ft_is_sorted(t_stack *stack_a);
int					is_digit(int c);
t_stack				*ft_create_new_stack(int nbr);
void				ft_error(void);
void				ft_free(t_stack *stack);
int					ft_make_rarb(t_stack **stack_a, t_stack **stack_b, int nbr,
						char s);
int					ft_make_rrarrb(t_stack **stack_a, t_stack **stack_b,
						int nbr, char s);
int					ft_make_rrarb(t_stack **stack_a, t_stack **stack_b,
						int nbr, char s);
int					ft_make_rarrb(t_stack **stack_a, t_stack **stack_b,
						int nbr, char s);
int					ft_rotate_type_ba(t_stack *stack_a, t_stack *stack_b);
int					ft_rotate_type_ab(t_stack *a, t_stack *b);
void				ft_sort_b_till_3(t_stack **stack_a, t_stack **stack_b);
t_stack				**ft_sort_b(t_stack **stack_a, t_stack **stack_b);
t_stack				**ft_sort_a(t_stack **stack_a, t_stack **stack_b);
void				ft_sort(t_stack **stack_a, t_stack **stack_b);
void				ft_sort_three(t_stack **stack_a);
t_stack				*ft_stack_last(t_stack *stack);
int					ft_stack_size(t_stack *stack);
int					ft_stack_min(t_stack *stack);
int					ft_stack_max(t_stack *stack);
int					ft_find_index(t_stack *a, int nbr);
int					ft_find_place_b(t_stack *stack_b, int nbr_push);
int					ft_find_place_a(t_stack *stack_a, int nbr_push);
void				ft_ra(t_stack **stack_a, int j);
void				ft_sa(t_stack **stack, int j);
void				ft_pa(t_stack **stack_a, t_stack **stack_b, int j);
void				ft_rra(t_stack **stack_a, int j);
void				ft_ss(t_stack **stack_a, t_stack **stack_b, int j);
void				ft_rr(t_stack **stack_a, t_stack **stack_b, int j);
void				ft_rrr(t_stack **a, t_stack **b, int j);
void				ft_pb(t_stack **stack_a, t_stack **stack_b, int j);
void				ft_rrb(t_stack **stack_b, int j);
void				ft_rb(t_stack **stack_b, int j);
void				ft_sb(t_stack **stack_b, int j);
int					ft_calc_rarb(t_stack *stack_a, t_stack *stack_b, int nbr,
						char mod);
int					ft_calc_rrarrb(t_stack *stack_a, t_stack *stack_b, int nbr,
						char mod);
int					ft_calc_rrarb(t_stack *stack_a, t_stack *stack_b, int nbr,
						char mod);
int					ft_calc_rarrb(t_stack *stack_a, t_stack *stack_b, int nbr,
						char mod);
char				*get_next_line(int fd);
void				ft_check_sub(t_stack **stack_a, t_stack **stack_b,
						char *line);
char				*ft_check(t_stack **stack_a, t_stack **stack_b, char *line);
void				ft_checker_sub(t_stack **stack_a, t_stack **stack_b,
						char *line);
#endif