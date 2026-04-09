#include "unity.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void setUp(void) {}
void tearDown(void) {}

void test_practice1_2_a1_b0_c_1(void) {
    const char* input = "1 \n 0 \n -1\n";  // a = 1, b = 0, c = -1

    // 入力ファイルの作成
    FILE* in = fopen("input.txt", "w");
    TEST_ASSERT_NOT_NULL(in);
    fputs(input, in);
    fclose(in);

    // プログラム実行
    FILE* fp = popen("./bin/practice1_2 < input.txt", "r");
    TEST_ASSERT_NOT_NULL(fp);

    char buffer[1024] = {0};
    fread(buffer, 1, sizeof(buffer) - 1, fp);
    pclose(fp);
    remove("input.txt");

    // 結果チェック
    double expctdX1 = 1;
    double expctdX2 = -1;
    double tol = 0.01;  // 許容誤差
    double actualX1, actualX2;;

    char* eq_pos1 = strstr(buffer, "x1 =");

    sscanf(eq_pos1 + 4, "%lf", &actualX1);  // "x1 =" 以降の実数を任意の行から抽出
    TEST_ASSERT_DOUBLE_WITHIN(tol, expctdX1, actualX1);
    
    char* eq_pos2 = strstr(buffer, "x2 =");
    sscanf(eq_pos2 + 4, "%lf", &actualX2);  // "x2 =" 以降の実数を任意の行から抽出
    TEST_ASSERT_DOUBLE_WITHIN(tol, expctdX2, actualX2);

}


void test_practice1_2_a1_b2_c1(void) {
    const char* input = "1 \n 2 \n 1\n";  // a = 1, b = 2, c = 1

    // 入力ファイルの作成
    FILE* in = fopen("input.txt", "w");
    TEST_ASSERT_NOT_NULL(in);
    fputs(input, in);
    fclose(in);

    // プログラム実行
    FILE* fp = popen("./bin/practice1_2 < input.txt", "r");
    TEST_ASSERT_NOT_NULL(fp);

    char buffer[1024] = {0};
    fread(buffer, 1, sizeof(buffer) - 1, fp);
    pclose(fp);
    remove("input.txt");

    // 結果チェック
    double expctdX = -1;
    double tol = 0.01;  // 許容誤差
    double actualX;

    char* eq_pos = strstr(buffer, "x  =");

    sscanf(eq_pos + 4, "%lf", &actualX);  // "x  =" 以降の実数を任意の行から抽出
    TEST_ASSERT_DOUBLE_WITHIN(tol, expctdX, actualX);
    
}   

void test_practice1_2_a1_b0_c1(void) {
    const char* input = "1 \n 0 \n 1\n";  // a = 1, b = 0, c = 1

    // 入力ファイルの作成
    FILE* in = fopen("input.txt", "w");
    TEST_ASSERT_NOT_NULL(in);
    fputs(input, in);
    fclose(in);

    // プログラム実行
    FILE* fp = popen("./bin/practice1_2 < input.txt", "r");
    TEST_ASSERT_NOT_NULL(fp);

    char buffer[1024] = {0};
    fread(buffer, 1, sizeof(buffer) - 1, fp);
    pclose(fp);
    remove("input.txt");

    // 結果チェック
    char* eq_pos1 = strstr(buffer, "x1 ="); 
    TEST_ASSERT_NOT_NULL(strchr(eq_pos1, 'j'));  // "x1 =" 以降に 'j' が含まれるか確認
    
    char* eq_pos2 = strstr(buffer, "x2 =");
    TEST_ASSERT_NOT_NULL(strchr(eq_pos2, 'j'));  // "x2 =" 以降に 'j' が含まれるか確認

}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_practice1_2_a1_b0_c_1);
    RUN_TEST(test_practice1_2_a1_b2_c1);
    RUN_TEST(test_practice1_2_a1_b0_c1);        
    return UNITY_END();
}
