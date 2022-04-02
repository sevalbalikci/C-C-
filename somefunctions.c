// Framework
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myframe.h"

// Merges two arrays into one.
void concatArrays(int *num1, int len1, int *num2, int len2)
{
  int sum = len1 + len2;
  int len11 = len1 / sizeof(int);
  int len22 = len2 / sizeof(int);
  int lensum = sum / sizeof(sum);
  num1 = realloc(num1, sum);
  if (num1 == NULL)
  {
    printf("Memory allocation failed.");
    return;
  }
  int i, j;
  for (i = len11, j = 0; i < lensum; i++, j++)
  {
    num1[i] = num2[j];
  }
  for (j = 0; j < lensum; j++)
  {
    printf("%d ", num1[j]);
  }
  free(num1);
}

void revOrd(char *input, char *rev)
{
  int i, end = 0;
  int len = strlen(input);

  end = len - 1;
  for (i = 0; i < len; i++)
  {
    rev[i] = input[end];
    end--;
  }
  rev[i] = '\0';
}

int compareStrings(char *input, char *rev)
{
  int result = 1;
  while (*input != '\0' || *rev != '\0')
  {
    if (*input == *rev)
    {
      input++;
      rev++;
    }
    else if ((*input == '\0' && *rev != '\0') || (*input != '\0' && *rev == '\0') || (*input != *rev))
    {
      result = 0;
      return result;
    }
  }
  return result;
}

bool isPalindrome(int x)
{
  int a = sizeof(x)/sizeof(int);
  int i;
  int arra[a];
  int ar[a];

  for (i = a - 1; i >= 0; i--)
  {
    arra[i] = x % 10;
    x /= 10;
  }

  for (i = 0; i < a; i++)
  {
    ar[i] = arra[a - i];
  }

  for (i = 0; i < a; i++)
  {
    if (ar[i] != arra[i])
    {
      return false;
    }
  }
  return true;
}

int intLength(int input)
{
  int len = 0;
  while (input != 0)
  {
    input /= 10;
    len++;
  }
  return len;
}

int armstrongNum(int input)
{
  int count = intLength(input);
  int mul, rem,  cnt = count;
  int result = 0;
  while (input != 0)
  {
    rem = input % 10;
    while (cnt != 0)
    {
      mul = mul * rem;
      cnt--;
    }
    result = result + mul;
    cnt = count;
    input = input / 10;
    mul = 1;
  }
  return result;
}

int revInt(int *a)
{
  int result = 0;
  int number = *a;
  int q = number;
  while (q != 0)
  {
    int remainder = q % 10;
    result = result * 10 + remainder;
    q = q / 10;
  }
  return result;
}

int intNegExpo(int* exponent, int* base)
{
  double power = 1.0;
  while (exponent != 0)
  {
    power = power * (1.0/(*base));
    exponent++;
  }
  return power;
}

int intPosExpo(int* exponent, int* base)
{
  int power = 1;
  if (exponent > 0)
  {
    while (exponent != 0)
    {
      power = power * *(base);
      exponent--;
    }
    return power;
  }
}

int fact(int num)
{
  int q = num;
  int fac = 1;
  int res = 0;

  while (q != 0)
  {
    int rem = q % 10;
    for (int i = 1; i <= rem; i++)
    {
      fac = fac * i;
    }
    res = res + fac;
    fac = 1;
    q = q / 10;
  }
  return res;
}

