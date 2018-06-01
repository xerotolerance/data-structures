//
// Created by cj on 4/26/17.
//

#ifndef DATA_STRUCTURES_BINARYSEARCHTREE_H
#define DATA_STRUCTURES_BINARYSEARCHTREE_H
typedef union Pouch {
    int i, *ip, iarr[];
    char c, *s, carr[], *sarry[];
    double d, *dp, darr[];
    float f, *fp, farr[];
} Pouch;

typedef enum datatype{  INT, DOUBLE, CHAR, STR, FLOAT,
                        iPTR, dPTR, cPTR, sPTR, fPTR,
                        iARR, dARR, cARR, sARR, fARR
} dtype;
typedef enum treetype{NUM, ALPHA, ARR} ttype;

typedef struct Node { struct Node * above, *left, *right; Pouch value; dtype type; } Node;

typedef struct BinarySearchTree { Node * root; int size; ttype holds; } Tree;
typedef struct Collection { Tree numerics, alphabetics, arrays; int totalsize; } Orchird;



//pseudo-constructors
Tree seedTree(ttype t);
Orchird plantOrchird();


//pseudo-destructors
int uproot(Tree *tree);
int deForest(Orchird * orchird);


//adds
int add(Node * leaf, Tree * tree);
int addNumeric(Node *leaf, Orchird * orchird);
int addAlphabetic(Node *leaf, Orchird * orchird);
int addARR(Node *leaf, Orchird * orchird);
int addToCollection(Node * leaf , Orchird * orchird);


//removes
Node cut(Node * leaf);

//searches
Node * findAlpha(dtype type, Pouch data, Tree * tree);
Node * findNum(dtype type, Pouch data, Tree * tree);
Node * findARR(dtype type, Pouch data, Tree * tree);
#endif //DATA_STRUCTURES_BINARYSEARCHTREE_H
