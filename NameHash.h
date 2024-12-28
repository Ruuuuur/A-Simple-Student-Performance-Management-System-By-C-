    #ifndef HASH_H
    #define HASH_H

    #include <string>
    #include "Student.h"
    #include <iostream>
    #include "choice.h"

    class LinkNode{  // 链表节点
    public:
        Student* student;
        LinkNode* next;
        LinkNode(Student* s){
            student = s;
            next = NULL;
        }
    };

    class LinkedList{ // 链表
    public:
        LinkNode* head = NULL;
        LinkedList(){
            head = NULL;
        }
        ~LinkedList() {   // 析构函数，释放链表内存
            LinkNode* current = head;  
            while (current != NULL) {  
                LinkNode* temp = current;  
                current = current->next;  
                delete temp->student; // 释放当前节点的学生内存
                delete temp; // 释放当前节点的内存  
            }  
        }
        void printHeader(){  // 打印表头
            std::cout<<std::setw(14)<<std::left<<"学号"<<std::setw(10)<<std::left<<"姓名"<<std::setw(10)<<
            std::left<<"性别"<<std::setw(10)<<std::left<<"英语"<<std::setw(10)<<std::left<<"数学"<<std::setw(10)
            <<std::left<<"编程"<<std::setw(10)<<std::left<<"数据结构"<<std::setw(10)<<std::left<<"总分"<<std::setw(10)<<std::left<<"排名"<<std::endl;
        } 

        void remove(std::string name){  // 删除链表中指定姓名的学生
            LinkNode* current = head;
            LinkNode* prev = NULL;
            while (current != NULL) {
                if (current->student->getName() == name) {
                    if (prev == NULL) {
                        head = current->next;
                    } else {
                        prev->next = current->next;
                    }
                    delete current->student;
                    delete current;
                    return;
                }
                prev = current;
                current = current->next;
            }
        }

        void Linsert(Student* s) {  // 插入链表
            if (head == NULL) {
                head = new LinkNode(s);
                return;
            }
            LinkNode* current = head;
            while (current->next != NULL) { // 遍历到链表末尾
                current = current->next;
            }
            current->next = new LinkNode(s); // 在链表末尾插入新节点
            
            LinkNode* temp = head;
        }

        LinkNode* search(std::string name){  // 搜索链表中指定姓名的学生
            LinkNode* current = head;
            if(current == NULL){
                return NULL;
            }
            while(current!= NULL){
                if(current->student->getName() == name){
                    return current;
                }
                current = current->next;
            }
            return NULL;
        }
        
        //输出所有同名学生
        bool printAll(LinkNode* node, std::string name){
            if(node == NULL){
                return false;
            }
            LinkNode* current = node;
            bool flag=0;
            while(current!= NULL){
                if(current->student->getName() == name){
                    if(!flag){
                        system("cls");
                        std::cout<<"找到如下姓名为"<<name<<"的学生："<<std::endl;
                        flag=1;
                        printHeader();
                    }
                    current->student->printInfo();
                }
                current = current->next;
            }
            if(!flag) return false;
            return true;
        }
    };

    class Hash{  // 哈希表(根据姓名首字母索引)
    public:
        LinkedList* arr[30];
        Hash(){  // 构造函数，初始化链表数组
            for(int i=0;i<30;i++){
                arr[i] = new LinkedList();
            }
        }

        void insert(Student *s){  // 插入学生
            int index=0;
            if(islower(s->getName()[0])){
                index = s->getName()[0] - 'a';
            }else{
                index = s->getName()[0] - 'A';
            }
            arr[index]->Linsert(s);
        }
        
       
        void remove(std::string name){  // 删除指定姓名的学生
            int index=0;
            if(islower(name[0])){
                index = name[0] - 'a';
            }else{
                index = name[0] - 'A';
            }
            arr[index]->remove(name);
        }

        bool OutputAll(std::string name){  // 输出所有同名学生
            int index=0;
            if(islower(name[0])){
                index = name[0] - 'a';
            }else{
                index = name[0] - 'A';
            }
            return arr[index]->printAll(arr[index]->head, name);
        }
    };

    #endif // HASH_H