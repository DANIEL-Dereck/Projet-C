# !/usr/bin/python3.3

import matplotlib.pyplot as plt
import numpy as np
import sys
import math

if (len(sys.argv) == 3):
    x = -2
    i = float(sys.argv[1])
    if (i < 2):
        sys.exit;
    nmax = int(sys.argv[2])
    if (nmax < 0):
        sys.exit;
    while (x <= 2):
        v = 0
        o = 0
        while (o <= nmax):
            v = v + (math.cos(math.pow(i, o) * math.pi * x) / (math.pow(2, o)));
            o = o + 1;
        l = plt.plot(x, v,'r', marker='o')
        x = x + 0.001;
    plt.title("108Monstre")
    plt.xlabel("Monstre")
    plt.savefig(sys.argv[1], format='pdf')
    plt.show()

else:
    print("Invalid arg number. Need 2 args.");
