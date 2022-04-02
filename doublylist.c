#include <stdio.h>
#include <stdlib.h>

typedef struct _Car_
{
    struct _Car_ *prev;
    int age;
    struct _Car_ *next;
} Car;

Car *addBeg(Car *head, int data)
{
    Car *temp = malloc(sizeof(Car));
    temp->prev = NULL;
    temp->age = data;
    temp->next = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}

Car *addEmpty(Car *head, int data)
{
    Car *temp = malloc(sizeof(Car));
    temp->prev = NULL;
    temp->age = data;
    temp->next = NULL;

    head = temp;
    return head;
}

Car *addEnd(Car *head, int data)
{
    Car *ptr, *temp;
    temp = malloc(sizeof(Car));
    temp->prev = NULL;
    temp->age = data;
    temp->next = NULL;

    ptr = head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
    return head;
}

int main()
{
    Car *head = NULL;
    head = addEmpty(head, 20);
    head = addEnd(head, 7);
    head = addBeg(head, 5);

    Car *ptr = head;
    while(ptr != NULL)
    {
        printf("%d\n", ptr->age);
        ptr = ptr->next;
    }
    return 0;
}