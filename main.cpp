//
// Created by Sesen Yonas on 5/31/22.
//

#include "Data.h"
#include "Tree.h"
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <map>
#include <vector>
#include <cstring>
#include <bits/stdc++.h>

using std::fstream;
using std::sort;
using std::vector;
using std::string;
using std::istream;
using std::ifstream;
using std::cout;
using std::cin;
using std::getline;
using std::endl;
using std::map;
using std::iostream;

bool Compare(Data val1, Data val2){
    if((val1.GetFreqeuncy() == val2.GetFreqeuncy())){
        return (val1.GetLetter() < val2.GetLetter());
    }
    else{
        return (val1.GetFreqeuncy() > val2.GetFreqeuncy());
    }

}

int TableMaker(string file, vector<Data>& TableInfo){
    ifstream input;
    string line;
    string c;
    char character;
    int otherchar = 0;
    map<char,int> myMap;


        if(file.empty()){
            cout << "Could not find file." << endl;
            return -1;
        }

        input.open(file);
        if(!input.is_open()){
            cout << "Could not open file." << endl;
            return -1;
        }


    do {
        //input.get(character);
        getline(input,c);
        otherchar++;
        for(size_t i=0; i<c.size(); i++){
            char currcharacter = c.at(i);
            if(myMap.count(currcharacter) > 0){
                myMap.at(currcharacter)++;
            }
            else{
                myMap.insert(std::pair<char,int>(currcharacter,1));
            }
        }

    } while(!input.eof());

    myMap.insert(std::pair<char,int>('\r',otherchar));


    for(std::pair<char,int> i: myMap){

        TableInfo.push_back(Data(i.second,i.first));

    }

    sort(TableInfo.begin(),TableInfo.end(),Compare);
    for(Data x: TableInfo){
        cout << "{element: " << x.GetLetter() << ", frequency: " << x.GetFreqeuncy() << "}" << endl;

    }



    return 0;
}





int main (int argc, char* argv[]){
    vector<Data> TableInfo;

    if(strcmp("-encode",argv[1]) ==0 ){

    }
    if(strcmp("-single",argv[1]) ==0){

    }
    if(strcmp("-frequency",argv[1])==0){
        string file(argv[2]);
        TableMaker(file,TableInfo);
    }
    if(strcmp("-endcoding-table",argv[1]) ==0){

    }

    return 0;
};