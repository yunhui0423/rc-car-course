# 無線遙控車｜從第一個封包到整車行駛

**每人獨立製作一台車與一支遙控器，不分組。**

使用 Arduino Nano、Uno R3、nRF24L01+ 與 TB6612FNG，依序完成無線傳輸、搖桿與馬達控制、雙向狀態回傳。適合具備基本 Arduino 操作經驗的初學者。

| 課程 | 日期／時間 | 開始閱讀 | 實作程式 |
|---|---|---|---|
| 第1堂：2.4GHz與單向應用資料 | 2026/12/03 19:10-21:20 | [第一堂](docs/01-radio.md) | [PingTx](sketches/PingTx/PingTx.ino)／[PingRx](sketches/PingRx/PingRx.ino) |
| 第2堂：搖桿、PWM與馬達 | 2026/12/10 19:10-21:20 | [第二堂](docs/02-motors.md) | [Bench](sketches/Bench/Bench.ino) |
| 第3堂：整車遙控與雙向回傳 | 2026/12/17 19:10-21:20 | [第三堂](docs/03-integration.md) | [Remote](sketches/Remote/Remote.ino)／[Car](sketches/Car/Car.ino) |

每堂130分鐘。地點：淡江大學工學大樓E302。數量暫以10人份規劃，人數變動按每人材料用量調整。

## 先從這裡開始

1. [個人材料與實際購買連結](docs/08-materials.md)：先準備一套首件，確認後再採購其餘材料。
2. [安裝與下載程式](docs/09-setup.md)：每人一台電腦，兩個可供電USB資料埠。
3. [完整接線表](docs/04-wiring.md)與[供電檢查](docs/05-power.md)：未檢查前不接馬達電源。
4. 依上表完成三堂課，使用[練習題](docs/10-exercises.md)整理結果。
5. [個人驗收](docs/07-assessment.md)與[交件模板](templates/submission.md)：每人獨立提交。

```mermaid
flowchart LR
    J[搖桿與按鍵] --> N[Nano 遙控端]
    N --> T[nRF24L01+]
    T -->|命令封包| R[nRF24L01+]
    R --> U[Uno 車端]
    U --> D[TB6612FNG]
    D --> M[左右兩顆馬達]
    R -.->|下次 ACK 回傳前次處理狀態| T
```

## 本版硬體配置

- 2WD兩輪差速底盤；每人兩顆馬達。購買底盤套件時確認馬達、輪子與萬向輪已包含。
- RF供電採獨立AMS1117 **3.3V輸出**模組，5V輸入；輸出接RF VCC。這不是TTL串口轉接器。
- 馬達以四顆AA鎳氫串聯供電；Arduino邏輯由USB供電。車端共地，正極分開。
- 本版程式僅支援直接引出PWMA、PWMB、STBY的TB6612FNG，不可直接套L298N或Grove I2C驅動板。

## 開始實作前要知道

`Car.ino`預設`MOTOR_ENABLED = false`。由教師核對供電、架空車輪測試後，才改成`true`。開機／失聯後須先置中並放開按鍵，之後按住按鍵才能行駛。超過500ms未收到有效命令會下達停車；實車仍有滑行距離。

回傳值是前次命令處理後的PWM與停止狀態，**不是實測車速或電量**。

[編譯驗證紀錄](docs/12-validation.md)：五份範例及Car啟用版本已有編譯通過紀錄，尚未燒錄與實車測試。供電、電流、無線穩定度與斷訊停止須由教師實測。

## 全部文件

- [無線遙控車｜完整教學與採購](docs/00-overview.md)
- [第1堂｜2.4GHz 與單向通訊](docs/01-radio.md)
- [第2堂｜搖桿、PWM 與馬達](docs/02-motors.md)
- [第3堂｜整車與雙向回傳](docs/03-integration.md)
- [接線表｜兩端共用 SPI](docs/04-wiring.md)
- [供電設計與首件驗證](docs/05-power.md)
- [程式使用與授課引導](docs/06-code.md)
- [學生紀錄與成果驗收](docs/07-assessment.md)
- [實際材料與購買連結](docs/08-materials.md)
- [安裝與下載](docs/09-setup.md)
- [練習題與解答](docs/10-exercises.md)
- [助教備課與除錯](docs/11-instructor.md)
- [驗證狀態與來源](docs/12-validation.md)

## 使用GitHub

直接點文件閱讀即可，不需要安裝Git。下載全部內容：本儲存庫上方 **Code → Download ZIP**，解壓縮後再開啟`.ino`，不要在ZIP預覽中直接操作。要保存自己的修改，可Fork至個人帳號，或先下載到電腦。

公開儲存庫的作業請用車號或自選代號，**不要公開學號、電話或含旁人個資的影片**。學生作業不需要公開張貼在Issues；以教師指定方式個別交件。

版本：v1.2 / 2026-11-10。價格為2026-11-09查得的參考價，非今日庫存承諾。教學內容依社課原定三堂主題重整，不包含原企畫書中的幹部個資與行政預算文件。
