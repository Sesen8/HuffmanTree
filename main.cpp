//
// Created by Sesen Yonas on 5/31/22.
//

#include "Data.h"
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
    char c;
    map<char,int> myMap;
    do{

        if(file.empty()){
            cout << "Could not find file." << endl;
            continue;
        }

        input.open(file);
        if(!input.is_open()){
            cout << "Could not open file." << endl;
            continue;
        }
    }while(!input.is_open());

    do {
        input>>c;
        if(myMap.count(c) > 0){
            myMap.at(c)++;
        }
        else{
            myMap.insert(std::pair<char,int>(c,1));
        }

    } while(!input.eof());


    for(std::pair<char,int> i: myMap){

        TableInfo.push_back(Data(i.second,i.first));

    }

    sort(TableInfo.begin(),TableInfo.end(),Compare);
    for(Data x: TableInfo){
        cout << x.GetFreqeuncy() << " " << x.GetLetter() << endl;

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