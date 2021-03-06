#ifndef SHOULD_H
#define SHOULD_H

#include <stdio.h>

// Functions in the external API.
void should_h(int, char *);
void should_h1(char *);
void should_h2(char *);
void should_h3(char *);
int should_passed_count();
int should_failed_count();
void should_print_stats();

// Internal function for handling indentation.
static void indent(int count);

// For stats.
static int passed_count = 0, failed_count = 0;

// For pretty output.
static const char *tick = "\u2713",
                 *cross = "\u2717",
                 *arrow = "\u279c";

static const char *red = "\x1b[31m",
                *green = "\x1b[32m",
                 *blue = "\x1b[34m",
                  *end = "\x1b[0m";

int current_indent_level = 0;

// Macros for external use.
#define should(expr) do { \
    int result = (expr); \
    if(result) { \
        __should_passed("%s should be truthy", #expr); \
    } else { \
        __should_failed("Expected %s to be truthy, but it's %d", \
                         #expr, result); \
    } \
} while(0);

#define should_not(expr) do { \
    int result = (expr); \
    if(result) { \
        __should_failed("Expected %s to be falsy, but it's %d", \
                         #expr, result); \
    } else { \
        __should_passed("%s should be falsy", #expr); \
    } \
} while(0);

#define should_eq(lhs, rhs) do { \
    int lhs_result = (lhs), rhs_result = (rhs); \
    if(lhs == rhs) { \
        __should_passed("%s should be equal to %s", #lhs, #rhs); \
    } else { \
        __should_failed("Expected %s to be equal to %s, but %d != %d", \
                         #lhs, #rhs, lhs_result, rhs_result); \
    } \
} while(0);

#define should_not_eq(lhs, rhs) do { \
    int lhs_result = (lhs), rhs_result = (rhs); \
    if(lhs != rhs) { \
        __should_passed("%s should not be equal to %s", #lhs, #rhs); \
    } else { \
        __should_failed("Expected %s to not be equal to %s, but %d == %d", \
                         #lhs, #rhs, lhs_result, rhs_result); \
    } \
} while(0);

// Macros for internal use.
#define __should_passed(format, ...) do { \
    passed_count++; \
    indent(current_indent_level); \
    fprintf(stdout, "%s%s  ", green, tick); \
    fprintf(stdout, format, __VA_ARGS__); \
    fprintf(stdout, "\n"); \
    printf("%s", end); \
} while(0);

#define __should_failed(format, ...) do { \
    failed_count++; \
    indent(current_indent_level); \
    fprintf(stdout, "%s%s  ", red, cross); \
    fprintf(stdout, format, __VA_ARGS__); \
    fprintf(stdout, " (%s:%d)\n", __FILE__, __LINE__); \
    printf("%s", end); \
} while(0);

void should_h(int level, char *message) {
    indent(level - 1);
    printf("%s%s  %s%s\n", blue, arrow, message, end);
    current_indent_level = level;
}

void should_h1(char *message) {
    should_h(1, message);
}

void should_h2(char *message) {
    should_h(2, message);
}

void should_h3(char *message) {
    should_h(3, message);
}

int should_passed_count() {
    return passed_count;
}

int should_failed_count() {
    return failed_count;
}

void should_print_stats() {
    printf("\n%s   %s  %d assertions, %d failures.%s\n",
            failed_count ? red : green,
            failed_count ? cross : tick,
            passed_count + failed_count,
            failed_count,
            end);
}

static void indent(int count) {
    int i;
    for(i = 0; i < count; i++) {
        printf("    ");
    }
}

#endif
