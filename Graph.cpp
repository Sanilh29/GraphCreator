#include <cstring>
#include <vector>
#include <iostream>
#include "Graph.h"

using namespace std;

void Graph::addEdge(char data1, char data2, int newWeight){
  Node* node1 = nodeSearch(data1);
  Node* node2 = nodeSearch(data2);
  if (node1 != NULL && node2 != NULL){
    node1->add(node2, newWeight);
  }
}

void Graph::addVertex (char data){
  bool isVertex = false;
  for (vector<Node*>::iterator it=nodes.begin(); it!=nodes.end(); it++){
    if ((*it)->name == data){
      isVertex = true;
    }
  }
  if (isVertex== false) {
    Node* node = new Node(data);
    nodes.push_back(node);
    //cout << "hi" << endl;
  }
}

void Graph::removeVertex(char data){
  Node* node = nodeSearch(data);
  if (node != NULL){
    for (vector<Node*>::iterator it=nodes.begin(); it!= nodes.end(); it++){
      node->remove((*it));
    }
    for (vector<Node*>::iterator it=nodes.begin(); it!=nodes.end();it++){
      if (node->name == data){
	nodes.erase(it);
      }
    }
  }
}

void Graph::removeEdge(char data1, char data2){
  Node* node1 = nodeSearch(data1);
  Node* node2 = nodeSearch(data2);
  if (node1 != NULL && node2 != NULL){
    node1->remove(node2);
  }
}

Node* Graph::nodeSearch(char data){
  for (vector<Node*>::iterator it=nodes.begin(); it!=nodes.end(); it++){
    if ((*it)->name == data){
      return *it;
    }
  }
    return NULL;
}

void Graph::print(){
  for(vector<Node*>::iterator it=nodes.begin(); it!=nodes.end(); it++){
    (*it)->print();
  }
}

