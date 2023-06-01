#include "binary_trees.h"

/**
 * balance_t - Balances an AVL tree.
 * @tree: A pointer to the node to balance.
 *
 * Return: A pointer to the new root node of the tree after balancing.
 */

void balance_t(avl_t **tree)
{
	int balance_f;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	balance_t(&(*tree)->left);
	balance_t(&(*tree)->right);
	balance_f = binary_tree_balance((const binary_tree_t *)*tree);
	if (balance_f > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (balance_f < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
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
	int node_type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		node_type = remove_type(root);
		if (node_type != 0)
			bst_remove(root->right, node_type);
	}
	else
		return (NULL);
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
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	balance_t(&root_a);
	return (root_a);
}
