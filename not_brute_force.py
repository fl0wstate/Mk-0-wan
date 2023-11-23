import random

def gcd(a, b): # this will help us find the non trivial values
    while b:
        a, b = b, a % b
    return a

def pollards_rho(n): # allows us to get the factors of the given number 
    # with the concept of tortoise and hare (floyd's algorithm)
    if n % 2 == 0:
        return 2
    
    x = random.randint(1, n-1) # tortoise
    y = x # hare
    c = random.randint(1, n-1)
    d = 1
    
    f = lambda x: (x**2 + c) % n
    
    while d == 1:
        x = f(x)
        y = f(f(y))
        d = gcd(abs(x - y), n)
    
    return d

def factorize(n):
    factors = []
    
    while n > 1:
        factor = pollards_rho(n)
        factors.append(factor)
        n //= factor

        
    return factors
def is_prime(n=0):
    i = 2
    while (i < n):
        if (n % i == 0):
          break
        i += 1
    
    if (i == n):
        print("{} is prime".format(i))
    else:
        print("{} is not prime".format(n))

# Example usage
number_to_factorize = 77
is_prime(number_to_factorize)
result = factorize(number_to_factorize)
print(f"The prime factors of {number_to_factorize} are: {result}")