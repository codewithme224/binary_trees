#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes through a binary tree
 *                          using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Return: void
 */

void binary_tree_levelorder(const binary_tree_t *tree,
		void (*func)(int))
{
	int height, i;

	if (tree == NULL || func == NULL)
		return;

	height = binary_tree_height(tree);

	for (i = 1; i <= height + 1; i++)
		binary_tree_levelorder_func(tree, func, i);
}

/**
 * binary_tree_levelorder_func - goes through a binary tree
 *                               using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * @level: level of the tree
 *
 * Return: void
 */

void binary_tree_levelorder_func(const binary_tree_t *tree,
		void (*func)(int), int level)
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		binary_tree_levelorder_func(tree->left, func, level - 1);
		binary_tree_levelorder_func(tree->right, func, level - 1);
	}
}
