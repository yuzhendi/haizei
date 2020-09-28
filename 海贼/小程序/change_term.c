/*************************************************************************
	> File Name: change_term.c
	> Author: yu zhen di
	> Mail: 1316215578@qq.com
	> Created Time: 2020年05月28日 星期四 20时28分37秒
 ************************************************************************/
#include <stdio.h>
#include <termios.h>
#define Q "Do you want another try?"

int getresponse();

void tty_mode(int);
void setcrmode();

int main() {
    int response;
    tty_mode(0);
    setcrmode();
    response = getresponse();
    tty_mode(1);
    printf("return val = %d\n", response);
    return response;
}

int getresponse() {
    printf("%s", Q);
    printf("(y/n) : ");
    switch (getchar()) {
        case 'y':
        case 'Y': return 1;
        case 'N':
        case 'n': return 0;
        default: return 0;
    }
}


void setcrmode() {
    struct termios ttystate;
    tcgetattr(0, &ttystate);
    ttystate.c_lflag &= ~ICANON;
    ttystate.c_cc[VMIN] = 1;
    ttystate.c_cc[VTIME] = 1;
    tcsetattr(0, TCSANOW, &ttystate);
}

void tty_mode (int how) {
    static struct termios orignal_mode;
    if (how == 0) {
        tcgetattr(0, &orignal_mode);
    } else {
        tcsetattr(0, TCSANOW, &orignal_mode);
    }
}
