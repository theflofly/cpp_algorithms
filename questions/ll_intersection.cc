#include<iostream>
#include <stack>

using namespace std;

class Node {
  public:
    ~Node() {};
    int data_;
    Node*  next_;
    Node(int data, Node* next) : data_(data), next_(next) {}
};

void CleanMemory(Node* n) {
  if (n != nullptr) {
    CleanMemory(n->next_);
  }
  delete n;
}

void PrintLinkedList(const Node* head) {
  while (head != nullptr) {
    cout << head->data_ << "->";
    head = head->next_;
  }
  cout << endl;
}

int SizeLinkedList(const Node* n) {
  int i = 0;
  while(n != nullptr) {
    i++;
    n = n->next_;
  }
  return i;
}

const Node* ContainsIntersection(const Node* n1, const Node* n2) {
    int size_n1 = SizeLinkedList(n1);
    int size_n2 = SizeLinkedList(n2);
    if (size_n1 < size_n2) {
        for (int i = 0; i < size_n2 - size_n1; ++i) {
            n2 = n2->next_;
        }
    } else if (size_n1 > size_n2) {
        for (int i = 0; i < size_n1 - size_n2; ++i) {
            n1 = n1->next_;
        }
    }
    while (n1 != nullptr) {
        if (n1 == n2) {
            return n1;
        }
        n1 = n1->next_;
        n2 = n2->next_;
    }
    return n1;
}

int main() {
  Node* n4 = new Node(5, nullptr);
  Node* n3 = new Node(4, n4);
  Node* n2 = new Node(3, n3);
  Node* n1 = new Node(2, n2);
  Node* head1 = new Node(1, n1);

  Node* n8 = new Node(14, n3);
  Node* n7 = new Node(13, n8);
  Node* n6 = new Node(12, n7);
  Node* n5 = new Node(11, n6);
  Node* head2 = new Node(10, n5);

  PrintLinkedList(head1);
  PrintLinkedList(head2);
  cout << ContainsIntersection(head1, head2)->data_ << endl;

  n8->next_ = nullptr;
  
  CleanMemory(head1);
  CleanMemory(head2);
  return 0;
}