#include <concepts>
#import <format>
#import <source_location>
#import <iostream>



template<typename T>
struct with_source_location{
private:
    T inner;
    std::source_location loc;

public:
    template<typename U> requires std::constructible_from<T, U>
    consteval explicit with_source_location(U &&inner, std::source_location loc = std::source_location::current())
    :inner(std::forward<U>(inner)), loc(loc){}
    constexpr T const &format() const {return inner;}
    [[nodiscard]] constexpr std::source_location const &location() const {return loc;}
};

template<typename... Args>
void log_info(with_source_location<std::format_string<Args...>> fmt, Args &&...args){
    auto const &loc = fmt.location();
    std::cout << loc.file_name() << ":" << loc.line() << " [Info] " << std::vformat(fmt.format().get(), std::make_format_args(args...)) << '\n';
}

int main(){

    constexpr auto loc = std::source_location::current();
    std::cout << std::format("line = {0}, column={1}, file={2}, func={3}",loc.line(),loc.column(),loc.file_name(),loc.function_name()) << "\n";

    return 0;
}