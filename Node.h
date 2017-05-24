#include <vector>
#include <iostream>

using namespace std;

struct Link;

class Node{
 private:
  vector<Link> links;
 public:
  vector<Link*> getLinks();
  Node(char newName);
  char name;
  bool remove(Node* toRemove);
  bool add(Node* toAdd, int newWeight);
  void print();
};

struct Link{
  int weight;
  Node* next;
  Node* last;
};
