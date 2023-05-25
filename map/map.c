#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// key -> value的指针偏移量(v)   v -> 真正的数据
int i;

typedef struct Node
{
    char *key;
    int p;
} Node;

typedef struct Map
{
    void **Data;
    unsigned int length;
    unsigned int capacity;
    Node **nodes;
    unsigned int node_length;
    unsigned int node_capacity;
} Map;

Map *New()
{
    Map *m = malloc(sizeof(Map));
    m->length = 0;
    m->capacity = 5;
    m->Data = malloc(sizeof(void *) * m->capacity);
    m->nodes = malloc(sizeof(Node *) * m->capacity);
    m->nodes = NULL;
    return m;
}

void put(Map *m, char *key, void *value)
{
    if (m == NULL)
    {
        return;
    }
    int curLen = m->length;
    int curCap = m->capacity;
    if (curLen == curCap)
    {
        void **newData = malloc(sizeof(void *) * (m->capacity *= 2));
        memcpy(newData, m->Data, curLen);
        free(m->Data);
        m->Data = newData;
    }
    m->Data[curLen] = value;
    m->length++;
}