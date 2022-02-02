/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namwkim <namwkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 21:05:07 by namwkim           #+#    #+#             */
/*   Updated: 2022/02/02 17:32:43 by namwkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

tree *new_tree(int data)
{
	tree *new;

	new = malloc(sizeof(tree));
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

int tree_insert_data(tree **input, int data)
{
	tree *head;
	int rtn;

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

void free_all_tree(tree *input)
{
	if (!input)
		return;
	free_all_tree(input->left);
	free_all_tree(input->right);
	free(input);
}

void print_tree_preorder(tree *input)
{
	if (!input)
		return;
	ft_putnbr_fd(input->data, 1);
	ft_putstr_fd(" ", 1);
	print_tree_preorder(input->left);
	print_tree_preorder(input->right);
}

/*
** 중위 순회로 판별, 시작 인덱스는 0, 반환값은 현재 인덱스의 순서
*/
int get_value_from_index(tree *input, int target_index, int target_find, int *ans)
{
	int now_idx;

	if (!input)
		return (0);
	// 죄측 순회
	now_idx = get_value_from_index(input->left, target_index, target_find, ans) + 1;
	if (now_idx == target_index)
	{
		target_find = 1;
		*ans = input->data;
		return now_idx;
	}
	// 우측 순회
	get_value_from_index(input->right, target_index, target_find, ans);
	return now_idx;
}
