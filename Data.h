//
// Created by Sesen Yonas on 5/25/22.
//



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
