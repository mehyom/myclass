list1 = [48, 91, 7, 24, 94, 48, 28, 82, 91, 82, 15, 62, 28, 69, 87, 44, 20, 62, 88, 0, 36, 78, 42, 28, 1, 19, 9, 15, 41, 50, 8, 52, 93, 52, 56, 30, 77, 36, 99, 25, 81, 92, 92, 27, 18, 85, 28, 50, 66, 95]
list2 = [66, 22, 15, 39, 95, 87, 90, 88, 38, 48, 8, 37, 47, 46, 4, 16, 25, 1, 89, 60, 90, 72, 23, 66, 28, 9, 64, 99, 14, 3, 100, 13, 11, 42, 29, 50, 49, 86, 9, 8, 0, 100, 4, 13, 7, 32, 92, 92, 73, 40]
def listzip(list1, list2):
    return list(zip(list1, list2))
print(listzip(list1,list2))
