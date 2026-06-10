// lets implement queue in linked list

#include <stdio.h>
#include <stdlib.h>
#include <queue.h>


int main()
{
    queue_init();
    queue_add(12);
    queue_add(5);
    queue_add(1995);
    queue_add(18);

    queue_display();

    queue_read();
    queue_read();

    queue_display();

    queue_read();
    queue_read();

    queue_display();

    
    return 0;
}
