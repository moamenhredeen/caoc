#ifndef ASSERT_H
#define ASSERT_H

#include <stdio.h>
#include <stdlib.h>

#define ASSERT(condition, message) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "Assertion failed: %s\n", message); \
            fprintf(stderr, "File: %s, Line: %d\n", __FILE__, __LINE__); \
            exit(1); \
        } \
    } while (0)

#define ASSERT_EQ(expected, actual, message) \
    do { \
        if ((expected) != (actual)) { \
            fprintf(stderr, "Assertion failed: %s\n", message); \
            fprintf(stderr, "Expected: %d, Actual: %d\n", (expected), (actual)); \
            fprintf(stderr, "File: %s, Line: %d\n", __FILE__, __LINE__); \
            exit(1); \
        } \
    } while (0)

#define ASSERT_NE(not_expected, actual, message) \
    do { \
        if ((not_expected) == (actual)) { \
            fprintf(stderr, "Assertion failed: %s\n", message); \
            fprintf(stderr, "Expected not equal to: %d, Actual: %d\n", (not_expected), (actual)); \
            fprintf(stderr, "File: %s, Line: %d\n", __FILE__, __LINE__); \
            exit(1); \
        } \
    } while (0)

#define ASSERT_TRUE(condition, message) ASSERT((condition), message)

#define ASSERT_FALSE(condition, message) ASSERT(!(condition), message)

#define ASSERT_NULL(ptr, message) \
    do { \
        if ((ptr) != NULL) { \
            fprintf(stderr, "Assertion failed: %s\n", message); \
            fprintf(stderr, "Expected NULL, but got non-NULL pointer\n"); \
            fprintf(stderr, "File: %s, Line: %d\n", __FILE__, __LINE__); \
            exit(1); \
        } \
    } while (0)

#define ASSERT_NOT_NULL(ptr, message) \
    do { \
        if ((ptr) == NULL) { \
            fprintf(stderr, "Assertion failed: %s\n", message); \
            fprintf(stderr, "Expected non-NULL pointer, but got NULL\n"); \
            fprintf(stderr, "File: %s, Line: %d\n", __FILE__, __LINE__); \
            exit(1); \
        } \
    } while (0)

#endif /* ASSERT_H */
