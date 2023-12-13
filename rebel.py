class MyInt(type(4)):    
    def __ne__(self, other) -> bool:
        return super().__eq__(other)
    
    def __eq__(self, other) -> bool:
        return super().__ne__(other)

myint = MyInt(3)
print(myint)
print(myint == 3)
print(myint != 3)


# adding a new attribute to an empty class
mynum = 1000
mystr = {'key': 'Hello World!'}
print("{mystr} New-style formatting is {mynum}x more fun!".format(**locals()))
def add(*args) -> int:
    return sum(args)

print(add(1,2,3,44,5))

import sys
print(sys.float_info)



##--------------Matching with regular expression--------------------##
# coding=utf8
# the above tag defines encoding for this document and is for Python 2.x compatibility

import re

regex = r"(\d[1-255])"

test_str = ""

matches = re.finditer(regex, test_str, re.IGNORECASE)

for matchNum, match in enumerate(matches, start=1):
    
    print("Match {matchNum} was found at {start}-{end}: {match}".format(matchNum = matchNum, start = match.start(), end = match.end(), match = match.group()))
    
    for groupNum in range(0, len(match.groups())):
        groupNum = groupNum + 1
        
        print ("Group {groupNum} found at {start}-{end}: {group}".format(groupNum = groupNum, start = match.start(groupNum), end = match.end(groupNum), group = match.group(groupNum)))

# Note: for Python 2.7 compatibility, use ur"" to prefix the regex and u"" to prefix the test string and substitution.
