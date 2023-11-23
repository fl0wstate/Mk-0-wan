from math import sqrt, floor, isqrt
from time import time
start = time()
n = 77
# to write it mathimatically would be like this
# guess a number and we need to start from the half of the original number
# this will be our base start value
# add 1 to find the insqrt
# 
a = floor(sqrt(n)) + 1

while True:
    b2 = pow(a, 2) - n # fermets theory  x^2 + y^2 = z^2 this will help us find y == b2
    # keep checking if the number is a perfect square if so then we found y == b2
    if isqrt(b2):
        b = sqrt(b2) # we found the other number 
        break
    a = a + 1 # well if the above fails keep on adding the value of a by 1

# N = a^2 - b^2 = (a + b) * (a - b) --> see how i got the value of p and q
p = a + b
q = a - b
# getting the floor to avoid decimal places
print (floor(p))
print (floor(q))

print(n == floor(p * q))
end = time()
# getting time in macro seconds
elapsed_time = (end - start)
print(elapsed_time)

