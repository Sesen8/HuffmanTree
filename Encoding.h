//
// Created by Sesen Yonas on 6/1/22.
//

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


