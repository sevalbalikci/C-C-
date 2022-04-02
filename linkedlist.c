#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>


typedef struct _Person_
{
    char *name;
    int age;
    struct _Person_ *link;
} Person;

void count(Person *p)
{
    int count = 0;
    if (p == NULL)
    {
        printf("Linked list is empty");
    }
    else
    {
        Person *ptr = NULL;
        ptr = p;
        while (ptr != NULL)
        {
            count++;
            ptr = ptr->link;
        }
        printf("There are %d lists:\n", count); 
    }
}

Person* addEnd(Person *p, char *name, int age)
{
    Person *temp = (Person*)malloc(sizeof(Person));

    temp->name = name;
    temp->age = age;
    temp->link = NULL;

    p->link = temp;
    return temp;
}

Person* addBeg(Person *p, char *name, int age)
{
    Person *ptr = malloc(sizeof(Person));
    ptr->name = name;
    ptr->age = age;
    ptr->link = NULL;

    ptr->link = p;
    p = ptr;
    return p;
}

void freeList(Person *p)
{
    Person *ptr = NULL;
    ptr = p;
    while (ptr != NULL)
    {
        free(ptr);
        ptr = ptr->link;
    }
}

int main()
{
    Person *head = malloc(sizeof(Person));
    head->name = "Seval";
    head->age = 20;
    head->link  = NULL;

    int option = 0;
    printf("Please enter your option:\n1 for Begin - 2 for End\n");
    scanf("%d", &option);

    if (option == 1)
    {
        Person *ptr = malloc(sizeof(Person));
        ptr->name = "Eve";
        ptr->age = 68;
        ptr->link = NULL;

        head->link = ptr;
        head = addBeg(head, "Max", 70);
        ptr = head;
        count(ptr);

        while(ptr != NULL)
        {
            printf("Name:\t%s\t- Age:\t%d\n", ptr->name, ptr->age);
            ptr = ptr->link;
        }
    }
    else if (option == 2)
    {
        Person *ptr = head;
        ptr = addEnd(ptr, "Laura", 39);
        ptr = addEnd(ptr, "Anna", 41);
        ptr = addEnd(ptr, "Lisa", 12);
        ptr = head;
        count(ptr);

        while(ptr != NULL)
        {
            printf("Name:\t%s\t- Age:\t%d\n", ptr->name, ptr->age);
            ptr = ptr->link;
        }
    }

    freeList(head);
    return 0;
}


