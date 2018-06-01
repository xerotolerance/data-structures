/**
 * @Author: CJ Maxwell - NJIT
 * @Last Updated: 4/25/17
 * @Title: LinkedList
 * *** Dependency for included CURSES.c file ***
 *
 * */

#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


//Create (but do not link into the list yet) an item for use in a list
Link * emptyLink(){
    Link * l = malloc(sizeof(Link));
    l->type=EMPTY;
    return l;
}

Link * iLink(int i){
    Link* l= malloc(sizeof(Link));
    l->payload.i=i;
    l->type=INT;
    return l;
}

Link * fLink(float f){
    Link * l = malloc(sizeof(Link));
    l->payload.f=f;
    l->type=FLOAT;
    return l;
}

Link * strLink(char * str){
    Link * l =  malloc(sizeof(Link));
    l->payload.str=str;
    l->type=STR;
    return l;
}

Link * cLink(char c){
    Link * l = malloc(sizeof(Link));
    l->payload.c=c;
    l->type=CHAR;
    return l;
}

Link * dLink(double d){
    Link * l = malloc(sizeof(Link));
    l->payload.d=d;
    l->type=DOUBLE;
    return l;
}



//Add an item to the list in-between specified items
//   (links existing items into a list -- see create functions before use)
int link(Link ** l, Link ** prev, Link ** next){
    if (!l) return 0;

    if (next) {
        (*l)->next = *next;
        if (*next)
            (*next)->prev = *l;
    }
    else
        (*l)->next = NULL;

    if (prev){
        (*l)->prev=*prev;
        if (*prev)
            (*prev)->next=*l;
    }
    else
        (*l)->prev = NULL;
    return 1;
}

//Untethers a specified item from the items around it,
// then links surrounding items to each other. NOTE: unlinked item's memory is not freed.
// to delete/remove an item from memory run free() on the corresponding pop command for the item type.
int unlink(Link ** l){
    if (!l) return 0;
    if ((*l)->prev)
        ((*l)->prev)->next=(*l)->next;
    if ((*l)->next)
        ((*l)->next)->prev=(*l)->prev;
    return 1;
}



//Adds a specified item to the end of the list
int appendToList(Link * l, LinkedList *ll){
    if (link(&l, &(ll->tail), NULL)) {
        ll->size++;
        ll->tail=l;
        if (!ll->head) {
            ll->head=ll->tail;
            ll->fakeroot=emptyLink();
            ll->fakeroot->next=ll->head;
        }
        return 1;
    }
    return 0;
}

//create a CHAR item from a char and add it to end of list
int appendCharToList(char c, LinkedList *ll){
    Link * l = cLink(c);
    if (link(&l, &(ll->tail), NULL)) {
        ll->size++;
        ll->tail=l;
        if (!ll->head) {
            ll->head=ll->tail;
            ll->fakeroot=emptyLink();
            ll->fakeroot->next=ll->head;
        }
        return 1;
    }
    return 0;
}

//same but for INT
int appendIntToList(int i, LinkedList *ll){
    Link * l = iLink(i);
    if (link(&l, &(ll->tail), NULL)) {
        ll->size++;
        ll->tail=l;
        if (!ll->head) {
            ll->head=ll->tail;
            ll->fakeroot=emptyLink();
            ll->fakeroot->next=ll->head;
        }
        return 1;
    }
    return 0;
}

//same but for FLOAT
int appendFloatToList(float f, LinkedList *ll){
    Link * l = fLink(f);
    if (link(&l, &(ll->tail), NULL)) {
        ll->size++;
        ll->tail=l;
        if (!ll->head) {
            ll->head=ll->tail;
            ll->fakeroot=emptyLink();
            ll->fakeroot->next=ll->head;
        }
        return 1;
    }
    return 0;
}

//same but for DOUBLE
int appendDoubleToList(double d, LinkedList *ll){
    Link * l = dLink(d);
    if (link(&l, &(ll->tail), NULL)) {
        ll->size++;
        ll->tail=l;
        if (!ll->head) {
            ll->head=ll->tail;
            ll->fakeroot=emptyLink();
            ll->fakeroot->next=ll->head;
        }
        return 1;
    }
    return 0;
}

