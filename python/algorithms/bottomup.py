import numpy as np

def maxProductBottomup(S):
  # Create memory
  M = [[None for j in range(0, len(S) + 1)] for i in range(0, len(S) + 1)]

  for k in range(1, len(S) + 1):

    i = 0
    j = k

    while(j != len(S) + 1):

      if i+1 == j:
        # (product, max_product, max_sublist)
        M[i][j]=S[i:j][0]
      else:

      # Llamados a casos base
       max_a = M[i+1][j]
       max_b = M[i][j-1]

      # Hallar el producto
       product = np.prod(S[i:j])

      # Hallar el máximo entre todas las soluciones
       max_product = max(max_a, max_b,product)

       if product >= max_product:
         M[i][j]= product

       elif max_a >= max_product:
         M[i][j] = max_a

       else:
         M[i][j] = max_b
      i+=1
      j+=1

  return M[0][len(S)],M