#include "binary_trees.h"

/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: a double pointer to the root node of the Heap to insert the value
 * @value: the value to store in the node to be inserted
 *
 * Return: a pointer to the created node
 *         NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new_node, *flip;
	int size, leaves, sub, bit, level, temp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	leaves = size;
	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;


	new_node = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new_node) : (tree->left = new_node);

	flip = new_node;
	for (; flip->parent && (flip->n > flip->parent->n); flip = flip->parent)
	{
		temp = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = temp;
		new_node = new_node->parent;
	}

	return (new_node);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure the size of
 *
 * Return: size of the tree
 *         0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
