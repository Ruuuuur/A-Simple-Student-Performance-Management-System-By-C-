#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iomanip>
#include <iostream>

class Student{
private: 
    std::string id, name, gender; 
    int english, math, programming, dataStructure,rank;

public:

    Student(const std::string &id, const std::string &name, const std::string &gender,
    int english, int math, int programming, int dataStructure, int rank):
    id(id), name(name), gender(gender),
    english(english), math(math), programming(programming), dataStructure(dataStructure), rank(rank){}

    Student(){
        id = "";
        name = "";
        gender = "";
        english = 0;
        math = 0;
        programming = 0;
        dataStructure = 0;
        rank = 0;
    }

    //Setter
    void setId(std::string id){this->id = id;};
    void setName(std::string name){this->name = name;};
    void setGender(std::string gender){this->gender = gender;};
    void setEnglish(int english){this->english = english;};
    void setMath(int math){this->math = math;};
    void setProgramming(int programming){this->programming = programming;};
    void setDataStructure(int dataStructure){this->dataStructure = dataStructure;};
    void setRank(int rank){this->rank = rank;};

    //Getter
    std::string getId() const{return id;};
    std::string getName() const{return name;};
    std::string getGender() const{return gender;};
    int getEnglish() const{return english;};
    int getMath() const{return math;};
    int getProgramming() const{return programming;};
    int getDataStructure() const{return dataStructure;};
    int getTotal() const{return english + math + programming + dataStructure;};
    int getRank() const{return rank;};

    void printInfo() const {
    std::cout << std::setw(14) << std::left << getId()
              << std::setw(10) << std::left << getName()
              << std::setw(10) << std::left << getGender()
              << std::setw(10) << std::left << getEnglish()
              << std::setw(10) << std::left << getMath()
              << std::setw(10) << std::left << getProgramming()
              << std::setw(10) << std::left << getDataStructure()
              << std::setw(10) << std::left << getTotal()
              << std::setw(10) << std::left << getRank()
              << std::endl;
    }
};


#endif // STUDENT_H