#include "bottomup.h"
#include <cstddef>
#include <cstdint>
#include <utility>
#include <vector>

std::pair<int64_t, bottomup_memory>
maxProductBottomUp(std::vector<int64_t> &S) {
  // Create memory
  bottomup_memory M{};
  for (size_t i = 0; i < S.size(); i++) {
    M.push_back(std::vector<int64_t>());
    for (size_t j = 0; j < S.size() + 1; j++)
      M[i].push_back(0);
  }

  for (size_t k = 1; k < S.size() + 1; k++) {

    for (size_t i = 0, j = k; j != S.size() + 1; i++, j++) {
      if (i + 1 == j) {

        M[i][j] = S[i];
      } else {
        // Llamados a casos base
        auto max_a = M[i + 1][j];
        auto max_b = M[i][j - 1];

        // Hallar el producto
        int64_t product = 1;
        for (size_t idx = i; idx < j; idx++) {
          product *= S[idx];
        }

        // Hallar el máximo entre todas las soluciones
        int64_t max_product = std::max({max_a, max_b, product});

        if (product >= max_product) {
          M[i][j] = product;
        } else if (max_a >= max_product) {
          M[i][j] = max_a;
        } else {
          M[i][j] = max_b;
        }
      }
    }
  }

  // Return value
  return std::make_pair(M[0][S.size()], M);
}