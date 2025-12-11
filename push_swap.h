/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meodev <meodev@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:51:58 by meodev            #+#    #+#             */
/*   Updated: 2025/12/08 04:49:00 by meodev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

typedef struct s_program
{
	t_stack	*a;
	t_stack	*b;
	char	**input;
	int		arg_count;
}	t_program;

t_stack		*stack_create(void);
void		stack_destroy(t_stack *stack);
t_node		*node_create(int value);
void		stack_push(t_stack *stack, int value);
int			stack_pop(t_stack *stack);
int			stack_peek(t_stack *stack);
int			stack_is_empty(t_stack *stack);

void		memory_cleanup(t_program *prog, int free_input);

int			text_length(const char *text);
char		*copy_text(const char *source);
int			compare_text(const char *t1, const char *t2);
void		print_text(const char *text);
void		print_number(int num);

char		**tokenize(const char *text, char separator);
void		free_tokens(char **tokens);
int			count_tokens(const char *text, char sep);
char		*extract_token(const char *start, const char *end);
void		cleanup_tokens(char **tokens, int count);

long		convert_to_long(const char *text);
int			is_alphabetic(char c);
int			is_numeric(char c);
int			is_whitespace(char c);

void		op_swap(t_stack *stack, char stack_name);
void		op_push(t_stack *from, t_stack *to, char to_name);
void		op_rotate(t_stack *stack, char stack_name);
void		op_reverse_rotate(t_stack *stack, char stack_name);

void		validate_args2(char **args);
int			validate_args(char **args);
void		error_exit(const char *msg);

int			is_stack_sorted(t_stack *stack);
void		sort_stack(t_program *prog);
void		sort_three_elements(t_stack *a);
void		sort_five_elements(t_program *prog);
void		sort_large_stack(t_program *prog);

int			find_minimum(t_stack *stack);
int			find_maximum(t_stack *stack);
int			find_median(t_stack *stack);
int			get_element_position(t_stack *stack, int value);
int			calculate_cost(t_stack *stack, int pos);
int			get_chunk_count(int size);

void		push_chunks_to_b(t_program *prog);
void		push_back_to_a(t_program *prog);

#endif
