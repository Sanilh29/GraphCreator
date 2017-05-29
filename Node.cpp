//Sanil Hattangadi, node.cpp. actually runs the methods and has the algorithm for the methods
#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

Node::Node(char newName){//constructor
  name = newName;
}

bool Node::remove(Node* toRemove){//removes vertex
  for (vector<Link>::iterator it =links.begin();it !=links.end(); it++){//walks through link
    if((*it).next == toRemove){//checks if the nexts ones data is equal to one wanting to be deleted
      links.erase(it);//erase it
      return true;
    }
  }
  return false;
}

bool Node::add(Node* toAdd, int newWeight){//adds it to the list
  bool linkExists = false;
  if(toAdd == this){
    cout << "You can't link your node to itself." << endl;
    return false;
  }
  for (vector<Link>::iterator it =links.begin(); it !=links.end(); it++){//walk through the list
    if((*it).next ==toAdd){
      linkExists = true;
      break;
    }
  }
  if (!linkExists){//if nothing is in the link
    Link newLink;//create it
    newLink.weight = newWeight;//set the variables
    newLink.next = toAdd;
    newLink.last = this;
    links.push_back(newLink);//add it to the list
    return true;
  }
  else {
    cout << "There already is a connection between " << name << "and " << toAdd->name << endl;
  }
}

void Node::print(){//prints out the vertexs and edges
  bool noLinks = true;
  cout << name  << "::";//print out the name

  for (vector<Link>:: iterator it= links.begin(); it != links.end(); it++){//walk through vector
    cout << (*it).next->name << ":" << (*it).weight;//write the edges it has
    noLinks = false;
  }
  if (noLinks){//if it has no edges
    cout << "has no links.";
  }
  cout << endl;
}

vector<Link*> Node::getLinks(){//making a duplicate vector for searching
  vector<Link*> duplicate;
  for(vector<Link>::iterator it = links.begin(); it != links.end(); it++){//walk through vector
    Link* newLink = new Link();
    //set the variables
    newLink->last = this;
    newLink->weight = (*it).weight;
    newLink->next = (*it).next;
    duplicate.push_back(newLink);
  }
  return duplicate;
}
