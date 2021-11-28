#include "bison.h"
#include "driver.h"

driver::driver() : trace_parsing(false), trace_scanning(false),
temp_counter(0),test_counter(0) {
    temp_prefix = "&temp";
    test_start_prefix = ":&test_start";
    test_end_prefix = ":&test_end";
}

int driver::parse(const std::string &f) {
    file = f;
    location.initialize(&file);
    auto t = f.find('.');
    if(t==std::string::npos){
        output = std::ofstream (f+".asm");
    } else {
        output = std::ofstream (f.substr(0,t)+".asm");
    }

    temp_counter = 0;
    scan_begin();
    yy::parser parser(*this);
    parser.set_debug_level(trace_parsing);
    int res = parser.parse();
    scan_end();
    symbol_table.clear();
    return res;
}
