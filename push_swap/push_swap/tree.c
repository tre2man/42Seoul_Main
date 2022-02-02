/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 21:05:07 by namwkim           #+#    #+#             */
/*   Updated: 2022/02/01 16:35:57 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

tree	*new_tree(int data)
{
	tree	*new;

	new = malloc(sizeof(tree));
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

int		tree_insert_data(tree **input, int data)
{
	tree	*head;
	int		rtn;

	if (!(*input))
	{
		*input = new_tree(data);
		return (0);
	}
	head = *input;
	if ((*input)->data == data)
		return (1);
	else if ((*input)->data < data)
		rtn = tree_insert_data(&((*input)->right), data);
	else
		rtn = tree_insert_data(&((*input)->left), data);
	*input = head;
	return (rtn);
}

void	free_all_tree(tree *input)
{
	if (!input)
		return ;
	free_all_tree(input->left);
	free_all_tree(input->right);
	free(input);
}

void	print_tree_preorder(tree *input)
{
	if (!input)
		return ;
	ft_putnbr_fd(input->data, 1);
	ft_putstr_fd(" ", 1);
	print_tree_preorder(input->left);
	print_tree_preorder(input->right);
}
