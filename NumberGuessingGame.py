import random

logo = r"""
  / _ \_   _  ___  ___ ___  /__   \ |__   ___    /\ \ \_   _ _ __ ___ | |__   ___ _ __ 
 / /_\/ | | |/ _ \/ __/ __|   / /\/ '_ \ / _ \  /  \/ / | | | '_ ` _ \| '_ \ / _ \ '__|
/ /_\\| |_| |  __/\__ \__ \  / /  | | | |  __/ / /\  /| |_| | | | | | | |_) |  __/ |   
\____/ \__,_|\___||___/___/  \/   |_| |_|\___| \_\ \/  \__,_|_| |_| |_|_.__/ \___|_| 
"""

number = random.randint(1,100)

def easy():
    print("Number of lives: 10")
    lives = 10
    game_over = False

    while game_over is False:
        guess = int(input("Make a guess: "))

        if guess == number:
            print(f"You are right, the number is {number}")
            game_over = True
        elif (abs(number - guess)) <= 5:
            if (number-guess) > 0:
                print("You are very close, think a little bit higher")
            elif (number - guess) < 0:
                print("You are very close, think a little bit lower")
            lives -= 1
            game_over = False
            print(f"Lives left: {lives}")
        elif (abs(number - guess)) <= 10:
            if (number - guess) > 0:
                print("You are close, think higher")
            elif (number - guess) < 0:
                print("You are close, think lower")
            lives -= 1
            game_over = False
            print(f"Lives left: {lives}")
        elif (abs(number - guess)) <= 25:
            if (number - guess) > 0:
                print("Think higher")
            elif (number - guess) < 0:
                print("Think lower")
            lives -= 1
            game_over = False
            print(f"Lives left: {lives}")
        elif (abs(number - guess)) <= 50:
            if (number - guess) > 0:
                print("You are far off, think higher")
            elif (number - guess) < 0:
                print("You are far off, think lower")
            lives -= 1
            game_over = False
            print(f"Lives left: {lives}")
        else:
            if (number - guess) > 0:
                print("You are very far, think a lot higher")
            elif (number - guess) < 0:
                print("You are very far, think a lot lower")
            lives -= 1
            game_over = False
            print(f"Lives left: {lives}")

        if lives == 0:
            print("Lives ended, you lost")
            print(f"The number was {number}")
            game_over = True
        elif game_over is True:
            print("You won")
def hard():
    print("Number of lives: 5")
    lives = 5
    game_over = False

    while game_over is False:
        guess = int(input("Make a guess: "))

        if guess == number:
            print(f"You are right, the number is {number}")
            game_over = True
        elif (number-guess) > 0:
            print("Think higher")
            game_over = False
            lives -= 1
            print(f"Lives left: {lives}")
        elif (number-guess) < 0:
            print("Think lower")
            game_over = False
            lives -= 1
            print(f"Lives left: {lives}")

        if lives == 0:
            print("Lives ended, you lost")
            print(f"The number was {number}")
            game_over = True
        elif game_over is True:
            print("You won")

print(logo)
print("Welcome to number guessing game")

choice = input("Enter easy for easier level or enter hard for harder level: ").lower()

if choice == "easy":
    easy()
elif choice == "hard":
    hard()
else:
    print("Wrong input")

