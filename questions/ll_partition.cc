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

void Partition(Node*& head, int p) {
  // before contains the list before the pivot p
  // after contains the list after the pivot p
  // we keep pointers to the start and the end in order
  // to merge both lists at the end
  Node* before_start = nullptr;
  Node* before_end = nullptr;
  Node* after_start = nullptr;
  Node* after_end = nullptr;

  while (head != nullptr) {
    Node* next = head->next_;
    head->next_ = nullptr;
    if (head->data_ < p) {
      if (before_start == nullptr) {
        before_start = head;
        before_end = head;
      } else {
        before_end->next_ = head;
        before_end = head;
      }
    } else {
      if (after_start == nullptr) {
        after_start = head;
        after_end = head;
      } else {
        after_end->next_ = head;
        after_end = head;
      }
    }
    head = next;
  }
  head = before_start;
  before_end->next_ = after_start;
}

int main() {
  Node n3 {0, nullptr};
  Node n2 {1, &n3};
  Node n1 {2, &n2};
  Node head {3, &n1};
  Node* current = &head;
  PrintLinkedList(current);
  Partition(current, 1);
  PrintLinkedList(current);
  return 0;
}