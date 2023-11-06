sentence = "At school learn coding"
letter_1, letter_2 = sentence[0], sentence[1]

print(letter_1, letter_2)
# finding the max is killing me have no idea of how to implement it
my_list = [1, 90, 2, 13, 34, 5, -13, 3]
my_list_2 = [1, 90, 2, 13, 34, 5, -13, 31, 190, 200, 13, 34, 5, -13, 3]
my_list = [1, 90, 2, 13, 34, 5, -13, 3]
def max_l(my_list=[]):
    if len(my_list) == 0:
        return None
    max_val = my_list[0]
    for i in my_list[1:]:
        if (i > max_val):
            max_val = i
    return max_val

max_val = max_l(my_list_2)
print(max_val)
#max_val = (my_list[:1], my_list[0])[my_list[:1]  my_list[0]]
#rint(max_val)

#for i, indx in enumerate(my_list):
 #   print(i, indx)

def divisible_by_2(my_list=[]):
    true_or_false_list = []
    for i in range(0, len(my_list)):
        if (my_list[i] % 2 == 0):
            true_or_false_list.append(True)
        else:
            true_or_false_list.append(False)
    return true_or_false_list

my_list = [0, 1, 2, 3, 4, 5, 6]
list_result = divisible_by_2(my_list)

i = 0
while i < len(list_result):
    print("{:d} {:s} divisible by 2".format(my_list[i], "is" if list_result[i] else "is not"))
    i += 1

def delete_at(my_list=[], idx=0):
    if 0 > idx or idx > len(my_list)-1:
        return my_list
    my_list = my_list[:idx] + my_list[idx+1:]
    return my_list

new_list = delete_at(my_list_2, 1)
print(new_list)
#!/usr/bin/python3
a = 89
b = 10
a, b = b, a
print("a={:d} - b={:d}".format(a, b))