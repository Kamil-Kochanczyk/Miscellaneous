import numpy as np

#a = np.array([0, 1, 2])
a = np.array([0, 1, 2], dtype="int32")
print(a)
print(a.ndim)
print(a.shape)
print(a.dtype)
print(a.itemsize)
print(a.size)
print(a.nbytes)
print()

b = np.array([["Three", "Four"], ["Five", "Six"], ["Seven", "Eight"]])
print(b)
print(b.ndim)
print(b.shape)
print(b.dtype)
print(b.itemsize)
print(b.size)
print(b.nbytes)
print()

c = np.array([[1, 2, 3, 4, 5], [6, 7, 8, 9, 10]])
print(c)
print(c[1, 2])
print(c[1, :]) #Specific row
print(c[:, 3]) #Specific column
print(c[0, 1:4])
print(c[1, 0:4:2])
c[:, 1] = 0
print(c)
c[:, 4] = [10, 5]
print(c)
print()

zeros = np.zeros(5)
print(zeros)
ones = np.ones((3, 6), dtype="int32")
print(ones)
sevens = np.full((4, 2), 7)
print(sevens)
print()

random_decimals = np.random.rand(2, 3)
print(random_decimals)
random_integers = np.random.randint(-9, 10, (3, 2))
print(random_integers)
print()

identity_matrix = np.identity(3, dtype="int32")
print(identity_matrix)
print()

d = np.ones((5, 5), dtype="int32")
print(d)
print()

d[1:4, 1:4] = np.zeros(3)
print(d)
print()

d[2, 2] = 9
print(d)
print()

e = np.array([1, 2, 3, 4])
print(e)
print(e + 2)
print()

f = np.array([5, 6, 7, 8])
print(f)
print(f * 4)
print()

print(e + f)
print(f ** e)
print(np.sin(e * f))
print()

print("REAL matrix multiplication:\n")

g = np.array([[1, 2, 3, 4], [2, 4, 1, 3]])
print(g)
print(np.min(g))
print()

h = np.array([[5, 4, 5], [2, 3, 2], [1, 1, 1], [0, 0, 0]])
print(h)
print(np.max(h))
print()

print(np.matmul(g, h))
print()

i = np.array([[2, 4], [3, 5]])
print(i)
print(np.linalg.det(i))
print()

file_data = np.genfromtxt(r"/home/kamil/Desktop/Array.txt", delimiter=" ")
print(file_data)
file_data = file_data.astype("int32")
print(file_data)
print()

print(file_data >= 10)
print(file_data[file_data >= 10])
print(np.any(file_data < 1))
print(np.all(file_data > 0))
print((file_data >= 3) & (file_data <= 5))
print(~((file_data == 3) | (file_data != 5)))
print()

j = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9])
print(j)
print(j[[2, 4, 5, 7]])
print()

k = np.array([[1, 2, 3, 4, 5], [5, 4, 3, 2, 1], [0, 0, 1, 0, 0]])
print(k)
print(k[[0, 0, 0, 1, 2], [1, 2, 3, 2, 1]])
print(k[[0, 2], 1:4])
print()
