import numpy as np


def maxProductMemoized(S):
    # Create memory
    M = [[None for j in range(0, len(S) + 1)] for i in range(0, len(S))]
    # Create auxiliary
    maxProductMemoizedAux(M, S, 0, len(S))
    return M[0][len(S)], M


def maxProductMemoizedAux(M, S, i, j):
    # Caso base memoizado
    if M[i][j] != None:
        return M[i][j]

    # Caso Base
    if i + 1 == j:
        # (product, max_product, max_sublist)
        M[i][j] = S[i]
        return M[i][j]

    # Llamados a casos base
    max_a = maxProductMemoizedAux(M, S, i + 1, j)
    max_b = maxProductMemoizedAux(M, S, i, j - 1)

    # Hallar el producto
    product = np.prod(S[i:j])

    # Hallar el máximo entre todas las soluciones
    max_product = max(max_a, max_b, product)

    if product >= max_product:
        M[i][j] = product

    elif max_a >= max_product:
        M[i][j] = max_a

    else:
        M[i][j] = max_b

    return M[i][j]