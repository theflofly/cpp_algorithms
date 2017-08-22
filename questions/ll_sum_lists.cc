#include<iostream>
#include <unordered_set>

using namespace std;

class Node {
  public:
    int data_;
    Node*  next_;
    Node(int data, Node* next) : data_(data), next_(next) {}
};

class PartialSum {
  public:
    Node* previous_;
    int carry_;
    PartialSum(Node* previous, int carry) : previous_(previous), 
                                            carry_(carry) {}
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

Node* SumListLeftToRight(const Node* n1, const Node* n2, int carry) {
  if (n1 == nullptr && n2 == nullptr) {
    return nullptr;
  }
  int value = carry;
  if (n1 != nullptr) {
    value += n1->data_;
  }
  if (n2 != nullptr) {
    value += n2->data_;
  }
  Node* result = new Node(value % 10, 
      SumListLeftToRight(n1 != nullptr ? n1->next_ : nullptr, 
                         n2 != nullptr ? n2->next_ : nullptr, 
                         value >= 10));
  return result;
}

PartialSum SumListRightToLeftRecursive(const Node* n1, const Node* n2) {
  int sum = n1->data_ + n2->data_;
  if (n1->next_ == nullptr && n2->next_ == nullptr) {
    return PartialSum(new Node(sum % 10, nullptr), sum >= 10);
  }
  PartialSum psum = SumListRightToLeftRecursive(n1->next_, n2->next_);
  return PartialSum(new Node((sum + psum.carry_) % 10, 
                    psum.previous_), 
                    (sum + psum.carry_) >= 10);
}

int SizeLinkedList(const Node* n) {
  int i = 0;
  while(n != nullptr) {
    i++;
    n = n->next_;
  }
  return i;
}

void PadZeroes(Node*& n, int pad_size) {
  Node* pad = new Node(0, n);
  for (int i = 1; i < pad_size; ++i) {
    Node* pad1 = new Node(0, pad);
    pad = pad1;
  }
  n = pad;
}

Node* SumListRightToLeft(Node*& n1, Node*& n2) {

  int size_n1 = SizeLinkedList(n1);
  int size_n2 = SizeLinkedList(n2);
  
  if (size_n1 < size_n2) {
    PadZeroes(n1, size_n2 - size_n1);
  } else if (size_n1 > size_n2) {
    PadZeroes(n2, size_n1 - size_n2);
  }

  PartialSum psum = SumListRightToLeftRecursive(n1, n2);

  if (psum.carry_ == 1) {
    return new Node(1, psum.previous_);
  } else {
    return psum.previous_;
  }
}

int main() {
  Node* n2 = new Node(6, nullptr);
  Node* n1 = new Node(1, n2);
  Node* number_1 = new Node(7, n1);

  Node* n5 = new Node(0, nullptr);
  Node* n4 = new Node(2, nullptr);
  Node* n3 = new Node(9, n4);
  Node* number_2 = new Node(5, n3);

  Node* sumLeftToRight = SumListLeftToRight(number_1, number_2, 0);
  n4->next_ = n5;
  Node* sumRightToLeft = SumListRightToLeft(number_1, number_2);

  PrintLinkedList(sumLeftToRight);
  PrintLinkedList(sumRightToLeft);

  CleanMemory(number_1);
  CleanMemory(number_2);
  CleanMemory(sumLeftToRight);
  CleanMemory(sumRightToLeft);

  return 0;
}