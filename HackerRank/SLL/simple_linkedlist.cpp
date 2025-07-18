#include<iostream>
using namespace std;

struct node {
    int data;
    node* link;
};

node* first=NULL;

node* createNode(int data) {
    node* temp = new node();
    temp->data = data;
    temp->link = NULL;
    return temp;
}

void insertEnd(int data) {
    node* newNode = createNode(data);
    if (first == NULL) {
        first = newNode;
    } else {
        node* temp = first;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

void insertFront(int data) {
    node* newNode = createNode(data);
     if (first == NULL) {
        first = newNode;
    } 
    else {
        newNode->link = first;
        first = newNode;
    }
}

void insertAfter(int after, int data)
{
    node* trav= first;
    node* temp= createNode(data);
    if (first == NULL) {
        first = temp;
        return;
    }
    else{
        while(trav != NULL && trav->data != after) {
            trav = trav->link;
        }
        temp->link = trav->link;
        trav->link = temp;
    }
}

void deleteFront(){
    if (first == NULL) {
        cout << "List is Empty" << endl;
        return;
    }
    node* temp = first;
    first = first->link;
    delete temp;
}

void deleteLast() {
    if (first == NULL) {
        cout << "List is Empty" << endl;
        return;
    }
    if (first->link == NULL) {
        delete first;
        first = NULL;
        return;
    }
    node* temp = first;
    while (temp->link->link != NULL) {
        temp = temp->link;
    }
    delete temp->link;
    temp->link = NULL;
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
        temp = temp->link;
        }
        cout << endl;
    }
}

int main()
{
    int choice;
    int data, after;
    do {
        cin >> choice;
        switch (choice) {
            case 2:
                cin >> data;
                insertEnd(data);
                break;
            case 1:
                cin >> data;
                insertFront(data);
                break;
            case 3:
                cin >> after;
                cin >> data;
                insertAfter(after, data);
                break;
            case 4:
                deleteFront();
                break;
            case 5:
                deleteLast();
                break;
            case 6:
                display();
                break;
            case 0:
                break;
        }
    } while (choice != 0);
}