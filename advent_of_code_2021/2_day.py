# NOTE: 
# I assume that the input will always be that of the challenge
# I consciously didn't put error catches in input handling


# I parse the first line and the i loop for the others
# Simple implementation
# The thing to consider maybe is that you have to keep
# track of the variables of deep and horizontal
def first_star():
    first, second = input().split(" ")
    x_dir = 0
    y_dir = 0
    second = int(second) 
    if first == "forward":
        x_dir = second 
    elif first == "down":
        y_dir = second 
    elif first == "up":
        y_dir = -second 
    
    while first != "0" and second != 0:
        first, second = input().split(" ") 
        second = int(second)
        if first == "forward":
            x_dir += second 
        elif first == "down":
            y_dir += second 
        elif first == "up":
            y_dir -= second 
    
    
    print(x_dir * y_dir)

# Just set a aim variable and change it as requested
def second_star():
    first, second = input().split(" ") 
    second = int(second) 
    aim = 0
    x_dir = 0
    y_dir = 0 
    if first == "forward":
        x_dir = second 
    elif first == "down":
        aim = second 
    elif first == "up":
        aim = -second 
    
    while first != "0" and second != 0:
        first, second = input().split(" ") 
        second = int(second) 
        if first == "forward":
            x_dir += second 
            y_dir += aim * second 
        elif first == "down":
            aim += second 
        elif first == "up":
            aim -= second 

    print(x_dir * y_dir)
