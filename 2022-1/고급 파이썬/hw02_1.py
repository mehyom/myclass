def fun_ex1(*args):
    result = 0
    for i in args:
        if str(type(i)) == "<class 'int'>":
            result = result + i
    return result

print(fun_ex1('text', 1, 4.5, 4, 0.01, 'str', 45))
