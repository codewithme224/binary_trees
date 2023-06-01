#include "binary_trees.h"
#include "limits.h"

/**
 * height - finds the height of a binary tree.
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */

size_t height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = height(tree->left);
	right_height = height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}


/**
 * avl_helper - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @low: The value of the smallest node visited thus far.
 * @high: The value of the largest node visited this far.
 *
 * Return: If the tree is a valid AVL tree, 1, otherwise, 0.
 */
int avl_helper(const binary_tree_t *tree, int low, int high)
{
	size_t l_height, r_height, diff;

	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);
		l_height = height(tree->left);
		r_height = height(tree->right);
		diff = l_height > r_height ? l_height -
			r_height : r_height - l_height;
		if (diff > 1)
			return (0);
		return (avl_helper(tree->left, low, tree->n - 1) &&
			avl_helper(tree->right, tree->n + 1, high));
	}
	return (1);
}


/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (avl_helper(tree, INT_MIN, INT_MAX));
}
