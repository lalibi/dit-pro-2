#include <stdio.h>

int main() {
    int x = 123;
    const int y = 456;

    int *const p = &x;       /* (int *const – const δείκτης σε int) */
    const int *q = &y;       /* (δείκτης σε έναν const int) */
    const int *const r = &y; /* (const δείκτης σε const int) */

    /*p += 1;  Δεν επιτρέπεται */
    q += 1; /* Επιτρέπεται αλλά δεν έχει νόημα */
    /**q += 1;  Δεν επιτρέπεται */

    return 0;
}
