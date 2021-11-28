//
// Created by deal_with on 17/11/2021.
//

#ifndef CSE474_AST_H
#define CSE474_AST_H

#include <memory>
#include <iostream>
#include <vector>

class driver;
namespace h_ast {

    enum primitive {
        INT, REAL, CHAR, BOOL
    };

    std::ostream &operator<<(std::ostream &out, primitive type);

    enum bool_b_op {
        OR, AND
    };

    std::ostream &operator<<(std::ostream &out, bool_b_op op);

    enum bool_u_op {
        NOT
    };

    enum arithmetic_b_op {
        ADD, SUB, MUL, DIV, MOD
    };

    std::ostream &operator<<(std::ostream &out, arithmetic_b_op op);

    enum bool_a_op {
        EQ, NE, LT, GT, LE, GE

    };

    struct Exp {
        std::string name;
        primitive type;

        Exp(primitive type, std::string name) : name(std::move(name)), type(type) {};

        virtual void declare(driver &drv);

        virtual void logic(driver &drv) = 0;

        virtual void compile(driver &drv);

        virtual void recursive_declare(driver &drv) = 0;

        virtual void recursive_logic(driver &drv) = 0;

        virtual void recursive_compile(driver &drv) = 0;

        virtual ~Exp() = default;
    };

    struct ArithmeticExp : public Exp {
        arithmetic_b_op op;
        std::unique_ptr<Exp> _left, _right;

        ArithmeticExp(driver &drv, std::unique_ptr<Exp> left, std::unique_ptr<Exp> right, arithmetic_b_op op);

        void logic(driver &drv) final;

        void recursive_declare(driver &drv) final;

        void recursive_logic(driver &drv) final;

        void recursive_compile(driver &drv) final;
    };

    struct WrapperExp : public Exp {
        std::unique_ptr<Exp> exp;

        WrapperExp(driver &drv, std::unique_ptr<Exp> exp, h_ast::primitive type);

        void logic(driver &drv) final;

        void recursive_declare(driver &drv) final;

        void recursive_logic(driver &drv) final;

        void recursive_compile(driver &drv) final;

    };

    struct Literal : public Exp {
        Literal(std::string name, primitive type) : Exp(type, std::move(name)) {};

        void recursive_declare(driver &drv) final;

        void recursive_logic(driver &drv) final;

        void recursive_compile(driver &drv) final;
    };

    struct BoolLiteral : public Literal {
        bool t;

        BoolLiteral(driver &drv, bool t);

        void logic(driver &drv) final;

    };

    struct IntegerLiteral : public Literal {
        int t;

        IntegerLiteral(driver &drv, int t);

        void logic(driver &drv) final;


    };

    struct RealLiteral : public Literal {
        double t;

        RealLiteral(driver &drv, double t);

        void logic(driver &drv) final;

    };

    struct CharLiteral : public Literal {
        char t;

        CharLiteral(driver &drv, char t);

        void logic(driver &drv) final;

    };

    struct BooleanExp : public Exp {
        explicit BooleanExp(std::string name) : Exp(BOOL, move(name)) {};
    };

    struct LiteralBoolExp : public BooleanExp {
        std::unique_ptr<BoolLiteral> lit;

        LiteralBoolExp(driver &drv, std::unique_ptr<BoolLiteral> lit) : BooleanExp(lit->name) {};

        void logic(driver &drv) final;

        void recursive_declare(driver &drv) final;

        void recursive_logic(driver &drv) final;

        void recursive_compile(driver &drv) final;

    };

    struct UnaryBoolExp : public BooleanExp {
        bool_u_op op;
        std::unique_ptr<BooleanExp> exp;

        UnaryBoolExp(driver &drv, std::unique_ptr<BooleanExp> exp, bool_u_op op);

        void logic(driver &drv) final;

        void recursive_declare(driver &drv) final;

        void recursive_logic(driver &drv) final;

        void recursive_compile(driver &drv) final;

    };

    struct BinaryBoolExp : public BooleanExp {
        bool_b_op op;
        std::unique_ptr<BooleanExp> left, right;

        BinaryBoolExp(driver &drv, std::unique_ptr<BooleanExp> left, std::unique_ptr<BooleanExp> right, bool_b_op op);

        void logic(driver &drv) final;

        void recursive_declare(driver &drv) final;

        void recursive_logic(driver &drv) final;

        void recursive_compile(driver &drv) final;


    };

    struct BinaryArithmeticBoolExp : public BooleanExp {
        bool_a_op op;
        std::unique_ptr<Exp> left, right;

        BinaryArithmeticBoolExp(driver &drv, std::unique_ptr<Exp> left, std::unique_ptr<Exp> right, bool_a_op op);

        void logic(driver &drv) final;

        void recursive_declare(driver &drv) final;

        void recursive_logic(driver &drv) final;

        void recursive_compile(driver &drv) final;

    };

    struct IdentifierExist : public Exp {
        IdentifierExist(driver &drv, std::string name);

