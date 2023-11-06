def c_tenary(C = (), c = ""):
   return int(c.find((C[0], C[1])[C[1] in c]))

c = "Best SChool"
C = ('c', 'C')
while c_tenary(C,c) != -1:
    c = c[:c_tenary(C,c)] + c[c_tenary(C,c) + 1: ]

print(c)