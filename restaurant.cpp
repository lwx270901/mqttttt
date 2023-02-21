//
// Created by letun on 2/21/2023.
//

#include "restaurant.h"

table* setTable(table* current, int ID, string name, int age) {
    if (current == nullptr) {
        return nullptr;
    }
    table* temp = current;
    do {
        if (temp->ID == ID) {
            temp->name = name;
            temp->age = age;
            return temp;
        }
        temp = temp->next;
    } while (temp != current);
    return current;
}

bool is_number(const std::string& str) {
    try {
        // Try to convert the string to an integer
        int i = std::stoi(str);
    } catch (const std::invalid_argument& e) {
        // If the string cannot be converted to an integer, try to convert it to a double
        try {
            double d = std::stod(str);
        } catch (const std::invalid_argument& e) {
            // If the string cannot be converted to a double, it is not a number
            return false;
        }
    }
    return true;
}

int stringToInt(string str) {
    int num = 0;
    for (int i = 0; i < str.length(); i++) {
        int digit = (int)str[i] - (int)'0';
        num = num * 10 + digit;
    }
    return num;
}

void printTables(table* start) {
    if (start == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    table* current = start;

    do {
        cout << "ID: " << current->ID << ", Name: " << current->name << ", Age: " << current->age << endl;
        current = current->next;
    } while (current != start);
}

int split_string(string input_string, string output_array[], int array_size) {
    int index = 0;
    string token = "";
    for (char c : input_string) {
        if (c == ' ') {
            if (token != "") {
                output_array[index++] = token;
                token = "";
            }
        }
        else {
            token += c;
        }
        if (index == array_size) {
            break;
        }
    }
    if (token != "" && index < array_size) {
        output_array[index++] = token;
    }
    return index;
}

Instruction* Instruction::Create(InstructionType type) {
    if (type == REG)
        return new REGInstruction();
    else if (type == REGM)
        return new REGMInstruction();
    else if (type == CLE)
        return new CLEInstruction();
    else if(type == PS)
        return new PSInstruction();
    else if (type == PQ)
        return new PQInstruction();
    else if (type == SQ)
        return new SQInstruction();
    else return NULL;

}




void simulate(string filename, restaurant* r)
{
    ifstream file(filename);
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
//            std::cout << line << std::endl;
            //Get Ins
            string output[10];
            InstructionType type = NONE;
            int count = split_string(line, output, 10);
            if (output[0] == "REG")  type = REG;
            else if(output[0] =="REGM") type = REGM;
            else if(output[0] =="PS") type = CLE;
            else if(output[0] =="PQ") type = REGM;
            else if(output[0] =="SQ") type = REGM;

            //Deal with instructions
            Instruction* pInstruction = Instruction::Create(type);
            if(pInstruction != NULL) pInstruction->printInstruction(r, output);
            delete pInstruction;


        }
        printTables(r->recentTable);
        file.close();
    }
    else
    {
        cerr << "Unable to open file" << std::endl;

    }
}