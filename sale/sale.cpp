#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

struct Item{
    string itemName;
    int itemNum;
    Item *next;
};

Item *CreateList() {
    Item *head, *prev, *cur;
    bool flag = true;
    head = new(Item);
    prev = head;
    while (flag) {
        int x;
        string s_name;
        cin >> s_name;
        cin >> x;
        if (s_name != "End") {
            cur = new(Item);
            cur->itemNum = x;
            cur->itemName = s_name;
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

void PrintList(Item *head) {
    Item *p = head;
    if(head != NULL) {
        while(p != NULL) {
            cout << p->itemName << " ";
            cout << p->itemNum << endl;
            p = p->next;
        }
    }
}

void ClearList(Item *head) {
    if (head != NULL) {
        Item *Next;
        while(head->next != NULL)
        {
            Next = head->next;
            free(head);
            head = Next;
        }
    }
}

void ChangeList(Item *head, string tarName, int delta) {
    Item *p = head;
    while (p != NULL) {
        if (p->itemName == tarName)
            break;
        p = p->next; 
    }
    p->itemNum += delta;
}

int main() {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    Item *List = CreateList();
    PrintList(List);
    ChangeList(List, "qwerty", 2);
    PrintList(List);
    return 0;
}

