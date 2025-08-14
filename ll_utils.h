#pragma once

typedef struct node
{
    int value;
    struct node *next;
    struct node *prev;
} node_t;

int findSize(node_t *head);

node_t *create_new_node(int value);
node_t *find_node(node_t *head, int value);
node_t *insert_at_head(node_t *head, node_t *node_to_insert);
node_t *remove_node(node_t *head, node_t *node_to_remove);

void printlist(node_t *head);
void insert_after_node(node_t *node_to_insert_after, node_t *new_node);