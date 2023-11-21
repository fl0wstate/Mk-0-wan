class Square:
    """
    Just a simple demonstration of and empty class
    """
    def __init__(self, size=None):
        """
        Initializes the instances variables, taking in 
        none type size param.
        And making a private attribute out of it.

        Args:
            size (unkwon): Param that takes in a value which is later
            on transformed into a private variable
        """
        self.__size = size


my_square = Square(3)
print(my_square)
try:
    print(my_square.size)
except Exception as e:
    print(e)

try:
    print(my_square.__size)
except Exception as e:
    print(e)
print(my_square.__dict__)
print(my_square.__init__.__doc__)