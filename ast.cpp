//
// Created by deal_with on 26/11/2021.
//

#include "ast.h"
#include "driver.h"


std::ostream &h_ast::operator<<(std::ostream &out, primitive type) {
    switch (type) {
        case INT:
            out << "integer";
            break;
        case REAL:
            out << "real";
            break;
        case CHAR:
            out << "char";
            break;
        case BOOL:
            out << "boolean";
            break;
    }
    return out;
}

std::ostream &h_ast::operator<<(std::ostream &out, bool_b_op op) {
    switch (op) {
        case AND:
            out << "and";
            break;
        case OR:
            out << "or";
            break;
    }
    return out;
}

std::ostream &h_ast::operator<<(std::ostream &out, arithmetic_b_op op) {
    switch (op) {
        case ADD:
            out << "add";
            break;
        case SUB:
            out << "sub";
            break;
        case MUL:
            out << "mult";
            break;
        case DIV:
            out << "div";
            break;
        case MOD:
            out << "mod";
            break;
    }
    return out;
}


void h_ast::Exp::declare(driver &drv) {
    drv.output << "declare " << name << ", " << type << '\n';
}

void h_ast::Exp::compile(driver &drv) {
    declare(drv);
    logic(drv);
}

h_ast::ArithmeticExp::ArithmeticExp(driver &drv, std::unique_ptr<Exp> left, std::unique_ptr<Exp> right,
                                    h_ast::arithmetic_b_op op) :
        _left(std::move(left)), _right(std::move(right)), op(op),
        Exp(left->type == REAL || right->type == REAL ? REAL : INT, drv.get_temp_name()) {
    //if one side evaluate to real while the other does not, then do wrap/convert
    if (_left->type == REAL && _right->type != REAL) {
        _right = std::make_unique<WrapperExp>(drv, std::move(_right), REAL);
    } else if (_left->type != REAL && _right->type == REAL) {
        _left = std::make_unique<WrapperExp>(drv, std::move(_left), REAL);
    }
}

void h_ast::ArithmeticExp::logic(driver &drv) {
    drv.output << (type == REAL ? 'r' : 'i') << op << ' ' << _left->name << ", " << _right->name << ", " << name
               << '\n';
}

void h_ast::ArithmeticExp::recursive_compile(driver &drv) {
    _left->recursive_compile(drv);
    _right->recursive_compile(drv);
    compile(drv);
}

void h_ast::ArithmeticExp::recursive_declare(driver &drv) {
    _left->recursive_declare(drv);
    _right->recursive_declare(drv);
    declare(drv);
}

void h_ast::ArithmeticExp::recursive_logic(driver &drv) {
    _left->recursive_logic(drv);
    _right->recursive_logic(drv);
    logic(drv);
}


h_ast::WrapperExp::WrapperExp(
        driver &drv, std::unique_ptr<Exp> exp, h_ast::primitive type) :
        exp(std::move(exp)), Exp(type, drv.get_temp_name()) {}

void h_ast::WrapperExp::logic(driver &drv) {
    drv.output << (type == REAL ? "itor " : "rtoi ") << exp->name << ", " << name << '\n';
}

void h_ast::WrapperExp::recursive_declare(driver &drv) {
    exp->recursive_declare(drv);
    declare(drv);
}

void h_ast::WrapperExp::recursive_logic(driver &drv) {
    exp->recursive_logic(drv);
    logic(drv);
}

void h_ast::WrapperExp::recursive_compile(driver &drv) {
    exp->recursive_compile(drv);
    compile(drv);
}


void h_ast::Literal::recursive_declare(driver &drv) {
    declare(drv);
}

void h_ast::Literal::recursive_logic(driver &drv) {
    logic(drv);
}

void h_ast::Literal::recursive_compile(driver &drv) {
    compile(drv);
}

h_ast::BoolLiteral::BoolLiteral(driver &drv, bool t) : Literal(drv.get_temp_name(), BOOL), t(t) {}

void h_ast::BoolLiteral::logic(driver &drv) {
    drv.output << "store " << (t ? 1 : 0) << ", " << name << '\n';
}

h_ast::IntegerLiteral::IntegerLiteral(driver &drv, int t) : Literal(drv.get_temp_name(), INT), t(t) {}

void h_ast::IntegerLiteral::logic(driver &drv) {
    drv.output << "store " << t << ", " << name << '\n';
}

h_ast::RealLiteral::RealLiteral(driver &drv, double t) : Literal(drv.get_temp_name(), REAL), t(t) {}

void h_ast::RealLiteral::logic(driver &drv) {
    drv.output << "store " << t << ", " << name << '\n';
}

h_ast::CharLiteral::CharLiteral(driver &drv, char t) : Literal(drv.get_temp_name(), CHAR), t(t) {}

