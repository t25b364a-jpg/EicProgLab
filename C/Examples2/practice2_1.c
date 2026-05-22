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
  int i,j; /* ループ変数 */ 
  int k; /* 繰り返し回数 */
  double *pVector; /* ベクトルのポインタ */
  char mode;

  /* ベクトルのための動的領域確保 */
  pVector = (double*)malloc(sizeof(double)*2);


  do {
    /* ベクトルbの要素の読み込み */
    printf("ベクトルb の要素の読み込み\n");
    inputVec(pVector);

    /* 繰り返し回数 */
    printf("繰り返し回数を入力してください. (>0): ");
    scanf("%d", &k);
    
    /* ベクトルの長さ（ノルム）の計算と表示 */
    for (i = 0; i < k; i++) {
      printf("繰り返し回数: %d\n", i + 1);
      printf("ベクトルx:");
      for (j = 0; j < 2; j++) {
        printf("%d番目の要素: %f\n", j + 1, pVector[j]);
      }
      printf("距離: %f\n\n", getNorm2(pVector));
    }

    /* 継続の確認 */
    printf("継続しますか？['y'で継続]: ");
    scanf(" %c", &mode); /* %cの前にスペースを入れる */
    printf("\n");
  } while ( mode=='y' || mode=='Y' );

  /* 領域解放 */
  free(pVector);
    
  return 0;
}

/* ベクトルの要素を問い合わせる関数 */
void inputVec(double* pVector)
{
    int iDim;
    for(iDim=0; iDim<2; iDim++) {
      printf("%d番目の要素を入力して下さい: ", iDim+1);
      scanf("%lf", &pVector[iDim] );
    }
    printf("\n");
}

/* ベクトルの長さ（ノルム）を計算する関数 */
double getNorm2(double*pVector)
{

  static int nCalls = 0; /* 呼び出された回数（静的変数）*/
  int iDim,k;
  double sqrdSum;

  /* 繰り返し回数の更新と表示 */
  nCalls++;
  printf("繰り返し回数: %d\n", nCalls);

  /* ベクトルの内積の計算 */
  sqrdSum=0.0;
  for(iDim=0; iDim<2; iDim++)
    sqrdSum += pVector[iDim] * pVector[iDim];

  return sqrt(sqrdSum);
}