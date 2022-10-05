def filternum(*args):
    if str(type(args[0]))== "<class 'list'>":
        args = [i for i in args[0]]
    return [i for i in args if i % 2 != 1]

print(filternum(1,2,3,4,5,5,5,5))
print(filternum([1,2,3,4,5]))
