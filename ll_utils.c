#include <stdlib.h>
#include <stdio.h>

#include "ll_utils.h"

void printlist(node_t *head)
{
    node_t *temp = head;
    while (temp != NULL)
    {
        printf("%d - ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

node_t *create_new_node(int value)
{
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    result->prev = NULL;
    return result;
}

node_t *insert_at_head(node_t *head, node_t *node_to_insert)
{
    node_to_insert->next = head;
    if (head != NULL)
    {
        head->prev = node_to_insert;
    }
    head = node_to_insert;
    return head;
}

void insert_after_node(node_t *node_to_insert_after, node_t *new_node)
{
    new_node->next = node_to_insert_after->next;
    if (new_node->next != NULL)
    {
        new_node->next->prev = new_node;
    }
    new_node->prev = node_to_insert_after;
    node_to_insert_after->next = new_node;
}

node_t *remove_node(node_t *head, node_t *node_to_remove)
{
    if (head == NULL || node_to_remove == NULL)
        return head; // nothing to remove

    // Ensure the node is in the list
    node_t *cursor = head;
    while (cursor != NULL && cursor != node_to_remove)
    {
        cursor = cursor->next;
    }
    if (cursor == NULL)
        return head; // node not found

    // If removing the head
    if (node_to_remove == head)
    {
        head = node_to_remove->next;
        if (head != NULL)
            head->prev = NULL;
    }
    else
    {
        node_to_remove->prev->next = node_to_remove->next;
        if (node_to_remove->next != NULL)
            node_to_remove->next->prev = node_to_remove->prev;
    }

    // Clear pointers in removed node
    node_to_remove->next = NULL;
    node_to_remove->prev = NULL;

    return head; // head may have changed
}

node_t *find_node(node_t *head, int value)
{
    node_t *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->value == value)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

int findSize(node_t *head)
{
    int size = 0;
    while (head != NULL)
    {
        size++;
        head = head->next;
    }
    return size;
}