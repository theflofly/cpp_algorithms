#include<iostream>
#include <stack>

using namespace std;

class Node {
  public:
    int data_;
    Node*  next_;
    Node(int data, Node* next) : data_(data), next_(next) {}
};

void CleanMemory(Node* n) {
  if (n->next_ != nullptr) {
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

bool IsPalindromeRecursive(Node* head, int length, Node** back) {
    if (length == 0) {
      *back = head;
      return true;
    } else if (length == 1) {
      *back = head->next_;
      return true;
    }

    bool result = IsPalindromeRecursive(head->next_, length - 2, back);

    if (!result) return false;

    if (head->data_ == (*back)->data_) {
      *back = (*back)->next_;
      return true;
    } else {
      return false;
    }
}

bool IsPalindromeIterative(Node* head, int length) {
  Node* slow = head;
  Node* fast = head;
  stack<int> stack;

  while(fast != nullptr && fast->next_ != nullptr) {
    stack.push(slow->data_);
    slow = slow->next_;
    fast = fast->next_->next_;
  }

  if (fast != nullptr) {
    slow = slow->next_;
  }
  
  while (slow != nullptr) {
    if (stack.top() != slow->data_) {
      return false;
    }
    slow = slow->next_;
    stack.pop();
  }
  return true;
}

int main() {
  Node* n4 = new Node(1, nullptr);
  Node* n3 = new Node(2, n4);
  Node* n2 = new Node(0, n3);
  Node* n1 = new Node(2, n2);
  Node* head = new Node(1, n1);
  Node* back = new Node(-1, nullptr);
  cout << IsPalindromeRecursive(head, SizeLinkedList(head), &back) << endl;
  cout << IsPalindromeIterative(head, SizeLinkedList(head)) << endl;
  PrintLinkedList(head);
  CleanMemory(head);
  return 0;
}