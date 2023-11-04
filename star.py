x = int(input("Enter start size: "))
for space in range(0, x):
    for spaces in range(0, x-space-1):
        print(end=" ")
    for start in range(0, space+1):
        print("*", end=" ")
    print(("\n", "")[start != x])
for space in range(x, 0, -1):
    for spaces in range(0, x-space+1):
        print(end=" ")
    for start in range(space-1, 0, -1):
        print("*", end=" ")
    print(("\n", "")[start > 0])