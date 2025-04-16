#include <iostream>
#include "expr.h"


int main(int argc, char* argv[]) {

    expr f;
    f.add_clause(1, 2, 3);
    f.print();




    return 0;
}