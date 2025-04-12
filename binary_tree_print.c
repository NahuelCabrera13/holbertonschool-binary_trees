#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEIGHT 100  /* Máxima altura del árbol que podemos manejar */

/**
 * compute_lprofile - Calcula el perfil izquierdo del árbol.
 * @tree: Puntero al nodo raíz del árbol
 * @height: Altura actual del nodo
 * @lprofile: Array para almacenar el perfil izquierdo
 * @level: Nivel actual del nodo
 */
static void compute_lprofile(const binary_tree_t *tree, int height,
                             int lprofile[MAX_HEIGHT], int level)
{
        if (tree == NULL)
                return;

        /* Solo registrar la primera vez que se visita un nivel */
        if (lprofile[level] == -1)
                lprofile[level] = height;

        /* Recursión para ambos hijos */
        compute_lprofile(tree->left, height + 1, lprofile, level + 1);
        compute_lprofile(tree->right, height + 1, lprofile, level + 1);
}

/**
 * compute_rprofile - Calcula el perfil derecho del árbol.
 * @tree: Puntero al nodo raíz del árbol
 * @height: Altura actual del nodo
 * @rprofile: Array para almacenar el perfil derecho
 * @level: Nivel actual del nodo
 */
static void compute_rprofile(const binary_tree_t *tree, int height,
                             int rprofile[MAX_HEIGHT], int level)
{
        if (tree == NULL)
                return;

        /* Solo registrar la primera vez que se visita un nivel */
        if (rprofile[level] == -1)
                rprofile[level] = height;

        /* Recursión para ambos hijos */
        compute_rprofile(tree->left, height + 1, rprofile, level + 1);
        compute_rprofile(tree->right, height + 1, rprofile, level + 1);
}

/**
 * print_tree - Imprime el árbol según los perfiles calculados.
 * @tree: Puntero al nodo raíz del árbol.
 * @lprofile: Array que contiene el perfil izquierdo.
 * @rprofile: Array que contiene el perfil derecho.
 * @height: Altura del árbol.
 * @level: Nivel actual del árbol a imprimir.
 * @x: Posición del nodo a imprimir.
 */
static void print_tree(const binary_tree_t *tree, int lprofile[MAX_HEIGHT],
                       int rprofile[MAX_HEIGHT], int height, int level, int x)
{
        int spaces; /* Declaración de la variable 'spaces' al principio */

        if (tree == NULL)
                return;

        /* Calcula el espacio a la izquierda para la impresión */
        spaces = rprofile[level] - lprofile[level] - 1;

        /* Imprime el nodo actual con espacios adecuados */
        printf("%*s(%d)", spaces, "", tree->n);

        /* Imprime los hijos izquierdo y derecho recursivamente */
        print_tree(tree->left, lprofile, rprofile, height, level + 1, x + 1);
        print_tree(tree->right, lprofile, rprofile, height, level + 1, x + 1);
}

/**
 * binary_tree_print - Imprime un árbol binario en formato jerárquico
 * @tree: Puntero al nodo raíz del árbol a imprimir
 */
void binary_tree_print(const binary_tree_t *tree)
{
        int lprofile[MAX_HEIGHT];
        int rprofile[MAX_HEIGHT];
        int height;
        int i;

        /* Inicializa los perfiles a -1 */
        for (i = 0; i < MAX_HEIGHT; i++) {
                lprofile[i] = -1;
                rprofile[i] = -1;
        }

        /* Calcula la altura del árbol */
        height = binary_tree_height(tree);

        /* Calcula los perfiles izquierdo y derecho */
        compute_lprofile(tree, 0, lprofile, 0);
        compute_rprofile(tree, 0, rprofile, 0);

        /* Imprime el árbol */
        print_tree(tree, lprofile, rprofile, height, 0, 0);
}
