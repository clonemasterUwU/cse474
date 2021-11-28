//
// Created by deal_with on 08/11/2021.
//

#ifndef CSE474_DRIVER_H
#define CSE474_DRIVER_H


# include <string>
# include <unordered_map>
#include <fstream>
#include <sstream>
#include <cassert>
#include "ast.h"
#include "bison.h"
# define YY_DECL \
  yy::parser::symbol_type yylex (driver& drv)
// ... and declare it for the parser's sake.
YY_DECL;


class driver {
private:
    u_int64_t temp_counter;
    u_int64_t test_counter;

public:

    driver();

    std::string temp_prefix;
    std::string test_end_prefix;
    std::string test_start_prefix;
    std::unordered_map<std::string, h_ast::primitive> symbol_table;

    std::ofstream output;
    std::stringstream buffer;

    // Run the parser on file F.  Return 0 on success.
    int parse(const std::string &f);

    // The name of the file being parsed.
    std::string file;
    // Whether to generate parser debug traces.
    bool trace_parsing;

    // Handling the scanner.
    void scan_begin();

    void scan_end();

    // Whether to generate scanner debug traces.
    bool trace_scanning;
    // The token's location used by the scanner.
    yy::location location;

    h_ast::primitive find_symbol(const std::string &symbol_name) {
        auto p = symbol_table.find(symbol_name);
        if (p == symbol_table.end()) {
            throw yy::parser::syntax_error(location, "variable " + symbol_name + " is not declared");
        }
        return p->second;
    }

    void insert_symbol_not_exist(const std::string &symbol_name, h_ast::primitive type) {
        if (symbol_table.find(symbol_name) != symbol_table.end()) {
            throw yy::parser::syntax_error(location, "variable " + symbol_name + " is already declared");
        }
        symbol_table[symbol_name] = type;
    }
//    void check_valid_operator(const symbol_type & a){
//        if(a.second!=INT && a.second != REAL){
////            throw yy::parser::syntax_error (location,"type " + a.second + " is not valid for operator");
//        }
//    }

    std::string get_temp_name() {
        return temp_prefix + std::to_string(temp_counter++);
    }

    u_int64_t get_test_id() {
        return test_counter++;
    }
//    void before_op(symbol_type& a,symbol_type & b){
//        check_valid_operator(a);
//        check_valid_operator(b);
//        if(a.second == REAL || b.second == REAL){
//            if(a.second==INT){
//                std::string temp = get_temp_name();
//                output << "declare " << temp << ", real\n" << "itor " << a.first << ", " << temp << '\n';
//                a.second = REAL;
//                a.first = std::move(temp);
//            }
//            if(b.second==INT){
//                std::string temp = get_temp_name();
//                output << "declare " << temp << ", real\n"
//                << "itor " << b.first << ", " << temp << '\n';
//                b.second = REAL;
//                b.first = std::move(temp);
//            }
//        }
//    }
//    symbol_type op(symbol_type& a,symbol_type& b,const char* op){
//        before_op(a,b);
//        symbol_type res;
//        res.first = get_temp_name();
//        if(a.second==INT){
//            res.second = INT;
//            output << 'i' << op << ' ' << a.first << ", " << b.first << ", " << res.first << '\n';
//        } else {
//            res.second = REAL;
//            output << 'r' << op << ' ' << a.first << ", " << b.first << ", " << res.first << '\n';
//        }
//        symbol_table.insert(res);
//        return res;
//    }

};


#endif //CSE474_DRIVER_H
