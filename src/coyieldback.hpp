#include "corogenback.hpp" // for CoroGenBack
#include <iostream>

CoroGenBack coro(int max) {
  std::cout << "         CORO " << max << " start\n";

  for (int val = 1; val <= max; ++val) {
    // print next value:
    std::cout << "         CORO " << val << '/' << max << '\n';

    // yield next value:
    auto back = co_yield val; // SUSPEND with value with response
    std::cout << "         CORO => " << back << "\n";
  }

  std::cout << "         CORO " << max << " end\n";
}
