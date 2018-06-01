//
// Created by cj on 4/26/17.
//

#include "BinarySearchTree.h"
#include <stdlib.h>

Tree seedTree(ttype t){
    Tree * seedling = (Tree*)calloc(sizeof(Tree),sizeof(Tree));
    seedling->holds=t;
    return *seedling;
}
Orchird plantOrchird() {
    Orchird * forest = (Orchird*)calloc(sizeof(Orchird), sizeof(Orchird));
    forest->numerics=seedTree(NUM);
    forest->alphabetics=seedTree(ALPHA);
    forest->arrays=seedTree(ARR);
    return *forest;
}


//kill every node in the orchird; return the number of nodes killed.
int deForest(Orchird * orchird){
    int leaves = 0;
    leaves+=uproot(&orchird->arrays);
    leaves+=uproot(&orchird->numerics);
    leaves+=uproot(&orchird->alphabetics);
    return leaves;
}

//deletes nodes in tree from memory; returns number of nodes deleted.
int uproot(Tree *tree){
    int startsize = tree->size;
    Node * curr= tree->root, *slave;
    while (tree->size>0){
        while (curr->left)
            curr=curr->left;
        if (curr->right) {
            curr = curr->right;
            continue;
        }
        slave=curr;
        curr=curr->above;
        if (curr)
            if (curr->left == slave)
                curr->left = NULL;
            else
                curr->right = NULL;

        free(slave);
        tree->size--;
    }
    return startsize-tree->size;
}



//insert nodes in a tree
int add(Node * leaf, Tree * tree){

    return tree->size;
}

//inserts a node into the correct tree in the orchird
int addToCollection(Node * leaf , Orchird * orchird){
    if (! leaf) return 0;

    switch (leaf->type){
        case INT:
        case DOUBLE:
        case iPTR:
        case dPTR:
            return addNumeric(leaf, orchird);
        case CHAR:
        case STR:
        case cPTR:
        case sPTR:
            return addAlphabetic(leaf, orchird);
        case iARR:
        case dARR:
        case cARR:
        case sARR:
            return addARR(leaf, orchird);
        default: break;
    }

    return 0;
}

int addNumeric (Node * leaf, Orchird * orchird){
    if (!leaf) return 0;
    return add(leaf, &orchird->numerics);
}

int addAlphabetic (Node * leaf, Orchird * orchird){
    if (!leaf) return 0;
    return add(leaf, &orchird->alphabetics);
}

int addARR (Node * leaf, Orchird * orchird){
    if (!leaf) return 0;
    return add(leaf, &orchird->arrays);
}


Node cut(Node * leaf){

}

Node trim(dtype type, Pouch data, Tree* tree){
    if (!tree) return NULL;
    Node * slave=NULL;
    switch (tree->holds){
        case ALPHA:
            switch (type){
                case CHAR:
                case STR:
                case cPTR:
                case sPTR: slave=findAlpha( type, data, tree);
                default:break;
            }
            break;
        case NUM:
            switch (type){
                case INT:
                case DOUBLE:
                case FLOAT:
                case iPTR:
                case dPTR:
                case fPTR: slave=findNum(  type, data, tree);
                default:break;
            }
            break;
        case ARR:
            switch (type){
                case cARR:
                case sARR:
                case iARR:
                case dARR:
                case fARR: slave=findARR(  type, data, tree);
                default:break;
            }
        default: break;
    }
}