void h_ast::CharLiteral::logic(driver &drv) {
    drv.output << "store \'" << t << "\', " << name << '\n';

}

h_ast::BinaryBoolExp::BinaryBoolExp(
        driver &drv, std::unique_ptr<BooleanExp> left, std::unique_ptr<BooleanExp> right, h_ast::bool_b_op op) :
        left(std::move(left)), right(std::move(right)), op(op), BooleanExp(drv.get_temp_name()) {}

void h_ast::BinaryBoolExp::logic(driver &drv) {
    drv.output << op << ' ' << left->name << ", " << right->name << ", " << name << '\n';
}

void h_ast::BinaryBoolExp::recursive_declare(driver &drv) {
    left->recursive_declare(drv);
    right->recursive_declare(drv);
    declare(drv);
}

void h_ast::BinaryBoolExp::recursive_logic(driver &drv) {
    auto idx = drv.get_test_id();
    left->recursive_logic(drv);
    drv.output << "store " << left->name << ", " << name << '\n'
               << (op == AND ? "jf " : "jt ") << name << ", " << drv.test_end_prefix << idx << '\n';
    right->recursive_logic(drv);
    drv.output << "store " << right->name << ", " << name << '\n'
               << drv.test_end_prefix << idx << '\n';
}

void h_ast::BinaryBoolExp::recursive_compile(driver &drv) {
    auto idx = drv.get_test_id();
    left->recursive_compile(drv);
    drv.output << "store " << left->name << ", " << name << '\n'
               << (op == AND ? "jf " : "jt ") << name << ", " << drv.test_end_prefix << idx << '\n';
    right->recursive_compile(drv);
    drv.output << "store " << right->name << ", " << name << '\n'
               << drv.test_end_prefix << idx << '\n';
}


h_ast::BinaryArithmeticBoolExp::BinaryArithmeticBoolExp(
        driver &drv, std::unique_ptr<Exp> left, std::unique_ptr<Exp> right, h_ast::bool_a_op op) :
        _left(std::move(left)), _right(std::move(right)), _op(op), BooleanExp(drv.get_temp_name()) {
    //if one side evaluate to real while the other does not, then do wrap/convert
    if (_left->type == REAL && _right->type != REAL) {
        _right = std::make_unique<WrapperExp>(drv, std::move(_right), REAL);
    } else if (_left->type != REAL && _right->type == REAL) {
        _left = std::make_unique<WrapperExp>(drv, std::move(_left), REAL);
    }
}

void h_ast::BinaryArithmeticBoolExp::logic(driver &drv) {
    switch (_op) {
        case EQ:
            drv.output << "equ " << _left->name << ", " << _right->name << ", " << name << '\n';
            break;
        case NE:
            drv.output << "equ " << _left->name << ", " << _right->name << ", " << name << '\n'
                       << "not " << name << ", " << name << '\n';
            break;
        case GT:
            drv.output << "high " << _left->name << ", " << _right->name << ", " << name << '\n';
            break;
        case LE:
            drv.output << "high " << _left->name << ", " << _right->name << ", " << name << '\n'
                       << "not " << name << ", " << name << '\n';
            break;
        case LT:
            drv.output << "low " << _left->name << ", " << _right->name << ", " << name << '\n';
            break;
        case GE:
            drv.output << "low " << _left->name << ", " << _right->name << ", " << name << '\n'
                       << "not " << name << ", " << name << '\n';
            break;
    }
}

void h_ast::BinaryArithmeticBoolExp::recursive_declare(driver &drv) {
    _left->recursive_declare(drv);
    _right->recursive_declare(drv);
    declare(drv);
}

void h_ast::BinaryArithmeticBoolExp::recursive_logic(driver &drv) {
    _left->recursive_logic(drv);
    _right->recursive_logic(drv);
    logic(drv);
}

void h_ast::BinaryArithmeticBoolExp::recursive_compile(driver &drv) {
    _left->recursive_compile(drv);
    _right->recursive_compile(drv);
    compile(drv);
}


h_ast::UnaryBoolExp::UnaryBoolExp(driver &drv, std::unique_ptr<BooleanExp> exp, h_ast::bool_u_op op) :
        BooleanExp(drv.get_temp_name()), exp(std::move(exp)), op(op) {

}

void h_ast::UnaryBoolExp::logic(driver &drv) {
    drv.output << "not " << name << ", " << name << '\n';
}

void h_ast::UnaryBoolExp::recursive_declare(driver &drv) {
    exp->recursive_declare(drv);
    declare(drv);
}

void h_ast::UnaryBoolExp::recursive_logic(driver &drv) {
    exp->recursive_logic(drv);
    logic(drv);
}

void h_ast::UnaryBoolExp::recursive_compile(driver &drv) {
    exp->compile(drv);
    compile(drv);
}

