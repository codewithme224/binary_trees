#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to the created node, or NULL on failure
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node = NULL, *parent = NULL;

	if (tree == NULL)
		return (NULL);
	parent = *tree;

	while (parent != NULL)
	{
		if (value == parent->n)
			return (NULL);
		if (value < parent->n)
		{
			if (parent->left == NULL)
			{
				node = binary_tree_node(parent, value);
				if (node == NULL)
					return (NULL);
				parent->left = node;
				return (node);
			}
			parent = parent->left;
		}
		else
		{
			if (parent->right == NULL)
			{
				node = binary_tree_node(parent, value);
				if (node == NULL)
					return (NULL);
				parent->right = node;
				return (node);
			}
			parent = parent->right;
		}
	}
	node = binary_tree_node(parent, value);
	if (node == NULL)
		return (NULL);
	*tree = node;
	return (node);
}
