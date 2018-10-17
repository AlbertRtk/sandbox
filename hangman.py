''' Hangman game '''

import random


''' returns string where uncovered letteres are reprezented by '_'
    psw - password to hide, lts - list of uncovered letters '''
def covered(psw, lts):
    prt = ''  # covered password
    c = 0     # number of covered letters
    for l in psw:
        if l in lts:
            prt = prt + l + ' '
        else:
            prt = prt + '_ '
            c += 1
    return prt, c

# dictionary with passwords
words = {'Car': ['Mercedes', 'Volkswagen', 'Fiat', 'Ford', 'BMW'],
         'Food': ['Cheesburger', 'Pizza', 'Apple', 'Pasta'],
         'Animal': ['Dog', 'Spider', 'Snake', 'Lizard'],
         'Country': ['Poland', 'Croatia', 'Germany', 'Russia'],
        }

# number of lifes
life = 10

# choose cathegory
i = random.randint(0, len(words)-1)
cat = list(words.keys())[i]

# choose password from cathegory
i = random.randint(0, len(words[cat])-1)
word = words[cat][i].upper()

# list of used letters
used = []
# covered password and number of unvovered letteres
password, uncov = covered(word, used)

# game
while life > 0 and uncov > 0:
    print('_' * 48)
    print('\nYour lifes: {}'.format(life))
    print('Cathegory: {}\n'.format(cat.upper()))
    print(password)
    letter = input('Give a letter or guess the password: ')
    letter = letter.upper()
    
    # guessing password
    if len(letter) > 1:
        if letter == word:
            uncov = 0
        else:
            life -= 1
            
    # guessing letter
    else:
        if letter in used:
            print('You\'ve tried this letter!')
        else:
            used.append(letter)
            if not any(l == letter for l in word):
                life -= 1
            else:
                password, uncov = covered(word, used)
    
# finish
print('_' * 48)
if uncov == 0:
    print('\nYes, it\'s {}! You won!'.format(word))
else:
    print('\nGAME OVER')
    