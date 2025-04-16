#ifndef EXPR_H
#define EXPR_H

class expr{
    public:
    //Constructors and destructor
    expr() { this->create(); }
    expr(int* a) { this->create(a); }
    ~expr() { this->destroy(); }

    //access and modifying methods
    void add_clause(int, int, int);
    void print();



    private:
    //methods
    void create();
    void create(int*);
    void destroy();
    
    //data
    int num_clauses;
    int* data;
};





#endif