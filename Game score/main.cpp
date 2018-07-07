//
//  main.cpp
//  Game score
//
//  Created by 20161104607 on 18/6/25.
//  Copyright © 2018年 20161104607. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <String>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;


int menu_select()//菜单
{
    int MenuItem;
    
    printf("\n ");
    printf("          | *********评分系统********* |           \n");
    printf("          | ---------------------------------- |          \n");
    printf("          |              主菜单项              |          \n");
    printf("          | ---------------------------------- |          \n");
    printf("          |	  1 ---  读取裁判信息  ---       |          	  \n");
    printf("          |	  2 ---  裁判评分	 ---      |              \n");
    printf("          |	  3 ---  读取学生信息	---       |              \n");
    printf("          |	  4 ---  排序  ---       |              \n");
    printf("          |	  5 ---  退出系统  ---     |              \n");
    
    do
    {
        printf("\n请输入选项（1－5）：");
        fflush(stdin);
        scanf("%d",&MenuItem);
    }while(MenuItem<1||MenuItem>4);
    
    return MenuItem;
}


string Trim(string& str)
{
    str.erase(0,str.find_first_not_of(" \t\r\n"));
    str.erase(str.find_last_not_of(" \t\r\n") + 1);
    return str;
}


void input()
{
    int i,j,a=0,b=101,c=0;
    double average;
    
    
    cout<<"请输入选手成绩"<<endl;
    for(i=1;i<=5;i++)
    {
        cout<<"第"<<i<<"位评委给分：";
        cin>>j;
        a=max(a,j);
        b=min(b,j);
        c=c+j;
    }
    average=(c-a-b)/5;
    cout<<"减去一个最高分"<<a<<","<<"减去一个最低分"<<b<<endl;
    cout<<"该选手的最后得分："<<average<<endl;
    
}


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



void loads()
    {
        
        //int i,j,temp,score[8];
        //float ave=0;
        ifstream fin("/Users/a20161104607/Desktop/Game score/rater.csv");
        
        string line;
        while (getline(fin, line))
        {
            //cout << line << endl;
            
            istringstream sin(line);
            vector<string> fields;
            string field;
            while (getline(sin, field, ','))
            {
                fields.push_back(field);
            }
            string name = Trim(fields[0]);
            string age = Trim(fields[1]);
            string birthday = Trim(fields[2]);
            cout << name << "\t" << age << "\t" << birthday << endl;
        }
        
    }
void student_information()
{
    
    //int i,j,temp,score[8];
    //float ave=0;
    ifstream fin("/Users/a20161104607/Desktop/Game score/racer .csv");
    
    string line;
    while (getline(fin, line))
    {
        //cout << line << endl;
        
        istringstream sin(line);
        vector<string> fields;
        string field;
        while (getline(sin, field, ','))
        {
            fields.push_back(field);
        }
        string name = Trim(fields[0]);
        string age = Trim(fields[1]);
        string birthday = Trim(fields[2]);
        cout << name << "\t" << age << "\t" << birthday << endl;
    }
    
}



int main()
{
    
    while(1)
    {
        switch(menu_select())
        {
            case 1:
                loads();
                break;
            case 2:
                input();
                break;
              
            case 3:
                student_information();
                break;
            case 4:

                printf("Thank you for using！\n");
                return 0;
        }
        

    }
}
