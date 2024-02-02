#include "binary_trees.h"
#include "9-binary_tree_height.c"
/**
 *print_level - function
 *@func: function
 *@level: level
 *@node: node
 *Return: result
 */
void print_level(binary_tree_t *node, void (*func)(int), int level)
{
	if (node != NULL && func != NULL)
	{
		if (level == 1)
			func(node->n);
		if (level > 1)
		{
			print_level(node->left, func, level - 1);
			print_level(node->right, func, level - 1);
		}
	}
}
/**
 *binary_tree_levelorder - function
 *@tree: tree
 *@func: function
 *Return: result
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height = 0;
	size_t counter;
	binary_tree_t *copy_tree = (binary_tree_t *)tree;

	if (tree == NULL || func == NULL)
		return;
	height = binary_tree_height(tree);
	for (counter = 0; counter <= height + 1; counter++)
		print_level(copy_tree, func, counter);
}
