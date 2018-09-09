'''
The Roll-over optimization problem from MIT lecture:
https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-0002-
introduction-to-computational-thinking-and-data-science-fall-2016/lecture-slides
-and-files/MIT6_0002F16_lec2.pdf

Problem:
Score = (60	– (a+b+c+d+e))*F + a*ps1 + b*ps2 + c*ps3 + d*ps4 + e*ps5
Given F, ps1, ps2, ps3, ps4, ps5
Find a, b, c, d, e that maximize score
Where
a, b, c, d, e = 0 or 10
a+b+c+d+e >= 20

Solution:
Notice that
Score = 60*F + a*(ps1-F) + b*(ps2-F) + c*(ps3-F) + d*(ps4-F) + e*(ps5-F)
So we have to maximize part
max_score = a*(ps1-F) + b*(ps2-F) + c*(ps3-F) + d*(ps4-F) + e*(ps5-F)
'''

# ps and f - table with given ps1, ps2... and given f
# sum_ae - sum of a, b, c, d, e
# memo - dictionary with already calculated solutions for specific conditions
def max_score(ps, f, sum_ae=0, memo={}):
	# Checking if solution for specific conditions is saved in dictionary memo
	# Refering to solution by length of table ps and sum of variables a,...,e
	if (len(ps), sum_ae) in memo:
		result = memo[(len(ps), sum_ae)]
	
	# If table ps is empty, the solution is 0, sum_ae doesn't change
	elif ps==[]:
		result = (0, sum_ae)
		
	# if length of ps is 2 or 1 and sum_ae is 0 or 10, 
	# then the value ps[i]-f has to be taken,
	# that means d and/or e has to have value 10
	elif (len(ps) == 2 and sum_ae == 0) or (len(ps) == 1 and sum_ae == 10):
		take, sum_ae = max_score(ps[1:], f, sum_ae+10, memo)
		take += 10 * (ps[0] - f)
		result = (take, sum_ae)
		
	# otherwise looking for optimal solution
	else:
		# checking the score while taking ps[i]-f,  a,b,c,d,e = 10
		take, sum_take = max_score(ps[1:], f, sum_ae+10, memo)
		take += 10 * (ps[0] - f)
		
		# checking the score while skiping ps[i]-f,  a,b,c,d,e = 0
		skip, sum_skip = max_score(ps[1:], f, sum_ae, memo)
		
		# checking what gives higher score
		if take > skip:
			result = (take, sum_take)
			sum_ae = sum_take
		else:
			result = (skip, sum_skip)
			sum_ae = sum_skip
			
	# saving the score to memo	
	if (len(ps), sum_ae) not in memo:	
		memo[(len(ps), sum_ae)] = result
	
	return result
	
# given values
f = 3
ps = [1, 2, 3, 4, 5]

# calculating max_score and final answer - score
s = max_score(ps, f)
score = 60 * f + s[0]

# printing solution
print('\nMaximal score: ', score)
print('a + b + c + d + e = ', s[1])
print()
