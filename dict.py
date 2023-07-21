dict = {1:'one', 2:'two', 3:'three'}
for i in dict.values():
    
a = i
print(a)
key = dict.values()
print(list(a) == key)

#question from tweeter
dict = {1:'one', 2:'two', 3:'three'}
ls = [i for i in dict]
key = dict.keys()
print(ls == list(key))

#obtaining  the values of the keys using the for loop
#again we assign a new variable called key which stores only the value of keys in the dict
#since ls variable contains a list of only the first arguments of the dict(keys)
#the == will perform a comparison and return a boolen of true.
