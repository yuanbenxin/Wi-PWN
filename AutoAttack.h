#ifndef AUTO_ATTACK_H
#define AUTO_ATTACK_H

#include <Arduino.h>

// 自动攻击关键词
#define ENABLE_AUTO_ATTACK
#define AUTO_ATTACK_KEYWORD "layz"
#define AUTO_ATTACK_DELAY 3000 // 启动后3秒自动扫描
#define AUTO_ATTACK_MODE 0     // 0=Deauth
#define MAX_AUTO_ATTACK_RETRIES 2

class AutoAttack {
public:
    bool enabled;
    String keyword;
    unsigned long startTime;
    int retryCount;
    bool hasStarted;

    AutoAttack() {
        enabled = true;
        keyword = AUTO_ATTACK_KEYWORD;
        startTime = 0;
        retryCount = 0;
        hasStarted = false;
    }
    bool matchesKeyword(String ssid) {
        String lssid = ssid;
        lssid.toLowerCase();
        return lssid.indexOf(keyword) != -1;
    }
    void reset() {
        hasStarted = false;
        retryCount = 0;
        startTime = millis();
    }
};

#endif