//same but for STR
int appendStrToList(char * str, LinkedList *ll){
    Link * l = strLink(str);
    if (link(&l, &(ll->tail), NULL)) {
        ll->size++;
        ll->tail=l;
        if (!ll->head) {
            ll->head=ll->tail;
            ll->fakeroot=emptyLink();
            ll->fakeroot->next=ll->head;
        }
        return 1;
    }
    return 0;
}

//same but for EMPTY
int appendEmptyToList(LinkedList *ll){
    Link * l = emptyLink();
    if (link(&l, &(ll->tail), NULL)) {
        ll->size++;
        ll->tail=l;
        if (!ll->head) {
            ll->head=ll->tail;
            ll->fakeroot=emptyLink();
            ll->fakeroot->next=ll->head;
        }
        return 1;
    }
    return 0;
}



//Array-list style insert@ function
int insertAt(Link * l, int pos, LinkedList *ll){
    Link * curr;
    int i;
    for (i=0,curr=ll->head; curr && i < pos; i++, curr=curr->next);
    if (!curr) return 0;
    else if (link(&l,&curr,&curr->next)) return 1;
    return 0;
}

//Array-list style Remove@ function
Link * removeAt(int pos, LinkedList *ll){
    Link * curr;
    int i;
    for (i=0,curr=ll->head; curr && i < pos; i++, curr=curr->next);
    if (curr == ll->head)
        ll->head=curr->next;
    if (curr==ll->tail)
        ll->tail=curr->prev;
    if (unlink(&curr)) {ll->size--;return curr;}
    return 0;
}



//Remove an item from the list and return the removed item.
Link * popChar(char c, LinkedList *ll){
    Link * head = ll->head;
    while (head){
        if (head->type==CHAR && head->payload.c == c){
            if (head == ll->head)
                ll->head=head->next;
            if (head==ll->tail)
                ll->tail=head->prev;
            unlink(&head);
            ll->size--;
            return head;
        }
        head=head->next;
    }
    return 0;
}

Link * popStr(char * str, LinkedList *ll){
    Link * head = ll->head;
    while (head){
        if (head->type==STR && !strcmp(head->payload.str,  str)){
            if (head == ll->head)
                ll->head=head->next;
            if (head==ll->tail)
                ll->tail=head->prev;
            unlink(&head);
            ll->size--;
            return head;
        }
        head=head->next;
    }
    return 0;
}

Link * popFloat(float f, LinkedList *ll){
    Link * head = ll->head;
    while (head){
        if (head->type==FLOAT && head->payload.f - f < .000001){
            if (head == ll->head)
                ll->head=head->next;
            if (head==ll->tail)
                ll->tail=head->prev;
            unlink(&head);
            ll->size--;
            return head;
        }
        head=head->next;
    }
    return 0;
}

Link * popDouble(double d, LinkedList *ll){
    Link * head = ll->head;
    while (head){
        if (head->type==DOUBLE && head->payload.d - d <= .000000001){
            if (head == ll->head)
                ll->head=head->next;
            if (head==ll->tail)
                ll->tail=head->prev;
            unlink(&head);
            ll->size--;
            return head;
        }
        head=head->next;
    }
    return 0;
}

Link * popInt(int i, LinkedList *ll){
    Link * head = ll->head;
    while (head){
        if (head->type==INT && head->payload.i - i < .0000001){
            if (head == ll->head)
                ll->head=head->next;
            if (head==ll->tail)
                ll->tail=head->prev;
            unlink(&head);
            ll->size--;
            return head;
        }
        head=head->next;
    }
    return 0;
}

Link * popEmpty(LinkedList *ll){
    Link * head = ll->head;
    while (head){
        if (head->type==EMPTY){
            if (head == ll->head)
                ll->head=head->next;
            if (head==ll->tail)
                ll->tail=head->prev;
            ll->size--;
            unlink(&head);
            return head;
        }
        head=head->next;
    }
    return 0;
}


//returns the number of items in the list
int getListSize(Link* head){
    int size=0;
    while(head){
        size++;
        head=head->next;
    }
    return size;
}

