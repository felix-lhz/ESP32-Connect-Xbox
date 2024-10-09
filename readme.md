# ESP32-Connect-XBOX

A repository for connecting ESP32 to XBOX controllers via Bluetooth.

## 基本配置

- vscode+platformIO
- ESP32-S3-1-WROOM-N16R8

###### platformIO配置

[ESP32-S3-N16R8在platformio中的开发板设置_platformio n16r8-CSDN博客](https://blog.csdn.net/CD391/article/details/139878023#:~:text=ESP32-S3-N)

```platformio.ini增加
board_build.arduino.partitions = default_16MB.csv
board_build.arduino.memory_type = qio_opi
build_flags = -DBOARD_HAS_PSRAM
board_upload.flash_size = 16MB

;开源库
lib_deps = h2zero/NimBLE-Arduino@^1.4.2
```

```验证配置修改是否生效
  Serial.begin(115200);
  Serial.printf("Deafult free size: %d\n", heap_caps_get_free_size(MALLOC_CAP_DEFAULT));
  Serial.printf("PSRAM free size: %d\n", heap_caps_get_free_size(MALLOC_CAP_SPIRAM));
  Serial.printf("Flash size: %d bytes\n", ESP.getFlashChipSize());
```

###### 蓝牙地址修改

```修改位置
// Required to replace with your xbox address
// 需要在此替换成自己的手柄蓝牙MAC地址
XboxSeriesXControllerESP32_asukiaaa::Core
    xboxController("0c:35:26:e6:90:d9");
```

###### 查找xbox手柄蓝牙MAC地址

- 电脑蓝牙连接XBOX
- `Ctrl+x`->设备管理器->Xbox Wireless controller->右键->属性->详细信息->“蓝牙设备地址”

## References

[xiaocainiao11111/ESP32_connect_XboxController: ESP32通过蓝牙连接Xbox手柄读取所有的信号 (github.com)](https://github.com/xiaocainiao11111/ESP32_connect_XboxController?tab=readme-ov-file)

[arduino-XboxSeriesXControllerESP32 (XboxSeriesXControllerESP32_asukiaaa) (github.com)](https://github.com/asukiaaa/arduino-XboxSeriesXControllerESP32)

[arduino-XboxSeriesXReportBuilder(XboxSeriesXHIDReportBuilder_asukiaaa) (github.com)](https://github.com/asukiaaa/arduino-XboxSeriesXHIDReportBuilder)

[arduino-XboxControllerNotificationParser (github.com)](https://github.com/asukiaaa/arduino-XboxControllerNotificationParser)