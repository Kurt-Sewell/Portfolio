def top_character():
    temp = {}
    out = []
    global inp
    inp = """Proud and immortal Bright shines your name Oklahoma State We herald your fame Ever you'll find us Loyal and true To our Alma Mater (O-S-U)."""

    for i in inp:
        if (i in temp):
            temp[i] += 1
        else:
            temp[i] = 1

    sort = sorted(temp.items(), key=lambda i: i[1], reverse=True)

    top = sort[:5]
    print(type(top))

    out = list(top)

    print(out)


top_character()
