    #ifndef HASH_H
    #define HASH_H

    #include <string>
    #include "Student.h"
    #include <iostream>
    #include "choice.h"

    class LinkNode{  // ����ڵ�
    public:
        Student* student;
        LinkNode* next;
        LinkNode(Student* s){
            student = s;
            next = NULL;
        }
    };

    class LinkedList{ // ����
    public:
        LinkNode* head = NULL;
        LinkedList(){
            head = NULL;
        }
        ~LinkedList() {   // �����������ͷ������ڴ�
            LinkNode* current = head;  
            while (current != NULL) {  
                LinkNode* temp = current;  
                current = current->next;  
                delete temp->student; // �ͷŵ�ǰ�ڵ��ѧ���ڴ�
                delete temp; // �ͷŵ�ǰ�ڵ���ڴ�  
            }  
        }
        void printHeader(){  // ��ӡ��ͷ
            std::cout<<std::setw(14)<<std::left<<"ѧ��"<<std::setw(10)<<std::left<<"����"<<std::setw(10)<<
            std::left<<"�Ա�"<<std::setw(10)<<std::left<<"Ӣ��"<<std::setw(10)<<std::left<<"��ѧ"<<std::setw(10)
            <<std::left<<"���"<<std::setw(10)<<std::left<<"���ݽṹ"<<std::setw(10)<<std::left<<"�ܷ�"<<std::setw(10)<<std::left<<"����"<<std::endl;
        } 

        void remove(std::string name){  // ɾ��������ָ��������ѧ��
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

        void Linsert(Student* s) {  // ��������
            if (head == NULL) {
                head = new LinkNode(s);
                return;
            }
            LinkNode* current = head;
            while (current->next != NULL) { // ����������ĩβ
                current = current->next;
            }
            current->next = new LinkNode(s); // ������ĩβ�����½ڵ�
            
            LinkNode* temp = head;
        }

        LinkNode* search(std::string name){  // ����������ָ��������ѧ��
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
        
        //�������ͬ��ѧ��
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
                        std::cout<<"�ҵ���������Ϊ"<<name<<"��ѧ����"<<std::endl;
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

    class Hash{  // ��ϣ��(������������ĸ����)
    public:
        LinkedList* arr[30];
        Hash(){  // ���캯������ʼ����������
            for(int i=0;i<30;i++){
                arr[i] = new LinkedList();
            }
        }

        void insert(Student *s){  // ����ѧ��
            int index=0;
            if(islower(s->getName()[0])){
                index = s->getName()[0] - 'a';
            }else{
                index = s->getName()[0] - 'A';
            }
            arr[index]->Linsert(s);
        }
        
       
        void remove(std::string name){  // ɾ��ָ��������ѧ��
            int index=0;
            if(islower(name[0])){
                index = name[0] - 'a';
            }else{
                index = name[0] - 'A';
            }
            arr[index]->remove(name);
        }

        bool OutputAll(std::string name){  // �������ͬ��ѧ��
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