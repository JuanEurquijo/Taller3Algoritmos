#include "recursive.h"
#include <cstdint>
#include <utility>
#include <vector>

std::pair<int64_t, std::pair<int64_t, int64_t>>
maxProductRecursiveAux(std::vector<int64_t> &S, int64_t i, int64_t j) {
  // Caso Base
  if (i + 1 == j) {
    return std::make_pair(S[i], std::make_pair(i, j));
  }

  // Llamados a casos base
  auto call_a = maxProductRecursiveAux(S, i + 1, j);
  auto call_b = maxProductRecursiveAux(S, i, j - 1);

  // Obtener los pares
  auto max_a = std::get<0>(call_a);
  auto sub_a = std::get<1>(call_a);

  auto max_b = std::get<0>(call_b);
  auto sub_b = std::get<1>(call_b);

  // Hallar el producto
  int64_t product = 1;
  for (int64_t idx = i; idx < j; idx++) {
    product *= S[idx];
  }

  // Hallar el máximo entre todas las soluciones
  int64_t max_product = std::max({max_a, max_b, product});

  if (product >= max_product) {
    return std::make_pair(product, std::make_pair(i, j));
  } else if (max_a >= max_product) {
    return std::make_pair(max_a, sub_a);
  } else {
    return std::make_pair(max_b, sub_b);
  }
}

std::pair<int64_t, std::pair<int64_t, int64_t>>
maxProductRecursive(std::vector<int64_t> &S) {
  return maxProductRecursiveAux(S, 0, S.size());
}