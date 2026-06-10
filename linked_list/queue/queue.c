// lets implement queue in linked list

#include <stdio.h>
#include <stdlib.h>

// struct for the node
typedef struct linkedList {
    int data;
    struct linkedList *p_node;
}node_t;

// head pointer to keep track of the first element of the list
static node_t *p_head;

// tail pointer to keep track of the last element added to the list
static node_t *p_tail;

// Current pointer to hold the address for the operations API
static node_t *p_curr;


// initlize all the global pointer to NULL value
void queue_init(void)
{
    // head pointer to keep track of the first element of the list
    node_t *p_head = NULL;

    // tail pointer to keep track of the last element added to the list
    node_t *p_tail = NULL;

    // Current pointer to hold the address for the operations API
    node_t *p_curr = NULL;
}

// API to add element at the tail of the queue
int queue_add(int value)
{
    if (p_tail == NULL)
    {
        // if tail is NULL then it means list is empty
        p_tail = malloc(sizeof(node_t));
        if (p_tail == NULL)
        {
            printf ("Memory allocation failed \n");
            return -1;
        }
        // since tail is empty which means head is also NULL
        p_head = p_tail;
        p_curr = p_tail;
    }
    else
    {
        p_curr = malloc(sizeof(node_t));
        if (p_curr == NULL)
        {
            printf ("Memory allocation failed \n");
            return -1;
        }
        // if tail is already exists then point the next node to the p_curr 
        p_tail->p_node = p_curr;
        p_tail = p_curr;
    }

    p_curr->data = value;
    p_curr->p_node = NULL;

    return 0;
}

// this API reads the head element and delete's it and also free's up the space
int queue_read(void)
{
    if (p_head == NULL)
    {
        printf("List is empty \n");
        return 1;
    }

    p_curr = p_head;

    printf("The current head value is: %d\n",p_head->data);

    p_head = p_head->p_node;

    free(p_curr);

    return 0;
}

// Start from the head and print all the values till we reach the NULL pointer Node
int queue_display(void)
{
    if (p_head == NULL)
    {
        printf("List is empty \n");
        return 1;
    }

    p_curr = p_head;

    while (p_curr != NULL)
    {
        printf("%d\n",p_curr->data);
        p_curr = p_curr->p_node;
    }
    return 0;
}