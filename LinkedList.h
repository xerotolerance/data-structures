/**
 * @Author: CJ Maxwell - NJIT
 * @Last Updated: 4/25/17
 * @Title: LinkedList
 * *** Dependency for included CURSES.c file ***
 *
 * */

#include <stdio.h>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/*
 * Welp this is as close to OOPS as it gets lol*
 * */

//Defines the Hierarchy as
// LinkedList (has)--> Link --> Payload (wrapper around primative types) & Type (says which primative type is in wrapper)
typedef enum Type {INT, STR, CHAR, FLOAT, DOUBLE,EMPTY} Type;
typedef union payload { int i; float f; char * str; char c; double d;} Payload;
typedef struct Link {struct Link * next, *prev; Payload payload;Type type;} Link;
typedef struct LinkedList {Link * head, * fakeroot, *tail; int size;} LinkedList;

//Create (but do not link into the list yet) an item for use in a list
Link * emptyLink();
Link * iLink(int i);
Link * fLink(float f);
Link * strLink(char * str);
Link * cLink(char c);
Link * dLink(double d);

//Add an item to the list in-between specified items
//   (links existing items into a list -- see create functions before use)
int link(Link ** l, Link ** prev, Link ** next);

//Untethers a specified item from the items around it,
// then links surrounding items to each other. NOTE: unlinked item's memory is not freed.
// to delete/remove an item from memory run free() on the corresponding pop command for the item type.
int unlink(Link ** l);

//Adds a specified item to the end of the list
int appendToList(Link * l, LinkedList *ll);

//create a CHAR item from a char and add it to end of list
int appendCharToList(char c, LinkedList *ll);

//same but for INT
int appendIntToList(int i, LinkedList *ll);

//same but for FLOAT
int appendFloatToList(float f, LinkedList *ll);

//same but for DOUBLE
int appendDoubleToList(double d, LinkedList *ll);

//same but for STR
int appendStrToList(char * str, LinkedList *ll);

//same but for EMPTY
int appendEmptyToList(LinkedList *ll);


//Array-list style insert@ function
int insertAt(Link * l, int pos, LinkedList * ll);

//Array-list style Remove@ function
Link * removeAt(int pos, LinkedList *ll);


//Remove an item from the list and return the removed item.
Link * popChar(char c, LinkedList *ll);
Link * popStr(char * str, LinkedList *ll);
Link * popFloat(float f, LinkedList *ll);
Link * popDouble(double d, LinkedList *ll);
Link * popInt(int i, LinkedList *ll);
Link * popEmpty(LinkedList *ll);

//returns the number of items in the list
int getListSize(Link* head);


//writes a visual representation of the list starting at a specified item to a specified file discriptor
//  (e.g. stderr, stdout, stdin, FILE *, etc)
void showListPointers(FILE *fd, Link *head);

//writes a nice, clean python-esque list style representation of mixed data type to a given file descriptor
void printList(FILE * fd, Link *head);


//given a string array, generate a python-esque list of mixed datatypes (encapsulated in link nodes)
const LinkedList createListFromStringArray(int argc, char **argv);

//initialize an empty linked list
const LinkedList newLinkedList();


//goes through linked list freeing all dynamically allocated links and then loses the info pointers (sets them to NULL)
int deleteLinkedList(LinkedList *ll);
#endif //LINKEDLIST_H