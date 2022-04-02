#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Square(x) x*x
struct site
{
    char name[20];
};

typedef struct _Student_ {
  char stud_id_[9];
  int grade_;
  struct _Student_ *next_student;
} Student;

typedef struct Strings
{
//    char *strg;
    int size;
    struct Strings *link;
} String;

typedef struct Double
{
    struct Double *prev;
    int data;
    struct Double *next;
} Double;

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

void desOrd(int arr[], int len)
{
    int new[len];
    for (int i = 0; i < len; i++)
    {
        for (int j = 1; j < len; j++)
        {
            if (arr[i] < arr[j])
            {
                new[i] = arr[i];
            }
            else
            {
                new[i] = arr[j];
            }   
        }
    }
    for (int i = 0; i<len; i++)
    {
        printf("%d", new[i]);
    }
}

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

void delLastN(String **head)
{
    String *prev, *ptr = *head;
    while (ptr->link != NULL)
    {
        prev = ptr;
        ptr = ptr->link;
    }
    if(ptr == *head)
    {
        *head = NULL;
    }
    else
    {
        prev->link = NULL;
    }
    
    free(ptr);
    
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

void triangle(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= i; k++)
        {
            printf("*");
        }
        printf("\n");        
    }
}

void crf()
{
    FILE *fp = fopen("text.txt", "w+");
    fseek(fp, 0, SEEK_SET);
    char str[] = "The file test.txt created success\n";
    fwrite(str, 1, sizeof(str), fp);

    for (int i = 0; i < 4; i++)
    {
        fprintf(fp, "Test line %d\n", i);
    }
    fseek(fp, 0L, SEEK_END);
    char string[] = "Hallo\n";
    fwrite(string, 1, sizeof(string), fp);

    fseek(fp, 0, SEEK_SET);
    int c;
    int cnt = 0;
    int snt = 0;
    int k = 10;
    while(1)
    {
        c = fgetc(fp);
        if (c == k)
        {
            cnt++;
        }
        if (c == ' ' || c == '\n')
        {
            snt++;
        }
        if (feof(fp)){
            break;
        }
        printf("%c", c);
    }
    printf("There are %d lines\n", cnt);
    printf("There are %d words\n", snt);
    char ch;

    fseek(fp, 0, SEEK_SET);
    FILE *fp2 = fopen("test2.txt", "w+");

    while((ch = fgetc(fp)) != EOF)
    {
        fputc(ch, fp2);
    }

    fseek(fp, 0, SEEK_SET);
    fseek(fp2, 0, SEEK_SET);

    FILE *mf = fopen("merge.txt", "w+");
    if (mf == NULL)
        return;

    char ch3, ch2;

    while ((ch2 = fgetc(fp)) != EOF)
    {
        fputc(ch2, mf);
    }
    fseek(mf, 0L, SEEK_END);

    while ((ch3 = fgetc(fp2)) != EOF)
    {
        fputc(ch3, mf);
    }

    fclose(mf);
    fclose(fp2);
    fclose(fp);

    int del = remove("merge.txt");
    if (!del)
        printf("File deleted");
    else
        printf("File not deleeted");
}

int revInt(int q)
{
    int rem, res = 0;;
    while (q != 0)
    {
        rem = q % 10;
        res = res * 10 + rem;
        q = q / 10;
    }
    return res;
}

void add_student(Student **head, Student *stud)
{
    if (*head == NULL)
    {
        *head = stud;
        return;
    }
    stud = malloc(sizeof(Student));
    Student *ptr = *head;
    while (ptr->next_student != NULL)
    {
        ptr = ptr->next_student;
    }
    ptr->next_student = stud;
    stud->next_student = NULL;
}

int fo(char *str)
{
    char *tp = str;
    while(*++str);
    return (str - tp);
}

void lsb(int inp)
{
    if (inp & 1)
    {
        printf("%d & 1 = 1\n", inp);
    }
    else
    {
        printf("%d & 1 = 0\n", inp);
    }
}

void msb(int inp)
{
    int bits = sizeof(int) * 8;
    int msb = 1 << (bits - 1);

    if (msb & inp)
    {
        printf("MSB is set 1\n");
    }
    else
    {
        printf("MSB is set 0\n");
    }
}

void nthBit(int num, int n)
{
    int x = (num >> n) & 1;
    printf("the bit Status = %d\n", x);
}

void setnthBit(int num, int n)
{
    int x = 1 << n;
    int set = num | x;
    printf("Number after setting nth bit: %d in decimal\n", set);
}

void clBit(int num, int n)
{
    int x = 1 << n;
    int a = x & num;
    int b = x ^ num;
    if (a == 0)
    {
        printf("Already 0\n");
    }
    else
    {
        printf("Cleared bit = %d\n", b);
    }
}

void toggle(int num, int n)
{
    int x = 1 << n;
    int a = x ^ num;
    printf("After toggling nth bit: %d in dec\n", a);
}

void highset(int num)
{
    int size = sizeof(int) * 8;
    int i, order = -1;
    for (i = 0; i < size; i++)
    {
        if ((num >> i) & 1)
        {
            order = i;
        }
    }
    if (order != -1)
        printf("Highest order set bit in %d is %d\n", num, order);
    else 
        printf("0 has no set bits.\n");
}

void cntZeros(int inp)
{
    int cnt = 0;
    int bits = sizeof(int) * 8;
    for (int i = 0; i < bits; i++)
    {
        if((inp >> i) & 1)
        {
            break;
        }
        cnt++;
    }
    printf("Trailing zeros: %d\n", cnt);
}

void cntLeadZero(int inp)
{
    int bits = sizeof(int) * 8;
    int cnt = 0;
    int msb = 1 << (bits - 1);
    for (int i = 0; i < bits; i++)
    {
        if ((inp << i) & msb)
        {
            break;
        }
        cnt++;
    }
    printf("Leading zeros: %d\n", cnt);
}

void flipBits(int inp)
{
    int flip = ~inp;
    printf("Flipped version: %d\n", flip);
}

void rotateRight(int num, int rot)
{
    int bits = sizeof(int) * 8;
    int inp = num;
    int msb;
    rot %= bits;
    while(rot--)
    {
        msb = (num >> bits) & 1;
        num = (num << 1) | msb;
    }
    printf("%d right rotated %u times = %d\n", inp, rot, num);  
}


int main()
{
    int input;
    printf("Input any number: ");
    scanf("%d", &input);
    lsb(input);
    msb(input);
    int n;
    printf("Input number: ");
    scanf("%d", &n);
    nthBit(input, n);
    setnthBit(input, n);
    clBit(input, n);
    toggle(input, n);
    highset(input);
    cntZeros(input);
    cntLeadZero(input);
    flipBits(input);
    rotateRight(input, n);
    return 0;
}
