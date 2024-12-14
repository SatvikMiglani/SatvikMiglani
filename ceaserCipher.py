alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z','a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

def encryption(original_text, shift_amount):
    encryted_text = list()
    original_text = list(original_text.lower())
    for letter in original_text:
        i = 0
        if letter == " ":
            encryted_text += letter
        else:
            while i < 26:
                if letter == alphabet[i]:
                    encryted_text.append(alphabet[i+shift_amount])
                i += 1

    for letter in encryted_text:
        print(letter, end="")
    print()

action = input("Enter encode for encryption and decode for decryption: ")
shift = int(input("Enter the shift amount: "))
text = input("Enter the text: ")

if action == "encode":
    encryption(text, shift)
elif action == "decode":
    encryption(text, -shift)