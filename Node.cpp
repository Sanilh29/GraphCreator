#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

Node::Node(char newName){
  name = newName;
}

bool Node::remove(Node* toRemove){
  for (vector<Link>::iterator it =links.begin();it !=links.end(); it++){
    if((*it).next == toRemove){
      links.erase(it);
      return true;
    }
  }
  return false;
}

bool Node::add(Node* toAdd, int newWeight){
  bool linkExists = false;
  if(toAdd == this){
    cout << "You can't link your node to itself." << endl;
    return false;
  }
  for (vector<Link>::iterator it =links.begin(); it !=links.end(); it++){
    if((*it).next ==toAdd){
      linkExists = true;
      break;
    }
  }
  if (!linkExists){
    Link newLink;
    newLink.weight = newWeight;
    newLink.next = toAdd;
    newLink.last = this;
    links.push_back(newLink);
    return true;
  }
  else {
    cout << "There already is a connection between " << name << "and " << toAdd->name << endl;
  }
}

void Node::print(){
  bool noLinks = true;
  cout << name  << "::";

  for (vector<Link>:: iterator it= links.begin(); it != links.end(); it++){
    cout << (*it).next->name << ":" << (*it).weight;
    noLinks = false;
  }
  if (noLinks){
    cout << "has no links.";
  }
  cout << endl;
}

vector<Link*> Node::getLinks(){
  vector<Link*> duplicate;
  for(vector<Link>::iterator it = links.begin(); it != links.end(); it++){
    Link* newLink = new Link();
    newLink->last = this;
    newLink->weight = (*it).weight;
    newLink->next = (*it).next;
    duplicate.push_back(newLink);
  }
  return duplicate;
}
