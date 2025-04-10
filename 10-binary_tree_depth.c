#include "binary_trees.h"

/**
 * binary_tree_depth - Calcula la profundidad de un nodo en el árbol
 * @tree: Puntero al nodo objetivo
 *
 * Descripción:
 * La profundidad se define como el número de aristas
 * desde el nodo hasta la raíz del árl.
 *
 * Return:
 * Profundidad del nodo como size_t
 * 0 si el nodo es NULL o no tiene padre
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree && tree->parent)
		return (1 + binary_tree_depth(tree->parent));
	return (0);
}
