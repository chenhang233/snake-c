typedef struct linkedNode
{
    void *data;
    struct linkedNode *next;
    struct linkedNode *prev;
} LinkedNode;

typedef struct linkedList
{
    LinkedNode *head;
    unsigned int size;
} LL;

typedef void *LinkedList;

LinkedList linked_list_init();
void linked_list_print(LinkedList list, void (*Yprint)(void *));
void linked_list_insert_index(LinkedList list, int index, void *data);
void linked_list_insert_tail(LinkedList list, void *data);
void linked_list_insert_head(LinkedList list, void *data);
void linked_list_remove_head(LinkedList list);
void linked_list_remove_tail(LinkedList list);
void linked_list_remove_index(LinkedList list, int index);
void linked_list_remove_value(LinkedList list, int (*Ycompare)(void *data));
void linked_list_destroy(LinkedList list);

void myP(void *data);
int myCompare(void *data);