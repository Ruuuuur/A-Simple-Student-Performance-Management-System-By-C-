#ifndef CHOICE_H
#define CHOICE_H
#include "Student.h"
#include "BiTree.h"
#include <stdlib.h>
#include "NameHash.h"

void printHeader(){  //打印表头
     std::cout<<std::setw(14)<<std::left<<"学号"<<std::setw(10)<<std::left<<"姓名"<<std::setw(10)<<
     std::left<<"性别"<<std::setw(10)<<std::left<<"英语成绩"<<std::setw(10)<<std::left<<"数学成绩"<<std::setw(10)
     <<std::left<<"程序设计"<<std::setw(10)<<std::left<<"数据结构"<<std::setw(10)<<std::left<<"总分"<<std::setw(10)<<std::left<<"排名"<<std::endl;
}
   
bool checkNum(std::string str){  //判断字符串是否为纯数字
    for(auto i:str){
           if(!isdigit(i)){
               return false;
           } 
        }
        return true;
}

bool checkName(std::string str){  //判断字符串是否为纯字母或空格
    for(auto i:str){
           if(!isalpha(i) && i!=' '){
               return false;
           }
    }
    return true;
}

void merge(Student* arr[], int l, int mid, int r){  //合并两个有序数组
    int i = l, j = mid+1, k = l;
    int n1 = mid - l + 1;
    int n2 = r - mid;
    Student* L[n1];
    Student* R[n2];
    for(int i = 0; i < n1; i++){
        L[i] = arr[l+i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = arr[mid+1+j];
    }
    while(i <= mid && j <= r){
        if(L[i-l]->getTotal() <= R[j-mid-1]->getTotal()){
            arr[k] = L[i-l];
            i++;
        }else{
            arr[k] = R[j-mid-1];
            j++;
        }
        k++;
    }
    while(i <= mid){
        arr[k] = L[i-l];
        i++;
        k++;
    }
    while(j <= r){
        arr[k] = R[j-mid-1];
        j++;
        k++;
    }
}

void mergesort(Student* arr[], int l, int r){  //归并排序
    if(l < r){
        int mid = (l+r)/2;
        mergesort(arr, l, mid);
        mergesort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

void add_student(BiTree& allStudent, Hash& hashTable){  //添加学生信息
    std::string tId, tName, tGender;
    std::string tEnglish="", tMath="", tProgramming="", tDataStructure="";
    system("cls");
    
    std::cout<<"请输入要添加的学生学号(输入-1返回上级菜单)"<<std::endl;
    while(1){
        std::cin>>tId;
        if(tId == "-1"){
            system("cls");
            return;
        }
        if(checkNum(tId)){
            if(allStudent.searchById(tId)!= NULL){
                bool flag=0;
                std::cout<<"已有相同学号的学生，是否选择替换?(Y/N)"<<std::endl;
                std::string tModify;
                while(1){
                    std::cin>>tModify;
                    if(tModify == "Y" || tModify == "y"){
                        flag=1;
                        break;
                    }else if(tModify == "N" || tModify == "n"){
                        flag=0;
                        system("cls");
                        break;
                    }else if(tModify == "-1"){
                        system("cls");
                        return;
                    }else{
                        std::cout<<"输入有误，请重新输入(输入-1返回上级菜单)"<<std::endl;
                    }
                }
                if(!flag){
                    return;
                }
            }
            break;
        }else{
            std::cout<<"输入有误，请重新输入(输入-1返回上级菜单)"<<std::endl;
        }
    }
    std::cout<<"请输入要添加的学生姓名(输入-1返回上级菜单)"<<std::endl;
    while(1){
        std::cin>>tName;
        if(tName == "-1"){
            system("cls");
            return;
        }
        if(!checkName(tName)){
            std::cout<<"输入有误，请重新输入(输入-1返回上级菜单)"<<std::endl;
        }else{
            break;
        }
    }
    std::cout<<"请输入要添加的学生性别(M/F)(输入-1返回上级菜单)"<<std::endl;
    while(1){
        std::cin>>tGender;
        if(tGender == "-1"){
        system("cls");
        return;
        }
        if(tGender == "M" || tGender == "F" || tGender == "m" || tGender == "f"){
            if(tGender == "m") tGender = "M";
            if(tGender == "f") tGender = "F";
            break;
        }else{
            std::cout<<"输入有误，请重新输入(输入-1返回上级菜单)"<<std::endl;
        }
    }
    
    std::cout<<"请输入要添加的学生英语成绩(输入-1返回上级菜单)"<<std::endl;
    while(1){
        std::cin>>tEnglish;
        if(tEnglish == "-1"){
            system("cls");
            return;
        }
        if(!checkNum(tEnglish)){
            std::cout<<"输入有误，请重新输入(输入-1返回上级菜单)"<<std::endl;
            continue;
        }
        int ttEnglish = std::stoi(tEnglish);
        if(ttEnglish >= 0 && ttEnglish <= 100){
            break;
        }else{
            std::cout<<"输入有误，请重新输入(输入-1返回上级菜单)"<<std::endl;
        }  
    }

    std::cout<<"请输入要添加的学生数学成绩(输入-1返回上级菜单)"<<std::endl;
    while(1){
        std::cin>>tMath;
        if(tMath == "-1"){
            system("cls");
            return;
        }
        if(!checkNum(tMath)){
            std::cout<<"输入有误，请重新输入(输入-1返回上级菜单)"<<std::endl;
            continue;
        }
        int ttMath = std::stoi(tMath);
        if(ttMath >= 0 && ttMath <= 100){
            break;
        }else{
            std::cout<<"输入有误，请重新输入(输入-1返回上级菜单)"<<std::endl;
        }
    }
    
    std::cout<<"请输入要添加的学生程序设计成绩(输入-1返回上级菜单)"<<std::endl;
    while(1){
        std::cin>>tProgramming;
         if(tProgramming == "-1"){
            system("cls");
            return;
        }
        if(!checkNum(tProgramming)){
            std::cout<<"输入有误，请重新输入(输入-1返回上级菜单)"<<std::endl;
            continue;
        }
        int ttProgramming = std::stoi(tProgramming);
        if(ttProgramming >= 0 && ttProgramming <= 100){
            break;
        }else{
            std::cout<<"输入有误，请重新输入(输入-1返回上级菜单)"<<std::endl;
        }
    }
    
    std::cout<<"请输入要添加的学生数据结构成绩(输入-1返回上级菜单)"<<std::endl;
    while(1){
        std::cin>>tDataStructure;
        if(tDataStructure == "-1"){
            system("cls");
            return;
        }
        if(!checkNum(tDataStructure)){
            std::cout<<"输入有误，请重新输入(输入-1返回上级菜单)"<<std::endl;
            continue;
        }
        int ttDataStructure = std::stoi(tDataStructure);
        if(ttDataStructure >= 0 && ttDataStructure <= 100){
            break;
        }else{
            std::cout<<"输入有误，请重新输入(输入-1返回上级菜单)"<<std::endl;
        }
    }

    Student* tStudent = new Student(tId, tName, tGender, stoi(tEnglish), stoi(tMath), stoi(tProgramming), stoi(tDataStructure), 0);
    std::string flag = allStudent.insert(tStudent);
    if(flag != ""){ //有相同学号的学生，在哈希表中需要先删除该学号的学生信息
        hashTable.remove(flag);
    }
    hashTable.insert(tStudent);
    system("cls");
    std::cout<<"添加成功!"<<std::endl;
}

void update_student(BiTree& allStudent){ //修改学生信息
    system("cls");
    int Select=0;
    std::string tId;
    system("cls");
    std::cout<<"请输入要修改的学生学号(输入-1返回上级菜单)"<<std::endl;
    while(1){ 
        std::cin>>tId;
        if(tId == "-1"){
            system("cls");
            return;
        }
        if(checkNum(tId)){
            BiTreeNode* tNode = allStudent.searchById(tId);
            if(tNode == NULL){ 
                std::cout<<"未查询到学生信息!"<<std::endl;
                std::cout<<"如要继续修改,请重新输入学号,否则输入-1返回上级菜单"<<std::endl;
            }else{ 
                system("cls");
                std::cout<<"该学生当前信息如下:"<<std::endl;
                std::cout<<"学号:"<<tNode->student->getId()<<std::endl;
                std::cout<<"姓名:"<<tNode->student->getName()<<std::endl;
                std::cout<<"性别:"<<tNode->student->getGender()<<std::endl;
                std::cout<<"英语成绩:"<<tNode->student->getEnglish()<<std::endl;
                std::cout<<"数学成绩:"<<tNode->student->getMath()<<std::endl;
                std::cout<<"程序设计成绩:"<<tNode->student->getProgramming()<<std::endl;
                std::cout<<"数据结构成绩:"<<tNode->student->getDataStructure()<<std::endl;
                std::cout<<"请选择要修改的项目(输入-1返回上级菜单):"<<std::endl;
                std::cout<<"1.英语成绩 2.数学成绩 3.程序设计成绩 4.数据结构成绩"<<std::endl;
                std::string tChoice="";
                while(1){
                    std::cin>>tChoice;
                    if(tChoice == "-1"){
                        system("cls");
                        return;
                    }
                    if(!checkNum(tChoice)){
                        std::cout<<"输入有误，请重新输入(输入-1返回上级菜单)"<<std::endl;
                        continue;
                    }
                    if(stoi(tChoice) >= 1 && stoi(tChoice) <= 4){
                        switch(stoi(tChoice)){
                            case 1:
                                std::cout<<"请输入新的英语成绩(输入-1返回上级菜单):"<<std::endl;
                                while(1){
                                    std::string newEnglihs;
                                    std::cin>>newEnglihs;
                                    if(newEnglihs == "-1"){
                                        system("cls");
                                        return;
                                    }
                                    if(stoi(newEnglihs) >= 0 && stoi(newEnglihs) <= 100){
                                        tNode->student->setEnglish(stoi(newEnglihs));
                                        break;
                                    }else{
                                        std::cout<<"输入有误，请重新输入(输入-1返回上级菜单)"<<std::endl;
                                    }
                                }
                            break;
                            case 2:
                                std::cout<<"请输入新的数学成绩(输入-1返回上级菜单):"<<std::endl;
                                while(1){
                                    std::string newMath;
                                    std::cin>>newMath;
                                    if(newMath == "-1"){
                                        system("cls");
                                        return;
                                    }
                                    if(stoi(newMath) >= 0 && stoi(newMath) <= 100){
                                        tNode->student->setMath(stoi(newMath));
                                        break;
                                    }else{
                                        std::cout<<"输入有误，请重新输入(输入-1返回上级菜单)"<<std::endl;
                                    }
                                }
                            break;
                            case 3:
                                std::cout<<"请输入新的程序设计成绩(输入-1返回上级菜单):"<<std::endl;
                                while(1){
                                    std::string newProgramming;
                                    std::cin>>newProgramming;
                                    if(newProgramming == "-1"){
                                        system("cls");
                                        return;
                                    }
                                    if(stoi(newProgramming) >= 0 && stoi(newProgramming) <= 100){
                                        tNode->student->setProgramming(stoi(newProgramming));
                                        break;
                                    }else{
                                        std::cout<<"输入有误，请重新输入(输入-1返回上级菜单)"<<std::endl;
                                    }
                                }
                            break;
                            case 4:
                                std::cout<<"请输入新的数据结构成绩(输入-1返回上级菜单):"<<std::endl;
                                while(1){
                                    std::string newDataStructure;
                                    std::cin>>newDataStructure;
                                    if(newDataStructure == "-1"){
                                        system("cls");
                                        return;
                                    }
                                    if(stoi(newDataStructure) >= 0 && stoi(newDataStructure) <= 100){
                                        tNode->student->setDataStructure(stoi(newDataStructure));
                                        break;
                                    }else{
                                        std::cout<<"输入有误，请重新输入(输入-1返回上级菜单)"<<std::endl;
                                    }
                                }
                            break;
                        }
                        system("cls");
                        std::cout<<"修改成功!"<<std::endl;
                        std::cout<<"该学生当前信息如下:"<<std::endl;
                        std::cout<<"学号:"<<tNode->student->getId()<<std::endl;
                        std::cout<<"姓名:"<<tNode->student->getName()<<std::endl;
                        std::cout<<"性别:"<<tNode->student->getGender()<<std::endl;
                        std::cout<<"英语成绩:"<<tNode->student->getEnglish()<<std::endl;
                        std::cout<<"数学成绩:"<<tNode->student->getMath()<<std::endl;
                        std::cout<<"程序设计成绩:"<<tNode->student->getProgramming()<<std::endl;
                        std::cout<<"数据结构成绩:"<<tNode->student->getDataStructure()<<std::endl;
                        std::cout<<"如还需要继续更改,请选择修改项目1.英语成绩 2.数学成绩 3.程序设计成绩 4.数据结构成绩"<<std::endl;
                        std::cout<<"否则输入-1返回上级菜单"<<std::endl;
                    }else{
                        std::cout<<"输入有误，请重新输入(输入-1返回上级菜单)"<<std::endl;
                    }
                }
            }
            //std::cout<<""<<std::endl;            
        }else{
            std::cout<<"输入有误，请重新输入(输入-1返回上级菜单)"<<std::endl;
        }
    }
}

void search_student(BiTree& allStudent, Hash& hashTable){  //查询学生信息
    system("cls");
    std::string Select="";
    int n = allStudent.getSize(allStudent.getRoot());
    Student** arr = new Student*[n];  
    int tem = -1;
    allStudent.transmit(arr, tem, allStudent.getRoot());
    mergesort(arr, 0, n-1);   //排序, 更新排名
    int nowRank = 1;
    for(int i = n-1; i >=0; --i){
        if(i==n-1){
            arr[i]->setRank(1);
            nowRank ++;
        }else if(arr[i]->getTotal() == arr[i+1]->getTotal()){
            arr[i]->setRank(arr[i+1]->getRank());
            nowRank ++;
        }else{
            arr[i]->setRank(nowRank);
            nowRank++;
        }
    }
    delete[] arr;
    std::cout<<"请输入查询方式1.按学号查询 2.按姓名查询(输入-1返回上级菜单)"<<std::endl;
    while(1){
        std::cin>>Select;
        if(Select == "-1"){
            system("cls");
            return;
        }
        if(!checkNum(Select)){
            std::cout<<"输入有误，请重新输入(输入-1返回上级菜单)"<<std::endl;
            continue;
        }
        if(stoi(Select) == 1){
            std::string tId;
            std::cout<<"请输入要查询的学生学号(输入-1返回上级菜单):"<<std::endl;
            while(1){
                std::cin>>tId;
                if(tId == "-1"){
                    system("cls");
                    search_student(allStudent,hashTable);
                    return;
                }
                if(checkNum(tId)){
                    BiTreeNode* tNode = allStudent.searchById(tId);
                    if(tNode == NULL){
                        std::cout<<"未查询到学生信息!"<<std::endl;
                        std::cout<<"如要继续学号查询，请输入学号，否则输入-1返回上级菜单"<<std::endl;
                    }else{ 
                        system("cls");
                        std::cout<<"查询到学号为"<<tNode->student->getId()<<"的学生信息如下:"<<std::endl;
                        printHeader();
                        tNode->student->printInfo();
                        std::cout<<"如要继续学号查询，请输入学号，否则输入-1返回上级菜单"<<std::endl;
                    }
                }else{
                    std::cout<<"输入有误，请重新输入(输入-1返回上级菜单)"<<std::endl;
                }
            }
        }else if(stoi(Select) == 2){
            std::string tName;
            std::cout<<"请输入要查询的学生姓名(输入-1返回上级菜单):"<<std::endl;
            while(1){
                std::cin>>tName;
                if(tName == "-1"){
                    system("cls");
                    search_student(allStudent,hashTable);
                    return;
                }
                if(!checkName(tName)){
                    std::cout<<"输入有误，请重新输入(输入-1返回上级菜单)"<<std::endl;
                    continue;
                }
                if(!hashTable.OutputAll(tName)){ 
                    std::cout<<"未查询到学生信息!"<<std::endl;
                }
                std::cout<<"如要继续姓名查询，请输入姓名，否则输入-1返回上级菜单"<<std::endl;
            }
        }else{
            std::cout<<"输入有误，请重新输入(输入-1返回上级菜单)"<<std::endl;
        }
    }

};

void print_student(BiTree& allStudent){
    system("cls");
    if(allStudent.isEmpty()){
        std::cout<<"暂无学生信息!"<<std::endl;
        return;
    }

    int n = allStudent.getSize(allStudent.getRoot());
    Student** arr = new Student*[n];
    int tem = -1;
    allStudent.transmit(arr, tem, allStudent.getRoot());
    mergesort(arr, 0, n-1);  //排序, 更新排名
    int nowRank = 1;
    for(int i = n-1; i >=0; --i){
        if(i==n-1){
            arr[i]->setRank(1);
            nowRank ++;
        }else if(arr[i]->getTotal() == arr[i+1]->getTotal()){
            arr[i]->setRank(arr[i+1]->getRank());
            nowRank ++;
        }else{
            arr[i]->setRank(nowRank);
            nowRank++;
        }
    }

    std::cout<<"请选择排序方式:1.默认排序 2.按总分降序输出(输入-1返回上级菜单)"<<std::endl;
    std::string tChoice="";
    while(1){
        std::cin>>tChoice;
        if(stoi(tChoice) == -1){
            system("cls");
            return;
        }
        if(stoi(tChoice) == 1){
              printHeader();
              allStudent.outputByIdAsc();
        }else if(stoi(tChoice) == 2){
            printHeader();
            for(int i=n-1; i>=0; --i){
                arr[i]->printInfo();
            }
        }else{
            std::cout<<"输入有误，请重新输入(输入-1返回上级菜单)"<<std::endl;
        }
        std::cout<<"如要继续排序,请输入排序方式1.默认排序 2.按总分降序输出(输入-1返回上级菜单)"<<std::endl;
    }
    delete[] arr;
};

#endif // CHOICE_H