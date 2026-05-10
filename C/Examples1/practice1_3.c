/*
 * practice1_3.c
 *
 * プログラミングBI 演習課題1-3
 *
 * Copyright (C) 2010-2026, S. Muramatsu
 *
 */
#include <stdio.h>
#include <stdlib.h>

int hex_to_int(char c)
{	/* ASCIIを利用 */
    if ('0' <= c && c <= '9') return c - '0';
    if ('A' <= c && c <= 'F') return c - 'A' + 10;
    if ('a' <= c && c <= 'f') return c - 'a' + 10;
    return -1; /* 異常あり*/
}

int main()
{
    int n_int, n_frac; /* 整数部,小数部の桁数 */
    char *s_int, *s_frac; /* 整数部を文字列として受け取った */
    int *a_int, *a_frac; /* 小数部を文字列として受け取った */
    int i; /* 変数*/
    double value = 0.0; /* 10進数に直すための初期値*/
    double p,q; /* それぞれの桁について10進数に変えるための値*/

    printf("整数部の桁数：");
    scanf("%d", &n_int);

    printf("小数部の桁数：");
    scanf("%d", &n_frac);

	/*動的領域確保*/
	s_int = (char*)malloc(sizeof(char) * n_int);
	s_frac = (char*)malloc(sizeof(char) * n_frac);
	a_int = (int*)malloc(sizeof(int) * n_int);
	a_frac = (int*)malloc(sizeof(int) * n_frac);

    /* 配列への代入*/
	printf("整数部を1文字ずつ入力（0〜9, A〜F）：\n");
    for (i = 0; i < n_int; i++) {
        scanf(" %c", &s_int[i]);
        a_int[i] = hex_to_int(s_int[i]);
    }

    printf("小数部を1文字ずつ入力（0〜9, A〜F）：\n");
    for (i = 0; i < n_frac; i++) {
        scanf(" %c", &s_frac[i]);
        a_frac[i] = hex_to_int(s_frac[i]);
    }

    /* 整数部 */
    p = 1.0;
    for (i = n_int - 1; i >= 0; i--) {
        value += a_int[i] * p;
        p *= 16.0;
    }

    /* 小数部 */
    q = 1.0 / 16.0;
    for (i = 0; i < n_frac; i++) {
        value += a_frac[i] * q;
        q /= 16.0;
    }

    printf("10進数 = %f\n", value);

	/* 解放を行う*/
    free(s_int);
    free(s_frac);
    free(a_int);
    free(a_frac);

    return 0;
}