bool isLeapYear(int* year)
{
  if ((*year % 400) == 0)
  {
    return true;
  }
  else if ((*year % 100) == 0)
  {
    return false;
  }
  else if ((*year % 4) == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int revIntArray(int *arr, int len)
{
  int i;
  int new[len];
  for (i = len - 1; i >= 0; i--)
  {
    new[i] = arr[i];
  }
  return *new;
}

void printEvenOdd(int ar[], int len)
{
    int ev[10];
    int od[10];
    int  j, k = 0;
    for (int i = 0; i < len; i++)
    {
        if (ar[i] % 2 == 0)
        {
            ev[j] = ar[i];
            j++;
        }
        else if (ar[i] % 2 == 1)
        {
            od[k] = ar[i];
            k++;
        }
    }
    for (int i = 0; i < k; i++)
    {
        printf("%d ", od[i]);
    }    
    printf("\n");

    for (int i = 0; i < j; i++)
    {
        printf("%d ", ev[i]);
    }
}

typedef struct string
{
    int size;
    struct string *link;
} String;

void list(String **head, int data)
{
    String *temp = malloc(sizeof(String));
    temp->size = data;
    temp->link = NULL;
    *head = temp;
}

void addBeg(String **head, int data)
{
    String *temp = malloc(sizeof(String));
    temp->size = data;
    temp->link = NULL;
    temp->link = *head;
    *head = temp;
}

void addEnd(String **head, int data)
{
    String *temp = malloc(sizeof(String));
    temp->size = data;
    temp->link = NULL;

    String *ptr = *head;
    while(ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
}

void addMidd(String **head, int data)
{
    String *ptr, *ptr2 = *head;
    int cnt = 0;
    while (ptr != NULL)
    {
        ++cnt;
        ptr = ptr->link;
    }
    int pos = cnt / 2;
    int next = pos + 1;
    ptr = *head;

    pos--;
    while (pos)
    {
        ptr = ptr->link;
        pos--;
    }
    next--;
    while (next)
    {
        ptr2 = ptr2->link;
        next--;
    }
    String *temp = malloc(sizeof(String));
    temp->size = data;
    temp->link = ptr2;
    ptr->link = temp;
}

void printList(String **head)
{
    String *ptr = *head;
    int cnt = 1;
    
    if (ptr == NULL)
    {
        printf("No list");
        return;
    }
    while(ptr != NULL)
    {
        printf("The element %d is in %d\n", ptr->size, cnt);
        cnt++;
        ptr = ptr->link;
    }
}

void countNodes(String **head)
{
    String *ptr = *head;
    if (ptr == NULL)
    {
        printf("No list");
        return;
    }
    int cnt = 0;
    while(ptr != NULL)
    {
        ++cnt;
        ptr = ptr->link;
    }
    printf("\n");
    printf("Total numb of nodes = %d\n", cnt);
}

void delList(String **head)
{
    String *ptr = *head;
    if (ptr == NULL)
    {
        printf("No list");
        return;
    }
    while (ptr != NULL)
    {
        ptr = ptr->link;
        free(head);
        *head = ptr;
    }
    ptr = NULL;
    *head = NULL;
}

void delFrstN(String **head)
{
    String *ptr = *head;
    if (ptr == NULL)
    {
        printf("No list");
        return;
    }
    *head = ptr->link;
    free(ptr);
    ptr = NULL;
}

void delPos(String **head, int pos)
{
    String *ptr, *ptr2 = *head;
    int cnt = 0;
    while (ptr != NULL)
    {
        ++cnt;
        ptr = ptr->link;
    }

    ptr = *head;
    if (*head == NULL)
    {
        printf("No List");
    }
    else if (pos == 1)
    {
        *head = ptr->link;
        free(ptr);
        ptr = NULL;
    }
    else
    {
        while (pos != 1)
        {
            ptr2 = ptr;
            ptr = ptr->link;
            pos--;
        }
        ptr2->link = ptr->link;
        free(ptr);
        ptr->link = NULL;
    }   
}

void findElem(String **head, int elem)
{
    String *ptr = *head;
    int cnt = 0;
    while (ptr != NULL)
    {
        ++cnt;
        if (ptr->size == elem)
        {
            printf("Element found at node %d\n", cnt);
            return;
        }
        ptr = ptr->link;
    }
    printf("Element couldn't be found");
}

typedef struct Double
{
    int data;
    struct Double *prev;
    struct Double *next;
} Double;

void addEmptyDlist(Double **head, int data)
{
    Double *temp = malloc(sizeof(Double));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    *head = temp;
}

void addEndDlist(Double **head, int data)
{
    Double *temp = malloc(sizeof(Double));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;

    Double *ptr = *head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
    
}

void printDList(Double **head)
{
    Double *ptr = *head;
    int cnt = 0;
    while (ptr != NULL)
    {
        ++cnt;
        printf("The element %d is in %d\n", ptr->data, cnt);
        ptr = ptr->next;
    }
}

void printRevD(Double **head)
{
    Double *ptr = *head;
    int cnt = 1;
    while (ptr->next != NULL)
    {
        ++cnt;
        ptr = ptr->next;
    }

    while (ptr != NULL)
    {
        printf("The element %d is in %d\n", ptr->data, cnt);
        cnt--;
        ptr = ptr->prev;
    }
}

void addBegD(Double **head, int data)
{
    Double *temp = malloc(sizeof(Double));
    temp->data = data;
    temp->next = *head;
    temp->prev = NULL;
    (*head)->prev = temp;
    *head = temp;
}

void addEndD(Double **head, int data)
{
    Double *temp = malloc(sizeof(Double));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;

    Double *ptr = *head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
}

void addPosD(Double **head, int data, int pos)
{
    Double *temp = malloc(sizeof(Double));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;

    Double *ptr = *head;
    int i = 1;
    while (i < pos-1 && ptr != NULL)
    {
        ptr = ptr->next;
        i++;
    }

    temp->next = ptr->next;
    temp->prev = ptr;
    ptr->next->prev = temp;
    ptr->next = temp;
}

void delBegD(Double **head)
{
    Double *ptr = *head;
    *head = ptr->next;
    ptr->next->prev = NULL;
    free(ptr);
    ptr = NULL;
}

void delEndD(Double **head)
{
    Double *ptr = *head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    ptr->prev = NULL;
    free(ptr);
    ptr = NULL;
}

void delPosD(Double **head, int pos)
{
    Double *ptr = *head;
    int i = 0;
    while (i < pos-1 && ptr != NULL)
    {
        ptr = ptr->next;
        i++;
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    ptr->next = NULL;
    ptr->prev = NULL;
    free(ptr);
    ptr = NULL;
}

void findMaxD(Double **head)
{
    Double *ptr = *head;
    int max, min = ptr->data;

    while (ptr != NULL)
    {
        if (max < ptr->data)
        {
            max = ptr->data;
        }
        else if (min > ptr->data)
        {
            min = ptr->data;
        }
        ptr = ptr->next;
    }
    printf("\nMAx: %d Min; %d ", max, min);
}

void cubeNum(int num)
{
    int cu = 0;
    for (int i = 1; i <= num; i++)
    {
        cu = i * (i * i);
        printf("%d and cube is %d\n", i, cu);
    }
}

void multTable(int num)
{
    for (int i = 1; i <= 10; i++)
    {
        int sum = num * i;
        printf("%d x %d = %d\n", num, i, sum);
    }
}

void multVert(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            int sum = i * j;
            printf("%d x %d = %d\n ", i, j, sum);
        }
        
    }
}
