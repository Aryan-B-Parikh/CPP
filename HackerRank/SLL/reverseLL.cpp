#include<iostream>
using namespace std;

struct node {
    int data;
    node* link;
};

node* createNode(int data) {
    node* temp = new node();
    temp->data = data;
    temp->link = NULL;
    return temp;
}

node* reverseRecursive(node* head) {

    if (head == NULL || head->link == NULL)
        return head;

    node* newHead = reverseRecursive(head->link);

    head->link->link = head;
    head->link = NULL;

    return newHead;
}

void printList(node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->link;
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;

    node* first = NULL;

    for (int i = 0; i < N; i++) {
        int data;
        cin >> data;
        node* temp = createNode(data);
        if (first == NULL) {
            first = temp;
        } else {
            node* trav = first;
            while (trav->link != NULL) {
                trav = trav->link;
            }
            trav->link = temp;
        }
    }

    first = reverseRecursive(first);
    printList(first);
}
