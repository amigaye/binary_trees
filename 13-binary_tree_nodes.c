#include "binary_trees.h"

/**
 * binary_tree_nodes - functions
 *@tree: tree
 * Return: the number of nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t num = 0;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (0);
	num += binary_tree_nodes(tree->left);
	num += binary_tree_nodes(tree->right);
	num += (tree->right || tree->left) ? 1 : 0;
	return (num);
}
