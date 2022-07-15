def print_grid():
    global top, mid, bot
    top_border = "---------"
    print(top_border)
    print("| {} {} {} |".format(top[0],top[1], top[2]))  
    print("| {} {} {} |".format(mid[0],mid[1], mid[2]))
    print("| {} {} {} |".format(bot[0],bot[1], bot[2]))
    print(top_border)


toprow_win, midrow_win, botrow_win, leftcol_win, midcol_win, rightcol_win, ldialonal, rdialonal = None, None, None, None, None, None, None, None
def possible_combinations():
    global toprow_win, midrow_win, botrow_win, leftcol_win, midcol_win, rightcol_win, ldialonal, rdialonal
    if top[0] == top[1] == top[2]:  
        toprow_win = True
    else:
        toprow_win = False
    if mid[0] == mid[1] == mid[2]:  
        midrow_win = True
    else:
        midrow_win = False
    if bot[0] == bot[1] == bot[2]:  
        botrow_win = True
    else:
        botrow_win = False

    
    if top[0] == mid[0] == bot[0]:  
        leftcol_win = True
    else:
        leftcol_win = False
    if top[1] == mid[1] == bot[1]:  
        midcol_win = True
    else:
        midcol_win = False
    if top[2] == mid[2] == bot[2]:  
        rightcol_win = True
    else:
        rightcol_win = False

    if top[0] == mid[1] == bot[2]:  
        ldialonal = True
    else:
        ldialonal = False
    if top[2] == mid[1] == bot[0]:  
        rdialonal = True
    else:
        rdialonal = False


def user_move():
    row, column = input("Enter the coordinates:").split()
    global start, current_field
    try:
        column = int(column)
        row = int(row)
        column -= 1
        row -= 1
        if current_field[row][column] == "X":
            pass
        if current_field[row][column] == "O":
            pass
    except ValueError:
        print("You should enter numbers!")
        user_move()
    except IndexError:
        print("Coordinates should be from 1 to 3!")
        user_move()
    else:
        if current_field[row][column] == "X" or current_field[row][column] == "O":
            print("This cell is occupied! Choose another one!")
            user_move()
        else:
            current_field[row][column] = "X"  
            print(current_field)
            print_grid()


start = input("Enter cells:\n")

if len(start) == 9:
    start = list(start)
    current_field = [start[0:3], start[3:6], start[6:9]]
    top = current_field[0]
    mid = current_field[1]
    bot = current_field[2]

    print_grid()
    user_move()


    x = start.count("X")
    o = start.count("O")
    possible_combinations()  
    status = [toprow_win, midrow_win, botrow_win, leftcol_win, midcol_win, rightcol_win, ldialonal, rdialonal]

    if abs(x-o) > 1:  
        print("Impossible")  
        exit()


    if status.count(True) > 1:  
        print("Impossible")
        exit()

    if toprow_win:
            if top[0] == "O":
                print("O wins")
            else:
                print("X wins")
    elif midrow_win:
        if mid[0] == "O":
            print("O wins")
        else:
            print("X wins")
    elif botrow_win:
        if bot[0] == "O":
            print("O wins")
        else:
            print("X wins")

    elif leftcol_win:
        if top[0] == "O":
            print("O wins")
        else:
            print("X wins")
    elif midcol_win:
        if top[1] == "O":
            print("O wins")
        else:
            print("X wins")
    elif rightcol_win:
        if top[2] == "O":
            print("O wins")
        else:
            print("X wins")

    elif ldialonal or rdialonal:
        if mid[1] == "O":
            print("O wins")
        else:
            print("X wins")
    else:
        if x + o < 9:
            print("Game not finished")
        else:
            print("Draw")

else:
    print("INCORRECT INPUT")
