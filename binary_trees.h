#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdlib.h>
#include <limits.h>
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;


/**
 * struct queue_node - Queue node
 * @node: node of the tree
 * @next: point to the next node in queue
 */
typedef struct queue_node
{
	const binary_tree_t *node;
	struct queue_node *next;
} queue_node_t;


/**
 * struct queue_s - Queue data structure
 * @start: point to the fisrt node
 * @end: point to the last node
 */
typedef struct queue_s
{
	queue_node_t *start;
	queue_node_t *end;
} queue_t;

/**
 * struct complete_queue_s - Structure for a queue node
 * @node: Pointer to a binary tree node
 * @next: Pointer to the next node in the queue
 */
struct complete_queue_s
{
	binary_tree_t *node;
	struct complete_queue_s *next;
};
typedef struct complete_queue_s complete_queue_t;


/* ============ PRINT FUNCTION ============ */
void binary_tree_print(const binary_tree_t *tree);

/* ============ PROJECT FUNCTIONS ============ */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
int max(int a, int b);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
int recursive_helper(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
size_t binary_tree_power(size_t base, size_t ex);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);

int binary_tree_is_bst(const binary_tree_t *tree);
int is_binary_search_tree(const binary_tree_t *tree, int min, int max);

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
const binary_tree_t *dequeue(queue_t *q);
void enqueue(queue_t *q, const binary_tree_t *node);
int binary_tree_is_complete(const binary_tree_t *tree);
bst_t *bst_insert(bst_t **tree, int value);
bst_t *array_to_bst(int *array, size_t size);
bst_t *bst_search(const bst_t *tree, int value);
bst_t *bst_remove(bst_t *root, int value);
bst_t *bst_recursive_remove(bst_t *root, bst_t *node);
bst_t *inorder_successor(bst_t *root);

int avl_binary_tree(const binary_tree_t *tree, int min, int max);
int binary_tree_is_avl(const binary_tree_t *tree);

avl_t *avl_insert(avl_t **tree, int value);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new_node, int value);

avl_t *sorted_array_to_avl(int *array, size_t size);
avl_t *build_avl_tree(int *array, int start, int end, avl_t *parent);

avl_t *array_to_avl(int *array, size_t size);

avl_t *avl_remove(avl_t *root, int value);
avl_t *balance_recursive(avl_t **tree);
bst_t *bst_remove_avl(bst_t *root, int value);
bst_t *bst_search_avl(const bst_t *tree, int value);
bst_t *bst_recursive_remove_avl(bst_t *root, bst_t *node);


int binary_tree_is_heap(const binary_tree_t *tree);
int is_max_heap(const binary_tree_t *tree);

#endif /* BINARY_TREES_H */
