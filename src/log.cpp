#include <log/log.hpp>

namespace log {
auto log(std::string_view message) -> void { std::println("{}", message); }
} // namespace log
