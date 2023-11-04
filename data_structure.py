"""
mylist = []
mylist = eval(input("enter list: "))
print(len(mylist))
x = int(len(mylist) / 2)
mylist = mylist[len(mylist):] + mylist[:x]
print(mylist)
"""
# create list on the fly while on the terminal
# things to keep in mind
# you will need to make a list while enclosing each
# of the members with double quotes or single for strings
# create a new list from an iterable that satisfies a given condition
# [output_expression, input_sequence, predicate_part]
a = 0
single_line_list = [a **3 for a in range(20) if a % 2 == 0]
print(single_line_list)
# again you can have multiple loops if conditions all in one line even nested loops
a = 0
nested_list_in_one_line = [a for a in range(7) for k in range(a) ]
print(nested_list_in_one_line)

b = 0
default = 6
def c_tenary(a, b):
     return (a, b)[a == None]

loops= (input("Enter the no. of loops you want: "))
art = input("Enter the type of art you want to be displayed[!!pro tip type it 4 times!!]: ")
if (loops == "" and art == ""): 
    loops = None
    art = None
else:
    loops = int(loops)

for b in range(c_tenary(loops, default)):
    j = 0
    for j in range(b):
        #if (b % 2 == 0 and j % 2 == 0): getopt. builtin function to print only numbers div by 2
            print(f"[{j}]", end=' ')
    for c in range(0, c_tenary(loops, default)-1-b):
        if (art == None):
            print(end="----")
        elif art == None and j > 9:
             print(end="-----")
        else:
            print(end=art)  # 1 _ mean an element printed [ digit ]
    if b == 1:
         print (f" {b} loop")
    elif b > 9:
         print(f"{b} loops")
    else:
         print(f" {b} loops")

# tuples just list but with alot strictness
# simple to use and less memory is used
# just use parenthesis around a comma separated elements or data types
mytuple = (1,2,45,6,7,5)
# accessing tuple elements
for i in range(0, len(mytuple)):
    print(mytuple[i])
# once created you cannot modify each member