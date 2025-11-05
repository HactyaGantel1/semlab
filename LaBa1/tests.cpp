#define CATCH_CONFIG_MAIN
#define _CRT_SECURE_NO_WARNINGS
#include "catch.hpp"
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>

#include "../include/string_processor.h"

using namespace std;

string read_file() {
    char res[256];
    FILE* in = fopen("data/output.txt", "r");
    if (in && fgets(res, 256, in) != NULL) {
        fclose(in);
    }
    return res;
}

void write_file(const char str[]) {
    FILE* out = fopen("data/input.txt", "w");
    if (!out) return;
    fputs(str, out);
    fclose(out);
}

TEST_CASE("Array String Processing: Empty string", "[array_string]") {
    char str[256] = "";
    processCharArray(str);
    REQUIRE(strcmp(str, "") == 0);
}

TEST_CASE("Array String Processing: No digits in words", "[array_string]") {
    char str[256] = "hello world test";
    processCharArray(str);
    REQUIRE(strcmp(str, "hello world test") == 0);
}

TEST_CASE("Array String Processing: Words with even letters and digits", "[array_string]") {
    char str[256] = "ab12 cd34 ef56";
    processCharArray(str);
    REQUIRE(strcmp(str, "21ba 43cd 65ef") == 0);
}

TEST_CASE("Array String Processing: Words with odd letters and digits remain unchanged", "[array_string]") {
    char str[256] = "abc123 def456 ghi789";
    processCharArray(str);
    REQUIRE(strcmp(str, "abc123 def456 ghi789") == 0);
}

TEST_CASE("Array String Processing: Mixed case", "[array_string]") {
    char str[256] = "Hello123 World45 Test 678Word9 Simple";
    processCharArray(str);
    REQUIRE(strcmp(str, "Hello123 World45 Test 9droW876 Simple") == 0);
}

TEST_CASE("Array String Processing: Single word with even letters and digits", "[array_string]") {
    char str[256] = "test1234";
    processCharArray(str);
    REQUIRE(strcmp(str, "4321tset") == 0);
}

TEST_CASE("Array String Processing: Single word with odd letters and digits", "[array_string]") {
    char str[256] = "hello123";
    processCharArray(str);
    REQUIRE(strcmp(str, "hello123") == 0);
}

TEST_CASE("C String Processing: Empty string", "[c_string]") {
    char str[256] = "";
    processCString(str);
    REQUIRE(strcmp(str, "") == 0);
}

TEST_CASE("C String Processing: No digits in words", "[c_string]") {
    char str[256] = "hello world test";
    processCString(str);
    REQUIRE(strcmp(str, "hello world test") == 0);
}

TEST_CASE("C String Processing: Words with even letters and digits", "[c_string]") {
    char str[256] = "ab12 cd34 ef56";
    processCString(str);
    REQUIRE(strcmp(str, "21ba 43cd 65ef") == 0);
}

TEST_CASE("C String Processing: Words with odd letters and digits remain unchanged", "[c_string]") {
    char str[256] = "abc123 def456 ghi789";
    processCString(str);
    REQUIRE(strcmp(str, "abc123 def456 ghi789") == 0);
}

TEST_CASE("C String Processing: Mixed case", "[c_string]") {
    char str[256] = "Hello123 World45 Test 678Word9 Simple";
    processCString(str);
    REQUIRE(strcmp(str, "Hello123 World45 Test 9droW876 Simple") == 0);
}

TEST_CASE("C String Processing: Single word with even letters and digits", "[c_string]") {
    char str[256] = "test1234";
    processCString(str);
    REQUIRE(strcmp(str, "4321tset") == 0);
}

TEST_CASE("C String Processing: Single word with odd letters and digits", "[c_string]") {
    char str[256] = "hello123";
    processCString(str);
    REQUIRE(strcmp(str, "hello123") == 0);
}

TEST_CASE("File String Processing: Empty file", "[file_string]") {
    write_file("");
    system("cd bin && variant3.exe");
    string result = read_file();
    REQUIRE(result == "");
}

TEST_CASE("File String Processing: No digits in words", "[file_string]") {
    write_file("hello world test");
    system("cd bin && variant3.exe");
    string result = read_file();
    REQUIRE(result == "hello world test");
}

TEST_CASE("File String Processing: Words with even letters and digits", "[file_string]") {
    write_file("ab12 cd34 ef56");
    system("cd bin && variant3.exe");
    string result = read_file();
    REQUIRE(result == "21ba 43cd 65ef");
}
TEST_CASE("File String Processing: Words with odd letters and digits remain unchanged", "[file_string]") {
    write_file("abc123 def456 ghi789");
    system("cd bin && variant3.exe");
    string result = read_file();
    REQUIRE(result == "abc123 def456 ghi789");
}

TEST_CASE("File String Processing: Mixed case", "[file_string]") {
    write_file("Hello123 World45 Test 678Word9 Simple");
    system("cd bin && variant3.exe");
    string result = read_file();
    REQUIRE(result == "Hello123 World45 Test 9droW876 Simple");
}

TEST_CASE("File String Processing: Single word with even letters and digits", "[file_string]") {
    write_file("test1234");
    system("cd bin && variant3.exe");
    string result = read_file();
    REQUIRE(result == "4321tset");
}

TEST_CASE("File String Processing: Single word with odd letters and digits", "[file_string]") {
    write_file("hello123");
    system("cd bin && variant3.exe");
    string result = read_file();
    REQUIRE(result == "hello123");
}
