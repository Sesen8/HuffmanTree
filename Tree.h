/*
 Filename: Tree.h
 Description: Includes the data memebers and methods for the tree class
 Author: Sesen Yonas
 Date: 05/31/2022
 Course: Data Structures II
*/

#ifndef HUFFMAN_SESEN8_TREE_H
#define HUFFMAN_SESEN8_TREE_H
#include "Data.h"
#include "Encoding.h"
#include <iostream>
#include <vector>
using std::vector;

struct Node{
    string _info;
    int _freq;
    Node* left = nullptr;
    Node* right = nullptr;

};

class Tree{

    Node* _root;
    void TreeTableMem(Node* root, vector<Encoding>& encodingTable, string encoding);
    void TreeClear(Node* node);

public:
    Tree();
    ~Tree();
    void DataToNode(const vector<Data>& freqTable, vector<Node*>& node);
    void TreeMaker(vector<Node*>& node);
    void TreeTable(vector<Encoding>& encodingTable);
    void SingleChar(vector<Encoding>& encodingTable, const char* c);






};


#endif //HUFFMAN_SESEN8_TREE_H
