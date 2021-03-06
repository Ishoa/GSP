#include <iostream>
using namespace std;
#include <conio.h>
//in order to use maloc you must include stdlib
#include <stdlib.h> //maloc and free



//pointer of a char points to the first char in the array
//c++ increases the array by the nubmer of bytes it takes 1 so it goes over by one space
//if it was something of a different size say 12 it would move by 12 spaces
void print (char * c){ 
	while(*c){
		cout<<*c;
		c++;
	}
	cout<<endl;
}

void setArray(int * arr, int size, int value){
	for(int i=0; i<size;++i) arr[i]=value;
}

void printArray(int * iptr, int size){
	for(int i=0;i<size;++i){
		if(i>0) cout<<", ";
		cout<<*iptr;
		iptr++;
	}
	cout << endl;
}
class Vectr {
	float * m_data;
	int m_size; // how much memory is allocated
	int m_usedSize; //how much memory is actually being used..with this it is a vector without this it is a managed array
public:
	Vectr():m_data(0),m_size(0),m_usedSize(0){}
	void setSize(int newSize) {
		// in  general reducing memory allocation is good, especially when fragmentation is possible
		float * array2 = (float*)malloc(sizeof(float)*(newSize));
		for(int i=0;i<newSize && i<m_size; ++i)
		{
			array2[i] = m_data[i];
		}
		free(m_data);
		m_data = array2;
		m_size=newSize;
	}
	//int size() {return m_size;}
	int size() {return m_usedSize;}
	float get(int index) { return m_data[index];}
	void add(float value) {
				if(m_usedSize >= m_size){
			setSize(m_size+10);
		}
		m_data[m_usedSize++]=value;
	}
	~Vectr(){
		if(m_data) free(m_data);
		m_size=0;
		m_usedSize=0;
	}
	Vectr(Vectr & other):m_data(0),m_size(0),m_usedSize(0){
		setSize(other.size());
		for(int i=0;i<m_size;++i){
			m_data[i]= other.m_data[i];
		}
	}
	//	setSize(m_size+1);
	//	m_data[m_size-1] = value;
	//}
	//~Vectr(){
	//	if(m_data) free(m_data);
	//	m_size=0;
	//}
};

class LinkedList{
	struct LLNode{
		float data;
		LLNode * next;
		LLNode(float value):data(value),next(0){}
	};
	LLNode * head;
public:
	LinkedList():head(0){}
	int size(){
		LLNode * ptr =head;
		int count =0;
		while(ptr){
			count++;
			ptr =ptr->next;
		}
		/*int count=(1,2,3,0);
		LLNode *ptr;
		for(ptr=head,count=0;ptr;++count,ptr=ptr->next);
		return count;*/
	}
	LLNode*getNode(int index){
		LLNode*ptr = head;
		int count=0;
		while(count<index){
			ptr=ptr->next;
			count++;
		}
		return ptr;
	}
	float get(int index){
		return getNode(index)->data;
	}
	void add(float value){
		LLNode *newNode=new LLNode(value);
		if(head==0) head =newNode;
		else getNode(size()-1)->next=newNode;
	}
	void addFront(float value){
		LLNode*newNode=new LLNode(value);
		newNode->next=head;
		head=newNode;
	}
	~LinkedList(){
		LLNode*lefthand=head;
		LLNode*righthand;
		while(lefthand){
			righthand=lefthand;
			lefthand=lefthand->next;
			delete righthand;
		}
	}
};

void printByte(char byte){
	//for(int i=0;i<CHAR_BIT;++i)
	//must be in reverse
	for(int i=CHAR_BIT-1; i>=0;--i){
	/*	if(byte&(1<<i)){
			putchar('1');
		}else{
			putchar('0');
		}*/
		putchar( (byte &(1<<i))?'1':'0');
	}
}

#include <fstream>
using namespace std;



