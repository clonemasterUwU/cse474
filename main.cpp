#include <iostream>
#include "driver.h"

int
main(int argc, char *argv[]) {
    int res = 0;
    driver drv;

    for (int i = 1; i < argc; ++i)
        if (argv[i] == std::string("-p")) {
            drv.trace_parsing = true;
        } else if (argv[i] == std::string("-d")) {
            drv.trace_scanning = true;
        } else if (!drv.parse(argv[i])) {
            //should have std::cerr output the error
        } else {
            res = 1;
        }
    return res;
}