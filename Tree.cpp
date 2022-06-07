//
// Created by Sesen Yonas on 5/25/22.
//

#include "Tree.h"
#include "Encoding.h"
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using std::cout;
using std::endl;
using std::sort;

Tree::Tree() {
    _root = nullptr;

}

Tree::~Tree() {

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
    if((node1->_freq == node2->_freq)){
        return (node1->_info < node2->_info);
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

//    for(Node* x: node){
//        cout << x->_freq << " " << x->_info << endl;
//
//    }


}

void Tree::TreeTable(vector<Encoding> &encodingTable) {
    TreeTableMem(_root,encodingTable,"");

}

void Tree::TreeTableMem(Node *root, vector<Encoding>& encodingTable, string encoding) {
    if(root->left == NULL && root->right ==NULL){
        encodingTable.push_back(Encoding(root->_info,encoding));
        return;
    }
    if(root->left != NULL){
        TreeTableMem(root->left,encodingTable,encoding+"1");
    }
    if(root->right != NULL){
        TreeTableMem(root->right,encodingTable,encoding+"0");
    }

}

