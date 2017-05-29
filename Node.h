//Sanil Hattangadi, node header that contains the creation of methods and variables
#include <vector>
#include <iostream>

using namespace std;

struct Link;

class Node{
 private:
  //variables
  vector<Link> links;//creating vector
 public:
  //method
  vector<Link*> getLinks();//gets the links between vertexs
  Node(char newName);//constructor
  char name;
  bool remove(Node* toRemove);//removes vertex
  bool add(Node* toAdd, int newWeight);//adds vectex
  void print();//prints it out
};

struct Link{//gives link the qualities of weight, next, and last
  int weight;
  Node* next;
  Node* last;
};
