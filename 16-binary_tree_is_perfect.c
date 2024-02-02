#include <stdio.h>
#include "binary_trees.h"

size_t get_binary_tree_height(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_check_full(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - Checks if binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * Return: 0 if tree is NULL, Otherwise 1 if it is perfect
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	char balanced = (binary_tree_balance(tree) == 0) ? 1 : 0;
	int full = binary_tree_is_full(tree);

	if (!tree)
	{
		return (0);
	}
	return (balanced && full);
}

/**
 * binary_tree_is_full - Checks if binary tree is full
 * @tree: Pointer to the root node to check if tree is full
 * Return: 0 if tree is NULL, Otherwise 1 if tree is full
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int not_full = 0;

	if (!tree)
	{
		return (0);
	}
	not_full = binary_tree_check_full(tree);
	return ((not_full) ? 0 : 1);
}

/**
 * binary_tree_check_full - Checks the non full nodes
 * @tree: Pointer to the root node of binary tree to check
 * Return: The number of nodes that are not full
 */
int binary_tree_check_full(const binary_tree_t *tree)
{
	size_t not_full = 0;

	if (!tree)
	{
		return (0);
	}
	if ((tree->right && !tree->left) || (tree->left && !tree->right))
	{
		return (1);
	}
	not_full += binary_tree_check_full(tree->left);
	not_full += binary_tree_check_full(tree->right);
	return (not_full);
}

/**
 * binary_tree_balance - Returns the balance factor of the tree
 * @tree: Pointer to the root node to calculate balance factor
 * Return: The balance factor of the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_h = 0, right_h = 0;

	if (!tree)
	{
		return (0);
	}
	left_h = get_binary_tree_height(tree->left);
	right_h = get_binary_tree_height(tree->right);
	return (left_h - right_h);
}

/**
 * get_binary_tree_height - Counts the height of binary tree
 * @tree: Pointer to the root node to get height from
 * Return: The height of the tree
 */
size_t get_binary_tree_height(const binary_tree_t *tree)
{
	size_t left_h = 0;
	size_t right_h = 0;

	if (!tree)
	{
		return (0);
	}
	left_h += (tree) ? 1 + get_binary_tree_height(tree->left) : 0;
	right_h += (tree) ? 1 + get_binary_tree_height(tree->right) : 0;
	return ((right_h > left_h) ? right_h : left_h);
}
