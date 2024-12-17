import sys

MENU = {
    "espresso": {
        "ingredients": {"water": 50, "milk": 0, "coffee": 18},
        "cost": 1.5,
    },
    "latte": {
        "ingredients": {"water": 200, "milk": 150, "coffee": 24},
        "cost": 2.5,
    },
    "cappuccino": {
        "ingredients": {"water": 250, "milk": 100, "coffee": 24},
        "cost": 3.0,
    },
}

waterPresent = 0
milkPresent = 0
coffeePresent = 0
moneyPresent = 0

# Calculate total money entered
def money(dollars, quarters, dimes, nickels, pennies):
    return (dollars * 1) + (quarters * 0.25) + (dimes * 0.1) + (nickels * 0.05) + (pennies * 0.01)

# Check if the money is enough
def money_check(cost):
    global moneyPresent
    dollars = int(input("Enter the number of dollars you entered: "))
    quarters = int(input("Enter the number of quarters you entered: "))
    dimes = int(input("Enter the number of dimes you entered: "))
    nickels = int(input("Enter the number of nickels you entered: "))
    pennies = int(input("Enter the number of pennies you entered: "))

    money_given = money(dollars, quarters, dimes, nickels, pennies)
    if money_given >= cost:
        print(f"Money entered: ${money_given:.2f}")
        print(f"Cost of the drink: ${cost:.2f}")
        if money_given > cost:
            print(f"Your change: ${money_given - cost:.2f}")
        moneyPresent += cost
        return True
    else:
        print(f"Money entered: ${money_given:.2f}")
        print("Sorry, not enough money. Money refunded.")
        return False

# Print resources report
def print_report():
    print("Current resources:")
    print(f"Water: {waterPresent}ml")
    print(f"Milk: {milkPresent}ml")
    print(f"Coffee: {coffeePresent}g")
    print(f"Money: ${moneyPresent:.2f}")

# Add resources to the machine
def add_resources():
    global waterPresent, milkPresent, coffeePresent
    print("Add resources:")
    waterPresent += int(input("Enter the amount of water (ml): "))
    milkPresent += int(input("Enter the amount of milk (ml): "))
    coffeePresent += int(input("Enter the amount of coffee (g): "))

# Check if resources are sufficient
def resource_check(drink):
    global waterPresent, milkPresent, coffeePresent

    ingredients = MENU[drink]["ingredients"]
    if waterPresent < ingredients["water"]:
        print("Not enough water.")
        return False
    if milkPresent < ingredients["milk"]:
        print("Not enough milk.")
        return False
    if coffeePresent < ingredients["coffee"]:
        print("Not enough coffee.")
        return False

    # Deduct the ingredients if resources are sufficient
    waterPresent -= ingredients["water"]
    milkPresent -= ingredients["milk"]
    coffeePresent -= ingredients["coffee"]
    return True

# Exit function
def exit_check(value):
    if value.lower() == "off":
        print("Turning off the machine. Goodbye!")
        sys.exit(0)

# Report check
def report_check(value):
    if value.lower() == "report":
        print_report()

# Main loop
print("Welcome to the Coffee Machine!")
add_resources()

while True:
    drinkChoice = input("What would you like? (espresso/latte/cappuccino): ").lower()
    exit_check(drinkChoice)
    report_check(drinkChoice)

    if drinkChoice not in MENU:
        print("Invalid choice. Please try again.")
        continue

    if resource_check(drinkChoice):
        if money_check(MENU[drinkChoice]["cost"]):
            print(f"Here’s your {drinkChoice}. Enjoy!")
        else:
            print("Transaction cancelled. Please try again.")
    else:
        refill = input("Would you like to refill resources?, press 'y' for yes and 'n' for no")
        if refill == 'y':
            add_resources()
        elif refill == 'n':
            print("Insufficient resources, try again")
