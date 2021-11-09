#include "bison.h"
#include "driver.h"

driver::driver() : trace_parsing(false), trace_scanning(false),counter(0) {

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
    prefix = "&temp";
    counter = 0;
    scan_begin();
    yy::parser parser(*this);
    parser.set_debug_level(trace_parsing);
    int res = parser.parse();
    scan_end();
    symbol_table.clear();
    return res;
}
