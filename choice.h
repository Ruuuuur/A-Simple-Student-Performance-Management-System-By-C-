#ifndef CHOICE_H
#define CHOICE_H
#include "Student.h"
#include "BiTree.h"
#include <stdlib.h>
#include "NameHash.h"

void printHeader(){  //��ӡ��ͷ
     std::cout<<std::setw(14)<<std::left<<"ѧ��"<<std::setw(10)<<std::left<<"����"<<std::setw(10)<<
     std::left<<"�Ա�"<<std::setw(10)<<std::left<<"Ӣ��ɼ�"<<std::setw(10)<<std::left<<"��ѧ�ɼ�"<<std::setw(10)
     <<std::left<<"�������"<<std::setw(10)<<std::left<<"���ݽṹ"<<std::setw(10)<<std::left<<"�ܷ�"<<std::setw(10)<<std::left<<"����"<<std::endl;
}
   
bool checkNum(std::string str){  //�ж��ַ����Ƿ�Ϊ������
    for(auto i:str){
           if(!isdigit(i)){
               return false;
           } 
        }
        return true;
}

bool checkName(std::string str){  //�ж��ַ����Ƿ�Ϊ����ĸ��ո�
    for(auto i:str){
           if(!isalpha(i) && i!=' '){
               return false;
           }
    }
    return true;
}

void merge(Student* arr[], int l, int mid, int r){  //�ϲ�������������
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

void mergesort(Student* arr[], int l, int r){  //�鲢����
    if(l < r){
        int mid = (l+r)/2;
        mergesort(arr, l, mid);
        mergesort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

void add_student(BiTree& allStudent, Hash& hashTable){  //���ѧ����Ϣ
    std::string tId, tName, tGender;
    std::string tEnglish="", tMath="", tProgramming="", tDataStructure="";
    system("cls");
    
    std::cout<<"������Ҫ��ӵ�ѧ��ѧ��(����-1�����ϼ��˵�)"<<std::endl;
    while(1){
        std::cin>>tId;
        if(tId == "-1"){
            system("cls");
            return;
        }
        if(checkNum(tId)){
            if(allStudent.searchById(tId)!= NULL){
                bool flag=0;
                std::cout<<"������ͬѧ�ŵ�ѧ�����Ƿ�ѡ���滻?(Y/N)"<<std::endl;
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
                        std::cout<<"������������������(����-1�����ϼ��˵�)"<<std::endl;
                    }
                }
                if(!flag){
                    return;
                }
            }
            break;
        }else{
            std::cout<<"������������������(����-1�����ϼ��˵�)"<<std::endl;
        }
    }
    std::cout<<"������Ҫ��ӵ�ѧ������(����-1�����ϼ��˵�)"<<std::endl;
    while(1){
        std::cin>>tName;
        if(tName == "-1"){
            system("cls");
            return;
        }
        if(!checkName(tName)){
            std::cout<<"������������������(����-1�����ϼ��˵�)"<<std::endl;
        }else{
            break;
        }
    }
    std::cout<<"������Ҫ��ӵ�ѧ���Ա�(M/F)(����-1�����ϼ��˵�)"<<std::endl;
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
            std::cout<<"������������������(����-1�����ϼ��˵�)"<<std::endl;
        }
    }
    
    std::cout<<"������Ҫ��ӵ�ѧ��Ӣ��ɼ�(����-1�����ϼ��˵�)"<<std::endl;
    while(1){
        std::cin>>tEnglish;
        if(tEnglish == "-1"){
            system("cls");
            return;
        }
        if(!checkNum(tEnglish)){
            std::cout<<"������������������(����-1�����ϼ��˵�)"<<std::endl;
            continue;
        }
        int ttEnglish = std::stoi(tEnglish);
        if(ttEnglish >= 0 && ttEnglish <= 100){
            break;
        }else{
            std::cout<<"������������������(����-1�����ϼ��˵�)"<<std::endl;
        }  
    }

    std::cout<<"������Ҫ��ӵ�ѧ����ѧ�ɼ�(����-1�����ϼ��˵�)"<<std::endl;
    while(1){
        std::cin>>tMath;
        if(tMath == "-1"){
            system("cls");
            return;
        }
        if(!checkNum(tMath)){
            std::cout<<"������������������(����-1�����ϼ��˵�)"<<std::endl;
            continue;
        }
        int ttMath = std::stoi(tMath);
        if(ttMath >= 0 && ttMath <= 100){
            break;
        }else{
            std::cout<<"������������������(����-1�����ϼ��˵�)"<<std::endl;
        }
    }
    
    std::cout<<"������Ҫ��ӵ�ѧ��������Ƴɼ�(����-1�����ϼ��˵�)"<<std::endl;
    while(1){
        std::cin>>tProgramming;
         if(tProgramming == "-1"){
            system("cls");
            return;
        }
        if(!checkNum(tProgramming)){
            std::cout<<"������������������(����-1�����ϼ��˵�)"<<std::endl;
            continue;
        }
        int ttProgramming = std::stoi(tProgramming);
        if(ttProgramming >= 0 && ttProgramming <= 100){
            break;
        }else{
            std::cout<<"������������������(����-1�����ϼ��˵�)"<<std::endl;
        }
    }
    
    std::cout<<"������Ҫ��ӵ�ѧ�����ݽṹ�ɼ�(����-1�����ϼ��˵�)"<<std::endl;
    while(1){
        std::cin>>tDataStructure;
        if(tDataStructure == "-1"){
            system("cls");
            return;
        }
        if(!checkNum(tDataStructure)){
            std::cout<<"������������������(����-1�����ϼ��˵�)"<<std::endl;
            continue;
        }
        int ttDataStructure = std::stoi(tDataStructure);
        if(ttDataStructure >= 0 && ttDataStructure <= 100){
            break;
        }else{
            std::cout<<"������������������(����-1�����ϼ��˵�)"<<std::endl;
        }
    }

    Student* tStudent = new Student(tId, tName, tGender, stoi(tEnglish), stoi(tMath), stoi(tProgramming), stoi(tDataStructure), 0);
    std::string flag = allStudent.insert(tStudent);
    if(flag != ""){ //����ͬѧ�ŵ�ѧ�����ڹ�ϣ������Ҫ��ɾ����ѧ�ŵ�ѧ����Ϣ
        hashTable.remove(flag);
    }
    hashTable.insert(tStudent);
    system("cls");
    std::cout<<"��ӳɹ�!"<<std::endl;
}

