/*
 * practice1_1.c
 *
 * プログラミングBI 演習課題1-1
 *
 * Copyright (C) 2007-2026, S. Muramatsu
 *
 */
#include <stdio.h>

int main()
{
	/* 変数宣言 */
	double x; /* 独立変数 */
	double y; /* 従属変数 (関数の近似値) */
	double z; /* xの二乗の変数*/
	int n; /* 近似次数 */
	int i; /* 繰り返し変数の宣言 */
	double f; /* 階乗値 */
	double p; /* x の累乗値 */
	double q; /* 各項の値 */
	double r; /* 各項の符号を表す*/
	/* データの読み込み(倍精度, 整数) */
	scanf("%lf%d",&x,&n);

	/* 近似値の初期化 */
	y = 1.0;
	f = 1.0;
	p = 1.0;
	r = -1.0;
	z = x*x; 
	for (i=1; i<=n; i++) {
		f = f * (2 * (double)i - 1); /* f *= 2 * (double)i - 1; とも書ける */
		f = f * (2 * (double)i); /* f *= 2 * (double)i; とも書ける */
		p = p * z; /* p *= z; とも書ける */
		q = p/f; /* 各項を求めた */
		y = y + r * q; /* 各項の値を加えていく */
		r = -r; /* 各項の符号の調整 */
	}

	/* e^x の近似値の表示 */
	printf("マクローリン展開による次数 %d までの cos(%g) の近似値\n"
		"    =%21.16g\n", n, x, y);
	
	return 0;
}
