#include <iostream>
#include <random>
#include "expr.h"


expr** make_random_formulas(int n_vars, int n_clauses, int n_formulas) {
    std::random_device rd;
	std::mt19937_64 mt64(rd());
    std::uniform_int_distribution<> rng(1, n_vars);
    std::uniform_int_distribution<> sign(0, 1);

    expr** output = new expr*[n_formulas];
    for (int i = 0; i < n_formulas; i++) {
        output[i] = new expr(n_clauses);
        for (int j = 0; j < n_clauses; j++) {
            output[i]->set_clause((sign(mt64)*2 - 1) * rng(mt64), (sign(mt64)*2 - 1) * rng(mt64), (sign(mt64)*2 - 1) * rng(mt64), j);
        }
    } 
    return output;
}


int main(int argc, char* argv[]) {

    //testing expr class stuff
    expr f;
    f.add_clause(1, 2, 3);
    f.add_clause(2, -3, 4);
    f.add_clause(-1, -2, 4);
    f.print();

    bool test[4] = {0, 1, 0, 0};
    std::cout << f.satisfies(test) << std::endl;

    const int N = 10;
    expr** formula_array = make_random_formulas(10, 25, N);
    formula_array[0]->print();
    //formula_array[1]->print();

    for (int i = 0; i < N; i++) {
        delete formula_array[i];
    }
    delete[] formula_array;

    return 0;
}