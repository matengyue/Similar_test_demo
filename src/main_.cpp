/*************************************************************************
	> File Name: main_.cpp
	> Author: lumujin
	> Mail: lumujin@icloud.com 
	> Created Time: 2014年09月26日 星期五 11时13分14秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include"cosSimilar.h"
#include"vectorConstruct.h"
#include"deleteStopWords.h"
using namespace std;

int main(int argc, char **argv){
    string path_x = "../src/read_x";
    string path_y = "../src/read_y";
    string str_x;
    string str_y;

    if (argc == 4 && string(argv[1]) == "-w"){
        str_x = "python ../src/jiebaCutW.py " + string(argv[2]) + " > ../src/result_x";
        str_y = "python ../src/jiebaCutW.py " + string(argv[3]) + " > ../src/result_y";
    }
    else if (argc == 4 && string(argv[1]) == "-t"){
        path_x = argv[2];
        path_y = argv[3];
        str_x = "python ../src/jiebaCut.py " + path_x + " > ../src/result_x";
        str_y = "python ../src/jiebaCut.py " + path_y + " > ../src/result_y";
    }
    else {
        str_x = "python ../src/jiebaCut.py " + path_x + " > ../src/result_x";
        str_y = "python ../src/jiebaCut.py " + path_y + " > ../src/result_y";
    }

    system(str_x.c_str());
    system(str_y.c_str());
    
    vector<string> x = ReadAllLinesFromFile("../src/result_x");
    vector<string> y = ReadAllLinesFromFile("../src/result_y");

    x = deleteStopWords(x);
    y = deleteStopWords(y);

    int **a = vectorConstruct(x, y);
    double score = cosSimilar(a[2][0], a[0], a[1]);

    //cout << score << endl;

    if (score <= 0.31){
        cout << "不相关。" << endl;
    }
    else if (score <= 0.69){
        cout << "相关。" << endl;
    }
    else if (score <= 0.95){
        cout << "比较相似。" << endl;
    }
    else {
        cout << "非常相似。" << endl;
    }
    return 0;
}
