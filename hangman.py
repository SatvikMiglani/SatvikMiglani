import random

words = [
    "apple", "banana", "cherry", "dog", "elephant", "flower", "grape", "house", "island", "jungle",
    "kite", "lemon", "mountain", "notebook", "orange", "pencil", "queen", "river", "sunflower", "tree",
    "umbrella", "village", "waterfall", "xylophone", "yogurt", "zebra", "ant", "butterfly", "cat", "door",
    "engine", "forest", "gold", "honey", "ice", "jewel", "king", "lamp", "mirror", "night",
    "ocean", "pearl", "quilt", "rainbow", "snow", "train", "unicorn", "valley", "whale", "x-ray",
    "year", "zoo", "anchor", "bridge", "cloud", "diamond", "eagle", "fountain", "garden", "harbor",
    "igloo", "journey", "knight", "lighthouse", "magnet", "novel", "owl", "planet", "quasar", "rocket",
    "ship", "tower", "utopia", "voyage", "wizard", "yacht", "zest", "art", "book", "clock",
    "dancer", "energy", "feather", "glacier", "horizon", "instrument", "jigsaw", "kite", "lily", "moon",
    "nectar", "opera", "piano", "quill", "rose", "star", "treasure", "unity", "victory", "whisper"
]

hangman_pics = [r'''
  +---+
  |   |
  O   |
 /|\  |
 / \  |
      |
=========
''', r'''
  +---+
  |   |
  O   |
 /|\  |
 /    |
      |
=========
''', r'''
  +---+
  |   |
  O   |
 /|\  |
      |
      |
=========
''', '''
  +---+
  |   |
  O   |
 /|   |
      |
      |
=========''', '''
  +---+
  |   |
  O   |
  |   |
      |
      |
=========
''', '''
  +---+
  |   |
  O   |
      |
      |
      |
=========
''', '''
  +---+
  |   |
      |
      |
      |
      |
=========
''']

chosen_word = words[random.randint(0,100)]
chosen_word_list = list(chosen_word)

place_holder = str()
for letters in chosen_word:
    place_holder += "_"

print(place_holder)
place_holder_list = list(place_holder)

lives = 6
game_over = False

while game_over is False:
    print("Number of lives left: ",lives)
    guess = input("Make a guess: ").lower()

    i = 0
    while i < len(chosen_word):
        if chosen_word_list[i] == guess:
            place_holder_list[i] = guess
        i = i + 1

    if guess in chosen_word_list:
        lives_decreaser = False
    else:
        lives_decreaser = True

    if lives_decreaser == True:
        lives -= 1

    for letter in place_holder_list:
        print(letter, end="")

    print()

    print(hangman_pics[lives])

    if "_" not in place_holder_list:
        game_over = True
        print("You win")
    elif lives == 0:
        game_over = True
        print("You lose")

print("The word was ", chosen_word)







