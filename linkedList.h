typedef struct __node {
    int value;
    struct __node *next;
} node_t;

void add_entry(node_t **head, int new_value);
node_t *find_entry(node_t *head, int value);
void remove_entry(node_t **head, node_t *entry);
void swap_pair(node_t **head);
void reverse(node_t **head);
void print_list(node_t *head);
int get_list_length(node_t *head);
node_t *node_finder(node_t *head, int position);
void swapValue(node_t *a, node_t *b);
void fisherYatesShuffle(node_t *head, int length);
void recursive_reverse(node_t **head);
void recursive_reverse_step(node_t *curr, node_t *prev, node_t **head);
