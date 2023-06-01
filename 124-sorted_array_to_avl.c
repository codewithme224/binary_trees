#include "binary_trees.h"

/**
 * avl_rec - Builds an AVL tree from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @start: The starting index of @array.
 * @end: The ending index of @array.
 *
 * Return: A pointer to the root node of the created AVL tree,
 *         or NULL on failure
 */

avl_t *avl_rec(int *array, int start, int end)
{
	avl_t *root;
	int mid;

	if (end < start)
		return (NULL);

	mid = (start + end) / 2;
	root = binary_tree_node(NULL, array[mid]);

	if (!root)
		return (NULL);
	root->left = avl_rec(array, start, mid - 1);
	root->right = avl_rec(array, mid + 1, end);

	if (root->left)
		root->left->parent = root;
	if (root->right)
		root->right->parent = root;
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
	if (!array || size < 1)
		return (NULL);

	return (avl_rec(array, 0, size - 1));

}
