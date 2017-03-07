/*************************************************************************
	> File Name: src/vectorConstruct.h
	> Author: lumujin
	> Mail: lumujin@icloud.com 
	> Created Time: 2014年09月26日 星期五 11时36分12秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

//建立空间向量
//输入：两个独立词向量
//输出：两个数字空间向量（同一基向量）
int ** vectorConstruct(vector<string> vector_A, vector<string> vector_B){
    vector<string> words;
    //统计所有词
    for (int i = 0; i < vector_A.size(); i++){
        int flag = 1;
        for (int j = 0; j < words.size(); j++){
            if (vector_A[i] == words[j]){
                flag = 0;
                break;
            }
        }
        if (flag){
            string word = vector_A[i];
            words.push_back(word);    
        }
    }

    for (int i = 0; i < vector_B.size(); i++){
        int flag = 1;
        for (int j = 0; j < words.size(); j++){
            if (vector_B[i] == words[j]){
                flag = 0;
                break;
            }
        }
        if (flag){
            string word = vector_B[i];
            words.push_back(word);    
        }
    }

    //词频统计
    int count = words.size();
    int **a;
    a = new int *[3];
    a[0] = new int[count];
    a[1] = new int[count];
    a[2] = new int[1];
    a[2][0] = count;
    for (int i = 0; i < count; i++){
        a[0][i] = 0;
        a[1][i] = 0;
        
        for (int j = 0; j < vector_A.size(); j++){
            if (words[i] == vector_A[j]){
                a[0][i]++;
            }
        }
        
        for (int j = 0; j < vector_B.size(); j++){
            if (words[i] == vector_B[j]){
                a[1][i]++;
            }
        }
    }

    return a;
} 
