lam = lambda x, z: 1 + x + 3 * x ** 2 + 4 * z + 100 * z ** 3
x, z = map(int, input("Please enter x, z: ").split(" "))
print("f(x,z) =", lam(x, z))
