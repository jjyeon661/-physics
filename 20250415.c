#include <stdio.h>
#include <math.h>

#define g 9.8 // 중력 가속도 (m/s^2)

int main() {
    double v0 = 100.0;       // 초기 속도 (m/s)
    double angle_deg = 37.0; // 발사 각도 (도)
    double y0 = 140.0;       // 초기 높이 (m)
    double PI = 3.141592;
    // 각도를 라디안으로 변환하기
    double angle_rad = angle_deg * PI / 180.0;

    // 수평 및 수직 초기 속도 성분
    double v0x = v0 * cos(angle_rad);
    double v0y = v0 * sin(angle_rad);

    // (a) 지면에 도달하는 데 걸리는 시간 t 구하기
    // 0 = y0 + v0y * t - 0.5 * g * t^2  이차 방정식
    double a = -0.5 * g;
    double b = v0y;
    double c = y0;

    double dis = b * b - 4 * a * c;
    if (dis < 0) {
        printf("실수 해가 없습니다.\n");
        return 1;
    }

    // 양의 시간 값 선택
    double t1 = (-b + sqrt(dis)) / (2 * a);
    double t2 = (-b - sqrt(dis)) / (2 * a);
    double t = t1 > 0 ? t1 : t2;

    printf("(a) 지면에 도달하는 시간: %.2f 초\n", t);

    // (b) 수평 거리 x 계산
    double x = v0x * t;
    printf("(b) 수평 거리: %.2f m\n", x);

    // (c) 충돌 직전 속도의 x, y 성분
    double vx = v0x;         // 수평 속도는 일정
    double vy = v0y - g * t; // 수직 속도는 변화

    printf("(c) 충돌 직전 속도 성분: vx = %.2f m/s, vy = %.2f m/s\n", vx, vy);

    // (d) 속도 크기 및 충돌각
    double v = sqrt(vx * vx + vy * vy);
    double theta = atan2(vy, vx) * 180.0 / PI; // 속도 방향 각도 (도)

    printf("(d) 속도 크기: %.2f m/s\n", v);
    printf("(e) 충돌 각도 (수평과 이루는 각): %.2f 도\n", theta);

    return 0;
}
