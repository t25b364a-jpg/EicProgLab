/*
 * practice1_2.c
 *
 * プログラミングBI 演習課題1-2
 *
 * Copyright (C) 2010-2026, S. Muramatsu
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define DELTA 1E-15 /* 誤差の上限 */
#define absdif(x,y) ((x>y) ? (x-y) : (y-x)) /* 差分絶対値 */

/* 平方根を求める関数 */
double mysqrt(double y) {

	int k = 0; /* 反復回数 */
	double x = 1.0; /* 平方根 */
	double e = absdif(x,y/x); /* 誤差 */

	/* 反復計算 */
	printf(" %21.16g（反復回数 %d 回）\n", x, k);
	while (e >= DELTA && k < 1000) {
		k++;
		x = ( x + y/x )/2.0; /* 値の更新 */
		e = absdif( x, y/x ); /* 誤差 */
		printf(" %21.16g（反復回数 %d 回）\n", x, k);
	}
	x = ( x + y/x )/2.0; /* 値の更新 */

	return x;
}

/* メイン関数 */
int main()
{
	/* 変数宣言 */
	double a,b,c; /* 入力値 */
	double d; /*判別式Dの値*/
	double p,q,r; /*二次方程式の解を表す*/
	double x; /* 平方根 */

	/* 平方根を求める値の読み込み */
	printf("実数値aを入力して下さい: ");
	scanf("%lf",&a);
	printf("実数値bを入力して下さい: ");
	scanf("%lf",&b);
	printf("実数値cを入力して下さい: ");
	scanf("%lf",&c);

	/* 入力データの確認 */
	if ( a == 0 ) {
		printf("これは二次方程式ではありません。終了します。\n");
		exit(EXIT_SUCCESS);
	}

	/* 判別式Dの計算 */
	d = b * b - 4 * a * c;

	/*解の実部を求める*/
	p = - b / (2 * a);

	/*判別式Dの評価*/
	if (d > 0) {
		printf("二次方程式の解：\n");
		x = mysqrt(d);
		q = x / (2 * a);
		r = p + q;
		printf("x1 = %21.16g \n", r);
		r = - r;
		printf("x2 = %21.16g \n", r);
	}
	else if (d == 0) {
		printf("二次方程式の解：\n");
		printf("X = %21.16g(重解) \n", p);
	}
	else {
		printf("二次方程式の解：\n");
		d = -d;
		x = mysqrt(d);
		q = x / (2 * a);
		printf("x1 = %21.16g+%21.16gj \n", p,q);
		printf("x2 = %21.16g-%21.16gj \n", p,q);
	}
	
	return 0;
}
