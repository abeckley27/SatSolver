#include "expr.h"
#include <cmath>
#include <iostream>
#include <random>


void expr::create() {
    num_clauses = 0;
    data = nullptr;
}

void expr::create(int *a, int length)
{
    num_clauses = length;
    data = nullptr;     //lol
    //todo: implement this
    //I'm thinking it'll be faster to allocate memory for formulas in one method, rather than re-sizing several times
}

void expr::create(int m)
{
    //Create an m-clause formula of all zeros
    num_clauses = m;
    data = new int[3 * m];
    for (int i = 0; i < 3*m; i++) { data[i] = 0; }
}

void expr::destroy()
{
    if (data != nullptr) { delete[] data; }
    num_clauses = 0;
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





















