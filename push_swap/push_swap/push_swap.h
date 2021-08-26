/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 19:02:49 by namwkim           #+#    #+#             */
/*   Updated: 2021/08/26 21:19:01 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

typedef struct node
{
	int			data;
	struct node	*back;
	struct node	*next;
}	node;

typedef struct tree
{
	int			data;
	struct tree *left;
	struct tree *right;
}	tree;

/*
** onenode
*/
node	*new_node(int num);
void	print_stack(node *start);
int		get_stack_size(node *start);
void	free_all_node(node *start);

/*
** check
*/
void	add_node_front(node **start, int data);
void	add_node_back(node **start, int data);
int		del_node_front(node **start);
int		del_node_back(node **start);

/*
** run
*/
int		sx(node **stack_a, node **stack_b, char c);
int		px(node **stack_a, node **stack_b, char c);
int		rx(node **stack_a, node **stack_b, char c);
int		rrx(node **stack_a, node **stack_b, char c);

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
