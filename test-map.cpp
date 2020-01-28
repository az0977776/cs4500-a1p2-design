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

void object_test() {
    Object* o = new Object();
    Object* o1 = new Object();

    test(!o->equals(o1), "Test not Equals");
    test(o->equals(o), "Test Equals");

    test(o->hash() == o->hash(), "Test hash equals");
    test(o->hash() != o1->hash(), "Test hash not equals");

    delete o;
    delete o1;
    OK("Object Test");
}

void string_test() {
    String* s = new String("ONE");
    String* s1 = new String("TWO");
    String* s2 = new String("ONE");
    String* s3 = new String("");
    String* s4 = new String("ONETWO");

    test(!s->equals(s1), "Test not Equals");
    test(s->equals(s), "Test Equals");
    test(s->equals(s2), "Test Equals other one");

    test(s->hash() == s->hash(), "Test hash equals");
    test(s->hash() == s2->hash(), "Test hash equals other one");

    test(s->size() == 3, "Test length");
    test(s3->size() == 0, "Test length empty");

    test(s->concat(s1)->size() == 6, "Test concat");
    test(s->concat(s1)->equals(s4), "Test concat equals");

    test(s->compare(s1) < 0, "Compare two strings less than");
    test(s1->compare(s) > 0, "Compare two strings greater than");
    test(s->compare(s) == 0, "Compare two strings equal");

    delete s;
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    OK("String Test");
}

void map_test() {
    Object* o = new Object();
    Object* o1 = new Object();
    String* s = new String("ONE");
    String* s1 = new String("TWO");
    String* s2 = new String("");
    String* s3 = new String("ONETWO");
    Map* m = new Map();
    Map* m1 = new Map();

    m->put(s, o);
    m->put(s1, o);
    m->put(s2, o1);
    m->put(s3, o1);

    test(m->get(s)->equals(o), "Get test 1");
    test(m->get(s1)->equals(o), "Get test 2");
    test(m->get(s2)->equals(o1), "Get test 3");
    test(m->get(s3)->equals(o1), "Get test 4");

    test(m->contains(s), "m contains 'ONE'");
    test(!m1->contains(s), "m1 does not contain 'ONE'");

    test(m->size() == 4, "Size of map 1");
    test(m1->size() == 0, "Size of map 2");

    Object *temp = m->remove(s3);
    test(temp->equals(o1), "removed correct object");
    test(m->size() == 3, "Size of map changed");
    temp = m1->remove(s);
    test(temp == nullptr, "remove non-existant key");
    test(m1->size() == 0, "Size of map 2");

    Map* m2 = m->clone();
    test(m2->get(s)->equals(m->get(s)), "Get clone test 1");
    test(m2->get(s1)->equals(m->get(s1)), "Get clone test 2");
    test(m2->get(s2)->equals(m->get(s2)), "Get clone test 3");

    Object** keys = m->get_keys();
    for (int i = 0; i < m->size(); i++) {
        test(m->contains(keys[i]), "Contains the keys");
    }

    m->clear();
    test(m->size() == 0, "Size is 0 after clear");

    delete[] keys;
    
    delete m;
    delete m1;
    delete m2;
    delete s;
    delete s1;
    delete s2;
    delete s3;
    delete o;
    delete o1;
    OK("Map test");
}

int main() {
    object_test();
    string_test();
    map_test();
    return 0;
}