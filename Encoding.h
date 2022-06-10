/*
 Filename: Tree.h
 Description: Includes the data memebers and methods for the encoding class
 Author: Sesen Yonas
 Date: 05/31/2022
 Course: Data Structures II
*/

#ifndef HUFFMAN_SESEN8_ENCODING_H
#define HUFFMAN_SESEN8_ENCODING_H

#include <string>
using std::string;

class Encoding{
    string _char;
    string _bits;

public:

    Encoding(string char1, string bits);
    string GetChar() const;
    string GetBits() const;
    void SetChar(string char1);
    void SetBits(string bits);



};


#endif //HUFFMAN_SESEN8_ENCODING_H


