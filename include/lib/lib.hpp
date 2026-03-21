#pragma once
#include <format>
#include <string_view>

namespace lib {
template <typename... Args>
auto log(std::format_string<Args...> format_string, Args&&... args) -> void
{
    std::println(std::format(format_string, std::forward<Args>(args)...));
}

auto log(std::string_view message) -> void;
} // namespace lib
