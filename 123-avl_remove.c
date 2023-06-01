#include "binary_trees.h"

/**
 * balance_tree - Balances an AVL tree.
 * @node: A pointer to the node to balance.
 *
 * Return: A pointer to the new root node of the tree after balancing.
 */

avl_t *balance_tree(avl_t *node)
{
	int balance_factor;

	balance_factor = binary_tree_balance(node);

	if (balance_factor > 1 && binary_tree_balance(node->left) >= 0)
		return (binary_tree_rotate_right(node));

	if (balance_factor > 1 && binary_tree_balance(node->left) < 0)
	{
		node->left = binary_tree_rotate_left(node->left);
		return (binary_tree_rotate_right(node));
	}

	if (balance_factor < -1 && binary_tree_balance(node->right) <= 0)
		return (binary_tree_rotate_left(node));

	if (balance_factor < -1 && binary_tree_balance(node->right) > 0)
	{
		node->right = binary_tree_rotate_right(node->right);
		return (binary_tree_rotate_left(node));
	}

	return (node);
}


/**
 * successor_node - get the next successor i mean the min
 *                  node in the right subtree
 * @node: tree to check
 * Return: the min value of this tree
 */
int successor_node(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = successor_node(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}

}

/**
 *remove_type - function that removes a node depending of its children
 *@root: node to remove
 *Return: 0 if it has no children or other value if it has
 */
int remove_type(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = successor_node(root->right);
		root->n = new_value;
		return (new_value);
	}
}

/**
 * bst_remove - Removes a node from a Binary Search Tree.
 * @root: A pointer to the root node of the BST.
 * @value: The value to remove from the BST.
 *
 * Return: A pointer to the removed node, or NULL on failure.
 */

avl_t *bst_remove(avl_t *root, int value)
{
	avl_t *node;

	if (root == NULL)
		return (NULL);
	if (root->n > value)
		root->left = bst_remove(root->left, value);
	else if (root->n < value)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			return (NULL);
		}

		else if (root->left == NULL)
		{
			node = root->right;
			free(root);
			return (node);
		}

		else if (root->right == NULL)
		{
			node = root->left;
			free(root);
			return (node);
		}

		node = root->right;

		while (node->left != NULL)
			node = node->left;

		root->n = node->n;
		root->right = bst_remove(root->right, node->n);
	}

	return (root);
}


/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: A pointer to the root node of the tree for removing a node.
 * @value: The value to remove in the tree.
 *
 * Return: removing the desired value, and after rebalancing.
 */

avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *node;

	if (root == NULL)
		return (NULL);
	node = bst_remove(root, value);

	if (node == NULL)
		return (NULL);

	root = balance_tree(node);

	return (root);
}
