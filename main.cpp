#include <iostream>
#include "student.h"
#include "Bitree.h"
#include "choice.h"
#include "Namehash.h"

BiTree allStudent; // 全局变量，保存所有学生信息的二叉树
Hash hashTable; // 全局变量，以字母为索引的哈希表，保存学生指针

int main(){
    system("cls"); // 清屏
    auto ChekcChoice =[&](std::string choice){ //检查菜单输入选项是否合理
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
            学生成绩管理系统               
=========================================
|  1. 添加学生                          |
|  2. 查询学生                          |
|  3. 修改学生成绩                      |
|  4. 学生信息输出                      |
|  5. 退出系统                          |
=========================================
请输入选项：)";
    std::string tchoice;
    std::cin>>tchoice;
    if (!ChekcChoice(tchoice)) {
        system("cls"); // 清屏
        std::cout << "输入有误，请重新输入！" << std::endl;
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
            system("cls"); // 清屏
            std::cout << "输入有误，请重新输入！" << std::endl;
            break;
        }
    
    }
}