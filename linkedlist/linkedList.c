#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

LinkedList linked_list_init()
{
    LL *ll = malloc(sizeof(LL));
    ll->size = 0;
    ll->head = NULL;
    return ll;
}

void linked_list_print(LinkedList list, void (*Yprint)(void *))
{
    if (list == NULL)
        return;
    LL *L = list;
    int size = L->size;
    if (!size)
        return;
    LinkedNode *h = L->head;
    while (size)
    {
        Yprint(h->data);
        h = h->next;
        size--;
    }
}

void linked_list_insert_index(LinkedList list, int index, void *data)
{
    if (list == NULL)
        return;
    LL *l = list;
    int size = l->size;
    if (index < 0 || index > size)
    {
        index = size;
    }
    if (!index)
    {
        linked_list_insert_head(list, data);
        return;
    }
    if (index == size)
    {
        linked_list_insert_tail(list, data);
        return;
    }
    LinkedNode *node = malloc(sizeof(LinkedNode));
    node->data = data;
    if (!size)
    {
        node->next = node;
        node->prev = node;
        l->head = node;
    }
    else
    {
        int i;
        LinkedNode *cur = l->head;
        for (i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        LinkedNode *next = cur->next;
        cur->next = node;
        node->prev = cur;
        node->next = next;
        next->prev = node;
    }
    l->size++;
}
void linked_list_insert_head(LinkedList list, void *data)
{
    if (list == NULL)
        return;
    LL *l = list;
    int size = l->size;
    LinkedNode *node = malloc(sizeof(LinkedNode));
    node->data = data;
    if (!size)
    {
        node->next = node;
        node->prev = node;
        l->head = node;
    }
    else
    {
        LinkedNode *tail = l->head->prev;
        LinkedNode *next = l->head;
        tail->next = node;
        node->prev = tail;
        node->next = next;
        next->prev = node;
        l->head = node;
    }
    l->size++;
}
void linked_list_insert_tail(LinkedList list, void *data)
{
    if (list == NULL)
        return;
    LL *l = list;
    int size = l->size;
    if (!size)
    {
        linked_list_insert_head(list, data);
        return;
    }
    LinkedNode *node = malloc(sizeof(LinkedNode));
    node->data = data;
    LinkedNode *tail = l->head->prev;
    int *p = tail->data;
    int *da = data;
    tail->next = node;
    node->prev = tail;
    node->next = l->head;
    l->head->prev = node;
    l->size++;
}

void linked_list_remove_head(LinkedList list)
{
    if (list == NULL)
        return;
    LL *l = list;
    int size = l->size;
    if (!size)
        return;
    LinkedNode *head = l->head;
    if (size == 1)
    {
        free(head);
        l->head = NULL;
    }
    else
    {
        LinkedNode *next = head->next;
        LinkedNode *prev = head->prev;
        next->prev = prev;
        prev->next = next;
        free(head);
        l->head = next;
    }
    l->size--;
};
void linked_list_remove_tail(LinkedList list)
{
    if (list == NULL)
        return;
    LL *l = list;
    int size = l->size;
    if (!size)
        return;
    if (size == 1)
    {
        linked_list_remove_head(list);
        return;
    }
    else
    {
        LinkedNode *head = l->head;
        LinkedNode *remove = head->prev;
        LinkedNode *tail = head->prev->prev;
        if (head == tail)
        {
            head->next = head;
            head->prev = head;
        }
        else
        {
            tail->next = head;
            head->prev = tail;
        }
        free(remove);
    }
    l->size--;
};
void linked_list_remove_index(LinkedList list, int index)
{
    if (list == NULL)
        return;
    LL *l = list;
    int size = l->size;
    if (!size || index < 0 || index >= size)
    {
        return;
    }
    if (!index)
    {
        linked_list_remove_head(list);
        return;
    }
    if (index == size - 1)
    {
        linked_list_remove_tail(list);
        return;
    }
    int i;
    LinkedNode *cur = l->head;
    for (i = 0; i < index; i++)
    {
        cur = cur->next;
    }
    LinkedNode *next = cur->next;
    LinkedNode *prev = cur->prev;
    prev->next = next;
    next->prev = prev;
    free(cur);
    l->size--;
};

void linked_list_remove_value(LinkedList list, int (*Ycompare)(void *data))
{
    if (list == NULL || Ycompare == NULL)
        return;
    LL *l = list;
    int size = l->size;
    if (!size)
    {
        return;
    }
    int i;
    LinkedNode *cur = l->head;
    for (i = 0; i < size; i++)
    {
        if (!Ycompare(cur->data))
        {
            linked_list_remove_index(list, i);
            break;
        }
        cur = cur->next;
    }
}

void linked_list_destroy(LinkedList list)
{
    if (list == NULL)
        return;
    LL *l = list;
    int size = l->size;
    if (size)
    {
        int i;
        for (i = 0; i < size; i++)
        {
            linked_list_remove_head(list);
        }
    }
    free(l);
}

void myP(void *data)
{
    int *v = data;
    printf("v=%d\n", *v);
}

int myCompare(void *data)
{
    int *v = data;
    if (*v == 1)
        return 0;
    return 1;
}

int main(int argc, char const *argv[])
{
    LinkedList list = linked_list_init();
    int a = 1, a2 = 2, a3 = 3, a4 = 4, a5 = 5;
    linked_list_insert_tail(list, &a);
    linked_list_insert_tail(list, &a2);
    linked_list_insert_tail(list, &a3);
    linked_list_insert_index(list, 3, &a4);
    linked_list_insert_index(list, 0, &a5);
    // linked_list_remove_head(list);
    // linked_list_remove_tail(list);
    // linked_list_remove_index(list, 1);
    linked_list_remove_value(list, myCompare);
    linked_list_print(list, myP);
    linked_list_destroy(list);
    return 0;
}
