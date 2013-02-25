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
