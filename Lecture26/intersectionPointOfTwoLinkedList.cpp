// #include <bits/stdc++.h>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     Node(int d)
//     {
//         data = d;
//         next = NULL;
//     }
// };

Node *intersectionOfTwoLinkedLists(Node *l1, Node *l2)
{
    if (l1 == NULL || l2 == NULL)
        return NULL;

    Node *a = l1;
    Node *b = l2;

    while (a != b)
    {
        a = a == NULL ? l1 : a->next;
        b = b == NULL ? l2 : b->next;
    }

    return a;
}

// Node *buildList(unordered_map<int, Node *> &hash)
// {
//     int x;
//     cin >> x;
//     Node *head = new Node(x);
//     Node *current = head;
//     hash[x] = head;
//     while (x != -1)
//     {
//         cin >> x;
//         if (x == -1)
//             break;
//         Node *n = new Node(x);
//         hash[x] = n;
//         current->next = n;
//         current = n;
//     }
//     current->next = NULL;
//     return head;
// }

// void printLinkedList(Node *head)
// {
//     while (head != NULL)
//     {
//         cout << head->data << " ";
//         head = head->next;
//     }
//     cout << endl;
// }

// int main()
// {
//     unordered_map<int, Node *> hash;
//     Node *l1 = buildList(hash);

//     Node *l2 = NULL;
//     int x;
//     cin >> x;
//     l2 = new Node(x);
//     Node *temp = l2;

//     while (x != -1)
//     {
//         cin >> x;
//         if (x == -1)
//             break;
//         if (hash.find(x) != hash.end())
//         {
//             temp->next = hash[x];
//             break;
//         }
//         Node *n = new Node(x);
//         temp->next = n;
//         temp = n;
//     }

//     cout << "L1 - ";
//     printLinkedList(l1);
//     cout << "L2 - ";
//     printLinkedList(l2);

//     Node *intersectionPoint = intersectionOfTwoLinkedLists(l1, l2);
//     cout << "Intersection at node with data = " << intersectionPoint->data << endl;

//     return 0;
// }