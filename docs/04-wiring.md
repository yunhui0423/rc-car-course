[回課程首頁](../README.md) · [材料清單](08-materials.md) · [程式下載](../sketches/README.md)

# 接線表｜兩端共用 SPI

適用：ATmega328P Nano + Uno R3；TB6612FNG 直控板


## 兩片 nRF24L01+ 分別接各自的 Arduino

| RF／轉接板標示 | Nano與Uno腳位 | 注意 |
|---|---|---|
| AMS1117 模組 VIN / IN+ | Arduino 5V | 選3.3V輸出模組；不是5V輸出型 |
| 裸 RF VCC | 穩壓後3.3V | 不可直接接5V；確認轉接板輸出 |
| GND | GND | RF旁100uF與0.1uF並聯至3.3V/GND；AMS1117輸出接RF VCC，各GND共地 |
| CE / CSN | D7 / D8 | 與 RF24 radio(7,8) 對應 |
| SCK / MOSI / MISO | D13 / D11 / D12 | SPI固定腳位；IRQ不接 |


## 遙控端 Nano 與搖桿

| 搖桿 | Nano | 功能 |
|---|---|---|
| VCC / GND | 5V / GND | 供電 |
| VRx / VRy | A0 / A1 | 轉向／油門；依模組方向調整符號 |
| SW | D2 | INPUT_PULLUP，按下為LOW |


## 車端 Uno 與 TB6612FNG

| 驅動板 | Uno／電源 | 說明 |
|---|---|---|
| VCC / GND | 5V / 共地GND | VCC為邏輯電源，非馬達電源 |
| VM | 4顆AA鎳氫串聯正極經開關 | 標稱4.8V；負極到共地GND |
| PWMA / AIN1 / AIN2 | D5 / D2 / D3 | A通道為左馬達 |
| PWMB / BIN1 / BIN2 | D6 / D9 / D10 | B通道為右馬達 |
| STBY | D4；另10kΩ接GND | 上電預設待機 |
| AO1、AO2 / BO1、BO2 | 左馬達兩線 / 右馬達兩線 | 品牌可能標 A01/A02 等，以板圖核對 |

Nano D2 是搖桿按鍵；Uno D2 是馬達方向，分屬不同板。只有第2堂 Bench 暫把搖桿 SW 接 Uno D12，此時不使用 RF。第3堂必須移回 Nano D2，避免與 Uno SPI 的 MISO 衝突。

馬達端子與 VM 主電流採端子台、焊線及22AWG線；麵包板、杜邦線只走邏輯訊號。RF接線盡量短，遠離馬達導線與驅動板。
