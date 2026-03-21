#include <log/log.hpp>

namespace mthierman {
auto log(std::string_view message) -> void { std::println("{}", message); }
} // namespace mthierman
