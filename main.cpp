//// Created by Sesen Yonas on 5/31/22.//#include "Data.h"#include "Tree.h"#include <iostream>#include <fstream>#include <istream>#include <string>#include <map>#include <vector>#include <cstring>#include <bits/stdc++.h>using std::fstream;using std::sort;using std::vector;using std::string;using std::istream;using std::ifstream;using std::cout;using std::cin;using std::getline;using std::endl;using std::map;using std::iostream;bool Compare(Data val1, Data val2){    if((val1.GetFreqeuncy() == val2.GetFreqeuncy())){        //if(val1.GetLetter() == "CR")        return (val1.GetLetter() > val2.GetLetter());    }    else{        return (val1.GetFreqeuncy() > val2.GetFreqeuncy());    }}int TableMaker(string file, vector<Data>& TableInfo){    ifstream input;    string line;    string c;    char character;    int otherchar = 0;    map<string,int> myMap;        if(file.empty()){            cout << "Could not find file." << endl;            return -1;        }        input.open(file);        if(!input.is_open()){            cout << "Could not open file." << endl;            return -1;        }    do {        string newChar = "";        input.get(character);        newChar += character;        if(character>0){            if(character != '\r' && character != '\n' ) {                if(myMap.count(newChar) > 0){                    myMap.at(newChar)++;                }                else{                    myMap.insert(std::pair<string,int>(newChar,1));                }            }            else if(character == '\r'){                //cout << "Test" << endl;                if(myMap.count("CR") > 0){                    myMap.at("CR")++;                }                else{                    myMap.insert(std::pair<string,int>("CR",1));                }            }            else if(character == '\n'){                if(myMap.count("LF") > 0){                    myMap.at("LF")++;                }                else{                    myMap.insert(std::pair<string,int>("LF",1));                }            }        }//        for(size_t i=0; i<c.size(); i++){//            char currcharacter = c.at(i);//            if(myMap.count(currcharacter) > 0){//                myMap.at(currcharacter)++;//            }//            else{//                myMap.insert(std::pair<char,int>(currcharacter,1));//            }//        }    } while(!input.eof());    if(myMap.count("CR") > 0 && myMap.at("CR") > 1){        myMap.at("CR")--;    }    if(myMap.count("LF") > 0 && myMap.at("LF") > 1){        myMap.at("LF")--;    }    //myMap.insert(std::pair<char,int>('\r',otherchar));    for(std::pair<string,int> i: myMap){        TableInfo.push_back(Data(i.second,i.first));    }    sort(TableInfo.begin(),TableInfo.end(),Compare);    for(Data x: TableInfo){        cout << "{element: " << x.GetLetter() << ", frequency: " << x.GetFreqeuncy() << "}" << endl;    }    return 0;}int main (int argc, char* argv[]){    vector<Data> TableInfo;    if(strcmp("-encode",argv[1]) ==0 ){    }    if(strcmp("-single",argv[1]) ==0){        string file(argv[2]);        TableMaker(file,TableInfo);        Tree test;        vector<Node*>node;        test.DataToNode(TableInfo, node);        vector<Encoding> encodeData;        test.TreeTable(encodeData);        for(Encoding x: encodeData){            cout << "{key: " << x.GetChar() << ", code: " << x.GetBits() << "}" << endl;        }    }    if(strcmp("-frequency",argv[1])==0){        string file(argv[2]);        TableMaker(file,TableInfo);    }    if(strcmp("-endcoding-table",argv[1]) ==0){    }    return 0;};