void update_student(BiTree& allStudent){ //�޸�ѧ����Ϣ
    system("cls");
    int Select=0;
    std::string tId;
    system("cls");
    std::cout<<"������Ҫ�޸ĵ�ѧ��ѧ��(����-1�����ϼ��˵�)"<<std::endl;
    while(1){ 
        std::cin>>tId;
        if(tId == "-1"){
            system("cls");
            return;
        }
        if(checkNum(tId)){
            BiTreeNode* tNode = allStudent.searchById(tId);
            if(tNode == NULL){ 
                std::cout<<"δ��ѯ��ѧ����Ϣ!"<<std::endl;
                std::cout<<"��Ҫ�����޸�,����������ѧ��,��������-1�����ϼ��˵�"<<std::endl;
            }else{ 
                system("cls");
                std::cout<<"��ѧ����ǰ��Ϣ����:"<<std::endl;
                std::cout<<"ѧ��:"<<tNode->student->getId()<<std::endl;
                std::cout<<"����:"<<tNode->student->getName()<<std::endl;
                std::cout<<"�Ա�:"<<tNode->student->getGender()<<std::endl;
                std::cout<<"Ӣ��ɼ�:"<<tNode->student->getEnglish()<<std::endl;
                std::cout<<"��ѧ�ɼ�:"<<tNode->student->getMath()<<std::endl;
                std::cout<<"������Ƴɼ�:"<<tNode->student->getProgramming()<<std::endl;
                std::cout<<"���ݽṹ�ɼ�:"<<tNode->student->getDataStructure()<<std::endl;
                std::cout<<"��ѡ��Ҫ�޸ĵ���Ŀ(����-1�����ϼ��˵�):"<<std::endl;
                std::cout<<"1.Ӣ��ɼ� 2.��ѧ�ɼ� 3.������Ƴɼ� 4.���ݽṹ�ɼ�"<<std::endl;
                std::string tChoice="";
                while(1){
                    std::cin>>tChoice;
                    if(tChoice == "-1"){
                        system("cls");
                        return;
                    }
                    if(!checkNum(tChoice)){
                        std::cout<<"������������������(����-1�����ϼ��˵�)"<<std::endl;
                        continue;
                    }
                    if(stoi(tChoice) >= 1 && stoi(tChoice) <= 4){
                        switch(stoi(tChoice)){
                            case 1:
                                std::cout<<"�������µ�Ӣ��ɼ�(����-1�����ϼ��˵�):"<<std::endl;
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
                                        std::cout<<"������������������(����-1�����ϼ��˵�)"<<std::endl;
                                    }
                                }
                            break;
                            case 2:
                                std::cout<<"�������µ���ѧ�ɼ�(����-1�����ϼ��˵�):"<<std::endl;
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
                                        std::cout<<"������������������(����-1�����ϼ��˵�)"<<std::endl;
                                    }
                                }
                            break;
                            case 3:
                                std::cout<<"�������µĳ�����Ƴɼ�(����-1�����ϼ��˵�):"<<std::endl;
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
                                        std::cout<<"������������������(����-1�����ϼ��˵�)"<<std::endl;
                                    }
                                }
                            break;
                            case 4:
                                std::cout<<"�������µ����ݽṹ�ɼ�(����-1�����ϼ��˵�):"<<std::endl;
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
                                        std::cout<<"������������������(����-1�����ϼ��˵�)"<<std::endl;
                                    }
                                }
                            break;
                        }
                        system("cls");
                        std::cout<<"�޸ĳɹ�!"<<std::endl;
                        std::cout<<"��ѧ����ǰ��Ϣ����:"<<std::endl;
                        std::cout<<"ѧ��:"<<tNode->student->getId()<<std::endl;
                        std::cout<<"����:"<<tNode->student->getName()<<std::endl;
                        std::cout<<"�Ա�:"<<tNode->student->getGender()<<std::endl;
                        std::cout<<"Ӣ��ɼ�:"<<tNode->student->getEnglish()<<std::endl;
                        std::cout<<"��ѧ�ɼ�:"<<tNode->student->getMath()<<std::endl;
                        std::cout<<"������Ƴɼ�:"<<tNode->student->getProgramming()<<std::endl;
                        std::cout<<"���ݽṹ�ɼ�:"<<tNode->student->getDataStructure()<<std::endl;
                        std::cout<<"�绹��Ҫ��������,��ѡ���޸���Ŀ1.Ӣ��ɼ� 2.��ѧ�ɼ� 3.������Ƴɼ� 4.���ݽṹ�ɼ�"<<std::endl;
                        std::cout<<"��������-1�����ϼ��˵�"<<std::endl;
                    }else{
                        std::cout<<"������������������(����-1�����ϼ��˵�)"<<std::endl;
                    }
                }
            }
            //std::cout<<""<<std::endl;            
        }else{
            std::cout<<"������������������(����-1�����ϼ��˵�)"<<std::endl;
        }
    }
}

