#include "binary_trees.h"

/**
 * tree_size - measures the sum of heights of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: Height or 0 if tree is NULL
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t l_height = 0;
	size_t r_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		l_height = 1 + tree_size(tree->left);

	if (tree->right)
		r_height = 1 + tree_size(tree->right);

	return (l_height + r_height);
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap
 * to a sorted array of integers
 * @heap: a pointer to the root node of the heap to convert
 * @size: an address to store the size of the array
 *
 * Return: the generated array
 *         NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int index, *arr = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	arr = malloc(sizeof(int) * (*size));

	if (!arr)
		return (NULL);

	for (index = 0; heap; index++)
		arr[index] = heap_extract(&heap);

	return (arr);
}
