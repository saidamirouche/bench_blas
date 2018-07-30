import sys

#export PYTHONPATH=$PYTHONPATH:/home/said/work/bench_numpy/bench_numpy

from matrix import *
import time
import numpy as np



mat_type = int(sys.argv[1])
rows = int(sys.argv[2])
cols = int(sys.argv[3])
p = int(sys.argv[4])
p1 = float(p/100.)


example1 = Bench(rows,cols,mat_type,p1)


print "le temps d'execution de bench est", example1.time
