/*
 Filename: Data.h
 Description: Includes the data memebers and methods for the data class
 Author: Sesen Yonas
 Date: 05/31/2022
 Course: Data Structures II
*/



#ifndef HUFFMAN_SESEN8_DATA_H
#define HUFFMAN_SESEN8_DATA_H

#include <string>
using std::string;

class Data {
private:
    int _freq;
    string _letter;
public:

    Data(int frequency, string letter);
    int GetFreqeuncy() const;
    string GetLetter() const;
    void SetFrequency(int frequency);
    void SetLetter(string letter);

};


#endif //HUFFMAN_SESEN8_DATA_H
