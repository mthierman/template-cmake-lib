#include <lib/lib.hpp>
#include <print>

namespace lib {
auto log(std::string_view message) -> void { std::println(message); }
} // namespace lib
