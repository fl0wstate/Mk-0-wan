string = "Best School\nCan you c me"
C = ['c', 'C']
def tenary_op(C = [], str = ""):
    return int(str.find((C[0], C[1])[C[1] in str]))

while tenary_op(C, string) != -1:
    # do some slicing
    string = string[:tenary_op(C, string)] + string[tenary_op(C, string) + 1:]

print(string)
