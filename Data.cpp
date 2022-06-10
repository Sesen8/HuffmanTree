/*
 Filename: Data.cpp
 Description: Includes the constructor getters and setters for the data functions
 Author: Sesen Yonas
 Date: 05/31/2022
 Course: Data Structures II
*/

#include "Data.h"

Data::Data(int frequency, string letter) {
    _freq = frequency;
    _letter = letter;
}

int Data::GetFreqeuncy() const {
    return _freq;
}

string Data::GetLetter() const {
    return _letter;
}

void Data::SetFrequency(int freqeuncy) {
    _freq = freqeuncy;
}

void Data::SetLetter(string letter) {
    _letter = letter;
}