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
	size_t mid = 0;
	avl_t *root = NULL;

	if (start > end)
		return (NULL);
	mid = (start + end) / 2;
	root = binary_tree_node(parent, array[mid]);

	if (root == NULL)
		return (NULL);
	root->left = avl_rec(array, start, mid - 1, root);
	root->right = avl_rec(array, mid + 1, end, root);

	return (root);
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
