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

void DeleteNode(Node* n) {
    if (n->next_ == nullptr) {
        cout << "Does not work with the last node." << endl;
    }
    Node* next = n->next_;
    n->data_ = next->data_;
    n->next_ = next->next_;
}

int main() {

  Node n3 {3, nullptr};
  Node n2 {2, &n3};
  Node n1 {1, &n2};
  Node head {0, &n1};
  Node* current = &head;

  PrintLinkedList(current);
  DeleteNode(&n2);
  PrintLinkedList(current);

  return 0;
}