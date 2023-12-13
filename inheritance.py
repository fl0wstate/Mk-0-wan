# how multiple inheritance really work
class Grandpa(): # Base Class
    def __init__(self):
        print("I am a Farmer and i never give up")

class Father(Grandpa):
    def __init__(self):
        print("I am a bussiness man")
        super(Father, self).__init__() # same as super().__init__()

class Brother(Grandpa):
    def __init__(self):
        print("I am a Programmer")
        super().__init__() # inherits the init function from the granpa and runs it
        # you will later on learn that there is no repettion of the same Grandpa initialization
        # this is due to the power of MRO (Method Resolution Order)
        # super() follows the list returned by the MRO which is able to resolve how to get to the base class
        # super() traverses through the whole diamond structure and decides which superclass/Parent to call(According to MRO)
        # MRO a simple sequece that the super() follows, you can view it using subclass.mro() or 
        # subclass.__mro__ +> returns a tuple of method resolution used to get to the base class

class Child(Brother, Father):
    def __init__(self):
        print("I love doing hard things")
        super(Child, self).__init__()

child = Child()
print(Child.mro()) # returns a list of all the superclass call from the subclass upto the base class
print("--------------MRO--------------------")
print(Child.__mro__)
# the algorithm used for MRO is called C3 Linearization invented by Samuele Pedroni
# He wanted to resolve the inconsitency DLR algorithm had. DLR(Depth first, left to right order)

"""Cool Doc String

Alright, let's break it down in simpler terms!

Imagine you have a family:

Grandpa: A farmer who never gives up.
Father: A businessman who has Grandpa's qualities.
Brother: A programmer with Grandpa's qualities.
Child: Loves doing hard things, and inherits from both Brother and Father.
Here's what happens when we create a Child:

Child's Init:

Prints "I love doing hard things."
Brother's Init (Grandpa's Init Called Automatically):

Prints "I am a Programmer."
Calls super().__init__(), which means it goes to the next class in the method resolution order (MRO), which is Grandpa.
Prints "I am a Farmer and I never give up."
Father's Init (Grandpa's Init Called Automatically):

Prints "I am a businessman."
Calls super().__init__(), which goes to the next class in the MRO (Grandpa).
Prints "I am a Farmer and I never give up."
So, even though Grandpa's __init__ method is defined only once, it's called twice through the MRO, and it prints the message twice.

The MRO is like a roadmap that tells Python which class to look at next in the inheritance hierarchy. It prevents duplicate calls and ensures a smooth flow from the child to the base class.

And when you print Child.mro() or Child.__mro__, it shows you the sequence of classes that Python checks when resolving methods, from the child class up to the base class. In this case, it would be Child, Brother, Father, and finally Grandpa. The MRO is like a family tree for your classes!
"""