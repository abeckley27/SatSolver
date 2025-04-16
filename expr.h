#ifndef EXPR_H
#define EXPR_H

class expr{
    public:
    //Constructors and destructor
    expr() { this->create(); }
    expr(int* a, int length) { this->create(a, length); }
    expr(int m) { this->create(m); }
    ~expr() { this->destroy(); }

    //access and modifying methods
    void add_clause(int, int, int);
    void print();
    void set_clause(int, int, int, int);


    private:
    //methods
    void create();
    void create(int*, int);
    void create(int);
    void destroy();
    
    //data
    int num_clauses;
    int* data;
};





#endif