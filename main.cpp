#include <iostream>
#include "student.h"
#include "Bitree.h"
#include "choice.h"
#include "Namehash.h"

BiTree allStudent; // ȫ�ֱ�������������ѧ����Ϣ�Ķ�����
Hash hashTable; // ȫ�ֱ���������ĸΪ�����Ĺ�ϣ������ѧ��ָ��

int main(){
    system("cls"); // ����
    auto ChekcChoice =[&](std::string choice){ //���˵�����ѡ���Ƿ����
        if(choice.length()!=1){
            return 0;
        }
        for(auto i:choice){
            if(!isdigit(i)){
                return 0;
            }
        }
        return 1;
    };
    while(1){
        std::cout<<R"(=========================================
            ѧ���ɼ�����ϵͳ               
=========================================
|  1. ���ѧ��                          |
|  2. ��ѯѧ��                          |
|  3. �޸�ѧ���ɼ�                      |
|  4. ѧ����Ϣ���                      |
|  5. �˳�ϵͳ                          |
=========================================
������ѡ�)";
    std::string tchoice;
    std::cin>>tchoice;
    if (!ChekcChoice(tchoice)) {
        system("cls"); // ����
        std::cout << "�����������������룡" << std::endl;
        continue;
    }
    int choice = std::stoi(tchoice);
    switch(choice){
        case 1:
            add_student(allStudent,hashTable);
            break;
        case 2:
            search_student(allStudent,hashTable);
            break;
        case 3:
            update_student(allStudent);
            break;
        case 4:
            print_student(allStudent);
            break;
        case 5:
            return 0;
            break;
        default:
            system("cls"); // ����
            std::cout << "�����������������룡" << std::endl;
            break;
        }
    
    }
}