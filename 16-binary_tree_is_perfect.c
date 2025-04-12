#include "binary_trees.h"

/**
 * depth - Returns the depth of the leftmost path (used as reference)
 * @tree: Pointer to the tree
 *
 * Return: Depth (number of levels)
 */
int depth(const binary_tree_t *tree)
{
	int d = 0;

	while (tree)
	{
		d++;
		tree = tree->left;
	}
	return (d);
}

/**
 * is_perfect_recursive - Recursively checks if the tree is perfect
 * @tree: Pointer to the current node
 * @depth_ref: Expected depth for all leaves
 * @level: Current level
 *
 * Return: 1 if perfect, 0 otherwise
 */
int is_perfect_recursive(const binary_tree_t *tree, int depth_ref, int level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (depth_ref == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect_recursive(tree->left, depth_ref, level + 1) &&
	        is_perfect_recursive(tree->right, depth_ref, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d;

	if (tree == NULL)
		return (0);

	d = depth(tree);
	return (is_perfect_recursive(tree, d, 0));
}
