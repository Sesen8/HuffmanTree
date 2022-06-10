/*
 Filename: Encoding.cpp
 Description: Includes the constructor getters and setters for encoding functions
 Author: Sesen Yonas
 Date: 05/31/2022
 Course: Data Structures II
*/

#include "Encoding.h"

Encoding::Encoding(string char1, string bits) {
    _char = char1;
    _bits = bits;

}

string Encoding::GetChar() const {
    return _char;
}

string Encoding::GetBits() const {
    return _bits;
}

void Encoding::SetChar(string char1) {
    _char = char1;

}

void Encoding::SetBits(string bits) {
    _bits = bits;

}
