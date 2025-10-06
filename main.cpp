#include "minilog.h"

int main(){

    // minilog::set_log_level(minilog::log_level::info);

    minilog::generic_log(minilog::log_level::debug, "hello {}", 42);
    minilog::log_debug("hello {}", 42);
    minilog::generic_log(minilog::log_level::info, "world");
    minilog::log_warning("buru yuanshen :{}", 50);

    const auto pi = 3.1415926535;
    MINILOG_P(pi);

    return 0;
}