void search_student(BiTree& allStudent, Hash& hashTable){  //��ѯѧ����Ϣ
    system("cls");
    std::string Select="";
    int n = allStudent.getSize(allStudent.getRoot());
    Student** arr = new Student*[n];  
    int tem = -1;
    allStudent.transmit(arr, tem, allStudent.getRoot());
    mergesort(arr, 0, n-1);   //����, ��������
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
    std::cout<<"�������ѯ��ʽ1.��ѧ�Ų�ѯ 2.��������ѯ(����-1�����ϼ��˵�)"<<std::endl;
    while(1){
        std::cin>>Select;
        if(Select == "-1"){
            system("cls");
            return;
        }
        if(!checkNum(Select)){
            std::cout<<"������������������(����-1�����ϼ��˵�)"<<std::endl;
            continue;
        }
        if(stoi(Select) == 1){
            std::string tId;
            std::cout<<"������Ҫ��ѯ��ѧ��ѧ��(����-1�����ϼ��˵�):"<<std::endl;
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
                        std::cout<<"δ��ѯ��ѧ����Ϣ!"<<std::endl;
                        std::cout<<"��Ҫ����ѧ�Ų�ѯ��������ѧ�ţ���������-1�����ϼ��˵�"<<std::endl;
                    }else{ 
                        system("cls");
                        std::cout<<"��ѯ��ѧ��Ϊ"<<tNode->student->getId()<<"��ѧ����Ϣ����:"<<std::endl;
                        printHeader();
                        tNode->student->printInfo();
                        std::cout<<"��Ҫ����ѧ�Ų�ѯ��������ѧ�ţ���������-1�����ϼ��˵�"<<std::endl;
                    }
                }else{
                    std::cout<<"������������������(����-1�����ϼ��˵�)"<<std::endl;
                }
            }
        }else if(stoi(Select) == 2){
            std::string tName;
            std::cout<<"������Ҫ��ѯ��ѧ������(����-1�����ϼ��˵�):"<<std::endl;
            while(1){
                std::cin>>tName;
                if(tName == "-1"){
                    system("cls");
                    search_student(allStudent,hashTable);
                    return;
                }
                if(!checkName(tName)){
                    std::cout<<"������������������(����-1�����ϼ��˵�)"<<std::endl;
                    continue;
                }
                if(!hashTable.OutputAll(tName)){ 
                    std::cout<<"δ��ѯ��ѧ����Ϣ!"<<std::endl;
                }
                std::cout<<"��Ҫ����������ѯ����������������������-1�����ϼ��˵�"<<std::endl;
            }
        }else{
            std::cout<<"������������������(����-1�����ϼ��˵�)"<<std::endl;
        }
    }

};

void print_student(BiTree& allStudent){
    system("cls");
    if(allStudent.isEmpty()){
        std::cout<<"����ѧ����Ϣ!"<<std::endl;
        return;
    }

    int n = allStudent.getSize(allStudent.getRoot());
    Student** arr = new Student*[n];
    int tem = -1;
    allStudent.transmit(arr, tem, allStudent.getRoot());
    mergesort(arr, 0, n-1);  //����, ��������
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

    std::cout<<"��ѡ������ʽ:1.Ĭ������ 2.���ֽܷ������(����-1�����ϼ��˵�)"<<std::endl;
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
            std::cout<<"������������������(����-1�����ϼ��˵�)"<<std::endl;
        }
        std::cout<<"��Ҫ��������,����������ʽ1.Ĭ������ 2.���ֽܷ������(����-1�����ϼ��˵�)"<<std::endl;
    }
    delete[] arr;
};

#endif // CHOICE_H