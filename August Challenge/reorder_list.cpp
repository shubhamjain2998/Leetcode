#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class LinkedList
{
public:
    ListNode *head;
    ListNode *tail;

    LinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data)
    {
        ListNode *node = new ListNode(node_data);

        if (!this->head)
        {
            this->head = node;
        }
        else
        {
            this->tail->next = node;
        }
        this->tail = node;
    }
};

void freeLinkedList(ListNode *Node)
{
    while (Node)
    {
        ListNode *temp = Node;
        Node = Node->next;
        free(temp);
    }
}

void printLinkedList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (head == nullptr)
            return;
        ListNode *prev, *tail, *temp, *curr;
        curr = head;
        while (curr->next != NULL)
        {
            prev = curr;
            while (prev->next->next != NULL)
            {
                prev = prev->next;
            }
            if (curr == prev)
                break;
            tail = prev->next;
            temp = curr->next;
            curr->next = tail;
            curr = temp;
            tail->next = curr;
            tail = prev;
            tail->next = NULL;
        }
    }
};

int main()
{
    int numOfInputs, input;
    cin >> numOfInputs;
    LinkedList *llist = new LinkedList();
    Solution *sol = new Solution();
    for (int i = 0; i < numOfInputs; i++)
    {
        cin >> input;
        llist->insert_node(input);
    }
    printLinkedList(llist->head);
    sol->reorderList(llist->head);
    printLinkedList(llist->head);
    freeLinkedList(llist->head);
    delete llist;
    delete sol;
    return 0;
}