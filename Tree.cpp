//
// Created by Sesen Yonas on 5/25/22.
//

#include "Tree.h"
#include "Encoding.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using std::cout;
using std::endl;
using std::sort;

Tree::Tree() {
    _root = nullptr;

}

Tree::~Tree() {
    TreeClear(_root);

}

void Tree::DataToNode(const vector<Data>& freqTable, vector<Node*>& node) {

    for(Data j: freqTable){
        Node* newNode = new Node();
        newNode->_info = j.GetLetter();
        newNode->_freq = j.GetFreqeuncy();

        node.push_back(newNode);
    }

    TreeMaker(node);

}

bool SortTree(Node* node1, Node* node2){
    if(node1->_freq == node2->_freq){
        if(node1->_info.size() == node2->_info.size()){
            return (node1->_info > node2->_info);
        }
        return (node1->_info.size() < node2->_info.size());
    }
    else{
        return (node1->_freq > node2->_freq);
    }



}

void Tree::TreeMaker(vector<Node*>& node) {

    while(node.size() >1) {
        Node* last = node.back();
        node.pop_back();
        Node* secondtoLast = node.back();
        node.pop_back();

        Node* newNode = new Node;
        newNode->left = last;
        newNode->right = secondtoLast;
        newNode->_freq = last->_freq + secondtoLast->_freq;
        newNode->_info = last->_info + secondtoLast->_info;
        node.push_back(newNode);
        sort(node.begin(), node.end(), SortTree);

    }
    _root = node.back();

}
bool SortEncode(Encoding val1, Encoding val2){
    if(val1.GetBits().size() == val2.GetBits().size()){
        if(val1.GetBits() == val2.GetBits()){
            return (val1.GetChar() > val2.GetChar());
        }
        return (val1.GetBits() < val2.GetBits());
    }


    return val1.GetBits().size() < val2.GetBits().size();
}

void Tree::TreeTable(vector<Encoding> &encodingTable) {
    TreeTableMem(_root,encodingTable,"");

}

void Tree::TreeTableMem(Node *root, vector<Encoding>& encodingTable, string encoding) {
    if(root->left == NULL && root->right ==NULL){
        encodingTable.push_back(Encoding(root->_info,encoding));
        sort(encodingTable.begin(),encodingTable.end(),SortEncode);
        return;
    }
    if(root->left != NULL){
        TreeTableMem(root->left,encodingTable,encoding+"1");
    }
    if(root->right != NULL){
        TreeTableMem(root->right,encodingTable,encoding+"0");
    }
}

void Tree::SingleChar(vector<Encoding> &encodingTable, const char* c) {
    string letter = c;

    for(Encoding j : encodingTable){
        if (j.GetChar() == letter) {
            cout << j.GetBits() << endl;
        }


    }

}

void Tree::TreeClear(Node *node) {
    if (node == nullptr){
    return;
    }

    TreeClear(node->left);
    TreeClear(node->right);
    delete node;

}

