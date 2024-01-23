#include "sort.h"

void swap_nodes(listint_t **list, listint_t *node_i, listint_t *node_j);
void insert_node_after(listint_t **list, listint_t *prev_node,
listint_t *node, listint_t *after_node);

/**
 * swap_nodes -  A function that Swaps two nodes of a doubly
 * linked list, node_i must be before than node_j
 * @list: Double pointer to list
 * @node_i: The node that comes first
 * @node_j: The node that comes second
*/
void swap_nodes(listint_t **list, listint_t *node_i, listint_t *node_j)
{
listint_t *bef_x, *bef_y;
bef_x = node_i->prev;
insert_node_after(list, bef_x, node_i, node_j);
bef_y = node_j->prev;
insert_node_after(list, bef_y, node_j, bef_x);
}

/**
 * insert_node_after - Inserts a node after other passeda as argument
 * @list: The Double pointer to the list
 * @prev_node: The node that comes before the 'node'
 * @node: The Node to be inserted after 'after_node'
 * @after_node: The Node to insert after
*/
void insert_node_after(listint_t **list, listint_t *prev_node,
listint_t *node, listint_t *after_node)
{
if (prev_node == NULL)
(*list) = (*list)->next;
else
prev_node->next = node->next;
node->next->prev = prev_node;
if (after_node == NULL)
{
(*list)->prev = node;
node->prev = NULL;
node->next = *list;
*list = node;
return;
}
node->next = after_node->next;
node->prev = after_node;
if (after_node->next != NULL)
after_node->next->prev = node;
after_node->next = node;
}

/**
 * insertion_sort_list - A function that sorts a
 * doubly linked list of integers in ascending order
 * @list: double pointer to the list
 */
void insertion_sort_list(listint_t **list)
{
listint_t *xn, *yn;
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;
for (xn = (*list)->next; xn != NULL; xn = xn->next)
{
for (yn = xn; yn->prev != NULL; yn = yn->prev)
{
if (yn->prev->n > yn->n)
{
swap_nodes(list, yn->prev, yn);
yn = yn->next;
print_list(*list);
}
else
{
break;
}
}
}
}
