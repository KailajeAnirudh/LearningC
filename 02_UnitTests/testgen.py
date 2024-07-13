import numpy as np
from numpy.random import randint as rn
import os

if __name__=="__main__":
    filename = input("Filename: ")
    if os.path.exists(f"./{filename}.txt"):
        os.remove(f"./{filename}.txt")
    for i in range(1, 32):
        for _ in range(1000//32):
            with open(f"{filename}.txt", "a") as f:
                f.write(f"{rn(2**i)}\n")
            