void h_ast::LiteralBoolExp::logic(driver &drv) {

}

void h_ast::LiteralBoolExp::recursive_declare(driver &drv) {
    lit->declare(drv);
}

void h_ast::LiteralBoolExp::recursive_logic(driver &drv) {
    lit->recursive_logic(drv);
}

void h_ast::LiteralBoolExp::recursive_compile(driver &drv) {
    lit->recursive_compile(drv);
}


h_ast::IdentifierExist::IdentifierExist(driver &drv, std::string name) : Exp(drv.find_symbol(name), "") {
    this->name = std::move(name);
}

void h_ast::IdentifierExist::declare(driver &drv) {/* dont re-declare symbol*/}

void h_ast::IdentifierExist::logic(driver &drv) {}

void h_ast::IdentifierExist::recursive_declare(driver &drv) {}

void h_ast::IdentifierExist::recursive_logic(driver &drv) {}

void h_ast::IdentifierExist::recursive_compile(driver &drv) {}

h_ast::IdentifierNotExist::IdentifierNotExist(driver &drv, std::string name, h_ast::primitive type)
        : Exp(type, std::move(name)) {
    drv.insert_symbol_not_exist(this->name, type);
}

void h_ast::IdentifierNotExist::logic(driver &drv) {}

void h_ast::IdentifierNotExist::recursive_declare(driver &drv) {
    declare(drv);
}

void h_ast::IdentifierNotExist::recursive_logic(driver &drv) {}

void h_ast::IdentifierNotExist::recursive_compile(driver &drv) {
    declare(drv);
}


h_ast::AssignmentStatement::AssignmentStatement(
        driver &drv, std::unique_ptr<IdentifierExist> left, std::unique_ptr<Exp> right)
        : _left(std::move(left)), _right(std::move(right)) {
    if (_left->type == REAL && _right->type != REAL) {
        _right = std::make_unique<WrapperExp>(drv, std::move(_right), REAL);
    } else if (_left->type != REAL && _left->type == REAL) {
        _right = std::make_unique<WrapperExp>(drv, std::move(_right), INT);
    }

}

void h_ast::AssignmentStatement::logic(driver &drv) {
    drv.output << "store " << _right->name << ", " << _left->name << '\n';
}

void h_ast::AssignmentStatement::recursive_logic(driver &drv) {
    _right->recursive_logic(drv);
    _left->recursive_logic(drv);
    logic(drv);
}

void AssignmentStatement::recursive_declare(driver &drv) {
    _right->recursive_declare(drv);
    _left->recursive_declare(drv);
}

void AssignmentStatement::recursive_compile(driver &drv) {
    _right->recursive_compile(drv);
    _left->recursive_compile(drv);
    logic(drv);
}


void h_ast::ReadStatement::logic(driver &drv) {
    for (auto &ptr: _expList) {
        drv.output << "read " << ptr->name << ", " << ptr->type << '\n';
    }
}

void h_ast::ReadStatement::recursive_logic(driver &drv) {
    for (auto &ptr: _expList) {
        ptr->recursive_logic(drv);
        drv.output << "read " << ptr->name << ", " << ptr->type << '\n';
    }
}

void h_ast::ReadStatement::recursive_declare(driver &drv) {
    for (auto &ptr: _expList) {
        ptr->recursive_declare(drv);
    }
}

void h_ast::ReadStatement::recursive_compile(driver &drv) {
    for (auto &ptr: _expList) {
        ptr->recursive_compile(drv);
        drv.output << "read " << ptr->name << ", " << ptr->type << '\n';
    }
}

ReadStatement::ReadStatement(std::vector<std::unique_ptr<IdentifierExist>> expList): _expList(std::move(expList)){

}



void h_ast::WriteStatement::logic(driver &drv) {
    for (auto &ptr: _expList) {
        drv.output << "write " << ptr->name << ", " << ptr->type << '\n';
    }
}

void h_ast::WriteStatement::recursive_declare(driver &drv) {
    for (auto &ptr: _expList) {
        ptr->recursive_declare(drv);
    }
}

void h_ast::WriteStatement::recursive_compile(driver &drv) {
    for (auto &ptr: _expList) {
        ptr->recursive_compile(drv);
        drv.output << "write " << ptr->name << ", " << ptr->type << '\n';
    }
}

void h_ast::WriteStatement::recursive_logic(driver &drv) {
    for (auto &ptr: _expList) {
        ptr->recursive_logic(drv);
        drv.output << "write " << ptr->name << ", " << ptr->type << '\n';
    }
}

h_ast::WriteStatement::WriteStatement(std::vector<std::unique_ptr<Exp>> expList) : _expList(std::move(expList)) {}

