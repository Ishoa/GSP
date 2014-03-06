#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include "Map.h"

using namespace std;

//	Create a struct called Map that holds a pointer to a 2D array (char ** m_map), 
//	the map’s width (int m_width), and the map’s height (int m_height).
//	Also, create a method that loads a Map from a file with the signature:
//struct Map{
//	char **m_map;
//	int m_width;
//	int m_height;
//};

int main(){
	Map stuff;
	stuff.init();
	stuff.print();
	//fstream infile;
	//infile.open("letsblockparty.txt");
	//if (!infile.is_open()){
	//	cout<<"File not found";
	//}
	//int height;
	//int width;
	//infile>>height;
	//infile.ignore();
	//infile>>width;
	//infile.ignore();
	////initialize array
	//char **array2d=new char*[height];
	//for (int y =0;y<height;++y){
	//	array2d[y]=new char[width];
	//}
	//for(int row=0;row<height; ++row){//set array
	//	for(int col=0;col<width;++col){
	//		array2d[row][col]=infile.get();
	//	}
	//	infile.ignore();
	//}
	//for (int y=0;y<height;++y){//print a 2D array
	//	for(int x=0;x<width;++x){
	//		cout<<array2d[y][x]<<" ";
	//	}
	//	cout<< endl;
	//}
	//for (int y=0;y<height;++y){//print a 2D array fliped horizontally
	//	for(int x=0;x<width;++x){
	//		cout<<array2d[y][(width-1)-x]<<" ";
	//	}
	//	cout<< endl;
	//}
	//for (int y=0;y<height;++y){//print a 2D array fliped vertically
	//	for(int x=0;x<width;++x){
	//		cout<<array2d[(height-1)-y][x]<<" ";
	//	}
	//	cout<< endl;
	//}
	//for (int y=0;y<width;++y){//print a 2D array fliped x and y
	//	for(int x=0;x<height;++x){
	//		cout<<array2d[x][y]<<" ";
	//	}
	//	cout<< endl;
	//}
	//for (int y=0;y<width;++y){//print a 2D array fliped clockwise 90
	//	for(int x=0;x<height;++x){
	//		cout<<array2d[(height-1)-x][y]<<" ";
	//	}
	//	cout<< endl;
	//}
	//for (int y=0;y<width;++y){//print a 2D array fliped counter-clockwise 90
	//	for(int x=0;x<height;++x){
	//		cout<<array2d[x][(width-1)-y]<<" ";
	//	}
	//	cout<< endl;
	//}
	//for(int y=0; y<height; ++y){//release a 2D array
	//	delete [] array2d[y];
	//}
	//delete [] array2d;

	int num;
	cin>>num;
	return 0;
}
