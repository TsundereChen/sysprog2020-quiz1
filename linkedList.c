#include "linkedList.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void add_entry(node_t **head, int new_value)
{
    node_t **indirect = head;

    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = new_value;
    new_node->next = NULL;

    assert(new_node);
    while (*indirect)
        indirect = &(*indirect)->next;
    *indirect = new_node;
}

node_t *find_entry(node_t *head, int value)
{
    node_t *current = head;
    for (; current && current->value != value; current = current->next)
        /* interate */;
    return current;
}

void remove_entry(node_t **head, node_t *entry)
{
    node_t **indirect = head;

    while ((*indirect) != entry)
        indirect = &(*indirect)->next;

    *indirect = entry->next;
    free(entry);
}

void swap_pair(node_t **head) {
  for (node_t **node = head; *node && (*node)->next;
       node = &(*node)->next->next) {
    node_t *tmp = *node;
    *node = (*node)->next;
    tmp->next = (*node)->next;
    (*node)->next = tmp;
  }
  return;
}

void reverse(node_t **head) {
  node_t **now = head;
  node_t *cursor = NULL;
  node_t *next = NULL;
  while ((*now)) {
    next = (*now)->next;
    (*now)->next = cursor;
    cursor = *now;
    *now = next;
  }
  *now = cursor;
  return;
}

void print_list(node_t *head)
{
    for (node_t *current = head; current; current = current->next)
        printf("%d ", current->value);
    printf("\n");
}

int get_list_length(node_t *head) {
  int len = 0;
  for (node_t *current = head; current; current = current->next)
    len++;
  return len;
}

node_t *node_finder(node_t *head, int position) {
  node_t *now = head;
  for (int i = 0; i < position; i++) {
    now = now->next;
  }
  return now;
}

void swapValue(node_t *a, node_t *b) {
  if (a == b)
    return;
  a->value ^= b->value;
  b->value ^= a->value;
  a->value ^= b->value;
}

void fisherYatesShuffle(node_t *head, int length) {
  node_t *now = head;
  for (int i = 0; i < length; i++) {
    int randInt = i + (rand() % (length - i));
    node_t *targetNode = node_finder(head, randInt);
    swapValue(now, targetNode);
    now = now->next;
  }
}

void recursive_reverse(node_t **head) {
  if (!head)
    return;
  recursive_reverse_step(*head, NULL, head);
}

void recursive_reverse_step(node_t *curr, node_t *prev, node_t **head) {
  node_t *next = curr->next;
  curr->next = prev;

  if (!next) {
    *head = curr;
    return;
  }

  recursive_reverse_step(next, curr, head);
}