        void declare(driver &drv) final;

        void logic(driver &drv) final;

        void recursive_declare(driver &drv) final;

        void recursive_logic(driver &drv) final;

        void recursive_compile(driver &drv) final;
    };

    struct IdentifierNotExist : public Exp {
        IdentifierNotExist(driver &drv, std::string name, primitive type);

        void logic(driver &drv) final;

        void recursive_declare(driver &drv) final;

        void recursive_logic(driver &drv) final;

        void recursive_compile(driver &drv) final;
    };

    struct StatementLike {
        virtual void logic(driver &drv) = 0;

        virtual void recursive_declare(driver &drv) = 0;

        virtual void recursive_logic(driver &drv) = 0;

        virtual void recursive_compile(driver &drv) = 0;

        virtual ~StatementLike()=default;
    };

    struct AssignmentStatement : public StatementLike {

        AssignmentStatement(driver& drv,std::unique_ptr<IdentifierExist> left, std::unique_ptr<Exp> right);

        std::unique_ptr<IdentifierExist> _left;
        std::unique_ptr<Exp> _right;

        void logic(driver &drv) final;

        void recursive_logic(driver &drv) final;

        void recursive_declare(driver &drv) override;

        void recursive_compile(driver &drv) override;


    };

    struct ReadStatement : public StatementLike {
        std::vector<std::unique_ptr<IdentifierExist>> _expList;

        ReadStatement(std::vector<std::unique_ptr<IdentifierExist>> expList);

        void add(driver& drv,std::string name){
            _expList.push_back(std::make_unique<IdentifierExist>(drv, std::move(name)));
        }
        void logic(driver &drv) final;

        void recursive_declare(driver &drv) final;

        void recursive_compile(driver &drv) final;

        void recursive_logic(driver &drv) final;
    };

    struct WriteStatement : public StatementLike {
        std::vector<std::unique_ptr<Exp>> _expList;

        WriteStatement(std::vector<std::unique_ptr<Exp>> expList);

        void logic(driver &drv) final;

        void recursive_declare(driver &drv) final;

        void recursive_compile(driver &drv) final;

        void recursive_logic(driver &drv) final;
    };

    struct DeclarationStatement : public StatementLike {
        std::unique_ptr<IdentifierNotExist> _left;
        std::unique_ptr<Exp> _right;

        DeclarationStatement(driver &drv, std::string name, primitive type, std::unique_ptr<Exp> right);

        void recursive_declare(driver &drv) final;

        void logic(driver &drv) final;

        void recursive_logic(driver &drv) final;

        void recursive_compile(driver &drv) final;
    };

    struct MultiDeclarationStatement: public StatementLike {
        primitive type;
        std::vector<std::unique_ptr<DeclarationStatement>> list;
        MultiDeclarationStatement(primitive type):type(type){};

        void add(driver& drv,std::string name,std::unique_ptr<Exp> exp){
            list.push_back(std::make_unique<DeclarationStatement>(drv,std::move(name),type,std::move(exp)));
        }

        void recursive_declare(driver &drv) final;

        void logic(driver &drv) final;

        void recursive_logic(driver &drv) final;

        void recursive_compile(driver &drv) final;
    };
    //TODO: use for support function call
    struct ExpStatement : public StatementLike {
        std::unique_ptr<Exp> exp;
        ExpStatement(std::unique_ptr<Exp> exp);
    };

    //TODO:support nested-block in the future
    struct StatementList : public StatementLike {
        std::vector<std::unique_ptr<StatementLike>> statements;

        void add(std::unique_ptr<StatementLike> statement){
            statements.push_back(std::move(statement));
        }
        void recursive_declare(driver &drv) final;

        void logic(driver &drv)final {};

        void recursive_logic(driver &drv) final;

        void recursive_compile(driver &drv) final;

    };

    struct IfThenElse : public StatementLike {
        std::vector<std::pair<std::unique_ptr<BooleanExp>, std::unique_ptr<StatementLike>>> _case;
        std::unique_ptr<StatementLike> _else;

        /*
         * Give enough flexible for bison to modify
         */
        IfThenElse()= default;

        void add(std::unique_ptr<BooleanExp> test,std::unique_ptr<StatementList> body){
            _case.emplace_back(std::move(test),std::move(body));
        };
        void recursive_declare(driver &drv) final;

        void logic(driver &drv)final; // dont use this for if else

        void recursive_logic(driver &drv) final;

        void recursive_compile(driver &drv) final;

    };

    struct WhileDo: public StatementLike {
        std::unique_ptr<BooleanExp> _test;
        std::unique_ptr<StatementLike> _loop;
        WhileDo(std::unique_ptr<BooleanExp> test,std::unique_ptr<StatementLike> loop);
        void recursive_declare(driver &drv) final;

        void logic(driver &drv)final; // dont use this for while do

        void recursive_logic(driver &drv) final;

        void recursive_compile(driver &drv) final;

    };
}

#endif //CSE474_AST_H
