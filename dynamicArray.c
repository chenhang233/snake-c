#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DynamicArray
{
    void **p_arr;
    int capacity;
    int length;
};

struct Person
{
    char name[20];
    int age;
};

struct DynamicArray *dynamic_init(int capacity)
{
    if (capacity <= 0)
        return NULL;
    struct DynamicArray *arr = malloc(sizeof(struct DynamicArray));
    arr->p_arr = malloc(sizeof(void *) * capacity);
    arr->capacity = capacity;
    arr->length = 0;
    return arr;
}

void dynamic_insert_index(struct DynamicArray *arr, void *data, int index)
{
    if (data == NULL)
        return;
    if (index > arr->length || index < 0)
    {
        index = arr->length;
    };
    int cur_cap = arr->capacity;
    if (arr->length == cur_cap)
    {
        int new_cap = cur_cap * 2;
        void **new_space = malloc(sizeof(void *) * new_cap);
        memcpy(new_space, arr->p_arr, sizeof(void *) * cur_cap);
        free(arr->p_arr);
        arr->p_arr = new_space;
        arr->capacity = new_cap;
    }
    int i;
    for (i = arr->length - 1; i >= index; i--)
    {
        arr->p_arr[i + 1] = arr->p_arr[i];
    }
    arr->p_arr[index] = data;
    arr->length++;
}

void dynamic_remove_index(struct DynamicArray *arr, int index)
{
    if (arr->length == 0 || index < 0 || index >= arr->length)
        return;
    int i;
    for (i = index; i < arr->length; i++)
    {
        arr->p_arr[i] = arr->p_arr[i + 1];
    }
    arr->length--;
}

void dynamic_remove_value(struct DynamicArray *arr, void *data, int (*dynamic_compare)(void *, void *))
{
    if (arr->length == 0)
        return;
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (dynamic_compare(arr->p_arr[i], data))
        {
            dynamic_remove_index(arr, i);
        }
    }
}

void dynamic_destroy(struct DynamicArray *arr)
{
    if (arr == NULL)
        return;
    int n = arr->length, i;
    for (i = 0; i < n; i++)
    {
        free(arr->p_arr[i]);
    }
    free(arr);
    arr = NULL;
}

void dynamic_print_data(void *data)
{
    // int *t = data;
    // printf("t=%d\n", *t);
    struct Person *p = data;
    printf("name=%s age=%d\n", p->name, p->age);
}

int dynamic_compare(void *info, void *data)
{
    struct Person *p = data;
    struct Person *p2 = info;
    if (p->name == p2->name)
    {
        return 1;
    }
    return 0;
}

void dynamic_foreach(struct DynamicArray *arr, void (*dynamic_print)(void *))
{
    if (arr == NULL)
        return;
    int i;
    for (i = 0; i < arr->length; i++)
    {
        dynamic_print(arr->p_arr[i]);
    }
}

int main(int argc, char const *argv[])
{

    struct DynamicArray *arr = dynamic_init(2);
    // int a = 1, b = 2, c = 3;
    // dynamic_insert_index(arr, &a, 0);
    // dynamic_insert_index(arr, &b, 1);
    // dynamic_insert_index(arr, &c, -1);
    struct Person p1 = {"asd", 10};
    struct Person p2 = {"dni", 55};
    struct Person p3 = {"ier", 44};
    dynamic_insert_index(arr, &p1, -1);
    dynamic_insert_index(arr, &p2, 3);
    dynamic_insert_index(arr, &p3, 3);
    // p1.age = 88;
    // dynamic_foreach(arr, dynamic_print_data);
    printf("删除前: %d\n", arr->length);
    // dynamic_remove_index(arr, 0);
    dynamic_remove_value(arr, &p3, dynamic_compare);
    printf("删除后: %d\n", arr->length);
    dynamic_foreach(arr, dynamic_print_data);
    dynamic_destroy(arr);
    printf("销毁后: %p\n", arr);
    return 0;
}
