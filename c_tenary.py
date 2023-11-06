string = "Best School Cand you cfound me"
C = ['c', 'C']
def tenary_op(C = [], string = ""):
    return int(string.find((C[0], C[1])[C[1] in string]))

while tenary_op(C, string) != -1:
    # do some slicing
    string = string[:tenary_op(C, string)] + string[tenary_op(C, string) + 1:]

print(string)

def c_tuple_tenary(tuple_1=(), tuple_2=()):
    if len(tuple_2) == 1:
        tuple_3 = (tuple_1[0]+tuple_2[0], tuple_1[1]+0)
        print(tuple_3)
    elif len(tuple_2) > 1:
        tuple_3 = (tuple_1[0]+tuple_2[0], tuple_1[1]+tuple_2[1])
        print(tuple_3)
t_1 = 12 , 12
t_2 = 12 , 12
t_3 = (12,)
t_4 = (12, 12, 12)
c_tuple_tenary(t_1, t_4)


# make a function which returns a tuple
def multiple_returns(sentence):
    if len(sentence) == 0:
        return None
    else:
        return int(len(sentence)), sentence[0]
    
x , y = multiple_returns("Hello, world")
print("Length: {:d} - First character: {}".format(x, y))