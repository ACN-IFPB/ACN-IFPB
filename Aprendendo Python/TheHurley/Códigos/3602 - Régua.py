T1 = int (input ())
T2 = int (input())
T3 = int (input ())
T4 = int (input ())

if ( T1 < 2 or T1 > 6):
    print ("Requisito violado")
else:
    T1 -= 1
if ( T2 < 2 or T2 > 6):
    print ("Requisito violado")
else:
    T1 -= 1
if ( T3 < 2 or T3 > 6):
    print ("Requisito violado")
else:
    T3 -= 1
if ( T4 < 2 or T4 > 6):
    print ("Requisito violado")
else:
    print ("%d" %(T1+T2+T3+T4))