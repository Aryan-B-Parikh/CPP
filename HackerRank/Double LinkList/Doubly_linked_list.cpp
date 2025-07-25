#include<iostream>
using namespace std;

struct node {
    int data;
    node* previous;
    node* next;
};

node* first=NULL;

node* createNode(int data) {
    node* temp = new node();
    temp->data = data;
    temp->previous = NULL;
    temp->next = NULL;
    return temp;
}

void insertEnd(int data) {
    node* newNode = createNode(data);
    if (first == NULL) {
        first = newNode;
    } else {
        node* temp = first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->previous = temp;
    }
}

void insertFront(int data) {
    node* newNode = createNode(data);
    if (first == NULL) {
        first = newNode;
    } else {
        newNode->next = first;
        first->previous = newNode;
        first = newNode;
    }
}

void insertAfter(int after, int data)
{
    node* trav = first;
    node* temp = createNode(data);
    if (first == NULL) {
        first = temp;
        return;
    } else {
        while (trav != NULL && trav->data != after) {
            trav = trav->next;
        }
        if (trav != NULL) {
            temp->next = trav->next;
            temp->previous = trav;
            if (trav->next != NULL) {
                trav->next->previous = temp;
            }
            trav->next = temp;
        }
    }
}

void deleteFront(){
    if (first == NULL) {
        cout << "List is Empty" << endl;
        return;
    }
    node* temp = first;
    first = first->next;
    if (first != NULL) {
        first->previous = NULL;
    }
    delete temp;
}

void deleteLast() {
    if (first == NULL) {
        cout << "List is Empty" << endl;
        return;
    }
    if (first->next == NULL) {
        delete first;
        first = NULL;
        return;
    }
    node* temp = first;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->previous->next = NULL;
    delete temp;
}

void display(){
    node* temp = first;
    if (temp == NULL) {
        cout << "List is Empty" << endl;
        return;
    }
    else{
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void countNodes() {
    node* temp = first;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    cout << count << endl;
}

int main()
{
    int choice;
    int data, after;
    do {
        cin >> choice;
        switch (choice) {
             case 1:
                cin >> data;
                insertFront(data);
                break;

            case 2:
                cin >> data;
                insertEnd(data);
                break;
           
            

            case 3:
                deleteFront();
                break;

            case 4:
                deleteLast();
                break;

            case 5:
                cin >> after;
                cin >> data;
                insertAfter(after, data);
                break;

            case 6:
                display();
                break;

            case 7:
                countNodes();
                break;
                
            case 0:
                break;
        }
    } while (choice != 0);
}