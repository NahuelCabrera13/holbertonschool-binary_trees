#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_delete - elimina todo
 * @tree: pepe
 * Return: no retorna ningun pepe
*/
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);

	free(tree);
}
