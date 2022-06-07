//
// Created by Sesen Yonas on 5/25/22.
//

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