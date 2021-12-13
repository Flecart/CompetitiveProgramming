class Table():
    def __init__(self, x=2000, y=2000, table=None):
        self.x = x
        self.y = y
        self.table = [] 
        for _ in range(self.x):
            row = ["."] * self.y 
            self.table.append(row)
        
    def add_point(self, x, y):
        self.table[y][x] = "#"

    def check_line(self, table, x = 0):
        all_dot = True 
        for j in range(table.y):

            if table.table[x][j] == "#": all_dot = False 
        return all_dot 

    def check_col(self, table, y = 0):
        all_dot = True 
        for i in range(table.x):
            if table.table[i][y] == "#": all_dot = False 
                
        return all_dot

    def sanitize(self):
        while self.check_line(self, self.x - 1):
            self.table = self.table[:-1]
            self.x -= 1
        
        while self.check_col(self, self.y - 1):
            for x in range(self.x):
                self.table[x] = self.table[x][:-1]
            self.y -= 1

    def fold(self, x=-1, y=-1):
        new_table = Table(self.x, self.y) 

        if x != -1:
            print("folding on y")
            for i in range(self.x):
                for j in range(self.y):
                    if  new_table.table[abs(i - x)][j] == ".": 
                        new_table.table[abs(i - x)][j] = self.table[i][j] 
        elif y != -1:
            for i in range(self.x):
                for j in range(self.y):
                    if new_table.table[i][abs(j - y)] == ".":
                        new_table.table[i][abs(j - y)] = self.table[i][j] 

        while (self.check_line(new_table)):
            new_table.table = new_table.table[1:]
            new_table.x -= 1

        while (self.check_col(new_table)):
            for row in range(new_table.x):
                new_table.table[row] = new_table.table[row][1:]
            new_table.y -= 1
        new_table.sanitize()
        # new_table.table = new_table.table[::-1]
        return new_table;   

    def get_answer(self):
        sum = 0
        for i in range(self.y):
            for j in range(self.x):
                if self.table[j][i] == "#":
                    sum += 1

        return sum

    def print_table(self):
        for i in range(self.x):
            print("".join(self.table[i]))


def create_table():
    table = Table(2000, 2000) # only for the test 
    with open("input.txt", "r") as f:
        x, y = [int(tmp) for tmp in f.readline().split(",")] 
        while x != -1:
            table.add_point(x, y) 
            x, y = [int(tmp) for tmp in f.readline().split(",")] 
    table.sanitize()
    return table


def main():
    table = create_table()
    # Don 't know exactly what, but this part is bugged
    with open("folds.txt", "r") as f:
        char, value = f.readline().split("=")
        while char != "0":
            if char == "y":
                table = table.fold(int(value) , -1)
            elif char == "x":
                table = table.fold(-1, int(value))
            table.print_table()
            print(table.get_answer())
            char, value = f.readline().split("=")

main()
