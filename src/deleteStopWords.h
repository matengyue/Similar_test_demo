/*************************************************************************
	> File Name: deleteStopWords.h
	> Author: lumujin
	> Mail: lumujin@icloud.com 
	> Created Time: 2014年09月26日 星期五 17时17分28秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<stdexcept>
using namespace std;

//从文件中读取每行的信息存入vector
vector<string> ReadAllLinesFromFile(const string &fn){
    vector<string> result;
    ifstream ifs(fn);

    //文件异常
    if (!ifs){
        throw runtime_error("Cannot open file!");
    }
    string tmp;
    while (ifs){
        getline(ifs, tmp);
        result.push_back(tmp);
    }
    result.erase(result.end() - 1);

    return result;
}

//去停用词函数
//输入：词向量
//输出：去停用词后的词向量
vector<string> deleteStopWords(vector<string> vectorwords){
    vector<string> vectorwordsNStop;

    vector<string> stopwords = ReadAllLinesFromFile("../src/StopWord.txt");

    for (int i = 0; i < vectorwords.size(); i++){
        int flag = 1;
        for (int j = 0; j < stopwords.size(); j++){
            if (vectorwords[i] == stopwords[j]){
                flag = 0;
                break;
            }
        }
        if (flag){
            string word = vectorwords[i];
            vectorwordsNStop.push_back(word);    
        }
    }
    
    return vectorwordsNStop;
}
