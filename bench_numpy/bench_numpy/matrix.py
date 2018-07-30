import random
import operator
import sys
import unittest
import numpy as np
import time

class Bench(object):
    def __init__(self,m,n,type,p):
        self.m = m
        self.n = n
        self.type=type
        self.p=p
        mat1_obj = Matrix.makeRandom(m,n,type,p)
        mat2_obj = Matrix.makeRandom(m,n,type,p)

        mat1 = np.asarray(mat1_obj)
        mat2 = np.asarray(mat2_obj)


        tmps1=time.clock()
        mat1.dot(mat2)
        tmps2=time.clock()

        self.time=(tmps2-tmps1)





class Matrix(object):


    def __init__(self, m, n, init=True):
        if init:
            self.rows = [[0]*n for x in range(m)]
        else:
            self.rows = []
        self.m = m
        self.n = n

    def __getitem__(self, idx):
        return self.rows[idx]

    def __setitem__(self, idx, item):
        self.rows[idx] = item

    def __str__(self):
        s='\n'.join([' '.join([str(item) for item in row]) for row in self.rows])
        return s + '\n'

    def reset(self):
        self.rows = [[] for x in range(self.m)]



    def getTranspose(self):


        m, n = self.n, self.m
        mat = Matrix(m, n)
        mat.rows =  [list(item) for item in zip(*self.rows)]

        return mat

    def getRank(self):
        return (self.m, self.n)

    def __eq__(self, mat):

        return (mat.rows == self.rows)

    def __add__(self, mat):


        ret = Matrix(self.m, self.n)

        for x in range(self.m):
            row = [sum(item) for item in zip(self.rows[x], mat[x])]
            ret[x] = row

        return ret

    def __sub__(self, mat):


        ret = Matrix(self.m, self.n)

        for x in range(self.m):
            row = [item[0]-item[1] for item in zip(self.rows[x], mat[x])]
            ret[x] = row

        return ret

    def __mul__(self, mat):

        matm, matn = mat.getRank()


        mat_t = mat.getTranspose()
        mulmat = Matrix(self.m, matn)

        for x in range(self.m):
            for y in range(mat_t.m):
                mulmat[x][y] = sum([item[0]*item[1] for item in zip(self.rows[x], mat_t[y])])

        return mulmat



    @classmethod
    def makeRandom(cls, m, n,t,p1):
        """ Make a random matrix with elements in range (low-high) """
        low= m
        count=0
        high=random.randrange(low, low*5)
        obj = Matrix(m, n)
        if t==1:
            for x in range(m):
                obj.rows.append([random.randrange(low, high) for i in range(obj.n)])
        else:
            p=m*n*p1
            while(count<p):
                i=random.randrange(0,m)
                j=random.randrange(0,n)
                obj[i][j] = random.randrange(low, high)
                count=count+1

        return obj

if __name__ == "__main__":
    unittest.main()
