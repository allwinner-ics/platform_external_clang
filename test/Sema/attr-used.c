// RUN: %clang_cc1 -verify -fsyntax-only %s

extern int l0 __attribute__((used)); // expected-warning {{used attribute ignored}}
__private_extern__ int l1 __attribute__((used)); // expected-warning {{used attribute ignored}}

struct __attribute__((used)) s { // expected-warning {{'used' attribute only applies to variable and function types}}
  int x;
};

int a __attribute__((used));

static void __attribute__((used)) f0(void) {
}

void f1() {
  static int a __attribute__((used)); 
  int b __attribute__((used)); // expected-warning {{used attribute ignored}}
}


