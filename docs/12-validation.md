[回首頁](../README.md)

# 驗證狀態與來源

## 已完成與未完成

2026-11-09曾以Arduino AVR Boards 1.8.6、RF24 1.6.1編譯五份程式與Car馬達啟用副本。之後僅把GROUP_ID統一改名為VEHICLE_ID，功能未變；下列用量為改名前的既有紀錄，不能冒稱GitHub線上CI結果。本版沒有自動硬體驗證。

尚未燒錄，也未實測電流、續航、停止距離或RF距離。教師應以實際板卡重新Verify/Upload並依[供電文件](05-power.md)與[個人驗收](07-assessment.md)執行。

```text
Arduino AVR Boards 1.8.6 / RF24 1.6.1 / 2026-11-09
Car (MOTOR_ENABLED=false): Uno, exit=0, flash=4068/32256, RAM=252/2048
PingTx | arduino:avr:nano:cpu=atmega328 | exit=0 | Sketch uses 3722 bytes (12%) of program storage space. Maximum is 30720 bytes. Global variables use 236 bytes (11%) of dynamic memory, leaving 1812 bytes for local variables. Maximum is 2048 bytes.
PingRx | arduino:avr:uno | exit=0 | Sketch uses 3394 bytes (10%) of program storage space. Maximum is 32256 bytes. Global variables use 234 bytes (11%) of dynamic memory, leaving 1814 bytes for local variables. Maximum is 2048 bytes.
Bench | arduino:avr:uno | exit=0 | Sketch uses 3514 bytes (10%) of program storage space. Maximum is 32256 bytes. Global variables use 198 bytes (9%) of dynamic memory, leaving 1850 bytes for local variables. Maximum is 2048 bytes.
Remote | arduino:avr:nano:cpu=atmega328 | exit=0 | Sketch uses 5058 bytes (16%) of program storage space. Maximum is 30720 bytes. Global variables use 244 bytes (11%) of dynamic memory, leaving 1804 bytes for local variables. Maximum is 2048 bytes.
CarEnabled | arduino:avr:uno | exit=0 | Sketch uses 4546 bytes (14%) of program storage space. Maximum is 32256 bytes. Global variables use 252 bytes (12%) of dynamic memory, leaving 1796 bytes for local variables. Maximum is 2048 bytes.

僅編譯檢查；尚未燒錄與實車測試。CarEnabled為暫存編譯副本；交付Car仍維持false。

```

## 技術來源

- [RF24官方常見問題](https://nrf24.github.io/RF24/md_COMMON__ISSUES.html)：供電與通訊排查。
- [RF24官方ACK payload範例](https://nrf24.github.io/RF24/examples_2AcknowledgementPayloads_2AcknowledgementPayloads_8ino-example.html)：預載回報的使用方法。
- [Toshiba TB6612FNG](https://toshiba.semicon-storage.com/tw/semiconductor/product/motor-driver-ics/brushed-dc-motor-driver-ics/detail.TB6612FNG.html)：晶片額定與電氣條件，以資料表及實際模組限制判定。
- [Arduino IDE](https://www.arduino.cc/en/software)。

課程日期、場地與三堂主題依使用者提供的115-1課程企畫書。原PDF與個人／行政資料未上傳。購買來源逐項列在[材料文件](08-materials.md)，歷史標價與庫存不保證維持。
