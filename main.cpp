#include "main.h"
#include "restaurant.h"

int main(int argc, char* argv[]) {

    restaurant* r = new restaurant();
    string fileName = "D:\\Minh\\code\\CandC++\\Asignment1\\test.txt";

    //initialize table with ID, name and age
    for (int i = 1; i <= MAXSIZE; i++)
    {
        r->recentTable = r->insert(r->recentTable,i,"",0);
    }

    simulate(fileName,r);
    delete r;

    return 0;
}