int main(int argc, char ** argv){
	
	int magicNumber = 0x1337b335;//deadb33f;//b44df00d;
	
	char * ptr = (char*)&magicNumber;

	printf("%02x\n ", magicNumber);
	for(int i = 0;i<sizeof(magicNumber);++i)
	{
		printf("%02x ", (0xff & ptr[i]));
	}
	putchar('\n');
	//system("ipconfig");
	for (int i=0;i<argc;i++){
		std::cout<< i <<" "<<argv[i]<<endl;
	}
	char * filename="day1stuff.cpp";
	fstream file(filename);
	int filesize = 0;
	file.seekg (0, file.end);
	int expectedlength = file.tellg();
	file.seekg (0, file.beg);
	while(file.get()!=EOF){
		filesize++;
	}
	file.close();
	file.clear();
	file.open(filename);
	char *allTheData = new char[filesize+1];
	for(int i=0;i<filesize;++i){
		allTheData[i]=file.get();
	}
	allTheData[filesize]='\0';
	file.close();
	//cout<<allTheData<<filesize<<" vs "<<expectedlength<<endl;

#include "t.txt"
	int testNumber = 19;
	printByte(testNumber);
	putchar('\n');


#define BITSHIFT_THINGY(expression) printByte(expression); printf(" " #expression " = %d\n", expression);
	
	/*printByte(34);    printf(" 34 = %d\n",  34);
	printByte(34<<1); printf(" 34 << 1%d\n",34<<1);
	printByte(34>>2); printf(" 34>> 2%d\n", 34>>2);*/
	BITSHIFT_THINGY(34);
	BITSHIFT_THINGY(34 << 1);
	BITSHIFT_THINGY(34 >> 2);
	putchar('\n');
	BITSHIFT_THINGY(34);
	BITSHIFT_THINGY(19);
	BITSHIFT_THINGY(19 | 34);
	putchar('\n');
	BITSHIFT_THINGY(34);
	BITSHIFT_THINGY(19);
	BITSHIFT_THINGY(19 & 34);
	putchar('\n');
	BITSHIFT_THINGY(34);
	BITSHIFT_THINGY(19);
	BITSHIFT_THINGY(19 ^ 34);
	putchar('\n');
	BITSHIFT_THINGY(+34);
	BITSHIFT_THINGY(~34);
	BITSHIFT_THINGY(-34);
	//34>>2
	//19|34
	//19&34
	//19^34
	//~34

	int MYSECRETNUMBER = 17;
	int MYSECRETCODE = 3478906234;
	BITSHIFT_THINGY(MYSECRETNUMBER);
	BITSHIFT_THINGY(MYSECRETCODE);
	MYSECRETNUMBER = MYSECRETNUMBER ^ MYSECRETCODE;
	BITSHIFT_THINGY(MYSECRETNUMBER);
	MYSECRETNUMBER = MYSECRETNUMBER ^ MYSECRETCODE;
	BITSHIFT_THINGY(MYSECRETNUMBER);

	//swapping with exclusive or
	int num1 = 17;
	int num2 = 32;
	BITSHIFT_THINGY(num1);
	BITSHIFT_THINGY(num2);
	num1 ^= num2;
	BITSHIFT_THINGY(num1);
	BITSHIFT_THINGY(num2);
	num2 ^= num1;
	BITSHIFT_THINGY(num1);
	BITSHIFT_THINGY(num2);
	num1 ^= num2;
	BITSHIFT_THINGY(num1);
	BITSHIFT_THINGY(num2);

	BITSHIFT_THINGY(19);
	BITSHIFT_THINGY(~19);
	int sizes[] = {
		sizeof (int),
		sizeof (long),
		sizeof (short),
		sizeof (char),
		sizeof (float),
		sizeof (double),
		sizeof (int*),
		sizeof (long long)
	};
	char * names[] = {
		"int",
		"long",
		"short",
		"char",
		"float",
		"double",
		"int*",
		"long long"
	};
	int COUNT = sizeof(sizes)/sizeof(sizes[0]);
	for(int i = 0; i < COUNT; ++i) {
		cout << names[i] << " is " << sizes[i] << " bytes big " << endl;
	}
	
	char buffer[256];
	cin>>buffer;
	print(buffer);
	//for (int i=0; buffer[i]!='\0';++i)// i< sizeof(buffer)
	//	cout<<buffer[i];

	//void* is a pointer to anything
	//dynamically allocate an array of size 5 and another array of +2 
	int size = 5;
	int * array1 = new int [size];
	int * array2 = new int [size +2];
	// using malloc 
	//int * array1 = (int*)malloc(sizeof(int)*size); //new int [ size ]
	//int * array2 = (int*)malloc(sizeof(int)*(size+2));//new int [size + ]
	setArray(array1, size, 1);
	setArray(array2, size+2, 2);
	for(int i=0;i<size;++i)
	{
		array2[i]=array1[i];
	}	
	printArray(array1, size);
	delete [] array1;
	//free(array1);
	printArray(array2, size+2);
	//checks for memory leaks
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_getch();
	delete [] array2;
	//free(array2);

	Vectr v;  //vector to store our numbers
	//keep getting numbers from the user till the user types a non-number
	float num;
	do
	{
		cin>>num;
		if(cin)
		{
			v.add(num);
		}
	}
	while (cin); //if cin failed, a bad input was given
	for(int i=0;i<v.size();++i)
		cout<<" "<<v.get(i);
	cin.clear(); // clears error flags
	while(cin.get() != '\n'); //eat all the characters til new new line (enter key)
	cin>>num;
	cout<<num;


	//allocates a 2D array

	const int width=7, height = 5;
	//int staticarray2d[height][width];
	int **array2d=new int*[height];
	for (int y =0;y<height;++y){
		array2d[y]=new int[width];
	}
	// set the 2D array
	/*for(int y=0;y<height; ++y){
		for(int x=0;x<width;++x){
			array2d[y][x]=y * width+x;
		}
	}	*/
	// set the 2D array thinking in row and col
	for(int row=0;row<height; ++row){
		for(int col=0;col<width;++col){
			array2d[row][col]=row * width+col;
		}
	}
	//print a 2D array
	cout<<endl;
	for (int y=0;y<height;++y){
		for(int x=0;x<width;++x){
			cout<<array2d[y][x]<<" ";
		}
		cout<< endl;
	}
	//release a 2D array
	for(int y=0; y<height; ++y){
		delete [] array2d[y];
	}
	delete [] array2d;
	
	int depth = 3;
	int***array3d = new int **[depth]; // create the 3d array
	for(int dep = 0; dep < depth; ++dep){
		array3d [dep]=new int* [height];
		for(int row=0;row<height; ++row){
			array3d[dep][row]=new int [width];
			for(int col=0;col<width;++col){//set values for the 3d array elements
				array3d[dep][row][col]=(dep*height*width)+(row*width)+(col);
			}
		}
	}
	for(int dep=0; dep<depth;++dep){//prints
		for(int row=0;row<height;++row){
			for(int col=0;col<width;++col){
				printf("%03d ",array3d[dep][row][col]);
			}
			putchar('\n');
		}
		putchar('\n');
	}
	for(int dep=0;dep<depth;++dep){//releases
		for(int row=0;row<height;++row){
			delete[] array3d[dep][row];
		}
		delete [] array3d[dep];
	}
	delete[] array3d;


	const int ASIZE=10;
	int array1d[ASIZE];
	int number;
	int * a=array1d;//&number;//array1d;
	//array1d++;
	cout<<sizeof(array1d)<<endl;
	cout<<sizeof(a)<<endl;
	//1=1;
	//*a=10;
	//*(a+1)=10;
	//cout<<number<<endl;
	for(int i=0;i<ASIZE; ++i)
	{
		//array1d[i]=i;
		a[i]=i;
		//this is equivalent
		//array access is a wrapper around pointer arithmatic
		//*(a+i)=i;
		//*(i+a)=i;
		//i[a]=i;// also identicle
	}
	for(int i=0;i<ASIZE; ++i)
	{
		//printf("%d, ",array1d[i]);
		printf("%d, ",a[i]);
	}
	
	_getch();
	return 0;
}