//writes a visual representation of the list starting at a specified item to a specified file discriptor
//  (e.g. stderr, stdout, stdin, FILE *, etc)
void showListPointers(FILE *fd, Link *head){
    Link* curr=head;
    fprintf(stdout, "*NULL <-- ");
    while(curr){
        switch (curr->type){
            case INT:
                fprintf(fd, "%d", curr->payload.i);
                break;
            case CHAR:
                fprintf(fd, "%c", curr->payload.c);
                break;
            case FLOAT:
                fprintf(fd, "%3.2f", curr->payload.f);
                break;
            case DOUBLE:
                fprintf(fd, "%e", curr->payload.d);
                break;
            case EMPTY:
                fprintf(fd, "<empty_node>");
                break;
            default: fprintf(fd, "%s", curr->payload.str); break;
        }

        if ( curr->next)
            fprintf(fd, " <--> ");
        curr=curr->next;
    }
    fprintf(stdout, " --> NULL*\n");
}

//writes a python-esque list of mixed data type to a given file descriptor
void printList(FILE * fd, Link *head){
    Link* curr=head;
    fprintf(stdout, "[ ");
    while(curr){
        switch (curr->type){
            case INT:
                fprintf(fd, "%d", curr->payload.i);
                break;
            case CHAR:
                fprintf(fd, "%c", curr->payload.c);
                break;
            case FLOAT:
                fprintf(fd, "%3.2f", curr->payload.f);
                break;
            case DOUBLE:
                fprintf(fd, "%e", curr->payload.d);
                break;
            case EMPTY:
                fprintf(fd, "<empty_node>");
                break;
            default: fprintf(fd, "\"%s\"", curr->payload.str); break;
        }

        if ( curr->next)
            fprintf(fd, ", ");
        curr=curr->next;
    }
    fprintf(stdout, " ]\n");
}
//Creates a Linked list from the data in a given string array.  Datatype conversions are made on all parsable strings.
// As such, the data in its typecasted form is stored into the list in the same order as the array.

// Returns a struct containing 3 pointers: one to the first item in the list, one to the last item in the list, and an additional
// "fakeroot" pointer intended to be used for (but not limited to) transversing the list...
// fakeroot is initially pointed to a fakeroot which points to the first item in the list.

//given a string array, generate a python-esque list of mixed datatypes (encapsulated in link nodes)
const LinkedList createListFromStringArray(int argc, char **argv) {
    Link * head = NULL, *next=NULL, *prev=NULL;
    int i=0, iv=0;
    float fv = 0.0;
    char sv[1024], *arg = malloc(1024);
    Link * newlink;
    for (i=0;i<argc;i++) {
        arg=argv[i];
        if (sscanf(arg, "%f", &fv)){
            iv=(int)fv;
            if (iv==fv)
                newlink = iLink(iv);
            else
                newlink = fLink(fv);
        }
        else if (arg[1] == '\0')
            newlink = cLink(argv[i][0]);
        else if (sscanf(arg, "%s", sv))
            newlink = strLink(arg);
        else
            newlink = emptyLink();

        link(&newlink, &prev, &next);
        if (!head)
            head=newlink;
        prev=newlink;
    }
    LinkedList * lp = malloc(sizeof(LinkedList));
    lp->head=head;
    lp->tail=prev;
    lp->fakeroot=malloc(sizeof(Link));
    lp->fakeroot->next=lp->head;
    lp->size=getListSize(lp->head);
    return *lp;
}

//initialize an empty linked list
const LinkedList newLinkedList(){
    return *(LinkedList*)calloc(sizeof(LinkedList), sizeof(LinkedList));
}

//goes through linked list freeing all dynamically allocated links and then loses the info pointers (sets them to NULL)
int deleteLinkedList(LinkedList *ll){
    Link * curr = ll->head, *next = curr;
    while(next){
        unlink(&curr);
        next=curr->next;
        free(curr);
        --ll->size;
    }
    if (ll->head) ll->head=NULL;
    if (ll->tail) ll->tail=NULL;
    if (ll->fakeroot) ll->fakeroot=NULL;
    return ll->size;
}