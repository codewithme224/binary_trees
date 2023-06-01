#include "binary_trees.h"

/**
 * avl_rec - Builds an AVL tree from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @start: The starting index of @array.
 * @end: The ending index of @array.
 * @parent: A pointer to the parent node.
 *
 * Return: A pointer to the root node of the created AVL tree,
 *         or NULL on failure
 */

avl_t *avl_rec(int *array, size_t start, size_t end, avl_t *parent)
{
	avl_t *root;
	binary_tree_t *node;
	int mid = 0;

	if (start <= end)
	{
		mid = (start + end) / 2;
		node = binary_tree_node((binary_tree_t *)parent, array[mid]);
		if (node == NULL)
			return (NULL);
		root = (avl_t *)node;
		root->left = avl_rec(root, array, start, mid - 1);
		root->right = avl_rec(root, array, mid + 1, end);
	}
	return (NULL);
}


/**
 * sorted_array_to_avl - Builds an AVL tree from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in @array.
 *
 * Return: A pointer to the root node of the created AVL tree,
 *         or NULL on failure
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;

	if (array == NULL || size == 0)
		return (NULL);
	tree = avl_rec(array, 0, size - 1, NULL);

	return (tree);
}
