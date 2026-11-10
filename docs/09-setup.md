[回首頁](../README.md)

# 安裝與程式下載

## 每人準備

一台Windows/macOS/Linux電腦、能傳資料的Nano與Uno USB線。兩個USB資料埠可同時連接兩塊板；埠不足時用有足夠供電的USB集線器。暫不接VM電池。

## 安裝

1. 從[Arduino官方軟體頁](https://www.arduino.cc/en/software)下載Arduino IDE。
2. Boards Manager搜尋並安裝`Arduino AVR Boards`。此專案既有編譯證據用1.8.6。
3. Library Manager搜尋`RF24`，選TMRh20維護版本。既有驗證使用1.6.1。
4. 接上Nano，選Arduino Nano / ATmega328P與它的序列埠。相容板可能需要`ATmega328P (Old Bootloader)`；以供應商說明為準。Uno選Arduino Uno。
5. CH340板若沒有序列埠，依供應商提供的正式驅動安裝流程處理；先排除充電專用線與USB埠問題。

## 開啟資料夾

```text
sketches/
  PingTx/PingTx.ino    第1堂Nano
  PingRx/PingRx.ino    第1堂Uno
  Bench/Bench.ino      第2堂Uno
  Remote/Remote.ino    第3堂Nano
  Car/Car.ino          第3堂Uno
```

`.ino`檔名與資料夾名必須相同。Arduino詢問是否建立同名資料夾時，確認後再開啟；不要把五份範例合併進同一個sketch。

## 個人車號

```cpp
const uint8_t VEHICLE_ID = 1; // 每人選1至10的不同車號
```

自己的遙控端與車端相同；全班每人不同。第1堂兩端用PingTx/PingRx，第3堂兩端用Remote/Car；不可混用不同階段的封包格式。車號超過10請由教師另規劃頻道，不直接填大數字。

## 上傳與監控

先選板卡與序列埠，按Verify確認編譯，再按Upload。上傳前關閉占用同一序列埠的監控程式。上傳後以115200 baud開序列監控。可在同一電腦輪流選兩個埠查看兩端紀錄；截圖請標明Nano或Uno。

首次先跑第1堂，不接馬達電源。第2堂Bench使用Uno D12接SW；第3堂必須移回Nano D2。
