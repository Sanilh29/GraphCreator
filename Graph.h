#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <iostream>
#include "Node.h"

using namespace std;

class Graph{
 private:
  vector<Node*> nodes;
  Node* nodeSearch(char data);
  
 public:
  void addEdge(char data1, char data2, int newWeight);
  void addVertex(char data);
  void removeVertex(char data);
  void removeEdge(char data1, char data2);
  void print();
  void findPath(char data1, char data2);

};

#endif
