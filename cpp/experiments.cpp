#include "./algorithms/bottomup.h"
#include "./algorithms/memoized.h"
#include "./algorithms/recursive.h"

#include <chrono>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <random>
#include <tuple>
#include <vector>

/* --------- Function Prototipes --------- */
std::vector<int64_t> generate_random_list(int size);
std::tuple<double, double, double> measure_algorithms(std::vector<int64_t> &S);

/* --------- Main --------- */
int main(int argc, char **argv) {

  // Check arguments
  if (argc < 4) {
    std::cerr << "Usage: " << argv[0] << " output_file n_increment iterations";
    return 1;
  }

  // Obtain variables from arguments
  auto filename = std::string(argv[1]);
  auto n_increment = std::atoi(argv[2]);
  auto iterations = std::atoi(argv[3]);

  // Create file
  auto file = std::ofstream(filename + ".out", std::ios::out);

  if (!file) {
    std::cerr << "Error opening file!";
    return 1;
  }

  // Measure
  size_t n = n_increment;
  for (int i = 0; i < iterations; i++, n += n_increment) {

    // Generate RandomList
    auto S = generate_random_list(n);

    // Show variables
    std::cout << std::endl
              << "Test Iteration: (" << i + 1 << "/" << iterations << ")"
              << std::endl
              << "Number of elements: " << n << std::endl;

    auto times = measure_algorithms(S);

    // Print variables to output file
    file << std::fixed << std::setprecision(0) << n << " " << std::get<0>(times)
         << " " << std::get<1>(times) << " " << std::get<2>(times) << std::endl;
  }

  file.close();
  std::cout << "\nFinished: " << filename + ".out" << std::endl;
  return 0;
}

/* --------- Function definition --------- */
std::vector<int64_t> generate_random_list(int size) {
  static std::mt19937 rng(std::rand());
  static std::uniform_int_distribution<int> gen(-100, 100);

  std::vector<int64_t> list;
  for (int _ = 0; _ < size; _++) {
    list.push_back(gen(rng));
  }
  return list;
}

std::tuple<double, double, double> measure_algorithms(std::vector<int64_t> &S) {
  // Create clock
  static auto clock = std::chrono::high_resolution_clock{};

  // Recursive
  auto start_recursive = clock.now();
  (void)maxProductRecursive(S);
  auto end_recursive = clock.now();
  auto time_recursive = std::chrono::duration_cast<std::chrono::microseconds>(
      end_recursive - start_recursive);
  std::cout << "Recursive:\t" << std::fixed << std::setprecision(5)
            << time_recursive.count() << " μs" << std::endl;

  // Memoized
  auto start_memoized = clock.now();
  (void)maxProductMemoized(S);
  auto end_memoized = clock.now();
  auto time_memoized = std::chrono::duration_cast<std::chrono::microseconds>(
      end_memoized - start_memoized);
  std::cout << "Memoized:\t" << std::fixed << std::setprecision(5)
            << time_memoized.count() << " μs" << std::endl;

  // BottomUp
  auto start_bottomup = clock.now();
  (void)maxProductBottomUp(S);
  auto end_bottomup = clock.now();
  auto time_bottomup = std::chrono::duration_cast<std::chrono::microseconds>(
      end_bottomup - start_bottomup);
  std::cout << "BottomUp:\t" << std::fixed << std::setprecision(5)
            << time_bottomup.count() << " μs" << std::endl;

  // Return times
  return std::make_tuple(time_recursive.count(), time_memoized.count(),
                         time_bottomup.count());
}