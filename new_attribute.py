class MyClass():
    pass

mc = MyClass()


def new_attr(obj, attr, val) -> object:
    if hasattr(obj, "__dict__"):
        obj.__dict__[attr] = val
    else:
        raise TypeError("can't add new attributes")
    return (obj)

try:
    a = "My String"
    new_attr(a, "name", "Bob")
    print(a.name)
except Exception as e:
    print("[{}] {}".format(e.__class__.__name__, e))
#new_attr(new, "ew" , 22)
new_attr(mc, "name", "John")
new_attr(mc, "attr", 32)
print(mc.__dict__["name"])
