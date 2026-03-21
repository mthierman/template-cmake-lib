#pragma once
#include <format>
#include <print>
#include <string_view>

namespace utils {
template <typename... Args>
auto log(std::format_string<Args...> format_string, Args&&... args) -> void
{
    std::println(format_string, std::forward<Args>(args)...);
}

auto log(std::string_view message) -> void;
} // namespace utils
