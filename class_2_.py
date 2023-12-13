# working with classes in python
class Cat:
    ___counter = 0
    def __init__(self):
        """Nothing happened -> Zoro
        """
        type(self).___counter += 1

    @staticmethod
    def RobotInstance():
        return Cat.___counter
    
    def __del__(self):
        print("Deleting instances")
        self.___counter -= 1

    @property
    def counter(self):
        return self.___counter

if __name__ == "__main__":
    print(Cat.RobotInstance())
    x = Cat()
    print(x.RobotInstance())
    y = Cat()
    #print(eval(x))
    print(x.RobotInstance())
    z = Cat()
    k = Cat()
    print(Cat.counter)

animal = Cat()
print(animal.__dict__)
