#pragma once
#include <iostream>
#include <fstream>

//	Create a struct called Map that holds a pointer to a 2D array (char ** m_map), 
//	the map’s width (int m_width), and the map’s height (int m_height).
//	Also, create a method that loads a Map from a file with the signature:
struct Map{
	char **m_map;
	int m_width;
	int m_height;
}