def searchSubsequence(M):
    i, j = 0, len(M[0]) - 1
    max = M[i][j]

    while 1:
        left = M[i][j - 1]
        down = M[i + 1][j]

        if left == max:
            j -= 1
            continue

        if down == max:
            i += 1
            continue

        return (i, j)
