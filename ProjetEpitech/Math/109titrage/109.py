# !/usr/bin/python3.3

import matplotlib.pyplot as plt
import numpy as np
import sys
import math

if (len(sys.argv) == 1):
    i = 0
    tab = sys.stdin.read()
    x = 0.0
    y = 0.0
    while tab[i] != 'F':
        uneligne = ""
        while (tab[i] != ";"):
            uneligne += tab[i]
            i += 1;
        x = float(uneligne)
        if (tab[i]):
            i += 1;
        uneligne = ""
        while tab[i] != '\n':
            uneligne += tab[i]
            i += 1;
        y = float(uneligne)
        l = plt.plot(x, y,'r', marker='o')
    plt.title("109titrage")
    plt.xlabel("titrage")
    plt.savefig("save", format='pdf')
    plt.show()
