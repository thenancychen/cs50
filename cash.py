import cs50


def main():

    cents = get_cents()

    # calculate amount of cents needed
    quarters = calculate_quarters(cents)
    cents = cents - (quarters * 25)
    dimes = calculate_dimes(cents)
    cents = cents - (dimes * 10)
    nickels = calculate_nickels(cents)
    cents = cents - (nickels * 5)
    pennies = calculate_pennies(cents)
    cents = cents - pennies

    sum_cents = int(quarters + dimes + nickels + pennies)
    print(sum_cents)


# asks user for user input
def get_cents():

    cents = -1
    while cents < 0: 
        cents = cs50.get_float("How many cents are you owed? ")
        cents *= 100
    return cents


# calculates how many quarters
def calculate_quarters(cents):
    return cents // 25 


# calculates how many dimes
def calculate_dimes(cents):
    return cents // 10 


# calculates how many nickels
def calculate_nickels(cents):
    return cents // 5 


# calculate how many pennies
def calculate_pennies(cents):
    return cents 


main()

