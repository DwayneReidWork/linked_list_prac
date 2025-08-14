#include <stdio.h>
#include <stdlib.h>

#include "ll_utils.h"

int main()
{
    node_t *head = NULL;
    node_t *tmp;

    // add nodes for 1-25
    for (int i = 0; i < 25; i++)
    {
        tmp = create_new_node(i);
        head = insert_at_head(head, tmp);
    }

    // search for node 13
    tmp = find_node(head, 13);
    printf("Found the node with value %d\n", tmp->value);

    // insert node 75 after node 13 [tmp]
    insert_after_node(tmp, create_new_node(75));

    printlist(head);

    // Removes 13
    head = remove_node(head, tmp);

    // Removes first node
    head = remove_node(head, head);

    printlist(head);

    printf("The list has %d nodes.\n", findSize(head));

    return 0;
}