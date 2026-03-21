#include <lib/lib.hpp>

namespace lib {
auto log(std::string_view message) -> void { std::println("{}", message); }
} // namespace lib
