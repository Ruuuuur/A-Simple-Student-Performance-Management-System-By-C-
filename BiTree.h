#ifndef BITREE_H
#define BITREE_H

#include <iostream>
#include "Student.h"

//��ѧ����Ϣ���뵽�����������У�ʵ�ְ�ѧ�Ż����������ѧ����Ϣ
//�������Ľڵ�ṹ�������£�
class BiTreeNode {
public:
    Student *student; //ѧ����Ϣ
    BiTreeNode* leftChild; //������ָ��
    BiTreeNode* rightChild; //������ָ��
    BiTreeNode(Student* s) {
        student = s;
        leftChild = NULL;
        rightChild = NULL;
    }
    BiTreeNode() {
        student = NULL;
        leftChild = NULL;
        rightChild = NULL;
    }
};

//�����������ඨ�����£�
class BiTree {
private:
    BiTreeNode* root; //���ڵ�ָ��
public:
    BiTree() {
        root = NULL;
    }

    ~BiTree() {  //�����������ͷŶ������ڴ�
        clearBiTree();
    }   

    void deleteBiTree(BiTreeNode* node) {  //ɾ���������ڵ�
        if (node == NULL) {
            return;
        }
        deleteBiTree(node->leftChild);
        deleteBiTree(node->rightChild);
        delete node;
    }

    void clearBiTree() {  //��ն�����
        deleteBiTree(root);
        root = NULL;
    }
    BiTreeNode* getRoot() {
        return root;
    }

    //����ѧ����Ϣ����������
    std::string insert(Student *s) {  // ����ѧ����ͬ��ѧ�����������򷵻ؿ��ַ���, �����ϣ�����
        if (root == NULL) {
            root = new BiTreeNode(s);
        } else {
            BiTreeNode* p = root;
            while (true) {
                if (s->getId() < p->student->getId()) {
                    if (p->leftChild == NULL) {
                        p->leftChild = new BiTreeNode(s);
                        break;
                    } else {
                        p = p->leftChild;
                    }
                } else if (s->getId() > p->student->getId()) {
                    if (p->rightChild == NULL) {
                        p->rightChild = new BiTreeNode(s);
                        break;
                    } else {
                        p = p->rightChild;
                    }
                } else { //ѧ����ͬ������ѧ����Ϣ
                    std::string res = p->student->getName();
                    p->student = s;
                    return res;
                }
            }
        }
        return "";
    }
    //��ѧ�Ų���ѧ����Ϣ
    BiTreeNode* searchById(std::string id) {
        BiTreeNode* p = root;
        while (p!= NULL) {
            if (id == p->student->getId()) {
                return p; //����ָ�룬��������޸�ѧ����Ϣ
            } else if (id < p->student->getId()) {
                p = p->leftChild;
            } else {
                p = p->rightChild;
            }
        }
        return NULL;
    }
    //����������ѧ����Ϣ
    BiTreeNode* searchByName(std::string name) {
        BiTreeNode* p = root;
        while (p!= NULL) {
            if (name == p->student->getName()) {
                return p; //����ָ�룬��������޸�ѧ����Ϣ
            } else if (name < p->student->getName()) {
                p = p->leftChild;
            } else {
                p = p->rightChild;
            }
        }
        return NULL;
    }

    //�ж϶������Ƿ�Ϊ��
    bool isEmpty() {
        return root == NULL;
    }


    void Inorder(BiTreeNode* node) {  //�������
        if (node == NULL) {
            return;
        }
        Inorder(node->leftChild);
        node->student->printInfo();
        Inorder(node->rightChild);
    }

    //��ѧ�Ŵ�С�������ѧ����Ϣ
    void outputByIdAsc(){
        if (root == NULL) {
            std::cout << "ѧ���б�Ϊ��" << std::endl;
            return;
        }
        Inorder(root);   
    }

    int getSize(BiTreeNode* node){ //��ȡ�ܽڵ���
        if (node == NULL) {
            return 0;
        }
        int size = 1;
        BiTreeNode* p = node;
        size+=getSize(p->leftChild)+getSize(p->rightChild);
        return size;
    }

    void transmit(Student *arr[],int &now, BiTreeNode* p){  //�����������ѧ����Ϣ��������
        if(p == NULL){
            return;
        }
        arr[++now] = p->student;
        transmit(arr,now,p->leftChild);
        transmit(arr,now,p->rightChild);
    }

};
    
    

#endif // BITREE_H