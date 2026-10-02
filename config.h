#pragma once

// ---------- LCD1602 / PCF8574T ----------
static constexpr int I2C_SDA_PIN = 8;
static constexpr int I2C_SCL_PIN = 9;
static constexpr uint32_t I2C_CLOCK_HZ = 250000;

static constexpr uint8_t LCD_COLUMNS = 16;
static constexpr uint8_t LCD_ROWS = 2;
static constexpr uint8_t LCD_PCF8574_ADDRESS = 0x27;
static constexpr uint8_t LCD_PCF8574_RS_MASK = 0x01;  // P0
static constexpr uint8_t LCD_PCF8574_EN_MASK = 0x04;  // P2
static constexpr uint8_t LCD_PCF8574_BL_MASK = 0x08;  // P3, active high

#define SHOW_SECONDS 1
#if SHOW_SECONDS != 0 && SHOW_SECONDS != 1
#error "SHOW_SECONDS must be 0 or 1"
#endif

// ---------- HH:MM animation ----------
#define HHMM_ANIMATION_NONE        0
#define HHMM_ANIMATION_PIXEL_SCAN  1
#define HHMM_ANIMATION_SPLIT_FLIP  2

#define HHMM_ANIMATION_MODE HHMM_ANIMATION_SPLIT_FLIP
#if HHMM_ANIMATION_MODE != HHMM_ANIMATION_NONE && \
    HHMM_ANIMATION_MODE != HHMM_ANIMATION_PIXEL_SCAN && \
    HHMM_ANIMATION_MODE != HHMM_ANIMATION_SPLIT_FLIP
#error "Invalid HHMM_ANIMATION_MODE"
#endif

static constexpr uint32_t HHMM_FLIP_PHASE_MS = 100;

// ---------- Wi-Fi profile ----------
#define NETWORK_MODE_ENTERPRISE_EAP 1
#define NETWORK_MODE_WPA2_PERSONAL  2
#define NETWORK_MODE NETWORK_MODE_WPA2_PERSONAL

#if NETWORK_MODE != NETWORK_MODE_ENTERPRISE_EAP && NETWORK_MODE != NETWORK_MODE_WPA2_PERSONAL
#error "NETWORK_MODE must be NETWORK_MODE_ENTERPRISE_EAP or NETWORK_MODE_WPA2_PERSONAL"
#endif

// ---------- Time and NTP ----------
static constexpr char TIMEZONE[] = "CST-8";
static constexpr char NTP_PRIMARY[] = "ntp.aliyun.com";
static constexpr char NTP_SECONDARY[] = "time.cloudflare.com";
static constexpr char NTP_TERTIARY[] = "cn.pool.ntp.org";

// 👇 开机最多尝试连接 WiFi 的次数
static constexpr uint8_t WIFI_MAX_ATTEMPTS = 3;

static constexpr uint32_t WIFI_CONNECT_TIMEOUT_MS = 30000;
// 👇 每次失败后，等待 5 秒再试下一次
static constexpr uint32_t WIFI_RETRY_DELAY_MS = 5000;
static constexpr uint32_t WIFI_STATUS_HOLD_MS = 3000;
static constexpr uint32_t NTP_FIRST_SYNC_TIMEOUT_MS = 20000;

// 最小保存间隔改为1小时（3600秒）
static constexpr uint32_t TIME_SAVE_MIN_INTERVAL_SEC = 3600;

static constexpr uint32_t PIXEL_SCAN_FRAME_MS = 60;
static constexpr uint32_t SECOND_SCAN_FRAME_MS = PIXEL_SCAN_FRAME_MS / 2U;

static constexpr time_t MIN_VALID_EPOCH = 1704067200;
