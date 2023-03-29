import numpy as np

def maxProductRecursive(S):
    return maxProductRecursiveAux(S, 0, len(S))


def maxProductRecursiveAux(S, i, j):
    # Caso Base
    if i + 1 == j:
        return S[i], (i, j)

    # Llamados a casos base
    max_a, sub_a = maxProductRecursiveAux(S, i + 1, j)
    max_b, sub_b = maxProductRecursiveAux(S, i, j - 1)

    # Hallar el producto
    product = np.prod(S[i:j])

    # Hallar el máximo entre todas las soluciones
    max_product = max(max_a, max_b, product)

    if product >= max_product:
        return product, (i, j)

    elif max_a >= max_product:
        return max_a, sub_a

    else:
        return max_b, sub_b
