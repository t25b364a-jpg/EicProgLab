"""
practice1_1.py
(c) Copyright 2022-2025, Shogo MURAMATSU, All rights reserved
"""
import sys
import math

# 電源電圧値
SRC_VOLTAGE = 5.0
# 要素の数
NUM_ELEMENTS = 4

def main(args):
    if len(args) != 5:
        print('エラー：引数の数' + str(len(args)))
        sys.exit(0)

    # 要素それぞれの格納
    elements = [ 0.0 for idx in range(NUM_ELEMENTS) ]
    for idx in range(NUM_ELEMENTS):
        elements[idx] = float(args[idx+1])
        
    # 抵抗Rに流れる電流の大きさ|I|の計算
    E = SRC_VOLTAGE
    R, L, C, ω = elements[0], elements[1], elements[2], elements[3]
    I = E / math.sqrt(R**2 + (ω * L - 1 / (ω * C))**2)

    # 入力した値と電流の大きさ|I|の表示
    print('電源電圧 |E| = ' + str(SRC_VOLTAGE) + ' V')
    print('抵抗 R = ' + str(R) + ' Ω')
    print('インダクタ L = ' + str(L) + ' H')
    print('コンデンサ C = ' + str(C) + ' F')
    print('角周波数 ω = ' + str(ω) + ' rad/s')
    print('Rに流れる電流 |I| = ' + str(I) + ' A')

if __name__ == '__main__':
    main(sys.argv)
        
        
