//lang::CwC
#include <stdlib.h>
#include <stdio.h>

#include "object.h"
#include "string.h"
#include "map.h"

/**
 * These functions are used for testing.
 */
void OK(const char* c) { 
    printf("OK: %s\n", c); 
}
void FAIL(const char* c) { 
    printf("FAIL: %s\n", c); 
    abort();
}
void test(bool t, const char* c) {
    if (!t) {
        FAIL(c);
    } else {
        OK(c);
    }
}
bool str_cmp(char* s1, char* s2) {
    if (s1 == nullptr && s2 == nullptr) {
        return true;
    } else if (s1 == nullptr || s2 == nullptr) {
        return false;
    }
    int i = 0;
    for (; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            return false;
        }
    }
    return s1[i] == s2[i];
}

String *s0;
String *s1;
String *s2;
String *s3;
String *s4;
String *s5;
String *s6;
Object *o0;
Object *o1;
Object *o2;

void test_puts_gets() {
    Map* m0 = new Map();

    m0->put(s0, s4);
    m0->put(s1, s4);
    m0->put(s2, s5);
    m0->put(s3, s5);

    test(m0->get(s0)->equals(s4), "Get test 1");
    test(m0->get(s1)->equals(s4), "Get test 2");
    test(m0->get(s2)->equals(s5), "Get test 3");
    test(m0->get(s3)->equals(s5), "Get test 4");
    
    delete m0;
    OK("test puts and gets");
}

void test_contains() {
    Map* m0 = new Map();
    Map* m1 = new Map();

    m0->put(s0, s4);

    test(m0->contains(s0), "m contains key");
    test(!m1->contains(s0), "m1 does not contain key");

    delete m0;
    delete m1;
    OK("test contains");
}

void test_size() {
    Map* m0 = new Map();
    Map* m1 = new Map();

    m0->put(s0, s4);
    m0->put(s1, s4);
    m0->put(s2, s5);
    m0->put(s3, s5);

    test(m0->size() == 4, "Size of map 1");
    test(m1->size() == 0, "Size of map 2");

    delete m0;
    delete m1;
    OK("test size");
}

void test_clear() {
    Map* m0 = new Map();

    m0->put(s0, s4);
    m0->put(s1, s4);
    m0->put(s2, s5);
    m0->put(s3, s5);

    test(m0->size() == 4, "Size of map 1");
    m0->clear();
    test(m0->size() == 0, "Size of map 1 after clear");

    delete m0;
    OK("test clear");
}

void test_remove() {
    Map* m0 = new Map();
    Map* m1 = new Map();

    m0->put(s0, s4);
    m0->put(s1, s4);
    m0->put(s2, s5);
    m0->put(s3, s5);

    Object *temp = m0->remove(s3);
    test(s5->equals(temp), "removed correct object");
    test(m0->size() == 3, "Size of map changed");
    temp = m1->remove(s4);
    test(temp == nullptr, "remove non-existant key");
    test(m1->size() == 0, "Size of map 2");
    
    delete m0;
    delete m1;
    OK("test remove");
}

void test_clone_equality() {
    Map* m0 = new Map();
    Map* m1 = new Map();

    m0->put(s0, s4);
    m0->put(s1, s4);
    m0->put(s2, s5);

    test(!m1->equals(m0), "check not equal");
    Map* m2 = m0->clone();
    test(m2->equals(m0), "check equality of clone");
    test(m2->get(s0)->equals(m0->get(s0)), "Get clone test 1");
    test(m2->get(s1)->equals(m0->get(s1)), "Get clone test 2");
    test(m2->get(s2)->equals(m0->get(s2)), "Get clone test 3");

    delete m0;
    delete m1;
    OK("test clone and equality");
}

void test_overwrite_puts() { 
    Map* m0 = new Map();

    m0->put(o0, o1);
    test(m0->size() == 1, "size check after adding object -> object");
    test(m0->get(o0)->equals(o1), "checking put value");
    m0->put(o0, o2);
    test(m0->size() == 1, "size check after updating value in key-value map");
    test(m0->get(o0)->equals(o2), "overwrite when putting with the same key");
    m0->put(o1, o2);
    test(m0->size() == 2, "size check after adding object -> object 2");

    delete m0;
    OK("test overwrite puts");
}

void test_get_keys() {
    Map* m0 = new Map();

    m0->put(s0, s4);
    m0->put(s1, s4);
    m0->put(s2, s5);
    m0->put(s3, s5);

    Object** keys = m0->get_keys();
    for (int i = 0; i < m0->size(); i++) {
        test(m0->contains(keys[i]), "Contains the keys");
    }

    delete m0;
    delete[] keys;
    OK("test get keys");
}

void test_hash() {
    Map* m0 = new Map();
    Map* m1 = new Map();
    test(m0->equals(m1), "equal");
    test(m0->hash() == m1->hash(), "equal hash if equal");

    m0->put(s0, s1);
    m0->put(s1, s2);
    m1->put(s0, s1);

    test(!m0->equals(m1), "not equal");
    m0->put(s1, s2);
    test(m0->equals(m1), "equal");
    test(m0->hash() == m1->hash(), "equal hash if equal");

    delete m0;
    delete m1;
}

int main() {
    s0 = new String("ONE");
    s1 = new String("TWO");
    s2 = new String("");
    s3 = new String("ONETWO");
    s4 = new String("foo");
    s5 = new String("bar");
    o0 = new Object();
    o1 = new Object();
    o2 = new Object();
    
    test_puts_gets();
    test_contains();
    test_size();
    test_clear();
    test_remove();
    test_clone_equality();
    test_overwrite_puts();
    test_get_keys();

    delete s0;
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;
    delete o0;
    delete o1;
    delete o2;

    OK("test map");
    return 0;
}