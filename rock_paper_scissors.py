import random

print("""Do you want to play "Rock", "Paper", "Scissor" game made by SMAZY? [Y/N]""")
want_to_play = input().capitalize()
while want_to_play not in ("Yes", "Y", "No", "N"):
    print("Please enter a valid option  [Y/N]")
    want_to_play = input().capitalize()

player_score = 0
pc_score = 0
while want_to_play == "Yes" or want_to_play == "Y":

    # Possible outcomes
    possible_choices = ("Rock", "Paper", "Scissor")

    # making pc choose
    pc_choice_number = random.randint(0, 2)
    pc_choice = possible_choices[pc_choice_number]
    # print(pc_choice)  # todo  remove after testing

    # Letting player choose what they want to play for the round
    print("""What do you chose? ["Rock", "Paper", "Scissor"]""")
    player_choice = input().capitalize()
    while player_choice not in possible_choices:
        print("""Please type "Rock", "Paper", "Scissor" one of them""")
        player_choice = input().capitalize()

    # Forming Conditions for the game
    if len(player_choice) == len(pc_choice):
        print("You chose {}, I chose {}. Its a tie".format(player_choice, pc_choice))

    elif len(player_choice) > len(pc_choice):
        if player_choice == "Scissor" and pc_choice == "Rock":
            print("You chose {}, I chose {}. You Lost".format(player_choice, pc_choice))
            pc_score += 1
        else:
            print("You chose {}, I chose {}. You Won".format(player_choice, pc_choice))
            player_score += 1
    else:
        if pc_choice == "Scissor" and player_choice == "Rock":
            print("You chose {}, I chose {}. You Won".format(player_choice, pc_choice))
            player_score += 1
        else:
            print("You chose {}, I chose {}. You Lost".format(player_choice, pc_choice))
            pc_score += 1

    # Letting player choose whether to play or not
    print("Do you want to continue playing?  [Y/N]")
    want_to_play = input().capitalize()
    while want_to_play not in ("Yes", "Y", "No", "N"):
        print("Please enter a valid option  [Y/N]")
        want_to_play = input().capitalize()

# Printing out scores
if player_score > pc_score:
    print("""You scored {}, while I scored {}, You won by {}""".format(player_score, pc_score, player_score - pc_score))
elif pc_score > player_score:
    print("""You scored {}, while I scored {}, I won by {}""".format(player_score, pc_score, pc_score - player_score))
else:
    print("""Its a tie, You scored {}, I scored {}""".format(player_score, pc_score))