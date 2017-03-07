/*************************************************************************
	> File Name: cosSimilar.h
	> Author: lumujin
	> Mail: lumujin@icloud.com 
	> Created Time: 2014年09月26日 星期五 10时53分04秒
 ************************************************************************/

#include<iostream>
#include<math.h>
using namespace std;

//计算两个向量的相似度
//参数dimension是向量维度
//返回double类型的数值，越接近1越相似
double cosSimilar(int dimension, int vector_A[], int vector_B[]){
    double score = 0;
    double sum = 0;
    double sq_A = 0, sq_B = 0;

    for (int i = 0; i < dimension; i++){
        sum += vector_A[i] * vector_B[i];
        sq_A += vector_A[i] * vector_A[i];
        sq_B += vector_B[i] * vector_B[i];
    }

    score = sum / (sqrt(sq_A) * sqrt(sq_B));

    return score;
}
