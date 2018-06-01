#include "LinkedList.h"

int main(int argc, char ** argv){
    LinkedList list = newLinkedList();
    Link * testlink = strLink("\\m/(0o0)\\m/");
    Link * testlink2 = iLink(0);
    fprintf(stderr, "%d\n", appendStrToList("penis", &list));
    fprintf(stderr, "%d\n", appendIntToList(9, &list));
    fprintf(stderr, "%d\n", appendCharToList('$', &list));
    fprintf(stderr, "%d\n", appendEmptyToList(&list));
    fprintf(stderr, "%d\n", appendFloatToList(2.71, &list));
    fprintf(stderr, "%d\n", appendDoubleToList(2147483647, &list));
    fprintf(stderr, "%d\n", appendToList(testlink, &list));
    showListPointers(stdout, list.head);

    fprintf(stderr, "%d\n",insertAt(testlink2,3, &list));

    showListPointers(stdout, list.head);

    fprintf(stderr, "%s\n", removeAt(7,&list)->payload.str);

    showListPointers(stdout, list.head);

    fprintf(stderr, "%c\n", popChar('$', &list)->payload.c);

    showListPointers(stdout, list.head);

    fprintf(stderr, "%s\n", popStr("penis", &list)->payload.str);

    showListPointers(stdout, list.head);

    fprintf(stderr, "%3.8f\n", (popFloat(2.71, &list)->payload.f));

    showListPointers(stdout, list.head);

    fprintf(stderr, "%e\n", (popDouble(2.147484e+09, &list)->payload.d));

    showListPointers(stdout, list.head);

    fprintf(stderr, "%d\n", (popInt(0, &list)->payload.i));

    showListPointers(stdout, list.head);

    popEmpty(&list);

    showListPointers(stdout, list.head);

    fprintf(stdout, "Size of list is: %d\n", getListSize(list.head));

    printList(stdout, list.head);

    deleteLinkedList(&list);

    printList(stdout, list.head);

    fprintf(stdout, "Size of list is: %d\n", getListSize(list.head));

    char * slogan[5] = {"I am GROOT", "Wow, It's sooo new!", "Follow me Man", "Theta Chi, Do or Die", "CJM"};

    LinkedList breakdown = createListFromStringArray(5, slogan);
    printList(stdout,breakdown.head);
    return 0;
}