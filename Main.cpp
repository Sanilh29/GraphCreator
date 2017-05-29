//Sanil Hattangadi, May 26, this program adds vertexes and lines connecting vertexes. you can add, delete
//and find the fastest path between points
#include <iostream>
#include <cstring>
#include "Graph.h"
#include <cstdlib>

using namespace std;

int main(){//the method that runs everything
  Graph* graph = new Graph();
  char input[128];
  bool running = true;
  while(running){//while running is true
    cout << "Enter a command: add, delete, print, search, or quit" << endl;
    cin.getline(input, 128);//take in the input
    if(0==strcmp(input, "add")){//the inputted add
      cout << "do you want to add an edge or vertex?" << endl;
      cin.getline(input, 128);
      if(0==strcmp(input, "edge")){//they want to add an edge
	cout << "Give me 2 single character vertex names and a weight, space separated" << endl;
	cin.getline(input,10);
	if(isdigit(input[4]) && input[1] == ' ' && input[3] == ' '){
	  graph->addEdge(input[0],input[2],atoi(&input[4]));//take in the input and run add edge
	}
      }
      else if (0==strcmp(input, "vertex")){//if they input vertex
	cout << "Give me the single character name for the new Vertex" << endl;
	cin.getline(input,10);//take in one char
	graph->addVertex(input[0]);
      }
      else cout << "incorrect formatting" << endl;
    }
    else if(0==strcmp(input, "delete")){//if they say delete
      cout << "Do you want to delete a vertex or an edge?"<< endl;
      cin.getline(input, 128);//take in what they want to delete
      if(0==strcmp(input, "vertex")){
	cout << "Give me one vertex name to delete it" << endl;
	cin.getline(input,10);
	graph->removeVertex(input[0]);//removes vertex
      }
      if(0==strcmp(input, "edge")){//they said edge
	cout << "Give me two vertex names separated by a space to delete the edge between them."<< endl;
	cin.getline(input, 128);//take in two vertexes to delete edge
	graph->removeEdge(input[0], input[2]);
      }
      else{
	cout << "Bad Formating" << endl;
      }
    } 
    else if(0==strcmp(input, "print")){//they want to print
      graph->print();
    } 
    else if(0==strcmp(input, "search")){//they want to search
      cout << "Give me two nodes to find a path between" << endl;
      cin.getline(input,10);
      if (strlen(input) >= 3){
	graph->findPath(input[0],input[2]);//take in 2 chars they inputted
      }  
    }
    else if(0==strcmp(input, "quit")){
      running = false;
    }
    else{
      cout << "I don't understand" << endl;
      cout << "The possible commands are:\nadd\ndelete\nsearch\nprint\nquit" << endl;
    }
  }

}