h_ast::DeclarationStatement::DeclarationStatement(driver &drv, std::string name, primitive type,
                                                  std::unique_ptr<Exp> right)
        : _left(std::make_unique<IdentifierNotExist>(drv, std::move(name), type)), _right(std::move(right)) {
    if (_right) {
        if (_left->type == REAL && _right->type != REAL) {
            _right = std::make_unique<WrapperExp>(drv, std::move(_right), REAL);
        } else if (_left->type != REAL && _left->type == REAL) {
            _right = std::make_unique<WrapperExp>(drv, std::move(_right), INT);
        }
    }
}

void h_ast::DeclarationStatement::recursive_declare(driver &drv) {
    if (_right) _right->recursive_declare(drv);
    _left->recursive_declare(drv);
}

void h_ast::DeclarationStatement::logic(driver &drv) {
    if (_right) {
        drv.output << "store " << _right->name << ", " << _left->name << '\n';
    }
}

void h_ast::DeclarationStatement::recursive_logic(driver &drv) {
    if (_right) _right->recursive_logic(drv);
    _left->recursive_logic(drv);
    logic(drv);
}

void h_ast::DeclarationStatement::recursive_compile(driver &drv) {
    if (_right) _right->recursive_compile(drv);
    _left->recursive_compile(drv);
    logic(drv);
}

void h_ast::StatementList::recursive_declare(driver &drv) {
    for (auto &ptr: statements) {
        ptr->recursive_declare(drv);
    }
}

void h_ast::StatementList::recursive_logic(driver &drv) {
    for (auto &ptr: statements) {
        ptr->recursive_logic(drv);
    }
}

void h_ast::StatementList::recursive_compile(driver &drv) {
    for (auto &ptr: statements) {
        ptr->recursive_compile(drv);
    }
}

void h_ast::IfThenElse::recursive_declare(driver &drv) {
    for (auto&[bexp, stmts]: _case) {
        bexp->recursive_declare(drv);
        stmts->recursive_declare(drv);
    }
}

void h_ast::IfThenElse::logic(driver &drv) {

}

void h_ast::IfThenElse::recursive_logic(driver &drv) {
    auto idx = drv.get_test_id();
    for (size_t i = 0; i < _case.size(); i++) {
        if (i) {
            drv.output << drv.test_start_prefix << idx << '_' << i << '\n';
        }
        _case[i].first->recursive_logic(drv);
        drv.output << "iff " << _case[i].first->name << ", " << drv.test_start_prefix << idx << '_' << i + 1 << '\n';
        _case[i].second->recursive_logic(drv);
        drv.output << "jmp " << drv.test_end_prefix << idx << '\n';
    }
    drv.output << drv.test_start_prefix << idx  << '_' << _case.size() << '\n';
    if (_else) {
        _else->recursive_logic(drv);
    }
    drv.output << drv.test_end_prefix << idx << '\n';
}

void h_ast::IfThenElse::recursive_compile(driver &drv) {
    recursive_declare(drv);
    recursive_logic(drv);
}

h_ast::WhileDo::WhileDo(std::unique_ptr<BooleanExp> test, std::unique_ptr<StatementLike> loop)
        : _test(std::move(test)), _loop(std::move(loop)) {}

void h_ast::WhileDo::recursive_declare(driver &drv) {
    _test->recursive_declare(drv);
    _loop->recursive_declare(drv);
}

void h_ast::WhileDo::logic(driver &drv) {

}

void h_ast::WhileDo::recursive_logic(driver &drv) {
    auto idx = drv.get_test_id();
    drv.output << drv.test_start_prefix << idx << '\n';
    _test->recursive_logic(drv);
    drv.output << "iff " << _test->name << ", " << drv.test_end_prefix << idx << '\n';
    _loop->recursive_logic(drv);
    drv.output << "jmp " << drv.test_start_prefix << idx << '\n';
    drv.output << drv.test_end_prefix << idx << '\n';
}

void h_ast::WhileDo::recursive_compile(driver &drv) {
    recursive_declare(drv);
    recursive_logic(drv);
}

void h_ast::MultiDeclarationStatement::recursive_declare(driver &drv) {
    for (auto &ptr: list) {
        ptr->recursive_declare(drv);
    }
}

void h_ast::MultiDeclarationStatement::logic(driver &drv) {

}

void h_ast::MultiDeclarationStatement::recursive_logic(driver &drv) {
    for (auto &ptr: list) {
        ptr->recursive_logic(drv);
    }
}

void h_ast::MultiDeclarationStatement::recursive_compile(driver &drv) {
    for (auto &ptr: list) {
        ptr->recursive_compile(drv);
    }
}

ExpStatement::ExpStatement(std::unique_ptr<Exp> exp) : exp(std::move(exp)) {

}
