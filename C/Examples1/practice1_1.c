/*
 * practice1_1 .c
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
	int n; /* 近似次数 */
	double z; /*xの二乗の変数*/

	/* 途中の計算に必要な変数の宣言 */
	int i; /* 繰り返し変数の宣言 */
	int j; /*繰り返し変数を二倍したもの*/
	double f; /* 階乗値 */
	double p; /* x の累乗値 */
	double q; /*各項の値*/
	double r; /*偶数番目の項は負、奇数番目は正にした値/
	/* データの読み込み(倍精度, 整数) */
	scanf("%lf%d",&x,&n);

	/* 近似値の初期化 */
	y = 1.0;
	f = 1.0;
	p = 1.0;
	z = x*x; 
	for (i=1; i<=n; i++) {
		f = f * (double)i; /* f *= (double)i; とも書ける */
		j = i*2;
		f = f * (double)j;
		p = p * z; /* p *= z; とも書ける */
		q = p/f;
		for (j=2; j<=i; j++) {
			r = q*-1;
		}
		y = y + r; /* y += r; とも書ける */
	}

	/* e^x の近似値の表示 */
	printf("マクローリン展開による次数 %d までの e^(%g) の近似値\n"
		"    =%21.16g\n", n, x, y);
	
	return 0;
}
