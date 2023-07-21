def fam(age):
    all = {
            "Dad" : range(40, 100),
            "Mom" : range(50),
            "Siblings": range(1, 18)
        }
    for member, ages in all.items():
        if age in ages:
            return member

    return "Uknown"

print(fam(40))
#simple way to play around with dicts in py.
#separate also the dict into two which will include keys and value
#use a for loop to keep track of all the data keys and value
#now compare the values of each key to that passed argument
#range will begin from param1 < param2 and check where the value falls
#range take this nature of first come first served
