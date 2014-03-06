#include "Map.h"


void Map::init(){
	fstream infile;
	infile.open("letsblockparty.txt");
	if (!infile.is_open()){
		cout<<"File not found";
	}
	//int height;
	//int width;
	infile>>height;
	infile.ignore();
	infile>>width;
	infile.ignore();
	//initialize array
	char **array2d=new char*[height];
	for (int y =0;y<height;++y){
		array2d[y]=new char[width];
	}
	for(int row=0;row<height; ++row){//set array
		for(int col=0;col<width;++col){
			array2d[row][col]=infile.get();
		}
		infile.ignore();
	} 
}
void Map::print(){
	for (int y=0;y<height;++y){//print a 2D array
		for(int x=0;x<width;++x){
			cout<<array2d[y][x]<<" ";
		}
		cout<< endl;
	}
}
void Map::printH(){
	for (int y=0;y<height;++y){//print a 2D array fliped horizontally
		for(int x=0;x<width;++x){
			cout<<array2d[y][(width-1)-x]<<" ";
		}
		cout<< endl;
	}
}
void Map::printV(){
	for (int y=0;y<height;++y){//print a 2D array fliped vertically
		for(int x=0;x<width;++x){
			cout<<array2d[(height-1)-y][x]<<" ";
		}
		cout<< endl;
	}
}
void Map::printXY(){
	for (int y=0;y<width;++y){//print a 2D array fliped x and y
		for(int x=0;x<height;++x){
			cout<<array2d[x][y]<<" ";
		}
		cout<< endl;
	}
}
void Map::printCW90(){
	for (int y=0;y<width;++y){//print a 2D array fliped clockwise 90
		for(int x=0;x<height;++x){
			cout<<array2d[(height-1)-x][y]<<" ";
		}
		cout<< endl;
	}
}
void Map::printCCW90(){
	for (int y=0;y<width;++y){//print a 2D array fliped counter-clockwise 90
		for(int x=0;x<height;++x){
			cout<<array2d[x][(width-1)-y]<<" ";
		}
		cout<< endl;
	}
}
