#include <cstdlib>
#include <lib/lib.hxx>
#include <print>

auto wmain([[maybe_unused]] int argc, [[maybe_unused]] wchar_t** argv) -> int {
    std::println("{}", lib::thirteen());

    return EXIT_SUCCESS;
}
