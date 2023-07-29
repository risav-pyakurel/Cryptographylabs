

#************* CAESER CIPHER PROGRAM IN PYTHON****************

letters = 'abcdefghijklmnopqrstuvwxyz'
number_letters = len(letters)

def encrypt(plaintext, key):
    ciphertext = ''
    for letter in  plaintext:
        letter = letter.lower()
        if not letter == ' ' :
            index = letters.find(letter)
            if index == -1:
                ciphertext += letter
            else:
                new_index = index+ key
                if new_index >=number_letters:
                    new_index -=number_letters
                ciphertext += letters[new_index]
    return ciphertext

def decrypt(ciphertext, key):
    plaintext = ''
    for letter in  ciphertext:
        letter = letter.lower()
        if not letter == ' ' :
            index = letters.find(letter)
            if index == -1:
                plaintext += letter
            else:
                new_index = index - key
                if new_index <0:
                    new_index +=number_letters
                plaintext += letters[new_index]
    return plaintext




print()
print('......DEMONSTRATING CAESAR CIPHER PROGRAM.......')
print()

print('Do you want to encrypt or decrypt? ')
your_input= input('e/d: ').lower()

print()
if your_input=='e':
    print('ENCRYPTION MODE SELECTED')
    print()
    key = int(input('enter the (1 through 26): '))
    text = input('Enter the text to encrypt:')
    ciphertext = encrypt(text,key)
    print(f'CIPHERTEXT: {ciphertext}')

elif your_input == 'd':
    print('DECRYPTION MODE SELECTED')
    print()
    key = int(input('enter the (1 through 26): '))
    text = input('Enter the text to decrypt:')
    plaintext = decrypt(text, key)
    print(f'PLAINTEXT: {plaintext}')
