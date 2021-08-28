/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 19:02:49 by namwkim           #+#    #+#             */
/*   Updated: 2021/08/28 01:25:17 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

typedef struct node
{
	int			data;
	struct node	*back;
	struct node	*next;
}	node;

typedef struct stack
{
	int			size;
	node		*head;
	node		*tail;
}	stack;

typedef struct tree
{
	int			data;
	struct tree *left;
	struct tree *right;
}	tree;

/*
** stack_utils
*/
stack	new_stack(void);
void	print_stack(stack stack);
void	free_stack(stack stack);

/*
** stack_node
*/
node	*new_node(int num);
void	add_node_front(stack *stack, int data);
void	add_node_back(stack *stack, int data);
int		del_node_front(stack *stack);
int		del_node_back(stack *stack);

/*
** stack_func
*/
int		sx(stack *stack_a, stack *stack_b, char c);
int		px(stack *stack_a, stack *stack_b, char c);
int		rx(stack *stack_a, stack *stack_b, char c);
int		rrx(stack *stack_a, stack *stack_b, char c);

/*
** tree
*/
tree	*new_tree(int data);
int		tree_insert_data(tree **input, int data);
void	free_all_tree(tree *input);
void	print_tree_preorder(tree *input);

/*
** error
*/
int		throw_error(char *str);
