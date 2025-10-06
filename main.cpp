#include "minilog.h"

int main(){

    minilog::set_log_level(minilog::log_level::debug);
    generic_log(minilog::log_level::debug, "hello {}", 42);
    minilog::log_debug("hello {}", 42);
    generic_log(minilog::log_level::info, "world");

    const auto pi = 3.1415926535;
    MINILOG_P(pi);

    return 0;
}