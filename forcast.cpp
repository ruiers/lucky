#include "stdio.h"
#include "stdlib.h"
#include "sys/queue.h"
#include "lucky.h"

SLIST_HEAD(HEAD, _node) head;

typedef struct _node
{
    num data;
    SLIST_ENTRY(_node) entry;
} node;

class number
{
public:
    struct HEAD *head;

    number()
    {
        SLIST_INIT(this->head);
    };

    void add(num n)
    {
        node* item = (node*) malloc(sizeof(node));

        item->data = n;
        SLIST_INSERT_HEAD(this->head, item, entry);
    };

    void del(num n)
    {
        node* item = NULL;

        SLIST_FOREACH(item, this->head, entry)
        {
            if (n == item->data)
            {
                SLIST_REMOVE(this->head, item, _node, entry);
                free(item);
            }
        }
    };

    ~number()
    {
        node* item = NULL;

        SLIST_FOREACH(item, this->head, entry)
        {
            SLIST_REMOVE(this->head, item, _node, entry);
            free(item);
        }

        SLIST_EMPTY(this->head);

    };
};
