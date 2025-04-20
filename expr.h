#ifndef EXPR_H
#define EXPR_H
#include <cstdint>

class expr{
    public:
    //Constructors and destructor
    expr() { this->create(); }
    expr(int m, int n) { this->create(m, n); }
    expr(const expr& e1) { this->copy(e1); }
    ~expr() { this->destroy(); }

    //access and modifying methods
    void add_clause(int, int, int);
    void print();
    void set_clause(int, int, int, int);

    //calulcation methods
    bool satisfies(bool* assignment);
    bool is_satisfiable();

    private:
    //methods
    void create();
    void create(int, int);
    void copy(const expr&);
    void destroy();
    
    //data
    int num_clauses;
    int num_vars;
    int16_t* data;
};





#endif