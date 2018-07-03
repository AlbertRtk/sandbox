'''
Josephus Problem:
N people (numbered 1 to N) are standing in a circle. Person 1 kills Person 2 with a sword and gives it to Person 3. 
Person 3 kills Person 4 and gives the sword to Person 5. This process is repeated until only one person is alive.
Task:
1. Given the number of people N, write a program to find the number of the person that stays alive at the end.
2. Show each step of the process.
'''


try:    
    n = int(input("Give number of people: "))
except:
    print("Number of people has to be integer!\n")

people = [i+1 for i in range(n)]

while len(people) != 1:
    print("Person {} kills person {}.".format(people[0], people[1]))
    people = people[1:] + people[:1]
    del people[0]
	
print("Person {} survived!".format(people[0]))
