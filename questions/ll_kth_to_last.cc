#include<iostream>
#include <unordered_set>

using namespace std;

class Node {
  public:
    int data_;
    Node*  next_;
    Node(int data, Node* next) : data_(data), next_(next) {}
};

void PrintLinkedList(const Node* head) {
    while (head != nullptr) {
        cout << head->data_ << "->";
        head = head->next_;
    }
    cout << endl;
}

Node* kthToLastRecursive(Node* start, int k, int* i) {
    if (start == nullptr) {
        return nullptr;
    }
    Node* nd = kthToLastRecursive(start->next_, k, i);
    (*i)++;
    if (k == *i) {
        return start;
    }
    return nd;
}

Node* kthToLastIterative(Node* start, int k, int* i) {
    Node* ptr1 = start;
    Node* ptr2 = start;

    for (int i = 0; i < k; ++i) {
        if (ptr1 == nullptr) return nullptr;
        ptr1 = ptr1->next_;
    }
    while(ptr1 != nullptr) {
        ptr1 = ptr1->next_;
        ptr2 = ptr2->next_;
    }
    return ptr2;
}

int main() {
  Node n3 {3, nullptr};
  Node n2 {2, &n3};
  Node n1 {1, &n2};
  Node head {0, &n1};
  Node* current = &head;
  
  int i = 0;
  cout << kthToLastRecursive(current, 3, &i)->data_ << endl;
  cout << kthToLastIterative(current, 3, &i)->data_ << endl;

  return 0;
}