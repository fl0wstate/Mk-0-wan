from blessed import Terminal as term


def spaceout(value,length,space=' '):
    if (len(value) % 2) != 0:
        b = 1
    else:
        b = 0
    return space * ((length - len(value)) // 2) + str(value) + space * ((length - len(value) + b) // 2)

def menuloop(title, options):
    key = term.inkey(0)
    default = term.inkey(0)
    pos = 0
    while key.code != 361:
        if key.code == 258:
            pos += 1
            key = default
        elif key.code == 259:
            pos -= 1
            key = default
        elif key.code == 343 or key == ' ':
            cmd = list(options.values())[pos]
            cmd()
        if key.code == 361:
            break
        pos = pos % len(options.keys())
        keys = list(options.keys())
        vals = list(options.values())
        print(term.clear)
        long = len(max(options.keys(), key = len))
        if len(title) > long:
            long = len(title)
        long += 2

        print("\n" * ((term.height // 2) - (3 + len(options.keys()))))

        print(spaceout(f"╭{        spaceout(term.bold + title + term.normal,long + len(term.bold) + len(term.normal),'─')          }╮",term.width + len(term.bold) + len(term.normal)))

        # print(spaceout(f"│{ + spaceout(title,long) + term.normal}│",term.width + len(term.bold) + len(term.normal)))

        for i in range(len(options.keys())):
            if pos == i:
                col = term.black_on_white + term.bold
            else:
                col = term.normal
            print(spaceout(f"│{col + spaceout(keys[i],long) + term.normal}│",term.width + len(col) + len(term.normal)))
        print(spaceout(f"╰{'─' * long}╯",term.width))
        key = term.inkey(1)
        continue

menuloop("Main Menu",{"Start Test":starttest,"Settings":settings, "Exit":exit})
