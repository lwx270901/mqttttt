//
// Created by letun on 2/21/2023.
//

#ifndef ASIGNMENT1_RESTAURANT_H
#define ASIGNMENT1_RESTAURANT_H


#include "main.h"

//enum
enum InstructionType{
    NONE,
    REG,
    REGM,
    CLE,
    PS,
    PQ,
    SQ
};

//Helper function

table* setTable(table* current, int ID, string name, int age);
bool is_number(const std::string& str);
void printTables(table* start);

//End helper function

//Instruction implementation
class Instruction {
public:
    virtual void printInstruction(restaurant* r, string output[]) = 0;
    static Instruction* Create(InstructionType type);
    virtual ~Instruction(){}
};

class REGInstruction : public Instruction {
public:
    void printInstruction(restaurant* r, string output[]) {
        if(is_number(output[1])) //TH co ID
        {
            setTable(r->recentTable->next, stoi(output[1]) , output[2], stoi(output[3]));
        }
        else//TH nhan vien dat ban tuy y
        {
            setTable(r->recentTable->next, 1 , output[1], stoi(output[2]));
        }
    }
};

class REGMInstruction : public Instruction {
public:
    void printInstruction(restaurant* r, string output[]) {

    }
};

class CLEInstruction : public Instruction {
public:
    void printInstruction(restaurant* r, string output[]) {

    }
};

class PSInstruction : public Instruction {
public:
    void printInstruction(restaurant* r, string output[]) {

    }
};

class PQInstruction : public Instruction {
public:
    void printInstruction(restaurant* r, string output[]) {

    }
};
class SQInstruction : public Instruction {
public:
    void printInstruction(restaurant* r, string output[]) {

    }
};

//End instruction implementation





void simulate(string filename, restaurant* r);

#endif //ASIGNMENT1_RESTAURANT_H
