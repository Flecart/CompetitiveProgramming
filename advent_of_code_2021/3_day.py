
def first_star(): 
    LEN = 12
    
    inp = int(input(), 2) 
    count = 1
    frequencies = dict() 
    while inp != 0:
        index = 0
        while inp > 0:
            if inp % 2 == 1:
                if not index in frequencies:
                    frequencies[index] = 0
                frequencies[index] += 1
            inp = inp // 2
            index += 1
    
        inp = int(input(), 2) 
        count += 1
    
    gamma = 0
    for i in range(LEN): 
        if frequencies[i] > (count - frequencies[i]):
            gamma += 2**i 
    
    all_ones = 2**LEN - 1 
    epsilon = all_ones - gamma 
    
    print(gamma * epsilon)

def second_star():
    def count_bit(lists, index):
        count = len(lists)
        bit_count = 0
        for i in range(count):
            if (lists[i][index] == "1"):
                bit_count += 1

        return bit_count 
    
    def filter(lists, index, value):
        new_list = []
        count = len(lists)
        for i in range(count):
            if (lists[i][index] == value):
                new_list.append(lists[i])

        return new_list 

    LEN = 12
    inp = input() 
    big_list = [] 
    while inp != "0":
        big_list.append(inp)
        inp = input()
    lists = list(big_list)
    for index in range(LEN):
        count = len(lists)
        bit_count = count_bit(lists, index) 
        to_filter = "1" if bit_count >= count - bit_count else "0"
        lists = filter(lists, index, to_filter) 
        if (len(lists) == 1):
            break 

    print(lists) 
    some_rate = int(lists[0], 2)
    lists = list(big_list)
    for index in range(LEN):
        count = len(lists)
        bit_count = count_bit(lists, index) 
        to_filter = "1" if bit_count < count - bit_count else "0"
        lists = filter(lists, index, to_filter) 
        if (len(lists) == 1):
            break  
    print(lists)
    second_rte = int(lists[0], 2) 

    print(some_rate * second_rte)

second_star() 
