polimers = dict()
counts = dict() 

def step():
    global counts 
    current_step = dict() 
    for key in counts:
        if counts[key]<=0:
            continue
        if key in polimers:
            char = polimers[key] 
            first = key[0] + char 
            second = char + key[1] 
            current_step = add_in_dict(current_step, first, counts[key]) 
            current_step = add_in_dict(current_step, second, counts[key]) 
        else:
            current_step = add_in_dict(current_step, key, counts[key]) 
            
        

    
    counts =  current_step


def add_in_dict(dictionary, element, quantity):
    element = element.strip()
    if not element in dictionary:
        dictionary[element] = 0

    dictionary[element] += quantity
    return dictionary 

def get_map():
    global polimers
    with open("input.txt", "r") as f:
        key, value  = f.readline().strip().split(" -> ") 
        
        while key != "0":
            polimers[key] = value 
            key, value = f.readline().strip().split(" -> ")

def first_star(pol):
    # I'm counting everything two times except for the first and last couple
    # Hope they are not significant in this count
    count_dict = dict() 
    count_dict[pol]=1
    for key in counts:
        count_dict = add_in_dict(count_dict, key[1], counts[key])

    print(count_dict)

def main():
    global counts 
    get_map() 
    polimer = input().strip()

    for couple in range(0, len(polimer) - 1):
        cpl = polimer[couple:couple + 2]
        if not cpl in counts:
            counts[cpl] = 0
        counts[cpl] += 1
    print(counts)
    for _ in range(40):
        step() 
        print(counts)

    first_star(polimer[0])


main() 
