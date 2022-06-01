//
// Created by Sesen Yonas on 5/25/22.
//



#ifndef HUFFMAN_SESEN8_DATA_H
#define HUFFMAN_SESEN8_DATA_H


class Data {
private:
    int _freq;
    char _letter;
public:

    Data(int frequency, char letter);
    int GetFreqeuncy() const;
    char GetLetter() const;
    void SetFrequency(int frequency);
    void SetLetter(char letter);

};


#endif //HUFFMAN_SESEN8_DATA_H
