m1 = [[3,2], [1, 6]]
m2 = [[8, 4], [5, 7]]

for i in range (2):
    for j in range (2):
        if i !=0 :
            m2 [i][j] *= m1[i-1][j]
        else:
            m2 [i][j] += m1 [i][j]

print (m2 [1][1])
