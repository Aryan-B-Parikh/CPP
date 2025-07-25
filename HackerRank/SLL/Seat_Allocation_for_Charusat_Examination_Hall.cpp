#include <iostream>
using namespace std;

int swapcount = 0;
int comparecount = 0;

struct node {
    int data;
    node *link;
};

node *first = NULL;

node *createNode(int data) {
    node *temp = new node();
    temp->data = data;
    temp->link = NULL;
    return temp;
}

void sort() {
    if (!first) return;
    bool swapped;
    node *end = NULL;
    do {
        swapped = false;
        node *current = first;
        while (current->link != end) {
            ++comparecount;
            if (current->data > current->link->data) {
                int temp = current->data;
                current->data = current->link->data;
                current->link->data = temp;
                ++swapcount;
                swapped = true;
            }
            current = current->link;
        }
        end = current;
    } while (swapped);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        node *newNode = createNode(data);
        if (first == NULL) {
            first = newNode;
        } else {
            node *temp = first;
            while (temp->link != NULL) {
                temp = temp->link;
            }
            temp->link = newNode;
        }
    }
    sort();
    cout << comparecount << endl;
    cout << swapcount << endl;
    node *temp = first;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->link;
    }
    cout << endl;
}