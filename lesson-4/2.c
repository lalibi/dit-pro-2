#include <ctype.h>
#include <stdio.h>

int mydigit(char c) {
    /* return c >= '0' && c <= '9'; */

    if (c >= 48 && c <= 57) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char c;

    printf("Enter a character: ");
    scanf("%c", &c);

    printf("isdigit: %d\n", isdigit(c)); /* is digit? 0-9 */
    printf("mydigit: %d\n", mydigit(c)); /* is digit? 0-9 */
    printf("isalpha: %d\n", isalpha(c)); /* is letter? a-z, A-Z */
    printf("isalnum: %d\n", isalnum(c)); /* is letter or digit? a-z, A-Z, 0-9 */
    printf("islower: %d\n", islower(c)); /* is lowercase? a-z */
    printf("isupper: %d\n", isupper(c)); /* is uppercase? A-Z */
    printf("ispunct: %d\n", ispunct(c)); /* is punctuation? */
    printf("isspace: %d\n", isspace(c)); /* is whitespace? ' \n\t\f\v' */
    printf("iscntrl: %d\n", iscntrl(c)); /* is control character? */

    return 0;
}
