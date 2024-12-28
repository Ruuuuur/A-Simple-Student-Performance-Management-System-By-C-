#ifndef BITREE_H
#define BITREE_H

#include <iostream>
#include "Student.h"

//将学生信息存入到搜索二叉树中，实现按学号或者姓名输出学生信息
//二叉树的节点结构定义如下：
class BiTreeNode {
public:
    Student *student; //学生信息
    BiTreeNode* leftChild; //左子树指针
    BiTreeNode* rightChild; //右子树指针
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

//搜索二叉树类定义如下：
class BiTree {
private:
    BiTreeNode* root; //根节点指针
public:
    BiTree() {
        root = NULL;
    }

    ~BiTree() {  //析构函数，释放二叉树内存
        clearBiTree();
    }   

    void deleteBiTree(BiTreeNode* node) {  //删除二叉树节点
        if (node == NULL) {
            return;
        }
        deleteBiTree(node->leftChild);
        deleteBiTree(node->rightChild);
        delete node;
    }

    void clearBiTree() {  //清空二叉树
        deleteBiTree(root);
        root = NULL;
    }
    BiTreeNode* getRoot() {
        return root;
    }

    //插入学生信息到二叉树中
    std::string insert(Student *s) {  // 返回学号相同的学生姓名，否则返回空字符串, 方便哈希表更新
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
                } else { //学号相同，更新学生信息
                    std::string res = p->student->getName();
                    p->student = s;
                    return res;
                }
            }
        }
        return "";
    }
    //按学号查找学生信息
    BiTreeNode* searchById(std::string id) {
        BiTreeNode* p = root;
        while (p!= NULL) {
            if (id == p->student->getId()) {
                return p; //返回指针，方便后续修改学生信息
            } else if (id < p->student->getId()) {
                p = p->leftChild;
            } else {
                p = p->rightChild;
            }
        }
        return NULL;
    }
    //按姓名查找学生信息
    BiTreeNode* searchByName(std::string name) {
        BiTreeNode* p = root;
        while (p!= NULL) {
            if (name == p->student->getName()) {
                return p; //返回指针，方便后续修改学生信息
            } else if (name < p->student->getName()) {
                p = p->leftChild;
            } else {
                p = p->rightChild;
            }
        }
        return NULL;
    }

    //判断二叉树是否为空
    bool isEmpty() {
        return root == NULL;
    }


    void Inorder(BiTreeNode* node) {  //中序遍历
        if (node == NULL) {
            return;
        }
        Inorder(node->leftChild);
        node->student->printInfo();
        Inorder(node->rightChild);
    }

    //按学号从小到大输出学生信息
    void outputByIdAsc(){
        if (root == NULL) {
            std::cout << "学生列表为空" << std::endl;
            return;
        }
        Inorder(root);   
    }

    int getSize(BiTreeNode* node){ //获取总节点数
        if (node == NULL) {
            return 0;
        }
        int size = 1;
        BiTreeNode* p = node;
        size+=getSize(p->leftChild)+getSize(p->rightChild);
        return size;
    }

    void transmit(Student *arr[],int &now, BiTreeNode* p){  //中序遍历，将学生信息存入数组
        if(p == NULL){
            return;
        }
        arr[++now] = p->student;
        transmit(arr,now,p->leftChild);
        transmit(arr,now,p->rightChild);
    }

};
    
    

#endif // BITREE_H