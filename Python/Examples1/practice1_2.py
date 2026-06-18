"""
practice1_2.py
Copyright (c) 2018-2025, Shogo MURAMATSU, All rights reserved
"""
from my_complex import MyComplex
import sys
import math

# 電源電圧値
SRC_VOLTAGE = MyComplex(5.0, 0.0)

def main(args):
    # 引数の数の確認
    if len(args) != 5:
        print('引数の数は 4 つ必要です．')
        sys.exit(0)
        
    # コマンド引数からのデータの読み込み
    # MyComplexクラスをインスタンス化
    R = MyComplex(float(args[1]), 0)
    L = MyComplex(float(args[2]), 0)
    C = MyComplex(float(args[3]), 0)
    ω = MyComplex(float(args[4]), 0)
    
    # 各複素数の内容を表示して確認
    print('電源電圧 |E| \t= ' + str(SRC_VOLTAGE) +' V')
    print('抵抗 R \t= ' + str(R) + ' Ω')
    print('インダクタ L \t= ' + str(L) + ' H')
    print('コンデンサ C \t= ' + str(C) + ' F')
    print('角周波数 ω \t= ' + str(ω) + ' rad/s')

    # 抵抗にかかる電圧の複素数を求める
    X = (ω * L) - (1 / (ω * C))
    Y = MyComplex(X)
    V = (R * SRC_VOLTAGE) / (R + MyComplex(0, Y.real))
    print('R にかかる電圧 V \t= ' + str(V) + ' V')

    #電圧の大きさ[V]を求める
    absV = V.abs()
    print(' 大きさ : \t= ' + str(absV) + ' V')

    #電圧のの偏角[rad]を求める
    phaseV = V.ang()
    print(' 偏角 : \t= ' + str(phaseV) + ' rad')

if __name__ == '__main__':
    main(sys.argv)
