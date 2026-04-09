#include "unity.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void setUp(void) {}
void tearDown(void) {}

void test_practice1_1_cos_approximation_0_5(void) {
    const char* input = "0.0 5\n";  // x = 0.0 (rad), n = 5 (→ 10次まで)

    // 入力ファイルの作成
    FILE* in = fopen("input.txt", "w");
    TEST_ASSERT_NOT_NULL(in);
    fputs(input, in);
    fclose(in);

    // プログラム実行
    FILE* fp = popen("./bin/practice1_1 < input.txt", "r");
    TEST_ASSERT_NOT_NULL(fp);

    char buffer[512] = {0};
    fread(buffer, 1, sizeof(buffer) - 1, fp);
    pclose(fp);
    remove("input.txt");

    TEST_ASSERT_NOT_NULL(strstr(buffer, "cos(0"));

    // 結果チェック（cos(0.0) ≒ 1.0）
    double expctd = 1.00;
    double tol = 0.01;  // 許容誤差
    double actual;
    char* eq_pos = strchr(buffer, '=');

    sscanf(eq_pos + 1, "%lf", &actual);  // "=" 以降の実数を任意の行から抽出
    TEST_ASSERT_DOUBLE_WITHIN(tol, expctd, actual);

}

void test_practice1_1_cos_approximation_1_5(void) {
    const char* input = "1.0 5\n";  // x = 1.0 (rad), n = 5 (→ 10次まで)

    // 入力ファイルの作成
    FILE* in = fopen("input.txt", "w");
    TEST_ASSERT_NOT_NULL(in);
    fputs(input, in);
    fclose(in);

    // プログラム実行
    FILE* fp = popen("./bin/practice1_1 < input.txt", "r");
    TEST_ASSERT_NOT_NULL(fp);

    char buffer[512] = {0};
    fread(buffer, 1, sizeof(buffer) - 1, fp);
    pclose(fp);
    remove("input.txt");

    TEST_ASSERT_NOT_NULL(strstr(buffer, "cos(1"));    

    // 結果チェック（cos(1.0) ≒ 0.5403）
    double expctd = 0.5403;
    double tol = 0.01;  // 許容誤差
    double actual;
    char* eq_pos = strchr(buffer, '=');

    sscanf(eq_pos + 1, "%lf", &actual);  // "=" 以降の実数を任意の行から抽出
    TEST_ASSERT_DOUBLE_WITHIN(tol, expctd, actual);

}

void test_practice1_1_cos_approximation_2_5(void) {
    const char* input = "2.0 5\n";  // x = 2.0 (rad), n = 5 (→ 10次まで)

    // 入力ファイルの作成
    FILE* in = fopen("input.txt", "w");
    TEST_ASSERT_NOT_NULL(in);
    fputs(input, in);
    fclose(in);

    // プログラム実行
    FILE* fp = popen("./bin/practice1_1 < input.txt", "r");
    TEST_ASSERT_NOT_NULL(fp);

    char buffer[512] = {0};
    fread(buffer, 1, sizeof(buffer) - 1, fp);
    pclose(fp);
    remove("input.txt");

    TEST_ASSERT_NOT_NULL(strstr(buffer, "cos(2"));    

    // 結果チェック（cos(2.0) ≒ -0.4161）
    double expctd = -0.4161;
    double tol = 0.01;  // 許容誤差
    double actual;
    char* eq_pos = strchr(buffer, '=');

    sscanf(eq_pos + 1, "%lf", &actual);  // "=" 以降の実数を任意の行から抽出
    TEST_ASSERT_DOUBLE_WITHIN(tol, expctd, actual);
    
}

void test_practice1_1_cos_approximation_pi_5(void) {
    const char* input = "3.14159 5\n";  // x = π (rad), n = 5 (→ 10次まで)

    // 入力ファイルの作成
    FILE* in = fopen("input.txt", "w");
    TEST_ASSERT_NOT_NULL(in);
    fputs(input, in);
    fclose(in);

    // プログラム実行
    FILE* fp = popen("./bin/practice1_1 < input.txt", "r");
    TEST_ASSERT_NOT_NULL(fp);

    char buffer[512] = {0};
    fread(buffer, 1, sizeof(buffer) - 1, fp);
    pclose(fp);
    remove("input.txt");

    TEST_ASSERT_NOT_NULL(strstr(buffer, "cos(3.14"));

    // 結果チェック（cos(π) ≒ -1.0）
    double expctd = -1.00;
    double tol = 0.01;  // 許容誤差
    double actual;
    char* eq_pos = strchr(buffer, '=');

    sscanf(eq_pos + 1, "%lf", &actual);  // "=" 以降の実数を任意の行から抽出
    TEST_ASSERT_DOUBLE_WITHIN(tol, expctd, actual);
}

void test_practice1_1_cos_approximation_4_5(void) {
    const char* input = "4.0 10\n";  // x = 4.0  (rad), n = 10 (→ 10次まで)

    // 入力ファイルの作成
    FILE* in = fopen("input.txt", "w");
    TEST_ASSERT_NOT_NULL(in);
    fputs(input, in);
    fclose(in);

    // プログラム実行
    FILE* fp = popen("./bin/practice1_1 < input.txt", "r");
    TEST_ASSERT_NOT_NULL(fp);

    char buffer[512] = {0};
    fread(buffer, 1, sizeof(buffer) - 1, fp);
    pclose(fp);
    remove("input.txt");

    TEST_ASSERT_NOT_NULL(strstr(buffer, "cos(4"));    

    // 結果チェック（cos(4.0) ≒ -0.6536）
    double expctd = -0.6536;
    double tol = 0.01;  // 許容誤差
    double actual;
    char* eq_pos = strchr(buffer, '=');

    sscanf(eq_pos + 1, "%lf", &actual);  // "=" 以降の実数を任意の行から抽出
    TEST_ASSERT_DOUBLE_WITHIN(tol, expctd, actual);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_practice1_1_cos_approximation_0_5);
    RUN_TEST(test_practice1_1_cos_approximation_1_5);
    RUN_TEST(test_practice1_1_cos_approximation_2_5);
    RUN_TEST(test_practice1_1_cos_approximation_pi_5);
    RUN_TEST(test_practice1_1_cos_approximation_4_5);
    return UNITY_END();
}
