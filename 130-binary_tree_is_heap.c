#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of the tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_height = 0;
	size_t r_height = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree->left == NULL && tree->right == NULL)
			return (tree->parent != NULL);
		if (tree)
		{
			l_height = tree->left ? 1 +
				binary_tree_height(tree->left) : 0;
			r_height = tree->right ? 1 +
				binary_tree_height(tree->right) : 0;
		}
		return ((l_height > r_height) ? l_height : r_height);
	}
}


/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure
 *        the balance factor
 *
 * Return: balance factor of the tree
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0, result = 0;

	if (tree)
	{
		left_height = ((int)binary_tree_height(tree->left));
		right_height = ((int)binary_tree_height(tree->right));
		result = left_height - right_height;
	}
	return (result);
}


/**
 * tree_is_perfect - checks if a binary tree is perfect
 * @tree: the binary tree to check
 *
 * Return: 0 if is not a perfect or other number that is the level of height
 */

int tree_is_perfect(const binary_tree_t *tree)
{
	int left_node = 0, right_node = 0;

	if (tree->left && tree->right)
	{
		left_node = 1 + tree_is_perfect(tree->left);
		right_node = 1 + tree_is_perfect(tree->right);
		if (right_node == left_node && right_node != 0
				&& left_node != 0)
			return (right_node);
		return (0);
	}
	else if (!tree->left && !tree->right)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is perfect, otherwise 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int r = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		r = tree_is_perfect(tree);
		if (r != 0)
			return (1);
		return (0);
	}
}


/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or is not a valid Max Binary Heap - 0.
 */

int binary_tree_is_heap(const binary_tree_t *tree)
{
	int balance;

	if (tree == NULL)
		return (0);
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n > tree->n)
		return (0);
	if (binary_tree_is_perfect(tree))
		return (1);

	balance = binary_tree_balance(tree);

	if (balance == 0)
	{
		return (binary_tree_is_perfect(tree->left)
				&& binary_tree_is_heap(tree->right));
	}

	if (balance == 1)
	{
		return (binary_tree_is_heap(tree->left)
				&& binary_tree_is_perfect(tree->right));
	}
	else
	{
		return (0);
	}
}
