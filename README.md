# should.c [![Build Status](https://travis-ci.org/utkarshkukreti/should.c.png)](https://travis-ci.org/utkarshkukreti/should.c)

should.c is a mini testing framework for C, which also happens to be pretty.

![screenshot](https://dl.dropbox.com/u/2164813/github/utkarshkukreti/should.c/screenshot.png)

## Usage

Add this repository as a submodule in your project, or just copy over should.h
from include folder (make sure to check this repo for updates).

Add the folder containing `should.h` to your compiler's include path. In
gcc/clang this would be something like
`-I path/to/the/folder/which/contains/should.h`.

Below is an annotated example of using this framework, the screenshot of which
is showcased above.

```c
#include <should.h>

int main() {
    // should_h1, h2, h3 indent the assertions that follow to that level.
    should_h1("A demo of should.c");
    // Braces are nothing special, just simple C blocks.
    // They make reading the file easier for humans, and also scopes the
    // variables declared inside to be present only inside the block.
    {
        should_h2("should() and should_not()");
        {
            // should(expr) checks if expr evaluates to a truthy value,
            // that is, !!expr == 1
            // should_not(expr) checks if expr evaluates to a falsy value,
            // that is, !!expr == 0
            should_h3("Plain values");
            {
                should(7);
                should_not(0);

                int yes = 1;
                should(yes);
            }

            should_h3("Adding things");
            {
                should(1 + 2 == 3);
                should_not(1 + 2 == 4);
            }

            should_h3("Multiplying things");
            {
                should(3 * 4 == 12);
            }

            should_h3("These tests deliberately fail");
            {
                should(2 < 0);
                should_not(6 < 7);
            }
        }

        should_h2("should_eq() and should_not_eq()");
        {
            // should_eq and should_not_eq checks if the 2 passed integers are
            // equal or not equal respectively.
            should_eq(10, 10);
            should_eq(1 + 3, 2 + 2);

            should_not_eq(2 * 7, 2 + 7);

            should_h3("These should fail");
            {
                should_eq(2 + 3, 2 - 3);
                should_not_eq(2 * 2, 2 + 2);
            }
        }

        should_h2("should_passed_count(), should_failed_count()");
        {
            // should_passed_count() returns the number of passed assertions
            // till now.
            should(should_passed_count() > 5);
            // should_failed_count() returns the number of assertion failures
            // till now.
            // We know we've made atleast 1 test fail.
            should(should_failed_count() > 0);
        }
    }

    // Print some useful stats, like number of assertions, and number of
    // failures
    should_print_stats();
}
```
