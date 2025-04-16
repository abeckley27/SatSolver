#include "expr.h"
#include <cmath>
#include <iostream>


void expr::create() {
    num_clauses = 0;
    data = nullptr;
}

void expr::create(int *)
{
    //todo: implement this
    //I'm thinking it'll be faster to allocate memory for formulas in one method, rather than re-sizing several times
}

void expr::destroy()
{
    if (data != nullptr) { delete[] data; }
    num_clauses = 0;
}

void expr::print() {
    if (num_clauses > 0) {
        for (int i = 0; i < num_clauses; i++) {
            std::cout << '(' << data[3*i] << ", " << data[3*i + 1] << ", " << data[3*i + 2] << ") \n";
        }
        std::cout << std::endl;
    }

}

void expr::add_clause(int a, int b, int c)
{
    int* new_data = new int[num_clauses * 3 + 3];
    for (int i = 0; i < num_clauses * 3; i++) {
        new_data[i] = data[i];
    }
    new_data[num_clauses] = a;
    new_data[num_clauses + 1] = b;
    new_data[num_clauses + 2] = c;

    if (data != nullptr) { delete[] data; }
    data = new_data;
    num_clauses++;
}

