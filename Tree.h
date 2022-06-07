//
// Created by Sesen Yonas on 5/25/22.
//

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
    void TreeTableMem(Node* root, vector<Encoding> encodingTable, string encoding);

public:
    Tree();
    ~Tree();
    void DataToNode(const vector<Data>& freqTable, vector<Node*>& node);
    void TreeMaker(vector<Node*>& node);
    void TreeTable(vector<Encoding>& encodingTable);






};


#endif //HUFFMAN_SESEN8_TREE_H
