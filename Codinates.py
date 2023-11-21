class Square:
    """
    Just a simple demonstration of and empty class
    """
    def __init__(self, size=0, position=(0, 0)):
        """
        Initializes the instances variables, taking in 
        none type size param.
        And making a private attribute out of it.

        Args:
            size (unkwon): Param that takes in a value which is later
            on transformed into a private variable
            position (tuple): Param that holds a tuple value that's going to
            act as our own position for printing the spaces.
        """
        if isinstance((size, position[0], position[1]), int):
            self.__size = size
        else:
            raise TypeError("size must be an integer")
        if size < 0:
            raise ValueError("size must be >= 0")
        
        
    def area(self):
        """
        Simple exponent calculation for a given value

        Return:
            The square value of a given arguments
        """
        return self.__size ** 2
    @property
    def size(self):
        """
        Getter function which will be used to retrive the private size value

        Return:
            The private attribute is returned
        """
        return self.__size
    @size.setter
    def size(self, value):
        """
        Sets a new value to the private value, it mutates the private value

        Args:
            value (int): the new value for the private size
        
        """
        self.__size = value
    def my_print(self):
        x = self.__size
        y = x**2
        i = 1
        for _ in range(y):
           print("#" * x)
    @property
    def position(self):
        return self.__position
    @position.setter
    def position(self, value):
        self.__position = value
    