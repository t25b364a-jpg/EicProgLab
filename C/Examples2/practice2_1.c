/*
 * practice2_1.c
 *
 * プログラミングBI 演習課題2-1
 *
 * Copyright (C) 2010-2026, S. Muramatsu
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 関数プロトタイプ */
void inputVec(double* pVector);
void getMtxVecProd2(double*pVectorOut,double pMatrix[][2],double*pVectorIn); 
void getVecDiff2(double*pVectorOut,double*pVectorIn1,double*pVectorIn2);
double getNorm2(double*pVector);

int main()
{
  /* 変数宣言 */
  int i, j; /* ループ変数 */ 
  int k; /* 繰り返し回数 */
  double *pVector_b, *pVector_p, *pVector_q, *pVector_x, *pVector_y, *pVector_z; /* ベクトルのポインタ */
  double A[2][2] = {{1.0, 2.0}, {3.0, 4.0}}; /* 行列A */
  double a[2][2] = {{1.0, 3.0}, {2.0, 4.0}}; /* 行列Aの転置 */
  char mode;

  /* ベクトルのための動的領域確保 */
  pVector_b = (double*)malloc(sizeof(double)*2);/* bの配列*/
  pVector_p = (double*)malloc(sizeof(double)*2);/* pの配列*/
  pVector_q = (double*)malloc(sizeof(double)*2);/* qの配列*/
  pVector_x = (double*)malloc(sizeof(double)*2);/* xの配列*/
  pVector_y = (double*)malloc(sizeof(double)*2);/* yの配列*/
  pVector_z = (double*)malloc(sizeof(double)*2);/* zの配列*/

  /* ベクトルxの初期化 */
  for (i = 0; i < 2; i++) {
    pVector_x[i] = 0.0;
  }

  do {
    /* ベクトルbの要素の読み込み */
    printf("ベクトルb の要素の読み込み\n");
    inputVec(pVector_b);
    
    /* 繰り返し回数 */
    printf("繰り返し回数を入力してください. (>0): ");
    scanf("%d", &k);
   } while( k < 1 );
    
   /* ベクトルxの表示 */
    for (i = 0; i < k + 1; i++) {
      printf("繰り返し回数: %d\n", i);
      printf("ベクトルx:\n");
      for (j = 0; j < 2; j++) {
        printf("%d番目の要素: %0.6g\n", j + 1, pVector_x[j]);
      }
      getMtxVecProd2(pVector_y, A, pVector_x); /* 行列Aとベクトルxの積を計算 */
      getVecDiff2(pVector_z, pVector_y, pVector_b); /*ベクトルyとベクトルbの差分を計算 */
      getMtxVecProd2(pVector_p, a, pVector_z); /*ベクトルzと行列Aの転置の積を計算 */

      /* ベクトルqの計算 */
      for (j = 0; j < 2; j++){
        pVector_q[j] = pVector_p[j] / 30;
      }
      /* ベクトルxの更新 */
      for (j = 0; j < 2; j++){
        pVector_x[j] = pVector_x[j] - pVector_q[j];
      }

      printf("距離: %10.6g\n\n", getNorm2(pVector_z));
    }

  /* 領域解放 */
  free(pVector_b);
  free(pVector_p);
  free(pVector_q);
  free(pVector_x);
  free(pVector_y);
  free(pVector_z);

  return 0;
}

/* ベクトルの要素を問い合わせる関数 */
void inputVec(double*pVector)
{
  int i;
  for(i = 0; i < 2; i++) {
    printf("%d番目の要素を入力して下さい: ", i + 1);
    scanf("%lf", &pVector[i] );
  }
  printf("\n");
}

/* 行列とベクトルの積を計算する関数 */
void getMtxVecProd2(double*pVectorOut,double pMatrix[][2],double*pVectorIn)
{
  int i, j;
  for(i = 0; i < 2; i++) {
    pVectorOut[i] = 0.0;
    for(j = 0; j < 2; j++) {
      pVectorOut[i] += pMatrix[i][j] * pVectorIn[j];
    }
  }
}

/* 二つのベクトルの差分を計算する関数 */
void getVecDiff2(double*pVectorOut,double*pVectorIn1,double*pVectorIn2)
{
  int i;
  for(i = 0; i < 2; i++) {
    pVectorOut[i] = pVectorIn1[i] - pVectorIn2[i];
  }
}

/* ベクトルの長さ（ノルム）を計算する関数 */
double getNorm2(double*pVector)
{
int i;
double sqrdSum;

/* ベクトルの内積の計算 */
sqrdSum = 0.0;
for(i = 0; i < 2; i++)
  sqrdSum += pVector[i] * pVector[i];

  return sqrt(sqrdSum);
}