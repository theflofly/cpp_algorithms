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

int main() {
  Node n4 {4, nullptr};
  Node n3 {3, &n4};
  Node n2 {3, &n3};
  Node n1 {2, &n2};
  Node head {1, &n1};
  Node* current = &head;

  unordered_set<int> existing_values = {};
  while (current->next_ != nullptr) {
    auto search = existing_values.find(current->next_->data_);
    if (search != existing_values.end()) {
        current->next_ = current->next_->next_;
    }
    existing_values.insert(current->next_->data_);
    current = current->next_;
  }

  PrintLinkedList(&head);
}