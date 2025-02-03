#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <ctype.h>

// UART 포트를 설정하는 함수
int setup_uart(const char *device) {
    int uart = open(device, O_RDWR | O_NOCTTY | O_NDELAY);  // 포트 열기
    if (uart == -1) {
        perror("Unable to open UART");
        exit(1);
    }

    struct termios options;
    tcgetattr(uart, &options);

    // 보드레이트 설정 (115200)
    cfsetispeed(&options, B115200);
    cfsetospeed(&options, B115200);

    // 패리티, 데이터 비트, 스톱 비트 설정
    options.c_cflag &= ~PARENB;   // 패리티 비트 비활성화
    options.c_cflag &= ~CSTOPB;   // 1비트 스톱 비트
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;       // 8 비트 데이터 비트
    options.c_cflag &= ~CRTSCTS;  // 흐름 제어 비활성화
    options.c_cflag |= CREAD | CLOCAL; // 읽기 활성화, 로컬 연결

    // 설정을 적용
    tcsetattr(uart, TCSANOW, &options);
    return uart;
}

int main() {
    // UART 포트 설정
    const char *device = "/dev/serial0";  // 사용하려는 포트
    int uart = setup_uart(device);

    char received_char;

    printf("UART 통신 시작...\n");

    while (1) {
        // 데이터가 들어오기를 기다리며 읽기
        int n = read(uart, &received_char, 1);
        if (n > 0) {
            // 받은 문자를 화면에 출력
            printf("받은 문자: %c\n", received_char);

            // 받은 문자를 그대로 다시 송신
            write(uart, &received_char, 1);
        }
    }

    close(uart);  // UART 포트 닫기
    return 0;
}

