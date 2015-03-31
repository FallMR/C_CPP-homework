#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

struct Node{
    int SatelliteData;
    Node *next; 
};

Node *CreateList() {
    Node *head, *prev, *cur;
    bool flag = true;
    head = (Node *) malloc(sizeof(Node));
    prev = head;
    while (flag) {
        int x;
        printf("please input the data(0 to end): \n");
        scanf("%d", &x);
    	if (x != 0) {
            cur = (Node *)malloc(sizeof(Node));
            cur->SatelliteData = x;
            prev->next = cur;
            prev = cur;
        } else {
            flag = false;
        }
    }
    head = head->next;
    prev->next = NULL;
    return head;
}

void Insert(Node *head, int num, int data) {
    Node *cur = (Node *) malloc(sizeof(Node));
    cur->SatelliteData = data;
    Node *prev = head;
    int count = 1;
    while (count < num - 1) {
        prev = prev->next;
        count++;
    }
    Node *succ = prev->next;
    prev->next = cur;
    cur->next = succ;
}

void Delete(Node *head, int num) {
    Node *prev = head;
    int count = 1;
    while (count < num - 1) {
        prev = prev->next;
        count++;
    }
    Node *succ = prev->next->next;
    free(prev->next);
    prev->next = succ;
}

int GetLength(Node *head) {  
    int n = 0;
    Node *p;
    p = head;
    while(p!=NULL) {
        p=p->next;
        n++;
    }
    return n;
}

void PrintList(Node *head) {
    Node *p;
    int n;
    n = GetLength(head);
    printf("This List has %d records :\n",n);
    p = head;
    if(head != NULL) {
        while(p->next != NULL) {
            printf("%d ",p->SatelliteData);
            p = p->next;
        }
    }
    printf("%d\n", p->SatelliteData);
}

void ClearList(Node *head)
{
    if (head == NULL) exit; 
    Node *Next;
    while(head->next != NULL)
    {
        Next = head->next;
        free(head);
        head = Next;
    }
}
int main() {
    Node *List = CreateList();
    PrintList(List);
    Insert(List, 4, 3);
    Delete(List, 5);
    ClearList(List);
    PrintList(List);
    return 0;
}

