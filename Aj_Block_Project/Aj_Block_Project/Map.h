#pragma once
#include <iostream>
#include <fstream>
using namespace std;

//	Create a struct called Map that holds a pointer to a 2D array (char ** m_map), 
//	the map’s width (int m_width), and the map’s height (int m_height).
//	Also, create a method that loads a Map from a file with the signature:
class Map{
private:
	char **array2d;
	int width;
	int height;
public:
	Map():array2d(0),width(0),height(0){}
	void init();
	void print();
	void printH();
	void printV();
	void printXY();
	void printCW90();
	void printCCW90();
	~Map(){
		for(int y=0; y<height; ++y){//release a 2D array
		delete [] array2d[y];
	}
	delete [] array2d;
	};
};
