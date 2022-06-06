//
// Created by Sesen Yonas on 5/25/22.
//
#include "Data.h"
#ifndef HUFFMAN_SESEN8_TREE_H
#define HUFFMAN_SESEN8_TREE_H

#include <iostream>
#include <vector>
using std::vector;

struct Node{
    char _info;
    int _freq;
    Node* left = nullptr;
    Node* right = nullptr;

};

class Tree{

    Node* _root;
public:
    Tree();
    ~Tree();
    void DataToNode(vector<Data> freq, vector<Node*> node);
    void TreeMaker(vector<Node*> node);




};


#endif //HUFFMAN_SESEN8_TREE_H
