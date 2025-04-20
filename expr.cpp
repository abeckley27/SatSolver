#include "expr.h"
#include <cmath>
#include <iostream>
#include <random>


void expr::create() {
    num_clauses = 0;
    num_vars = 0;
    data = nullptr;
}


void expr::create(int m, int n)
{
    //Create an m-clause formula of all zeros
    num_clauses = m;
    num_vars = n;
    data = new int16_t[3 * m];
    for (int i = 0; i < 3*m; i++) { data[i] = 0; }
}

void expr::copy(const expr& e1)
{
    num_clauses = e1.num_clauses;
    num_vars = e1.num_vars;
    data = new int16_t[3 * e1.num_clauses];
    for (int i = 0; i < (3*e1.num_clauses); i++) { data[i] = e1.data[i]; } 
}

void expr::destroy()
{
    if (data != nullptr) { delete[] data; }
    num_clauses = 0;
    num_vars = 0;
}

void expr::print() {
    if (num_clauses > 0) {
        for (int i = 0; i < num_clauses; i++) {
            std::cout << '(' << data[3*i] << ", " << data[3*i + 1] << ", " << data[3*i + 2] << ") \t";
        }
        std::cout << std::endl;
    }

}

void expr::set_clause(int a, int b, int c, int n)
{
    if (n < num_clauses) {
        data[3*n] = a;
        data[3*n + 1] = b;
        data[3*n + 2] = c;
    }
    else {
        std::cout << "Error: clause index " << n << " is out of range\n";
    }
}

bool expr::satisfies(bool *assignment)
{
    bool output = true;
    bool x1, x2, x3;
    for (int i = 0; i < num_clauses; i++) {
        x1 = assignment[int(std::abs(data[3*i])) - 1] ^ (data[3*i] < 0);
        x2 = assignment[int(std::abs(data[3*i+1])) - 1] ^ (data[3*i + 1] < 0);
        x3 = assignment[int(std::abs(data[3*i+2])) - 1] ^ (data[3*i + 2] < 0);
        //  assignment  sign    result
        //      0       0       0
        //      0       1       1
        //      1       0       1
        //      1       1       0
        
        if (!x1 && !x2 && !x3) {
            output = false;
            break;
        }
    }
    return output;
}

bool expr::is_satisfiable()
{
    bool* assignment = new bool[num_vars];
    return false;
}

void expr::add_clause(int a, int b, int c)
{
    int16_t* new_data = new int16_t[num_clauses * 3 + 3];
    for (int i = 0; i < num_clauses * 3; i++) {
        new_data[i] = data[i];
    }
    
    new_data[num_clauses*3] = a;
    new_data[num_clauses*3 + 1] = b;
    new_data[num_clauses*3 + 2] = c;

    if (data != nullptr) { delete[] data; }
    data = new_data;
    num_clauses++;
}





















