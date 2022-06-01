//
// Created by Sesen Yonas on 5/25/22.
//

#include "Data.h"

Data::Data(int frequency, char letter) {
    _freq = frequency;
    _letter = letter;
}

int Data::GetFreqeuncy() const {
    return _freq;
}

char Data::GetLetter() const {
    return _letter;
}

void Data::SetFrequency(int freqeuncy) {
    _freq = freqeuncy;
}

void Data::SetLetter(char letter) {
    _letter = letter;
}