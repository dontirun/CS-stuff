//============================================================================
// Name        : Program4.cpp
// Author      : Thinh Ly, Arun Donti
// Copyright   : Your copyright notice
// Description : Program 4 in C++, Ansi-style
//============================================================================

#include <cstdlib> 
#include <cstdio> 
#include <iostream>
#include <string>
using namespace std;
#define DEBUG 1


struct line
{

	int linenum;  // line number
	line* linepointer; // pointer to next line number
 };
typedef struct line Line;
typedef Line* Link;



void insert(int linenum, Link *slinePtr)
{
	Link currentline;
	Link nextline;

    nextline = (Link) malloc(sizeof(Line));
	nextline->linenum = linenum;
	nextline->linepointer = NULL;
    currentline = *slinePtr;

if (DEBUG==1){
  printf("a");
}


	if(currentline== NULL) // insert newline if current pointer is NULL
	{
        *slinePtr = nextline;
	}

	else insert(linenum,&(*slinePtr)->linepointer);
	
}
void printline(Link *linPtr){
      if (*linPtr == NULL) printf("\n");
     else { printf("%3d",(*linPtr)->linenum);
            printline(&(*linPtr)->linepointer);
}
}
struct Tree
{

	string name;
	int amount;
	Link lines;
	Tree* leftpointer;
	Tree* rightpointer;


};
typedef struct Tree TREE;
typedef TREE* TREELink;


void insertTree(TREELink *nodePtr, string name, int amount , int linenum){
if (DEBUG==1){
  printf("a");
}
    TREELink nNodePtr, temPtr;
    Link L;
    L = (Link) malloc(sizeof(Line));
    L->linenum = linenum;
    L->linepointer = NULL;
if (DEBUG==1){
  printf("b");
}
    nNodePtr =(TREELink) malloc(sizeof(TREE)); //assigned a address to the new node
if (DEBUG==1){
  printf("c");
}
    nNodePtr->name = name; // copy information in to the new node
    	   nNodePtr->amount = amount;
    	   nNodePtr->lines = L;
    	   nNodePtr->leftpointer = NULL; // set initial value of the left pointer and right pointer of the node to NULL
    	   nNodePtr->rightpointer= NULL;
// check if there is memory available for the new node
   if(nNodePtr != NULL){
	   // check to see if the tree that will be inserted to is empty or not
   if (*nodePtr == NULL){
	   *nodePtr = nNodePtr; // if empty , the new node will be the first node of the tree
   }
   else {
	   // check to see if there is any repetition of Student ID
	   if(name != (*nodePtr)->name) /* check to see if the new node Student ID is less than the first node student ID*/{

	   if((*nodePtr)->name.compare(nNodePtr->name) >0){
		   if ((*nodePtr)->leftpointer == NULL){
			   (*nodePtr)->leftpointer = nNodePtr;
		   }
		   else {
			    temPtr = (*nodePtr)->leftpointer;
		        insertTree(&temPtr,name, amount, linenum); /*recursive call for the left subtree*/
	   }
   }
   if((*nodePtr)->name.compare(nNodePtr->name)<0)/* check to see if the new node Student ID is greater than the first node student ID*/{
		   if ((*nodePtr)->rightpointer == NULL){
		 			   (*nodePtr)->rightpointer = nNodePtr;
		 		   }
		   else {
			    temPtr = (*nodePtr)->rightpointer;
		        insertTree(&temPtr,name,amount,linenum); // recursive call for the right subtree
	   }
	   }
}
	  else {
       (*nodePtr)->amount++;
       insert(linenum,&(*nodePtr)->lines);
   }
   }
}
   else printf("invalid");
}
string seperateword(string word){
	int i;
	string k;     
  if (DEBUG==1){
  printf("c");
}
for (i=0; i < word.length(); i++){
    	 if(word.at(i) != ' '){
    		k += word.at(i);
    		}
    	 else{
    		
    		 break;
    		}
    	 }
     return k;
}
int countblank(string word){
     int i,j;
if (DEBUG==1){
  printf("d");
}
     for (j=0; j <word.length(); j++){
       if(!word.empty()){          
 if (word.at(j) == ' ')
            { i=i+1;
}

}
else break;
}
if (DEBUG==1){
  printf("z \n");
}
     return i;
}
void print_tree(TREELink *NodePtr){
if (DEBUG==1){
  printf("e");
}
	TREELink rightPtr;
	TREELink leftPtr;
	if(*NodePtr == NULL){
		printf(" ") ;
	}
	else{
	 rightPtr = (*NodePtr)->rightpointer;
	 leftPtr = (*NodePtr)->leftpointer;
	 print_tree(&leftPtr);
	 printf("%3s , %3d"  ,(*NodePtr)->name.c_str(),  (*NodePtr)->amount);
//         printline(&(*NodePtr)->lines);
	 print_tree(&rightPtr);
	}
}
void addworktoTree(string Word, TREELink *trPtr, int linenum){
   string newword; 
if (DEBUG==1){
  printf("f");
}  
   while(!Word.empty()){
    newword = seperateword(Word);
    insertTree(trPtr, newword,1,linenum);
    Word.erase(0,newword.length());
}
}
int main() {
 string LineString;
 string newstring;
 string newword;
string Str;
 int linenum;
 TREELink Tptr;
//while(getline(cin,LineString)){
for (int i = 0 ; i < 2; i++){
    getline(cin , LineString);  
   newstring = LineString;
  Str= LineString;
   linenum= linenum+1;
if (newstring != ""){
for(int i =0; i< countblank(newstring)+1; i++){
   newword = seperateword(Str);  
 insertTree(&Tptr, newword,1,linenum);
 Str.erase(0,newword.length()+1);
}
}
}
print_tree(&Tptr);
 cout << LineString << newword << Tptr->amount << countblank(newstring);
return 0;
}
