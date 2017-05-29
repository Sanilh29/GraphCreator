//Sanil Hattangadi, graph.cpp that actually creates the algorpthms for the methods
#include <cstring>
#include <vector>
#include <iostream>
#include "Graph.h"

using namespace std;

void Graph::addEdge(char data1, char data2, int newWeight){//adds an edge to the function
  Node* node1 = nodeSearch(data1);//finds where its located
  Node* node2 = nodeSearch(data2);
  if (node1 != NULL && node2 != NULL){//if the nodes exist
    node1->add(node2, newWeight);//connect node2 to node 1 with a weight
  }
}

void Graph::addVertex (char data){//adds a vertex
  bool isVertex = false;
  for (vector<Node*>::iterator it=nodes.begin(); it!=nodes.end(); it++){//go through the vector
    if ((*it)->name == data){//check if the vertex already exists
      isVertex = true;
    }
  }
  if (isVertex== false) {//if doesnt exist
    Node* node = new Node(data);
    nodes.push_back(node);//push it to the list
  }
}

void Graph::removeVertex(char data){//removing a vertex
  Node* node = nodeSearch(data);//find where its located
  if (node != NULL){//if it exists
    for (vector<Node*>::iterator it=nodes.begin(); it!= nodes.end(); it++){//go through vector
      node->remove((*it));//remove all the edges it has
    }
    for (vector<Node*>::iterator it=nodes.begin(); it!=nodes.end();it++){//go through the node vector
      if (node->name == data){//delete the actual node
	nodes.erase(it);
      }
    }
  }
}

void Graph::removeEdge(char data1, char data2){//removing an edge
  Node* node1 = nodeSearch(data1);
  Node* node2 = nodeSearch(data2);
  if (node1 != NULL && node2 != NULL){//if they exist
    node1->remove(node2);//remove the edge
  }
}

Node* Graph::nodeSearch(char data){//locate where the nodes are
  for (vector<Node*>::iterator it=nodes.begin(); it!=nodes.end(); it++){//go through the vector
    if ((*it)->name == data){
      return *it;//find a node
    }
  }
    return NULL;
}

void Graph::print(){//printing out the vertexes and edges
  for(vector<Node*>::iterator it=nodes.begin(); it!=nodes.end(); it++){//go through the nodes
    (*it)->print();//print it out
  }
}

bool removeSmaller(vector<Link*>* links, Link* link){//removes the weight of a smaller edge
  for(vector<Link*>::iterator it = links->begin(); it != links->end(); it++){//go through the vector
    if((*it)->next == link->next){
      if((*it)->weight > link->weight){//if the vectors weight is greater than the links weight
	links->erase(it);//erase it
	return true;
      }
      else return false;
    }
  }
  return true;
}

void orderedAdd(vector<Link*>* links,Link* link){
  //add things making sure that it stays in decending order 
  if(removeSmaller(links,link)){
    bool inserted = false;
    for(vector<Link*>::reverse_iterator it = links->rbegin(); it != links->rend(); it++){//goes through vector backwards      
      if(link->weight < (*it)->weight){
	links->insert(it.base(),link);
	inserted = true;
      }
    }
    if (!inserted){
      links->insert(links->rend().base(),link);
    }
  }
}

void Graph::findPath(char data1, char data2){ //find the shortest path through the grid between two points
  Node* start = nodeSearch(data1);
  Node* end = nodeSearch(data2);
  if(!start || !end){//see if the nodes exist
    cout << "Those Nodes dont exist" << endl;
  }
  //create two vectors: active and done
  vector<Link*> active;
  vector<Link*> done;
   
  Link* first = new Link(); //add the first link to the active list
  //set the variables
  first->next = start;
  first->weight = 0;
  first->last = NULL;
   
  active.push_back(first);//add first to the vector
   
  while((active.size()) > 0){//if theres still more links to look at
    if (done.size() > 0){//if you havent looked at end node
      if((*done.back()).next == end){
	break;
      }
    }
    //take the next node in the list
    Link* current = (*active.rbegin());
    //grab its links
    vector<Link*> newLinks = current->next->getLinks();
    //add them to the active list if they are either new or smaller than the current smallest link to the node
    for(vector<Link*>::iterator it = newLinks.begin(); it != newLinks.end(); it++){
      Link* newLink = (*it);
      bool isDone = false;
      for(vector<Link*>::iterator it = done.begin(); it != done.end(); it++){//go through the done vector
	if ((*it)->next == newLink->next){//check if the next is equal
	  isDone = true;
	  break;
	}
      }
      if(!isDone){//if not
	newLink->weight += current->weight;//add the weights
	orderedAdd(&active,newLink);
      }
    }
    done.push_back(current);//add the current link to vector
    active.pop_back();//remove from active vector
  }
  //if you found the last node, print out the path
  if((*done.rbegin())->next == end){
    Node* nextPrint = end;
    cout << "The total weight was " << (*done.rbegin())->weight << endl;
     
    for(vector<Link*>::reverse_iterator it = done.rbegin(); it != done.rend(); it++){//go trhough done backwards
      if ((*it)->next == nextPrint){//print out the next from end point to starting point
	cout << nextPrint->name << "<-";
	nextPrint = (*it)->last;
      }
    }
    cout << endl;
  }
  else cout << "No posible path" << endl;
}
