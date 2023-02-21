//
// Created by letun on 2/21/2023.
//

#ifndef ASIGNMENT1_RESTAURANT_H
#define ASIGNMENT1_RESTAURANT_H


#include "main.h"
enum InstructionType{
    NONE,
    REG,
    REGM,
    CLE,
    PS,
    PQ,
    SQ
};
int stringToInt(string str);
table* setTable(table* current, int ID, string name, int age);

bool is_number(const std::string& str);

void printTables(table* start);


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
            r->recentTable = setTable(r->recentTable, stringToInt(output[1]) , output[2], stringToInt(output[3]));
        }
        else//TH nhan vien dat ban tuy y
        {
            r->recentTable = setTable(r->recentTable, r->recentTable->ID , output[2], stringToInt(output[3]));
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



void simulate(string filename, restaurant* r);

#endif //ASIGNMENT1_RESTAURANT_H
