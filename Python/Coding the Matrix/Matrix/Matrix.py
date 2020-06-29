from mat import Mat
from vec import Vec
from matutil import coldict2mat

with open('UN_voting_data.txt', 'r') as f:
    lines = f.readlines()
    col_dict = dict()
    for line in lines:
        line = line.split()
        nations = line[0]
        votes = line[1:]
        len_votes = len(votes)
        vote_vec = Vec(set(range(len_votes)), {i:int(votes[i]) for i in range(len_votes)})
        col_dict[nations] = vote_vec
    A = coldict2mat(col_dict)
    M = A.transpose() * A

sorted_data = sorted([(value,key) for key,value in M.f.items()])

most_opposed = sorted_data[0][1]

most_opposed_top10 = [sorted_data[i][1] for i in range(10)]

most_agreeing = sorted_data[-1][1]

print(most_opposed, '|', most_opposed_top10, '|', most_agreeing)