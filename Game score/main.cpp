//
//  main.cpp
//  Game score
//
//  Created by 20161104607 on 18/6/25.
//  Copyright © 2018年 20161104607. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int max (int x,int y);
int min (int x,int y);

int max(int x, int y)
{
    if(x>y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

int min(int x, int y)
{
    if(x>y)
    {
        return y;
    }
    else
    {
        return x;
    }
    return 0;
}


string Trim(string& str)
{
    str.erase(0,str.find_first_not_of(" \t\r\n"));
    
    str.erase(str.find_last_not_of(" \t\r\n") + 1);
    
    return str;
}




int main()
{
    int a=0,b=101,c=0,i,j;
    double average;
    
    ifstream fin("/Users/a20161104607/Desktop/Game score/rater.csv"); //打开文件流操作
        string line;
        while (getline(fin, line))   //整行读取，换行符“\n”区分，遇到文件尾标志eof终止读取
        {
            cout << line << endl; //整行输出
            istringstream sin(line); //将整行字符串line读入到字符串流istringstream中
            vector<string> fields; //声明一个字符串向量
            string field;
            while (getline(sin, field, ',')) //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符
            {
                fields.push_back(field); //将刚刚读取的字符串添加到向量fields中
            }
            string name = Trim(fields[0]); //清除掉向量fields中第一个元素的无效字符，并赋值给变量name
            string num = Trim(fields[1]); //清除掉向量fields中第二个元素的无效字符，并赋值给变量num
            string sex= Trim(fields[2]); //清除掉向量fields中第三个元素的无效字符，并赋值给变量sex
            cout <<"处理之后的字符串："<< name << "\t" << num << "\t" << sex << endl;
            
        }
    
    
            cout<<"请输入选手成绩"<<endl;
            for(i=1;i<=10;i++)
            {
                cout<<"第"<<i<<"位评委给分：";
                cin>>j;
                a=max(a,j);
                b=min(b,j);
                c=c+j;
            }
            average=(c-a-b)/8;
            cout<<"减去一个最高分"<<a<<","<<"减去一个最低分"<<b<<endl;
            cout<<"该选手的最后得分："<<average<<endl;
    return 0;
        }


            






