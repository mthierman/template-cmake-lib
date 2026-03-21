#include <utils/log.hpp>

namespace utils {
auto log(std::string_view message) -> void { std::println("{}", message); }
} // namespace utils
