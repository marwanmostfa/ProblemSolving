# -*- coding: utf-8 -*-
"""
Created on Sat Jun 27 22:34:57 2020

@author: user2
"""

import numpy as np

#Challenge 1
print("challenge 1")
mat1=np.zeros((3,3))

mat1[0][0]=12
mat1[0][1]=17
mat1[0][2]=10
mat1[1][0]=11

rowSum=mat1[0][0]+mat1[0][1]+mat1[0][2]

mat1[2][0]=rowSum-(mat1[0][0]+mat1[1][0])
mat1[1][1]=rowSum-(mat1[0][2]+mat1[2][0])
mat1[1][2]=rowSum-(mat1[1][0]+mat1[1][1])
mat1[2][1]=rowSum-(mat1[0][1]+mat1[1][1])
mat1[2][2]=rowSum-(mat1[1][2]+mat1[0][2])
print(mat1)
print(mat1.sum(axis=0))
print(mat1.sum(axis=1))
print("dig1: "+str(mat1[0][0]+mat1[1][1]+mat1[2][2]))
print("dig2: "+str(mat1[0][2]+mat1[1][1]+mat1[2][0]))

#------------------------------------------------------------------------------
#challenge 2
print("challenge 2")

mat1=np.zeros((3,3))

mat1[0][1]=7
mat1[0][2]=16
mat1[1][0]=15
mat1[2][2]=11

diff=np.abs((mat1[0][1]+mat1[0][2])-(mat1[0][2]+mat1[2][2]))

done=False
minVal=1
maxVal=diff+1
while(not done):
    mat1[1][2]=minVal
    mat1[0][0]=maxVal
    
    rowSum=mat1[0][2]+mat1[0][1]+mat1[0][0]
    
    mat1[2][0]=rowSum-(mat1[0][0]+mat1[1][0])
    mat1[1][1]=rowSum-(mat1[0][0]+mat1[2][2])
    mat1[2][1]=rowSum-(mat1[0][1]+mat1[1][1])
    
    dig1=mat1[0][0]+mat1[1][1]+mat1[2][2]
    dig2=mat1[0][2]+mat1[1][1]+mat1[2][0]
    if(len(np.unique(mat1))== 9 and dig1==rowSum and dig2==rowSum):
        done=True
    else:
        minVal +=1
        maxVal +=1
    
print(mat1)
print(mat1.sum(axis=0))
print(mat1.sum(axis=1))
print("dig1: "+str(dig1))
print("dig2: "+str(dig2))

#------------------------------------------------------------------------------
#challenge 3
mat1[1][0]=31
mat1[1][2]=15
mat1[2][1]=41
mat1[0][1]=5

okay=False
centre=1
while(not okay):
    mat1[0][0]=centre+5
    mat1[0][2]=82-2*centre
    mat1[2][0]=2*centre-36
    mat1[2][2]=41-centre
    mat1[1][1]=centre
    rowSum=mat1[0][0]+mat1[0][1]+mat1[0][2]
    dig1=mat1[0][0]+mat1[1][1]+mat1[2][2]
    dig2=mat1[0][2]+mat1[1][1]+mat1[2][0]
    if(len(np.unique(mat1))==9 and dig1==rowSum and dig2==rowSum):
        c=0
        for i in range(3):
            for j in range(3):
                if mat1[i][j]>0:
                    c +=1
        if c==9:
            okay=True
        else:
            c=0    
    else:
        centre+=1

print("Challenge 3")
print(mat1)
print(mat1.sum(axis=0))
print(mat1.sum(axis=1))
print("dig1: "+str(dig1))
print("dig2: "+str(dig2))

#------------------------------------------------------------------------------
#challenge 4
print("challenge 4")
mat1[2][1]=28
mat1[1][2]=18
difference=np.abs(mat1[2][1]-mat1[1][2])

xx=1
good=False
while(not good):
    low=1
    mat1[2][2]=xx
    for a in range(100):
        mat1[2][0]=low
        mat1[0][2]=low+difference
        mat1[0][0]=mat1[2][2]-2*low+36
        mat1[0][1]=2*low-18
        mat1[1][0]=2*low-8
        mat1[1][1]=mat1[2][2]-low+18
        rowSum=mat1[0][0]+mat1[0][1]+mat1[0][2]
        dig1=mat1[0][0]+mat1[1][1]+mat1[2][2]
        dig2=mat1[0][2]+mat1[1][1]+mat1[2][0]
        if(len(np.unique(mat1))==9 and dig1==rowSum and dig2==rowSum):
            c=0
            for i in range(3):
                for j in range(3):
                    if mat1[i][j]>0:
                       c +=1
            if c==9:
                good=True
            else:
                c=0    
        else:
            low+=1
    
    xx +=1

print(mat1)
print(mat1.sum(axis=0))
print(mat1.sum(axis=1))
print("dig1: "+str(dig1))
print("dig2: "+str(dig2))

#------------------------------------------------------------------------------
#challenge 5
print("challenge 5")
mat1[2][1]=28
mat1[1][2]=18
difference=np.abs(mat1[2][1]-mat1[1][2])
low=1
sums=[]
mats=[]
xx=1
for i in range(3):
    good=False
    while(not good):
        low=1
        mat1[2][2]=xx
        for a in range(100):
            mat1[2][0]=low
            mat1[0][2]=low+difference
            mat1[0][0]=mat1[2][2]-2*low+36
            mat1[0][1]=2*low-18
            mat1[1][0]=2*low-8
            mat1[1][1]=mat1[2][2]-low+18
            rowSum=mat1[0][0]+mat1[0][1]+mat1[0][2]
            dig1=mat1[0][0]+mat1[1][1]+mat1[2][2]
            dig2=mat1[0][2]+mat1[1][1]+mat1[2][0]
            if(len(np.unique(mat1))==9 and dig1==rowSum and dig2==rowSum):
                c=0
                for i in range(3):
                    for j in range(3):
                        if mat1[i][j]>0:
                            c +=1
                if c==9:
                    print("Sum: "+str(rowSum))
                    print(mat1)
                    sums.append(rowSum)
                    mats.append(mat1)
                    good=True
                    break
                else:
                    c=0    
            else:
                low+=1
        xx +=1
#------------------------------------------------------------------------------