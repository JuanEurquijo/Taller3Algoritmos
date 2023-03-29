import sys
import time
import algorithms
import random

def generateRandomList(n):
    l = [random.randint(-100, 100) for _ in range(n)]
    print(l)
    return l


def MeasureTime(nameFile, increment, iterations):
    file = open(str(nameFile) + ".out", "w")
    n = int(increment)
    for i in range (0,int(iterations)):
      print(f"\nIteration: {i+1}/{iterations}\tN: {n}")
      data = generateRandomList(n)
      
    ###---------Measure for Recursive---------###

      print("\nExecuting recursive.....")
      init_rec = time.time_ns()
      result_rec, index = algorithms.recursive.maxProductRecursive(data)
      end_rec = time.time_ns()
      print(f"Maximum Product Subsequence\n({result_rec}): {data[index[0]:index[1]]}")

    ###---------Measure for Memoized---------###

      print("\nExecuting Memoized.....")
      init_mem = time.time_ns()
      _, result_mem = algorithms.memoized.maxProductMemoized(data)
      end_mem = time.time_ns()
      #index = algorithms.searchSubsequence(result_mem)
      print(f"Maximum Product Subsequence: {data[index[0]:index[1]]}")

    ###---------Measure for Bottom Up---------###
    
      print("\nExecuting Bottom Up.....")
      init_bu = time.time_ns()
      _, result_bu = algorithms.recursive.maxProductRecursive(data)
      end_bu = time.time_ns()
      #index = algorithms.searchSubsequence(result_mem)
      print(f"Maximum Product Subsequence: {data[index[0]:index[1]]}")


      file.write(str(n) + " " +str(end_rec-init_rec)
                 + " " + str(end_mem-init_mem)
                 + " " + str(end_bu-init_bu)+"\n")

      n += int(increment)
    file.close()

# end def


## -------------------------------------------------------------------------
## Main code
## -------------------------------------------------------------------------

if len(sys.argv) < 4:
    print("Usage: py", sys.argv[0],"output_file", "n_increment" ,"iterations")
    sys.exit(1)
# end if

MeasureTime(sys.argv[1],sys.argv[2],sys.argv[3])

