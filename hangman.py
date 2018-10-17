''' Hangman game by AR, Oct 2018 '''

import random


def main():
    cat, word = choose_psw()  # choosing cathegory and word
    life = 10                 # number of lives
    used = []                 # list of uncovered letters
    
    # covered password and number of uncovered letters
    password, uncov = covered(word, used)
    
    # game goes until life is over or word is guessed 
    while life > 0 and uncov > 0:
        print("_" * 48)
        print("\nYour lifes: {}".format(life))
        print("Category: {}\n".format(cat.upper()))
        print(password)
        letter = input("Give a letter or guess the password: ")
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
                print("You've tried this letter!")
            else:
                used.append(letter)
                if not any(l == letter for l in word):
                    life -= 1
                else:
                    password, uncov = covered(word, used)
        
    # finish
    print('_' * 48)
    if uncov == 0:
        print("\nYes, it's {}! You won!\n".format(word))
    else:
        print("\nGAME OVER\n")


# returns random category and word 
def choose_psw():
    # dictionary with passwords
    words = {'Car': ['Mercedes', 'Volkswagen', 'Fiat', 'Ford', 'BMW'],
             'Food': ['Cheesburger', 'Pizza', 'Apple', 'Pasta'],
             'Animal': ['Dog', 'Spider', 'Snake', 'Lizard'],
             'Country': ['Poland', 'Croatia', 'Germany', 'Russia'],
            }
    
    # choose category
    i = random.randint(0, len(words)-1)
    cat = list(words.keys())[i]
    
    # choose password from category
    i = random.randint(0, len(words[cat])-1)
    word = words[cat][i].upper()
    
    return cat, word
    

# returns string where uncovered letteres are reprezented by '_'
# psw - password to hide, lts - list of uncovered letters
def covered(psw, lts):
    prt = ""  # covered password
    c = 0     # number of covered letters
    for l in psw:
        if l in lts:
            prt = prt + l + " "
        else:
            prt = prt + "_ "
            c += 1
    return prt, c


if __name__ == "__main__":
    main()    