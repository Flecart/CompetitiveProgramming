
def is_first_in_sec(first, second):
    is_in_sec = True 
    for char in first:
        if not char in second:
            is_in_sec = False
            break

    return is_in_sec

def get_output(ls):
    ind = ls.index("|")
    return ls[ind + 1:]

# This is just a lot of logic to parse the input
def get_wiring(ls):
    ls = ["".join(sorted(el)) for el in ls]
    d = dict() 
    map_di = dict()
    ind = ls.index("|")
    wiring = ls[:ind]

    # find known ones
    for wire in wiring:
        lenght = len(wire)

        if lenght == 2: 
            num = 1
        elif lenght == 3:
            num = 7
        elif lenght == 4:
            num = 4
        elif lenght == 7:
            num = 8
        else:
            continue
        
        d[wire] = num
        map_di[num] = wire

    assert(1 in map_di)
    assert(4 in map_di)
    assert(7 in map_di)
    assert(8 in map_di)
    # find 6 and 9 and 0
    for wire in wiring:
        if not len(wire) == 6: continue 

        one = map_di[1] 
        four = map_di[4]

        if not is_first_in_sec(one, wire):
            num = 6
        elif is_first_in_sec(four, wire):
            num = 9
        else:
            num = 0
        

        d[wire] = num
        map_di[num] = wire

    assert(9 in map_di)
    assert(6 in map_di)
    assert(0 in map_di)

    # find 3, 5 and 2
    for wire in wiring: 
        if not len(wire) == 5: continue 

        nine = map_di[9]
        six = map_di[6]

        in_six = is_first_in_sec(wire, six)
        in_nine = is_first_in_sec(wire, nine)
        if in_six and in_nine:
            num = 5
        elif not in_six and in_nine:
            num = 3
        else: 
            num = 2
        one = map_di[1]
        d[wire] = num
        map_di[num] = wire

    assert(5 in map_di)
    assert(3 in map_di)
    assert(2 in map_di)

    return d 

# First i get a dictionary parsing the input
# then i use that to know the number in output!
def second_star():
    ans = 0
    
    while True:
        inp = input() 
        if inp == "0":
            break 

        inp = inp.split(" ")
        wiring = get_wiring(inp)
        output = get_output(inp)
        output = ["".join(sorted(sort)) for sort in output ]
        curr_num = ""
        for number in output:
            curr_num += str(wiring[number])

        ans += int(curr_num)
    
    print(ans)

# Just a naive count
def first_star():
    ans = 0
    
    while True:
        str = input() 
        if str == "0":
            break 

        str = str.split(" ")
        str = get_output(str)
        for out in str:
            lenght = len(out)
            if lenght == 2 or lenght == 3 or lenght == 4 or lenght == 7:
                ans += 1

    print(ans)