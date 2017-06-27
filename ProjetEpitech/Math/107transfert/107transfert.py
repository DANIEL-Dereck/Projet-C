# !/usr/bin/python3.3

import sys
import matplotlib.pyplot as plt
import numpy as np
import string


if len(sys.argv) == 2:
    print(sys.argv[1])
    a = 0;
    b = 0;
    liste = string.split(sys.argv[1],'|')
    b = len(liste) - 1
    print("evaluation du polynome")
    while (b > 0):
        print("%sx^%d" % liste[a] % b)
        b = b - 1
        a = a + 1
    print("%sx" % liste[a])
    a = a + 1
    print(lsite[a]);

elif len(sys.argv) >= 3:
    print(sys.argv[a])

else:
    print("Usage : python 107transfert")
    print("       Option 1 : 1 argument :")
    print("                la liste des coefficients d un polynome")
    print("       Option 2 : 2 arguments :")
    print("                 un nombre pair de parametres : pour chaque composant, la liste des coefficients du polynome au numerateur")
    print("                 la liste des coefficients du polynome au denominateur (dans l ordre, en commencant par le plus bas degre)")
