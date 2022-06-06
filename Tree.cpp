//
// Created by Sesen Yonas on 5/25/22.
//

#include "Tree.h"
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

void Tree::DataToNode(vector<Data> freq, vector<Node*> node) {
    for(Data j: freq){
        Node* newNode = new Node();
        newNode->_info = j.GetLetter();
        newNode->_freq = j.GetFreqeuncy();

        node.push_back(newNode);
    }

}

bool SortTree(Node* node1, Node* node2){
    if((node1->_freq == node2->_freq)){
        return (node1->_info < node2->_info);
    }
    else{
        return (node1->_freq > node2->_freq);
    }



}

void Tree::TreeMaker(vector<Node*> node) {

    while(node.size() >0) {
    Node* last = node.back();
    node.pop_back();
    Node* secondtoLast = node.back();
    node.pop_back();

    Node* newNode = new Node;
    newNode->left = last;
    newNode->right = secondtoLast;
    newNode->_freq = last->_freq + secondtoLast->_freq;

    node.push_back(newNode);
    sort(node.begin(), node.end(), SortTree);

    }
    _root = node.back();

//    for(Node x: node){
//        cout << x._freq << " " << x._info << endl;
//
//    }

}
