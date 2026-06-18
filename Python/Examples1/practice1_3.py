"""
practice1_3.py
Copyright (c) 2018-2025, Shogo MURAMATSU, All rights reserved
"""
from my_complex_copy import MyComplex
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
    print('電源電圧 E = ' + str(SRC_VOLTAGE) +' V')
    print('抵抗 R = ' + str(float(args[1])) + ' Ω')
    print('インダクタ L = ' + str(float(args[2])) + ' H')
    print('コンデンサ C = ' + str(float(args[3])) + ' F')
    print('角周波数 ω = ' + str(float(args[4])) + ' rad/s')

    # 抵抗にかかる電圧の複素数を求める
    X = (ω * L) - (MyComplex(1.0, 0.0) / (ω * C))
    V = (R * SRC_VOLTAGE) / (R + MyComplex(0, X.abs()))
    print('R にかかる電圧 V = ' + str(V) + ' V')

    #電圧の大きさ[V]を求める
    absV = V.abs()
    print(' 大きさ : ' + str(absV) + ' V')

    #電圧のの偏角[rad]を求める
    phaseV = V.ang()
    print(' 偏角   : ' + str(phaseV) + ' rad')

if __name__ == '__main__':
    main(sys.argv)
