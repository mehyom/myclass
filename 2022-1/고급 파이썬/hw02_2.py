def fun_int(N, *args, start = 0, end = 1):
    result = 0
    for i in range(N):
        x = start + i * (end - start) / N
        fun_x = 0
        count = 0
        for j in args:
            fun_x = fun_x + (x ** count) * j
            count += 1
        result = result + fun_x * (end - start) / N
    return result

print(fun_int(10, 1, 2, 3, start = 0, end = 1))
