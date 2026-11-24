
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

Node* insertAtFront(Node* head, int x)
{
    Node* newNode = new Node(x);
    newNode->next = head;

    return newNode;
}

Node* insertAtEnd(Node* head, int x)
{
    Node* newNode = new Node(x);

    if (head == nullptr)
    {
        return newNode;
    }

    Node* last = head;

    while (last->next != nullptr)
    {
        last = last->next;
    }

    last->next = newNode;

    return head;
}


Node* insertPos(Node* head, int pos, int val)
{
    if (pos < 1)
        return head;

    if (pos == 1)
    {
        Node* newNode = new Node(val);
        newNode->next = head;
        return newNode;
    }

    Node* curr = head;

    for (int i = 1; i < pos - 1 && curr != nullptr; i++)
    {
        curr = curr->next;
    }

    if (curr == nullptr)
        return head;

    Node* newNode = new Node(val);

    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}


void printList(Node* head)
{
    Node* curr = head;

    while (curr != nullptr)
    {
        cout << curr->data;

        if (curr->next != nullptr)
        {
            cout << " -> ";
        }

        curr = curr->next;
    }

    cout << endl;
}

int main()
{
    
    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);

    cout << "Original List: ";
    printList(head);


    head = insertAtFront(head, 1);
    cout << "After Insertion at Front: ";
    printList(head);

    
    head = insertAtEnd(head, 6);
    cout << "After Insertion at End: ";
    printList(head);

    
    int val = 10, pos = 3;
    head = insertPos(head, pos, val);
    cout << "After Insertion at Position "<< pos << ": ";
    printList(head);

    return 0;
}
