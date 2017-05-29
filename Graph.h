//Sanil Hattangadi, creates the variables and methods for the graph.cpp
#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <iostream>
#include "Node.h"

using namespace std;

class Graph{
 private:
  //variables i need
  vector<Node*> nodes;
  Node* nodeSearch(char data);
 public:
  //methods i need
  void addEdge(char data1, char data2, int newWeight);
  void addVertex(char data);
  void removeVertex(char data);
  void removeEdge(char data1, char data2);
  void print();
  void findPath(char data1, char data2);

};

#endif
