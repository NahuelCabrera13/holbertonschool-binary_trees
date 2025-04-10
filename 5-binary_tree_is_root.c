
#include "binary_trees.h"
/**
 * binary_tree_is_root - verifica que el nodo sea root 
 * @node: Puntero al nodo a verificar
 * Return:
 * 1 si el nodo es una hoja
 * 0 en cualquier otro caso (incluyendo si node es NULL)
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	return (node && !node->parent);
}
