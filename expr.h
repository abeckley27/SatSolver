#ifndef EXPR_H
#define EXPR_H


class expr{
    public:
    expr() { this->create(); }


    private:
    //methods
    void create();
    void add_clause(int, int, int);

    //data
    int num_clauses;
    int* data;
};

void expr::create() {
    num_clauses = 0;
    data = nullptr;
}







#endif