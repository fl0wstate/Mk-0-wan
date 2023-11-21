# Hey welcome to playing with py lets build a python class
class Robot:
    Robot_population = 1
    def __init__(self, name):
        self.name = name
        self._prot = "Hi i am a protected instance variable"
        self.__priv = "Deng! it wish you could see me from the outside but you can't sike"
        if self.name:
            self.pop = len(name) // 2
        else:
            self.pop = 10
        print("Just initialized a Robot, booting up...")
    def say_hi(self):
        if self.name:
            print("Hello I am {} ready at your service".format(self.name))
        else:
            print("I am a rog Robot call me RC096")
    def population(self):
        print("Current Robot population is {}".format(__class__.Robot_population))
    def increase_Robot(self):
        for i in range(0, self.pop):
            __class__.Robot_population += i
        if (self.name == ""):
            print("I have produced a colony of ROG robots current population is {}".format(__class__.Robot_population))
        else:
            print("{} robots have been produced".format(__class__.Robot_population))
    
x = Robot("Jarvis")
y = Robot("")
print(x.__dict__)
print(y.__dict__)
print(Robot.__dict__)
#y.say_hi()
#y.increase_Robot()
#y.population()
#x.say_hi()
#x.population()
#x.increase_Robot()
#print(y.__dict__)
#print(x.__dict__)
#print(x._prot)
#help(x)
#x.__priv