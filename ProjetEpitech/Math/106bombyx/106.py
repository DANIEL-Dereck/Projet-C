# !/usr/bin/python3.3

import sys
import matplotlib.pyplot as plt
import numpy as np

if len(sys.argv) == 2:
    k = float(sys.argv[1])
    i = 0
    x = 10
    y = k * x * ((1000 - x) * 0.001)
    if 1 <= k <= 4:
        print(x)
        l = plt.plot(i,x,'r',marker='o')
        i = i + 1
        print(y)
        l = plt.plot(i,y,'r',marker='o')
        i = i + 1
        print(y)
        l = plt.plot(i,y,'r',marker='o')
        i = i + 1
        while i <= 100:
            l = plt.plot(i,k * y * ((1000 - y) * 0.001),'r', marker='o')
            y = k * y * ((1000 - y) * 0.001)
            print(y)
            i = i + 1;
        plt.title("106Bombyx")
        plt.xlabel("Bombyx")
        plt.legend([l], ["Bombyx"])
        plt.savefig(sys.argv[1], format='pdf')
        plt.show()
    else:
        print("K doit etre compris entre 1 et 4");

elif len(sys.argv) == 3:
    min = int(sys.argv[1])
    max = int(sys.argv[2])

    i = 0
    x = 10
    k = 1;
    y = k * x * ((1000 - x) * 0.001)
    while k <= 4:
        i =  1
        x = 10
        while i <= min:
            y = k * y * ((1000 - y) * 0.001)
            i = i + 1;
        while i <= max:
            y = k * y * ((1000 - y) * 0.001)
            i = i + 1;
        l = plt.plot(k,y,'r', marker='o')
        k = k + 0.001;
    plt.title("106Bombyx")
    plt.xlabel("Bombyx")
    plt.legend([l], ["Bombyx"])
    plt.savefig("option2.pdf")
    plt.show()
    
else:
    print("Please enter argument")

