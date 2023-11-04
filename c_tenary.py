string = "Best School\nCan you c me"
C = ['c', 'C']
def tenary_op(C = [], string = ""):
    return int(string.find((C[0], C[1])[C[1] in string]))

while tenary_op(C, string) != -1:
    # do some slicing
    string = string[:tenary_op(C, string)] + string[tenary_op(C, string) + 1:]

print(string)
