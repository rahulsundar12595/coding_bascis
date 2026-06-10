#include <stdio.h>
#include <stdlib.h>

// lets implement stack next

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
void linkedList_stack_init(void)
{
    // head pointer to keep track of the first element of the list
    node_t *p_head = NULL;

    // tail pointer to keep track of the last element added to the list
    node_t *p_tail = NULL;

    // Current pointer to hold the address for the operations API
    node_t *p_curr = NULL;
}

// When pushing data on stack head will get updated
int linkedList_stack_push(int data)
{
    p_curr = malloc(sizeof(node_t));
    if (p_curr == NULL)
    {
        printf("Memory allocation failed \n");
        return 1;
    }
    // check if head already exists or not
    if (p_head == NULL)
    {
       p_tail = p_curr;
       p_tail->p_node = NULL;
    }
    else
    {
        p_curr->p_node = p_head;
    }

     p_head = p_curr;
     p_head->data = data;

     return 0;

}

int linkedList_stack_display(void)
{
    if (p_head == NULL)
    {
        printf("Stack is empty \n");
        return 1;
    }
    
    p_curr = p_head;

    while(p_curr != NULL)
    {
        printf("%d\n",p_curr->data);
        printf("------\n");
        p_curr = p_curr->p_node;
    }

    return 0;
    
}

// Display the head element value, update the head pointer to the next node and free the original head poniter addr
int linkedList_stack_pop(void)
{
    // check if stack exists
    if (p_head == NULL)
    {
        printf("Stack is empty \n");
        return 1;
    }
    
    p_curr = p_head;

    printf("Top of the stack value is: %d \n",p_head->data);

    p_head = p_head->p_node;

    free(p_curr);

    return 0;
    
}
